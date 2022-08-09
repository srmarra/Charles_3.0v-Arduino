//-Trabalho responsavel por desviar de obstaculos
void SensorUltraSonico(){
 float Distancia = ultrasonic.convert(ultrasonic.timing(), Ultrasonic::CM);
  
  
  if(Distancia<= Min_Distance && Distancia > 0){
    digitalWrite(LedTrabalho,HIGH);
    delay(75);
    digitalWrite(LedTrabalho, LOW);
    MotorDir(0);
    delay(250);
    if(Distancia <= Min_Distance && Distancia>0){
      analogWrite(VelEsq, VelVirar);
      analogWrite(VelDir, VelVirar);
      Mot_Virar();
    }
  }else{
    analogWrite(VelEsq, VelFrent);
    analogWrite(VelDir, VelFrent);
    Mot_Frente();
    
  }
  
}


//-Trabalho responsavel por ir para tras quando detectar colisão
int virar  = 0;
void FrenteTras(){
  float Distancia = ultrasonic.convert(ultrasonic.timing(), Ultrasonic::CM);
  if(Distancia <= Min_Distance && Distancia > 0){
    ForcaMotor(VelFrent);
    MotorDir(-1);
    virar++;
    delay(125);
    Serial.print(".");
  }else{
    MotorDir(0);
  }

  if(virar > 10){
    Serial.println("");
    Serial.print("virou");
    ForcaMotor(VelVirar);
    Mot_Virar();
    virar = 0;
  }
}



void Sentinela(){
  for(int i=0;i<180;i++){
    Cab(i,30);
    
  }
  delay(800);
  for(int i=180;i>0;i--){
    Cab(i,30);
  }
  delay(800);
}




//animação utilizada no video
#define animvTempoInicio 3000
#define esperaUmMotor 1000
#define esperaVirarMotUm 500
void AnimVideo(){
  delay(animvTempoInicio);
  Cab(180);
  Cab(180);
  
  delay(esperaUmMotor);
  MotorDir(2);
  delay(esperaVirarMotUm);
  MotorDir(0);
  delay(200);
  Cab(85);
  delay(2000);
  Bdir(180);
  Besq(180);
  delay(900);
  Besq(60);
  Bdir(60);
  delay(2000);
  Bdir(180);
  delay(400);
  Bdir(60);
  delay(1000);
  Cab(180); 
  delay(500);
  Cab(85);
  delay(6000);
  
  volt:
  MotorDir(2);
  Cab(0);
  Bdir(180);
  Besq(180);
  delay(100);
  MotorDir(3);
  Cab(180);
  Bdir(60);
  Besq(60);
  goto volt;
  delay(100);
  
}


//essa void controla o botão e troca de trabalho quando o botão for apertado
#define maxTrabalho 3
void ControlTrabalho(){
  
  if(trabalho > maxTrabalho){
      trabalho = 0;  
  }

  if(digitalRead(botaoTrabalho) == 1){
    trabalho++;
    digitalWrite(LedTrabalho,HIGH);
    delay(750);
    digitalWrite(LedTrabalho, LOW);
  }
}

//Essa void troca de trabalho
void EscolhaDoTrabalho(){
  switch(trabalho){
    case 0:
      MotorDir(0);
      break;
    case 1:
      SensorUltraSonico();
      break;
    case 2:
      FrenteTras();
      break;
    case 3:
      Sentinela();
      break;
    default:
      MotorDir(0);
  }
  
}




//void responsavel por indicar que o robo iniciou piscando a led varias vezes
#define ltt 50
void InicializacaoDeLed(){
  digitalWrite(LedTrabalho,HIGH);
  delay(ltt);
  digitalWrite(LedTrabalho, LOW);
  delay(ltt);
  digitalWrite(LedTrabalho,HIGH);
  delay(ltt);
  digitalWrite(LedTrabalho, LOW);
  delay(ltt);
  digitalWrite(LedTrabalho,HIGH);
  delay(ltt);
  digitalWrite(LedTrabalho, LOW);
  delay(ltt);
  digitalWrite(LedTrabalho,HIGH);
  delay(ltt);
  digitalWrite(LedTrabalho, LOW);
  delay(ltt);
  
}
