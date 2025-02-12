## Link do Vídeo: https://youtube.com/shorts/SkHSjfy0ImE

# 🎯 Controle de Servomotor com PWM no Raspberry Pi Pico

Este projeto demonstra o controle de um servomotor utilizando **modulação por largura de pulso (PWM)** no **Raspberry Pi Pico**, integrado a um LED para feedback visual.
---

## 📌 Objetivos da Atividade
✅ Configurar **PWM** em **50Hz** (período de **20ms**) na **GPIO22**  
✅ Posicionar o servo em **180° (2.400µs)**, **90° (1.470µs)** e **0° (500µs)** com intervalos de **5s**  
✅ Implementar **movimento suave** contínuo entre **0° e 180°**  
✅ Analisar o comportamento do **LED** na **GPIO12** durante a operação  

---

## 🛠 Materiais Necessários

| Componente | Especificação |
|------------|---------------|
| 🖥 **Microcontrolador** | Raspberry Pi Pico W |
| 🎛 **Servomotor** | Micro Servo SG90 |
| 💡 **LED** | RGB (canal azul - GPIO12) |

---

## 🔌 Conexões Físicas

| Componente | Pino Pico | Função |
|------------|-----------|--------|
| 🏎 **Servo - Sinal** | GPIO22 | Controle PWM |
| 🔋 **Servo - VCC** | 5V | Alimentação |
| ⚫ **Servo - GND** | GND | Terra |
| 💡 **LED - Anodo** | GPIO12 | Sinal digital |
| ⚫ **LED - Catodo** | GND | Terra |

---

## 💻 Código Principal

### ✨ Funcionalidades Chave:
- **Configuração PWM:** Precisão de **50Hz** para controle angular
- **Posicionamento Exato:**
  ```c
  set_position(2400); // 180° (2.400µs)
  set_position(1470); // 90° (1.470µs)
  set_position(500);  // 0° (500µs)
  ```
- **Movimento Suave:** Incrementos de **5µs** com **delay de 10ms**
- **Controle do LED:** Estados lógicos sincronizados com as operações

---

## 🔦 Observações do LED (GPIO12)

### 🔹 Estados Fixos:
✅ **180° e 0°** → LED **permanentemente aceso**  
❌ **90°** → LED **completamente apagado**  

---

## 📊 Conclusões Técnicas
🔹 Demonstração prática do uso de **PWM** para controle de posição  
🔹 Correlação direta entre **duty cycle** e resposta física do servo  
🔹 Visualização em **tempo real** da atividade do microcontrolador via LED  
🔹 **Taxa de atualização do PWM** afeta diretamente a **percepção visual**  

---

## **Projeto Desenvolvido por César Rebouças Costa**

