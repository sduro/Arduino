

// Pin 2-8 is connected to the 7 segments of the display.
/*
int segA = 2; 
int segB = 3; 
int segC = 4; 
int segD = 5; 
int segE = A0; //pin 6 is used bij display 1 for its pwm function
int segF = 7; 
int segG = 8; 
int digit1 = 6; //PWM Display most left display
int digit2 = 9; //PWM Display second left
int digit3 = 10; //PWM Display second right display
int digit4 = 11; //PWM Display most right display
*/


int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = A0; //6
int pinF = 7;
int pinG = 8;
int D1 = 6;
int D2 = 9;
int D3 = 10;
int D4 = 11;
//general var

long incomingByte;

#define DISPLAY_BRIGHTNESS  500

boolean duiz = false;
boolean hon = false;

// the setup routine runs once when you press reset:
void setup() {
Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
// initialize the digital pins as outputs.
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
pinMode(pinE, OUTPUT);
pinMode(pinF, OUTPUT);
pinMode(pinG, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //  incomingByte = random(1000, 9999);
  Serial.println(incomingByte);
 
    duiz = false;
    hon = false;
       for(int k = 0; k<10; k++){ // for loop to slow it down.
    incomingByte=42;    
       
for(int digit = 1 ; digit < 5 ; digit++) {
    switch(digit){
        case 1:
            if (incomingByte>999) {
                digitalWrite(D1, HIGH);
                showNumber(incomingByte /1000);
                incomingByte %= 1000;
                
                delayMicroseconds(DISPLAY_BRIGHTNESS); 
             if (incomingByte < 100){
            duiz = true;
            if (incomingByte <10){
            hon = true;
         }
     
      }else duiz = false; 
     }
            break;
        case 2:
            if (duiz==true){
              digitalWrite(D2, HIGH);
                showNumber(0);
                delayMicroseconds(DISPLAY_BRIGHTNESS); 
              }
               if(hon == true){
            break;
            }
            if (incomingByte>99 && incomingByte<1000) {
                digitalWrite(D2, HIGH);
                showNumber(incomingByte /100);
                incomingByte %= 100;
                delayMicroseconds(DISPLAY_BRIGHTNESS); 
                if (incomingByte < 10){
                  hon = true;
                }else hon = false;
            }
            break;
        case 3:
         if (hon==true){
              digitalWrite(D3, HIGH);
                showNumber(0);
                delayMicroseconds(DISPLAY_BRIGHTNESS); 
                break;
              }
                       
            if (incomingByte>9 && incomingByte<100) {
                digitalWrite(D3, HIGH);
                showNumber(incomingByte /10);
                incomingByte %= 10;
                delayMicroseconds(DISPLAY_BRIGHTNESS); 
            }
            break;
         case 4:
            if (incomingByte < 10) {
                digitalWrite(D4, HIGH);
                showNumber(incomingByte);
                delayMicroseconds(DISPLAY_BRIGHTNESS); 
            }
            break;
   

    } 
showNumber(11);
//ALL DIGITS OFF
digitalWrite(D1, LOW);
digitalWrite(D2, LOW);
digitalWrite(D3, LOW);
digitalWrite(D4, LOW);
}
}}

void showNumber(int numToDisplay) {
switch (numToDisplay){
  case 0:
  //0
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;
  case 1:
      //1
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;

    case 2:
        //2
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, LOW);
        break;

    case 3:
        //3
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, LOW);
        break;

    case 4:
        //4
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
    case 5: 
            //5
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
    case 6: 
        //6
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
    case 7: 
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;
    case 8:
        //8
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
    case 9:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;

}
}
