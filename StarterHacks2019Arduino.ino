#include <IRremote.h>

int led1 = 10;
int led2 = 9;
int led3 = 8;
int led4 = 7;
int led5 = 6;
int led6 = 5;
int lastbutton = 0;
char num[8];
const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}
void output(){
  int j;
  if (Serial.available()>0){
  for(j=0;j<8;j++){
    char c = num[j];
    Serial.println(c);
  }
  }
}

void loop(){
  if (irrecv.decode(&results)){
    lastbutton = millis();
    int i;
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            digitalWrite(led5, LOW);
            digitalWrite(led6, LOW);
            delay(80);
            
      switch(results.value){
        for(i = 0; i<8; i++){
        case 0xFFA25D:
           Serial.println("CH-");
            break;
        case 0xFF629D:
            Serial.println("CH");
            break;
        case 0xFFE21D:
            Serial.println("CH+");
            break;
        case 0xFF22DD:
            Serial.println("|<<");
            break;
        case 0xFF02FD:
            Serial.println(">>|");
            break ;  
        case 0xFFC23D:
            Serial.println(">|");
            break ;               
        case 0xFFE01F:
            Serial.println("-");
            break ;  
        case 0xFFA857:
            Serial.println("+");
            break ;  
        case 0xFF9867:
            Serial.println("EQ");
            output();
            break ;  
        case 0xFF6897:
            Serial.println("0");
            num[i]='0';
            digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            digitalWrite(led5, HIGH);
            digitalWrite(led6, LOW);
            break ;  
        case 0xFFB04F:
            Serial.println(".");
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            digitalWrite(led5, HIGH);
            digitalWrite(led6, LOW);
         
            break ;
        case 0xFF30CF:
            Serial.println("1");
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, HIGH);
            digitalWrite(led5, LOW);
            digitalWrite(led6, LOW);
    
            break ;
         case 0xFF18E7:
            Serial.println("2");
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, HIGH);
            digitalWrite(led5, HIGH);
            digitalWrite(led6, LOW);
        
            break ;
         case 0xFF7A85:
          Serial.println("3");
          digitalWrite(led1, HIGH);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, LOW);
          digitalWrite(led6, LOW);
      
          break ;
        case 0xFF10EF:
          Serial.println("4");
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, LOW);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, LOW);
          digitalWrite(led6, LOW);
   
          break ;
        case 0xFF38C7:
          Serial.println("5");
          digitalWrite(led1, LOW);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, LOW);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, LOW);
          digitalWrite(led6, LOW);
      
          break ;
        case 0xFF5AA5:
          Serial.println("6");
          digitalWrite(led1, HIGH);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, LOW);
         
          break ;
        case 0xFF42BD:
          Serial.println("7");
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, LOW);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, LOW);
         
          break ;
        case 0xFF4AB5:
          Serial.println("8");
          digitalWrite(led1, LOW);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, LOW);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, LOW);
          
          break ;
        case 0xFF52AD:
          Serial.println("9");
          digitalWrite(led1, HIGH);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, LOW);
    
          break ;  
        }
        delay(500);
        }

        key_value = results.value;
        irrecv.resume(); 
}
        Serial.println("hi");
          if (millis() > lastbutton + 2000) {
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            digitalWrite(led5, LOW);
            digitalWrite(led6, LOW);  
          }
}
