#include <Servo.h> //biblioteca responsavel por controlar os servos
#include <NewPing.h>
#include <Ultrasonic.h>
//---------------
#define bracodir 7
#define bracoesq 6 //definiçoes das partes braço e cabeça
#define cabeca 5
//---------------
#define Triger_Ultra 3
#define Echo_Ultra 2 //Defines do sensor ultra sonico
#define Max_Distance 100
#define Min_Distance 15
Ultrasonic ultrasonic(Triger_Ultra, Echo_Ultra);
//---------------
#define Mot1A 22
#define Mot1B 23
                //Defines dos motores
#define Mot2A 24 
#define Mot2B 25
                
#define VelEsq 8 //controle de velocidade dos motores
#define VelDir 9

#define VelFrent 110
#define VelVirar 200
//--------------
int trabalho = 0; //Sistemas de trabalho

#define botaoTrabalho 10
#define LedTrabalho 26
Servo PServo; //instancia do objeto Servo.




void setup() {
  Stodos(90,90,90);
  
  pinMode(LedTrabalho, OUTPUT);
  pinMode(VelEsq, OUTPUT);
  pinMode(VelDir, OUTPUT);
  pinMode(Mot1A,OUTPUT);
  pinMode(Mot1B,OUTPUT);
  pinMode(Mot2A,OUTPUT);
  pinMode(Mot2B,OUTPUT);
  ForcaMotor(120);
  randomSeed(analogRead(A0));
  pinMode(botaoTrabalho,INPUT);
  
  InicializacaoDeLed();
  
  Serial.begin(9600);
  //AnimVideo();
}

void loop() {
  
  Serial.println(trabalho);
  ControlTrabalho();
  EscolhaDoTrabalho(); 
   
}
