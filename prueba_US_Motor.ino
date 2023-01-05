#include <NewPing.h>

#define Trig1  6  
#define Echo1    7  
#define MaxDistance 200 
#define Trig2  4  
#define Echo2    5  
#define MaxDistance2 200

NewPing USEnfrente (Trig1, Echo1, MaxDistance);
NewPing USAtras (Trig2, Echo2, MaxDistance2);

int motorA1 = 9;
int motorB1 = 10;

int motorA2 = 11;
int motorB2 = 12;

int distanciaEnfrente = 0;
int distanciaAtras = 0;
int valorLineaIzq = 0;
int valorLineaDer = 0;

int contador = 0;
int contadorInicio = 0;

int mode = 0;
int direccion = 0;

void setup() {

 pinMode(motorA1,OUTPUT);
 pinMode(motorA2,OUTPUT);
 pinMode(motorB1,OUTPUT);
 pinMode(motorB2,OUTPUT); 

}


void loop() {
             
  distanciaEnfrente=USEnfrente.ping_cm();
  distanciaAtras=USAtras.ping_cm(); 
  
  valorLineaDer = analogRead(A0); //Derecha del Robot
  valorLineaIzq = analogRead(A1); //Izquierda del Robot

  if (mode == 0){//Enfrente
    digitalWrite(motorA1,LOW);
    digitalWrite(motorB1,HIGH);

    digitalWrite(motorA2,LOW);
    digitalWrite(motorB2,HIGH);
  }

   if (mode == 1){//Atras
    digitalWrite(motorA1,HIGH);
    digitalWrite(motorB1,LOW);

    digitalWrite(motorA2,HIGH);
    digitalWrite(motorB2,LOW);

    delay(150);

        if (direccion == 0){
          mode = 2;
        } else {
          mode = 3;
          }

          direccion = 0;
  }

   if (mode == 2 && contador < 25){//Girar Izq
    digitalWrite(motorA1,HIGH);
    digitalWrite(motorB1,LOW);

    digitalWrite(motorA2,LOW);
    digitalWrite(motorB2,HIGH);

    delay(17);

    digitalWrite(motorA1,LOW);
    digitalWrite(motorB1,LOW);

    digitalWrite(motorA2,LOW);
    digitalWrite(motorB2,LOW);

    delay(100);
   
    contador++;
 
  }

  if (mode == 3 && contador < 25){//Girar Der
    digitalWrite(motorA1,LOW);
    digitalWrite(motorB1,HIGH);

    digitalWrite(motorA2,HIGH);
    digitalWrite(motorB2,LOW);

    delay(17);

    digitalWrite(motorA1,LOW);
    digitalWrite(motorB1,LOW);

    digitalWrite(motorA2,LOW);
    digitalWrite(motorB2,LOW);

    delay(100);

    contador++;
  }

  if (mode == 4){//Avance Lento
    digitalWrite(motorA1,LOW);
    digitalWrite(motorB1,HIGH);

    digitalWrite(motorA2,LOW);
    digitalWrite(motorB2,HIGH);

  }
  

  
  if(mode == 10){
    digitalWrite(motorA1,LOW);
    digitalWrite(motorB1,LOW);

    digitalWrite(motorA2,LOW);
    digitalWrite(motorB2,LOW);
  }
  
//---------------------------------------


  if(contador >= 25){ //Reset Contador
  mode = 4;
  contador = 0;  
  }
  
if(contadorInicio==0){
  delay(700);
  contadorInicio++;
}
 

   if (distanciaEnfrente < 60 && distanciaEnfrente!=0){
    mode = 0;
  }

   if (valorLineaIzq > 450){
    mode = 1;
    direccion = 1; 
  }

 if (valorLineaDer > 450){
    mode = 1;
    direccion = 0; 
  }

   

//----------------------------------------

}
