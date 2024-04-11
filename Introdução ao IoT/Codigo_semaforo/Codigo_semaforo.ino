// CS&I LAB - INTRODUÇÃO À INTERNET DAS COISAS - SEMÁFORO

// Executada uma única vez
void setup() {

  pinMode(2, OUTPUT);  // Define o pino 2 como saída
  pinMode(3, OUTPUT);  // Define o pino 3 como saída
  pinMode(4, OUTPUT);  // Define o pino 4 como saída

}

//Executa constantemente
void loop() {

  digitalWrite(2, HIGH); // Liga o LED verde
  delay(4000);           // Aguarda 4 segundos
  digitalWrite(2, LOW);  // Apaga o LED verde

  digitalWrite(3, HIGH); // Liga o LED amarelo
  delay(2000);           // Aguarda 2 segundos
  digitalWrite(3, LOW);  // Apaga o LED amarelo

  digitalWrite(4, HIGH); // Liga o LED vermelho
  delay(5000);           // Aguarda 5 segundos
  digitalWrite(4, LOW);  // Apaga o LED vermelho
}