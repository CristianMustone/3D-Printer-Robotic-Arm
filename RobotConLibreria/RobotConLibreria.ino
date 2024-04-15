// Incluye la librería Stepper.h
#include <Stepper.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

String receivedMessage = "";
int MensajeRecibido = 1;

// Define el número de pasos por vuelta del motor
const int stepsPerRevolutionZ = 200; //suponiendo que es 1mm por vuelta
const int stepsPerRevolutionX = 1600; //suponiendo que la relacion es 80:1 
const int stepsPerRevolutionY = 200; //la relacion es 1:1

// Define los pines de control para el driver L298N
const int motor1Pins[] = {2, 3, 4, 5}; // IN1, IN2, IN3, IN4
const int motor2Pins[] = {6, 7, 8, 9};   // IN1, IN2, IN3, IN4
const int motor3Pins[] = {10, 11, 12, 13};   // IN1, IN2, IN3, IN4

int filas = 0, columnas = 3;
int Movimientos[50][3]; // cantidad de filas que va contener se estima en 50 por ahora

#define L1 21.0 // Longitud del primer eslabón en unidades de longitud
#define L2 20.0 // Longitud del segundo eslabón en unidades de longitud

#define avance_motor 1.8

// Crea objetos Stepper para cada motor
Stepper motorX(stepsPerRevolutionX, motor1Pins[0], motor1Pins[1], motor1Pins[2], motor1Pins[3]);
Stepper motorY(stepsPerRevolutionY, motor2Pins[0], motor2Pins[1], motor2Pins[2], motor2Pins[3]);
Stepper motorZ(stepsPerRevolutionZ, motor3Pins[0], motor3Pins[1], motor3Pins[2], motor3Pins[3]);

float ultimo_step1 = 0;
float ultimo_step2 = 0;
float ultimo_step3 = 0;

void setup() {
  // Establece la velocidad de los motores
  motorX.setSpeed(50); // Puedes ajustar esta velocidad según sea necesario
  motorY.setSpeed(50);
  motorZ.setSpeed(20);
  Serial.begin(2400);
}

void loop() {

  /*receivedMessage="G0 F600 X15 Y15 Z10,G1 X25 Y15 E0.94529,G1 X25 Y25 E0.94529,G1 X15 Y25 E0.94529";

  if (MensajeRecibido==1){
    const char* charMessage = receivedMessage.c_str();
    MatrizMovimientos(charMessage);
    for (int fila=0; fila <filas; fila++){
      motorZ.step(Movimientos[fila][2]*stepsPerRevolutionZ - ultimo_step3);
      moverRobotSCARA(Movimientos[fila][0], Movimientos[fila][1]);
      ultimo_step3 = Movimientos[fila][2]*stepsPerRevolutionZ;  
    }
    Serial.println("Terminado");
    MensajeRecibido = 0;
    receivedMessage = "";  // Limpiar el mensaje recibido
    delay(1000);
  }
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      Movimientos[i][j] = 0;
    }
  }
  filas=0;*/
  /*moverRobotSCARA(15, 15);
  delay(2000);*/
  MoverBrazo(-6, 100);
  delay(1000);
}