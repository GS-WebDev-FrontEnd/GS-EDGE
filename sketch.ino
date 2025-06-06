#include <LiquidCrystal.h>

// Definição de pinos
const int nivelAguaPin = A0;
const int sensorChuvaPin = A1;
const int ledVerde = 3;
const int ledAmarelo = 4;
const int ledVermelho = 5;
const int buzzer = 6;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int nivelAguaAnterior = 0;

void setup() {
  pinMode(sensorChuvaPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Sist. de Alerta");
  lcd.setCursor(0, 1);
  lcd.print("Risco de alagam.");
  delay(2000);
  lcd.clear();
}

void loop() {
  int nivelAgua = analogRead(nivelAguaPin);
  int chuvaValor = analogRead(sensorChuvaPin);

  int nivelPercentual = map(nivelAgua, 0, 1023, 0, 100);
  int chuvaPercentual = map(chuvaValor, 0, 1023, 0, 100);

  bool estaChovendo = chuvaPercentual > 50;  // Exemplo de limite para chuva


  // Verifica se o nível de água está subindo
  bool nivelSubindo = nivelPercentual > nivelAguaAnterior;

  // Atualiza LCD
  lcd.setCursor(0, 0);
  lcd.print("Nivel: ");
  lcd.print(nivelPercentual);
  lcd.print("%   ");

  lcd.setCursor(0, 1);
  lcd.print("Chuva: ");
  lcd.print(chuvaPercentual);
  lcd.print("%     ");

  // Debug no Serial Monitor
  Serial.print("Nivel: ");
  Serial.print(nivelPercentual);
  Serial.print(" | Chuva: ");
  Serial.println(chuvaPercentual);
  Serial.print("% | Subindo: ");
  Serial.println(nivelSubindo);


  //  Lógica combinada para alerta
  if (nivelPercentual < 30 ) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  } 
  else if ((nivelPercentual >= 30 && nivelPercentual < 70)) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  } 
  else { //  Alerta máximo se qualquer um estiver alto
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 1000);
  }

  delay(1000);
}
