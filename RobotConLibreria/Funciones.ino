void MatrizMovimientos(char texto[]){
  for (int i = 0; i < strlen(texto); i++) {
    if (texto[i] == ';') {
      filas++;
    }
  }
  char *token = strtok(texto, ",;");
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      Movimientos[i][j] = atoi(token);
      // Serial.print("Valor Leido: ");
      // Serial.println(Movimientos[i][j]);
      token = strtok(NULL, ",;");
    }
  }
}

void moverRobotSCARA(float x, float y) {
  Serial.print("yendo a la posicion: ");
  Serial.print(x);
  Serial.print(",");
  Serial.println(y);
  // Función para mover el robot SCARA a una posición específica
  x=abs(x);
  y=abs(y);

  float d = sqrt(x * x + y * y);
  float phi = atan2(y, x);
  // Calcular los ángulos de las articulaciones mediante cinemática inversa
  float theta2 = acos((d * d - L1 * L1 - L2 * L2) / (2 * L1 * L2));
  float theta1 = phi - atan2(L2 * sin(theta2), L1 + L2 * cos(theta2));
  // Convertir los ángulos a pasos para los motores paso a paso
  float avanzar1 = ((theta1 - ultimo_step1) * 360)/(2 * PI);
  float avanzar2 = ((theta2 - ultimo_step2) * 360)/(2 * PI);

  int steps1 = avanzar1 / avance_motor;
  int steps2 = avanzar2 / avance_motor;

  MoverBrazo(steps1, steps2);

  ultimo_step1 = theta1;
  ultimo_step2 = theta2;
}

void MoverBrazo(float pasosX, float pasosY){
  Serial.print("Moviendo: ");
  Serial.print(pasosX);
  Serial.print(",");
  Serial.println(pasosY);
  int timeX = 0;
  int timeY = 0;
  int timetotal = 0;
  int stepDelayX = 50;
  int stepDelayY = 50;
  if (pasosX!=0 && pasosY!=0){
    float relacion = abs(pasosX)/abs(pasosY);
    // Serial.println(relacion);
    stepDelayX = stepDelayX * pow(relacion,(-1));
  	timetotal = abs(pasosX) * stepDelayX;
  } else if (pasosY==0 && pasosX!=0){
  	timetotal = abs(pasosX)* stepDelayX;
  } else {
    timetotal = abs(pasosY)* stepDelayY;
  }

  Serial.println(stepDelayY);

  for(int i=0;i<=timetotal;i++){
    if (i-timeX >= stepDelayX){
      if (pasosX>0){
        motorX.step(1);
      } else if (pasosX<0){
        motorX.step(-1);
      }
      timeX = i;
    }
    if (i-timeY >= stepDelayY){
      if (pasosY>0){
        motorY.step(1);
      } else if (pasosY<0){
          motorY.step(-1);
        }
      timeY = i;
  	}	
    delay(1);
  }
}




