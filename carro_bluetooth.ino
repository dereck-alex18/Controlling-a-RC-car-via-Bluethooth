// Author: Dereck Portela


#define MOTOR1_IN1 8
#define MOTOR1_IN2 9
#define MOTOR2_IN3 10
#define MOTOR2_IN4 11 
#define EN1 3
#define EN2 5

void setup() {
  // Set the baud rate to 9600
  Serial.begin(9600);

  //Set up all the pins which are connected to the H bridge
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN3, OUTPUT);
  pinMode(MOTOR2_IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  Serial.println("Fim do setup!");
}

char leitura; //This variable will contain what is comming from the serial port
//Those functions will be called according to what is comming from the serial port
void Forward();
void Back();
void Right();
void Left();
void Stop();

void loop() {
  
  while(!Serial.available());
  //When a character is sent, the variable "leitura" will have this caracter
  //And depending on the character(F, B, L, R), the RC car will move forward, back, left, right
  //If any of those characters is not recevied the RC car will stop immediately 
  leitura = Serial.read();
  Serial.println(leitura);

   Stop();
  
  if(leitura == 'F' || leitura == 'f'){
      Forward();
      Serial.println("Frente!");
    
    }
  else if(leitura == 'B'){
    
       Back();
    }
  else if(leitura == 'R'){
    
       Right();
    }
  else if(leitura == 'L'){
      Left();
    
    }    
  
  // Stop();

}

void Forward(){
    //This function moves the RC forward
    digitalWrite(MOTOR1_IN2, HIGH);
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite (MOTOR2_IN3, LOW);
    digitalWrite(MOTOR2_IN4, HIGH);
    analogWrite(EN1, 255);
    analogWrite(EN2, 255);
  }

  void Back(){
    //This function moves the RC back
    analogWrite(EN1, 255);
    analogWrite(EN2, 255);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite (MOTOR2_IN3, HIGH);
    digitalWrite(MOTOR2_IN4, LOW);
    
    
    
    }
    void Right(){
    //This function moves the RC right  
      analogWrite(EN1, 200);
      analogWrite(EN2, 200);
      digitalWrite(MOTOR1_IN2, HIGH);
      digitalWrite(MOTOR1_IN1, LOW);
      digitalWrite (MOTOR2_IN3, HIGH);
      digitalWrite(MOTOR2_IN4, LOW);
      
      }
    void Left(){
      //This function moves the RC left
      analogWrite(EN1, 200);
      analogWrite(EN2, 200);    
      digitalWrite(MOTOR1_IN2, LOW);
      digitalWrite(MOTOR1_IN1, HIGH);
      digitalWrite (MOTOR2_IN3, LOW);
      digitalWrite(MOTOR2_IN4, HIGH);
          
        
        }

    void Stop(){
      //This function stops the RC car
      digitalWrite(MOTOR1_IN2, LOW);
      digitalWrite(MOTOR1_IN1, LOW);
      digitalWrite (MOTOR2_IN3, LOW);
      digitalWrite(MOTOR2_IN4, LOW);
        
        
    }
