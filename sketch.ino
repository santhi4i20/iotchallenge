#include <SoftwareSerial.h>

#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_PIN 4

SoftwareSerial bluetooth(10, 11);  // RX, TX para simular Bluetooth

// Dados simulados da moto
String placa = "MOT1234";
String modelo = "Sport 110i";
float latitude = -23.55052;
float longitude = -46.63331;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Sistema Mottu iniciado...");
  bluetooth.println("Conectando...");
}

long medirDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH);
  long distancia = duracao * 0.034 / 2;  // distância em cm
  return distancia;
}

void loop() {
  long distancia = medirDistancia();

  // LED e alerta conforme presença da moto
  if (distancia < 15) {
    digitalWrite(LED_PIN, HIGH); // Moto presente
  } else {
    digitalWrite(LED_PIN, LOW);  // Moto ausente
    bluetooth.println("ALERTA: Moto ausente da vaga!");
  }

  // Monta string de dados
  String dados = "PLACA:" + placa +
                 "|MODELO:" + modelo +
                 "|LAT:" + String(latitude, 5) +
                 "|LON:" + String(longitude, 5) +
                 "|DIST:" + String(distancia) + "cm";

  Serial.println("Enviando dados: " + dados);
  bluetooth.println(dados);

  // Simula movimentação da moto
  latitude += 0.00001;
  longitude += 0.00002;

  delay(5000);
}
