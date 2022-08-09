#define tempoServo 130 //Tempo universal para os servos pararem.
//VOIDS RESPONSAVEIS POR MEXER OS MEMBROS DO  ROBO
void Bdir(int ang){
  PServo.attach(bracodir);
  PServo.write(ang);
  delay(tempoServo);
  PServo.detach();
  
}

void Bdir(int ang,int De){
  PServo.attach(bracodir);
  PServo.write(ang);
  delay(De);
  PServo.detach();
  
}

void Besq(int ang){
  PServo.attach(bracoesq);
  PServo.write(180 - ang);
  delay(tempoServo);
  PServo.detach();
  
}

void Besq(int ang,int De){
  PServo.attach(bracoesq);
  PServo.write(180 - ang);
  delay(De);
  PServo.detach();
  
}


void Cab(int ang){
  PServo.attach(cabeca);
  PServo.write(ang);
  delay(tempoServo);
  PServo.detach();
  
}

void Cab(int ang,int De){
  PServo.attach(cabeca);
  PServo.write(ang);
  delay(De);
  PServo.detach();
  
}
#define tttempoTodos 300
void Stodos(int dir,int esq,int cab){
  PServo.attach(bracodir);
  PServo.write(dir);
  delay(tttempoTodos);
  PServo.detach();

  PServo.attach(bracoesq);
  PServo.write(esq);
  delay(tttempoTodos);
  PServo.detach();

  PServo.attach(cabeca);
  PServo.write(cab);
  delay(tttempoTodos);
  PServo.detach();

}
