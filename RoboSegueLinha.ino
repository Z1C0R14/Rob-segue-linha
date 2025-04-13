// Aqui é definido os sensores ópticos e em quais entradas do Arduíno estão
#define pinSensorD 11
#define pinSensorE 12

// Aqui é definido a velocidade dos motores
#define velocidade 80

// Aqui é definido os sensores dos motor (pra ir pra frente e pra trás) e também onde estão em cada entrada
#define pinMotorE1 3
#define pinMotorE2 5
#define pinMotorD1 6
#define pinMotorD2 9

void setup(){
  // put your setup code here, to run once:
  pinMode(pinSensorE, INPUT);
  pinMode(pinSensorD, INPUT);

  pinMode(pinMotorE1, OUTPUT);
  pinMode(pinMotorE2, OUTPUT);
  pinMode(pinMotorD1, OUTPUT);
  pinMode(pinMotorD2, OUTPUT);
}

void loop(){
  // put your main code here, to run repeatedly:
  bool estadoD = !digitalRead(pinSensorD);
  bool estadoE = !digitalRead(pinSensorE);

  if(estadoE && estadoD){
    analogWrite(pinMotorD1, velocidade);
    analogWrite(pinMotorD2, velocidade);
    analogWrite(pinMotorE1, velocidade);
    analogWrite(pinMotorE2, velocidade);
  }
  if(!estadoE && !estadoD){
    analogWrite(pinMotorD1, velocidade);
    analogWrite(pinMotorD2, velocidade);
    analogWrite(pinMotorE1, velocidade);
    analogWrite(pinMotorE2, velocidade);
  }
  if(!estadoE && estadoD){
    digitalWrite(pinMotorD2, LOW);
    analogWrite(pinMotorD1, velocidade);
    digitalWrite(pinMotorE2, LOW);
    analogWrite(pinMotorE1, velocidade);
  }
  if(estadoE && !estadoD){
    digitalWrite(pinMotorE1, LOW);
    analogWrite(pinMotorE2, velocidade);
    digitalWrite(pinMotorD1, LOW);
    analogWrite(pinMotorD2, velocidade);
  }
}
