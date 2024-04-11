// CS&I LAB - INTRODUÇÃO À INTERNET DAS COISAS - LÂMPADA

#define rele 13 // Atribui o pino 13 ao nome "rele"

void setup() {

  Serial.begin(9600);        // Inicia a comunicação serial

  pinMode(rele, OUTPUT);     // Define o pino "rele" como saída
  digitalWrite(rele, HIGH);  // Inicia com a lampada desligada
}

void loop() {

  if (Serial.available() > 0){                // Monitora a presença de dados na porta serial

    char leitura = Serial.read();             // Lê os dados da porta serial

    if (leitura == 'D' || leitura == 'd') {   // Condição para Desligar
      digitalWrite(rele,HIGH);                // Desliga a Lampada
      Serial.println("Lampada desligada");    // Mostra que está desligado na serial
    }
    else if (leitura == 'L' || leitura == 'l') {  // Condição para Ligar
      digitalWrite(rele, LOW);                    // Liga a Lampada
      Serial.println("Lampada Ligada");           // Mostra que está ligado na serial
    }
  }
}