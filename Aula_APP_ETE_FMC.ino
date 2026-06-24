#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// =======================
// Configuração do DHT11
// =======================
#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Informações da rede Wi-Fi
const char* ssid = "WLL-Inatel";
const char* password = "inatelsemfio";

// Informações do broker MQTT
const char* mqttServer = "0d7c95f4e39541858c28b9278c812618.s1.eu.hivemq.cloud";
const char* mqttUser = "INATEL";
const char* mqttPassword = "Telecom2025";
const int mqttPort = 8883;

const char* ID = "sensor_temperatura";
const char* mqttTopicPub = "fogueira";

WiFiClientSecure espClient;
PubSubClient client(espClient);

void connect() {
  while (!client.connected()) {
    Serial.println("Conectando ao Broker MQTT...");

    if (client.connect(ID, mqttUser, mqttPassword)) {
      Serial.println("Conectado ao MQTT!");
    } else {
      Serial.printf("Falha na conexão MQTT. Código: %d\n", client.state());
      Serial.println("Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  dht.begin();

  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi conectado!");

  espClient.setInsecure();
  espClient.setTimeout(30);

  client.setServer(mqttServer, mqttPort);

  connect();
}

void loop() {

  if (!client.connected()) {
    connect();
  }

  client.loop();

  float temperatura = dht.readTemperature();

  if (isnan(temperatura)) {
    Serial.println("Erro ao ler o DHT11!");
    delay(2000);
    return;
  }

  char tempString[10];
  dtostrf(temperatura, 4, 2, tempString);

  Serial.print("Temperatura: ");
  Serial.print(tempString);
  Serial.println(" °C");

  client.publish(mqttTopicPub, tempString);

  delay(5000); // publica a cada 5 segundos
}