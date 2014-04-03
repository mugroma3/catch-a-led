/*Catch-a-led game project*/

#define l1g 0
#define l1r 1
#define l2g 2
#define l2r 3
#define l3g 4
#define l3r 5
#define l4g 6
#define l4r 7
#define l5g 8
#define l5r 9
#define l6g 10
#define l6r 11
#define f1 A0
#define f2 A1
#define f3 A2
#define f4 A3
#define f5 A4
#define f6 A5


int points;
int tempPR;

// update points
void updatePoints(int value){
  points = points + value;
}

void blinkLed(int led, int dt){
  digitalWrite(led,HIGH);
  getCatch(led,dt);
  digitalWrite(led,LOW);
}

void getCatch(int led, int dt){
  findPhotoresistor(led);
  int catched=0;
  delay(dt/2);
  catched = analogRead(tempPR);
  if(catched>0)
    updatePoints(100);
  else
    updatePoints(-100);
  tempPR=0;
  delay(dt/2);
}

void findPhotoresistor(int led){
  switch (led) {
  case 1:   
    tempPR = f1;
    break;
  case 2:   
    tempPR = f2;
    break;
  case 3: 
    tempPR = f3;
    break;
  case 4: 
    tempPR = f4;
    break;  
  case 5: 
    tempPR = f5;
    break;
  case 6: 
    tempPR = f6;
    break;
  } 
}

void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(l1r,OUTPUT);
  pinMode(l1g,OUTPUT);
  points = 0;
  tempPR = 0;
}

void loop() {
  blinkLed(l1g,1000);


  delay(20000000); //just for pausing the game, while shut down Arduino
  }

}
