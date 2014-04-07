int FotoPin1 = A0; //pin del fotoresistore 1
int FotoPin2 = A1;
int FotoPin3 = A2;
int FotoPin4 = A3;
int FotoPin5 = A4;
int FotoPin6 = A5;

int ledPinR1 = 12; //pin ROSSO del led 1
int ledPinG1 = 0; //pin VERDE del led 1
int ledPinB1 = 13; //pin BLU del led 1
int ledPinR2 = 10;
int ledPinG2 = 0;
int ledPinB2 = 11;
int ledPinR3 = 8;
int ledPinG3 = 0;
int ledPinB3 = 9;
int ledPinR4 = 6;
int ledPinG4 = 0;
int ledPinB4 = 7;
int ledPinR5 = 4;
int ledPinG5 = 0;
int ledPinB5 = 5;
int ledPinR6 = 2;
int ledPinG6 = 0;
int ledPinB6 = 3;

int FotoValue1;
int FotoValue2;
int FotoValue3;
int FotoValue4;
int FotoValue5;
int FotoValue6;

int SOGLIA_PREMUTO = 300; //soglia del fotoresistore per la pressione
int pulsanti[] = {1, 2, 3, 4, 5, 6}; //pulsanti da implementare - MAX {1, 2, 3, 4, 5, 6}
int NUM_PULSANTI;

long punteggio;
int pulsante_attivo;
int pulsante_premuto;
int num_fake;
boolean genera_pulsanti;
boolean gioco_finito;

void disattiva_pulsanti(){
  digitalWrite(ledPinR1, LOW);
  digitalWrite(ledPinR2, LOW);
  digitalWrite(ledPinR3, LOW);
  digitalWrite(ledPinR4, LOW);
  digitalWrite(ledPinR5, LOW);
  digitalWrite(ledPinR6, LOW);
  digitalWrite(ledPinG1, LOW);
  digitalWrite(ledPinG2, LOW);
  digitalWrite(ledPinG3, LOW);
  digitalWrite(ledPinG4, LOW);
  digitalWrite(ledPinG5, LOW);
  digitalWrite(ledPinG6, LOW);
  digitalWrite(ledPinB1, LOW);
  digitalWrite(ledPinB2, LOW);
  digitalWrite(ledPinB3, LOW);
  digitalWrite(ledPinB4, LOW);
  digitalWrite(ledPinB5, LOW);
  digitalWrite(ledPinB6, LOW);
}

void attiva_pulsanti(){
  shuffle_pulsanti();
  
  pulsante_attivo = pulsanti[0];
  
  switch (pulsante_attivo){
    case 1:
      digitalWrite(ledPinB1, HIGH);
      break;
    case 2:
      digitalWrite(ledPinB2, HIGH);
      break;
    case 3:
      digitalWrite(ledPinB3, HIGH);
      break;
    case 4:
      digitalWrite(ledPinB4, HIGH);
      break;
    case 5:
      digitalWrite(ledPinB5, HIGH);
      break;
    case 6:
      digitalWrite(ledPinB6, HIGH);
      break;
  }
  
  num_fake = random(0, NUM_PULSANTI);
  
  while (num_fake>0){
    int pulsante_fake = pulsanti[num_fake];
    num_fake--;
    
    switch (pulsante_fake){
      case 1:
        digitalWrite(ledPinR1, HIGH);
        break;
      case 2:
        digitalWrite(ledPinR2, HIGH);
        break;
      case 3:
        digitalWrite(ledPinR3, HIGH);
        break;
      case 4:
        digitalWrite(ledPinR4, HIGH);
        break;
      case 5:
        digitalWrite(ledPinR5, HIGH);
        break;
      case 6:
        digitalWrite(ledPinR6, HIGH);
        break;
      
    }
  }
}

void shuffle_pulsanti(){
  for (int a=0; a<NUM_PULSANTI; a++){
    int r = random(a,NUM_PULSANTI);
    int temp = pulsanti[a];
    pulsanti[a] = pulsanti[r];
    pulsanti[r] = temp;
  }
}

int premuto(){
  int pulsante_premuto;
  FotoValue1 = analogRead(FotoPin1);
  FotoValue2 = analogRead(FotoPin2);
  FotoValue3 = analogRead(FotoPin3);
  FotoValue4 = analogRead(FotoPin4);
  FotoValue5 = analogRead(FotoPin5);
  FotoValue6 = analogRead(FotoPin6);
  
  Serial.println(FotoValue1);
  Serial.println(FotoValue2);
  Serial.println(FotoValue3);
  Serial.println(FotoValue4);
  Serial.println(FotoValue5);
  Serial.println(FotoValue6);
  
  if (FotoValue1<SOGLIA_PREMUTO){
    pulsante_premuto=1;
  }
  else if (FotoValue2<SOGLIA_PREMUTO){
    pulsante_premuto=2;
  }
  else if (FotoValue3<SOGLIA_PREMUTO){
    pulsante_premuto=3;
  }
  else if (FotoValue4<SOGLIA_PREMUTO){
    pulsante_premuto=4;
  }
  else if (FotoValue5<SOGLIA_PREMUTO){
    pulsante_premuto=5;
  }
  else if (FotoValue6<SOGLIA_PREMUTO){
    pulsante_premuto=6;
  }
  else{
    pulsante_premuto=0;
  }
  
  return pulsante_premuto;
}
 
void setup() {
  Serial.begin(9600);
  NUM_PULSANTI = sizeof(pulsanti) / sizeof(int);
  pinMode(ledPinR1, OUTPUT);
  pinMode(ledPinG1, OUTPUT);
  pinMode(ledPinB1, OUTPUT);
  pinMode(ledPinR2, OUTPUT);
  pinMode(ledPinG2, OUTPUT);
  pinMode(ledPinB2, OUTPUT);
  pinMode(ledPinR3, OUTPUT);
  pinMode(ledPinG3, OUTPUT);
  pinMode(ledPinB3, OUTPUT);
  pinMode(ledPinR4, OUTPUT);
  pinMode(ledPinG4, OUTPUT);
  pinMode(ledPinB4, OUTPUT);
  pinMode(ledPinR5, OUTPUT);
  pinMode(ledPinG5, OUTPUT);
  pinMode(ledPinB5, OUTPUT);
  pinMode(ledPinR6, OUTPUT);
  pinMode(ledPinG6, OUTPUT);
  pinMode(ledPinB6, OUTPUT);
  genera_pulsanti = true;
  boolean gioco_finito = false;
  punteggio=0;
}
 
void loop() {
  if (genera_pulsanti){
    genera_pulsanti=false;
    disattiva_pulsanti();
    attiva_pulsanti();
  }
  
  pulsante_premuto=premuto();
  
  Serial.print("Pulsante premuto: ");
  Serial.println(pulsante_premuto);
  Serial.print("Pulsante attivo: ");
  Serial.println(pulsante_attivo);
  
  if(!gioco_finito){
    if (pulsante_premuto==pulsante_attivo){
      punteggio++;
      genera_pulsanti=true;
      delay(500);
    }
    else if (pulsante_premuto==0){
    }
    else{
      gioco_finito = true;
      Serial.print("Punteggio: ");
      Serial.println(punteggio);
    }
  }
  delay(500);
}