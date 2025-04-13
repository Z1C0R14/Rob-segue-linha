#define pinSensorD 11
#define pinSensorE 12

#define pinMotorD1 3
#define pinMotorD2 5
#define pinMotorE1 6
#define pinMotorE2 9

void setup() {
  // put your setup code here, to run once:
  pinMode(pinSensorD, INPUT);
  pinMode(pinSensorE, INPUT);

  pinMode(pinMotorD1, OUTPUT);
  pinMode(pinMotorD2, OUTPUT);
  pinMode(pinMotorE1, OUTPUT);
  pinMode(pinMotorE2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoD = digitalRead(pinSensorD);
  estadoE = digitalRead(pinSensorE);

  if(estadoD && estadoE){
    analogWrite(pinMotorD1, 90);
    analogWrite(pinMotorE1, 90);
  }
  if(!estadoD && !estadoE){
    digitalWrite(pinMotorD1, LOW);
    digitalWrite(pinMotorD2, LOW);
    digitalWrite(pinMotorE1, LOW);
    digitalWrite(pinMotorE2, LOW);
  }
  if(!estadoD && estadoE){
    analogWrite(pinMotorD1, 90);
    digitalWrite(pinMotorE1, LOW);
  }
  if(estadoD && !estadoE){
    analogWrite(pinMotorE1, 90);
    digitalWrite(pinMotorD1, LOW);
  }
}