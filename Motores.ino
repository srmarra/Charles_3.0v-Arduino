void MotorDir(int dir){ //Void responsavel por definir a direção dos motores
    switch(dir){
      case 0:
        digitalWrite(Mot2A, LOW);
        digitalWrite(Mot2B, LOW);
        digitalWrite(Mot1A, LOW);
        digitalWrite(Mot1B, LOW);
        break;
      case 1:
        digitalWrite(Mot2A, HIGH);
        digitalWrite(Mot2B, LOW);
        digitalWrite(Mot1A, HIGH);
        digitalWrite(Mot1B, LOW);
        break;
      case -1:
        digitalWrite(Mot2A, LOW);
        digitalWrite(Mot2B, HIGH);
        digitalWrite(Mot1A, LOW);
        digitalWrite(Mot1B, HIGH);
        break;
      case 2:
        digitalWrite(Mot2A, HIGH);
        digitalWrite(Mot2B, LOW);
        digitalWrite(Mot1A, LOW);
        digitalWrite(Mot1B, HIGH);
        break;
      case 3:
        digitalWrite(Mot2A, LOW);
        digitalWrite(Mot2B, HIGH);
        digitalWrite(Mot1A, HIGH);
        digitalWrite(Mot1B, LOW);
       break;
      case 4:
        digitalWrite(Mot2A, HIGH);
        digitalWrite(Mot2B, LOW);
        digitalWrite(Mot1A, LOW);
        digitalWrite(Mot1B, LOW);
        break;
      case 5:
        digitalWrite(Mot2A, LOW);
        digitalWrite(Mot2B, LOW);
        digitalWrite(Mot1A, LOW);
        digitalWrite(Mot1B, HIGH);
        break;
    }

  
}


void Mot_Frente(){
  MotorDir(1);
}




int dire;

//void responsavel por virar o robo
#define ttTempoTras 250
#define ttTempoVirar 850
#define ttTempoParar 500
void Mot_Virar(){
  MotorDir(-1);
  delay(100);
  MotorDir(0);
  delay(ttTempoParar);
  MotorDir(-1);
  delay(ttTempoTras);
  int dir = random(2,4);
  MotorDir(dir); 
  
  delay (ttTempoVirar);
  Cab(85);
}

//void responsavel por definir a forca do motor
void ForcaMotor(int F){
   analogWrite(VelEsq, F);
   analogWrite(VelDir, F);

  
}
