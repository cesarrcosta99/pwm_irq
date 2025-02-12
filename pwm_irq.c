#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Configurações do PWM Servo
#define SERVO_PIN 22
#define PWM_FREQ 50
#define CLOCK_DIV 64
#define WRAP_VALUE 39062

// LED RGB - GPIO 12 (canal verde)
#define LED_PIN 12

// Valores de pulso
#define PULSE_180 2400
#define PULSE_90 1470
#define PULSE_0 500
#define STEP 5
#define DELAY_MS 10

void setup_pwm_servo() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, CLOCK_DIV);
    pwm_config_set_wrap(&config, WRAP_VALUE);
    pwm_init(slice_num, &config, true);
}

void setup_led() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void set_position(uint pulse_us) {
    float duty = (float)pulse_us / 20000.0f;
    pwm_set_gpio_level(SERVO_PIN, (uint16_t)(duty * (WRAP_VALUE + 1)));
}

int main() {
    stdio_init_all();
    setup_pwm_servo();
    setup_led();

    // Fase 1: Posições fixas
    set_position(PULSE_180);
    gpio_put(LED_PIN, 1);  // LED ligado
    sleep_ms(5000);

    set_position(PULSE_90);
    gpio_put(LED_PIN, 0);  // LED desligado
    sleep_ms(5000);

    set_position(PULSE_0);
    gpio_put(LED_PIN, 1);  // LED ligado
    sleep_ms(5000);

    // Fase 2: Movimento contínuo
    bool led_state = true;
    while(true) {
        for(uint pulse = PULSE_0; pulse <= PULSE_180; pulse += STEP) {
            set_position(pulse);
            gpio_put(LED_PIN, led_state);
            led_state = !led_state;  // Piscar durante movimento
            sleep_ms(DELAY_MS);
        }
        
        for(uint pulse = PULSE_180; pulse >= PULSE_0; pulse -= STEP) {
            set_position(pulse);
            gpio_put(LED_PIN, led_state);
            led_state = !led_state;  // Piscar durante movimento
            sleep_ms(DELAY_MS);
        }
    }
}