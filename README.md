Projeto Mottu – Challenge 2025

Este projeto foi desenvolvido como parte do Challenge 2025 da FIAP, em parceria com a empresa Mottu. O objetivo é criar uma solução tecnológica para **monitoramento e gestão de motos em pátios**, utilizando IoT, Visão Computacional e Inteligência Artificial.

---

 Objetivo

Automatizar a localização e o status das motos nos pátios da Mottu, reduzindo falhas operacionais causadas por controle manual e aumentando a eficiência das operações.

---

Tecnologias Utilizadas

- **Arduino Uno (via Wokwi)** – Microcontrolador principal
- **HC-SR04 Ultrassônico** – Sensor de presença
- **Bluetooth (simulado via SoftwareSerial)** – Envio de dados
- **LED** – Indicador de status da moto
- **GPS (simulado)** – Localização da moto
- **Python + OpenCV** – Visão computacional para detecção de motos (ver seção abaixo)

---

Simulação no Wokwi

Link do projeto Wokwi:  
https://wokwi.com/projects/431499122682137601
---

Visão Computacional (Python)

Utilizamos um script com **Python + OpenCV** para simular a identificação de motos em imagem ou vídeo.

Requisitos:
bash
pip install opencv-python


dados simulados:
PLACA:MOT1234 | MODELO:Sport 110i | LAT:-23.55052 | LON:-46.63331 | DIST:13cm


integrantes:
Henrique Pecora Vieira de Souza - RM556612
Santhiago De Gobbi Barros de Souza - RM:98420
Lívia de Oliveira Lopes - RM:556281
