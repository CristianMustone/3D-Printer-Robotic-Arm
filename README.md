# Brazo robotico de Impresion 3D


Se fabricará un brazo robótico con 3 grados de libertad: uno prismático y dos rotativos, con una distribución de tipo SCARA – PRR. Los motores paso a paso correspondientes a cada grado de libertad serán controlados mediante un Arduino Uno junto con controladores L298N.

Se añadirá una función de conexión vía WIFI con la integración de un ESP32 Cam, que se comunicará con el Arduino Uno. A través de esta conexión, se podrá enviar el archivo de código G (.GCODE) de la pieza a imprimir, y el proceso comenzará automáticamente. La comunicación entre la computadora donde se encuentra el archivo G code y el ESP32 de la impresora se realizará a través de un sitio web. Con un mayor desarrollo, podría ser controlado a larga distancia mediante páginas web, por ejemplo.

En una aplicación futura, la base de impresión podría ser reemplazada por una cinta que soporte la temperatura de extrusión para tener un nivel de producción en serie superior al de la mayoría de las máquinas disponibles en el mercado.


## Objetivos

Este proyecto busca diseñar un sistema de impresión 3D diferente de los modelos más comunes en el mercado, como las impresoras de 3 ejes o aquellas con un eje infinito. Además, tendrá una mayor capacidad de impresión en términos del tamaño de las piezas que puede fabricar, ya que, siendo un instrumento ampliamente utilizado hoy en día, existe la necesidad de imprimir piezas más grandes de una sola vez.
También se busca mejorar la relación humano-impresora a través de la comunicación en línea, ya sea para mostrar el progreso de la impresión o para adjuntar un nuevo trabajo sin tener que conectarlo a una PC o mediante una tarjeta de memoria compatible.
Otro objetivo es poder construir una impresora que implique menores costos de fabricación para competir con otras impresoras en el mercado que tienen un precio más alto por características iguales o inferiores.

## Resumen
Se desarrollará un brazo robótico con 3 grados de libertad, con una configuración de 1 eje prismático que se utilizará para el movimiento vertical del extrusor y 2 ejes rotativos en formato SCARA.
La ventaja de esta configuración es que nos proporciona un área de impresión de 180°, un alcance de 41 cm (la base puede ser modificada según las características) y una altura de aproximadamente 30 cm. En total, sería un área de impresión de [Cálculo del área de impresión].
Las partes a utilizar estarán hechas de PLA, ya que fueron diseñadas e impresas en 3D, madera, para los soportes y componentes que requieren mayor resistencia, y finalmente se integrarán los componentes electrónicos.
El funcionamiento se basa en enviar el archivo con extensión .gcode que se obtiene de cualquier laminador en el mercado (como Cura) a través de una página web, y que puede imprimirse automáticamente sin requerir acceso físico a la máquina. También contará con una cámara a la que se podrá acceder desde la misma página web para ver el progreso de la impresión 3D realizada por el brazo.


## Especificaciones Técnicas

- El brazo robótico debe tener un rango de movimiento adecuado para cubrir un área de impresión mínima de 300x300x300 mm.
- El brazo robótico debe estar equipado con una herramienta de extrusión que pueda imprimir tanto PLA como ABS, y la cabeza debe ser fácilmente intercambiable.
- Debe operarse a través de una red Wi-Fi desde una página web con una interfaz fácil de usar, capaz de cargar un archivo parametrizado directamente para imprimir y poder iniciar la operación, así como ver el proceso en tiempo real a través de la aplicación.
- La conexión inalámbrica debe ser estable y segura para garantizar una comunicación fluida entre la impresora y la aplicación.
- La estructura del brazo robótico debe ser robusta y resistente para asegurar una operación estable y segura.
- El costo de fabricación del brazo robótico debe ser lo más bajo posible sin comprometer la calidad y eficiencia del sistema.
- El brazo robótico debe ser fácil de desarmar y mantener para facilitar la reparación y el reemplazo de piezas en caso de falla.
- La estructura debe ser estable y de diseño simple que garantice posibles aplicaciones de dimensionamiento futuro.

# Materiales

| Material | Cantidad |
|---|:---:|
| L298N | x3 |
| Stepper NEMA 17 |        x3|
| Cables |
| Arduino Uno |            x1|
| ESP32      |             x1|
| ESP32 CAM |              x1|
| Madera |
| Fuente de poder 12v / 5v |x1|
| Lapiz de impresion 3d    |x1|
| Varilla roscada |           x1|

## Criterio de selección de materiales

### ARDUINO UNO
El Arduino fue seleccionado como la placa base para el movimiento de los motores debido a la gran cantidad de bibliotecas disponibles en el mercado para este tipo de placas, además de la facilidad que proporcionan al programar la secuencia de movimiento. No se utilizó directamente el ESP32 o el ESP32 CAM, ya que, aunque las bibliotecas pueden adaptarse a este tipo de placas, el uso de Wi-Fi requería el uso múltiple de pines para conectarse a Internet y mover los motores, lo que generaba señales no deseadas que producían movimientos indeseados en los motores o su mal funcionamiento.

### ESP32
Esta placa fue seleccionada porque nos ofrece la posibilidad de conectarnos a Internet a través de una conexión Wi-Fi integrada sin la necesidad de incorporar dispositivos adicionales.

### ESP32 CAM
Esta placa fue seleccionada por un criterio similar al del ESP32, ya que nos proporciona una cámara integrada capaz de transmitir video vía Wi-Fi sin una conexión física al equipo a través de una dirección IP del dispositivo.

## Especificaciones de Diseño
Se construirá principalmente a partir de piezas hechas en impresión 3D y madera, dejando de lado los componentes electrónicos y de transmisión. El diseño se basará en la figura 1, con modificaciones según las necesidades.

Las piezas impresas en 3D fueron diseñadas por nosotros mismos. Se adoptó un enfoque que permitiera generar una pieza con la misma funcionalidad utilizando la menor cantidad de material posible y que soportara las condiciones a las que estaría sometida. Se utilizó una configuración de 20% de relleno y el material seleccionado fue PLA.

# Software a utilizar
Se usará lenguaje C para programar los siguientes componentes:
ESP32: El cual se utilizará para comunicar la página web donde se depositara el código con el ARDUINO UNO.
ARDUINO UNO: Se utilizará esta placa de desarrollo para la transformación del código recibido por el usuario a uno que el robot pueda utilizar, y además para el comando de los motores a utilizar.
ESP32 CAM: En este caso se utilizará desde la página web para el seguimiento de la impresión a distancia. 
También se utilizará una combinación de HTML y CSS para el diseño de la página web.

Los pasos a seguir para el funcionamiento completo del proyecto son:

1. Subida del archivo: Se sube el archivo que se quiere imprimir a la página web. Esta realiza un HTTP POST del contenido del archivo a un archivo de Google sheets. 
2. Manejo desde Google Sheets: El archivo de Google Sheets está configurado para que cuando recibe un HTTP POST, obtenga todo el contenido que se le ha enviado y lo coloque por línea en la primera columna de la única hoja que se encuentra en el documento. De la misma forma, cuando recibe un HTTP GET, envía toda la información de la primera columna en un solo string, en el cual cada línea está separada por una coma. 
3. Obtención desde el ESP32: El ESP32 está programado para realizar un HTTP GET al archivo del Google Sheets. Cuando obtiene el string con el código subido, ejecuta una función que elimina todas las líneas innecesarias para el funcionamiento de los motores, ya sean pre configuraciones, manejo del extrusor, etc. 
4. Envío al ARDUINO UNO: Una vez filtrada toda la información, el ESP32 envía el nuevo string generado a través del puerto serie (TX y RX) hacia el ARDUINO UNO.
5. Este hace un segundo manejo del string en donde, por cada línea de comando del código, obtiene las posiciones de destino tanto de X como Y. 
6. Una vez obtenidas las posiciones, manda a llamar a la función que calcula la cantidad de pasos que debe realizar cada motor según nuestro sistema de movimiento.
7. Calculada la cantidad de pasos, utilizamos otra función que es la que comanda a los motores, haciendo que los mismos se muevan la cantidad de pasos calculados, en el mismo tiempo para los ejes del plano X, Y de tal forma de mantener un movimiento escalonado a travez del vector de desplazamiento.
8. Uso del ES32 CAM: El código del ESP32 CAM está seteado para funcionar a la inversa del ESP32, este genera una IP para la cámara que está integrada, y realiza un HTTP POST con su dirección IP a otro archivo de Google Sheets. 
9. Cuando la página web solicita ver el avance de la impresión, realiza primero un HTTP GET al archivo de Google Sheets donde esta la direccion IP de la cámara del ESP32 CAM, para dirigirse a esta y mostrar el video que está filmando el ESP32 CAM con el avance de la impresión. 

## Explicación de cómo funciona el código
### Explicación del código para el Arduino Uno
Nos vamos a detener específicamente en este punto para detallar el método de operación de la transformación de las posiciones cartesianas obtenidas a la cantidad de pasos que cada motor debe moverse junto con la velocidad a la que deben hacerlo.
``` sh
while (Serial.available() > 0 && MensajeRecibido==0) {
    receivedMessage = Serial.readStringUntil('\r');
    Serial.println("Mensaje Recibido");
    Serial.println(receivedMessage);
    //miCadena.indexOf(subCadena)
    if ( receivedMessage.indexOf(",") != -1 && receivedMessage.indexOf(";") != -1){
      MensajeRecibido=1;
    }
```
This code fragment is used to enable reading the Serial port of the arduino while waiting for the message sent by the ESP32 with the string that has the lines of code to be executed by the robot.

``` sh
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
```
Next, the first function to use is to generate the Movement Matrix, that is, a list is created with the final positions of each axis for each line of code received. This generates a list with 3 values in each element, these values being the final positions of (X, Y, Z) .

``` sh
void moverRobotSCARA(float x, float y) {
  // Función para mover el robot SCARA a una posición específica
  int cuadrante = 0; 
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

  ultimo_step1 = steps1;
  ultimo_step2 = steps2;
}
```

In the case of the moveRobotSCARA function, it is the one that transforms the final positions into the number of steps for each motor, only in the case of motors 1 and 2 (that is why it has 2 input values), representatives of the X and Y axes. , since, as they were defined as rotary type axes, a transformation from Cartesian coordinates to polar coordinates is necessary for their use.
Due to the configuration of the axes, it was decided to use the geometric method to calculate the angles to rotate in each motor in order to make the calculation simpler. We can observe the development of this method in the first lines of the function; converting them to mathematical language they would be:

$$ d = x2+ y2 $$

Calculates the distance from the origin to the end point where the extruder is located

$$phi = arc tangent (y,x)$$

To calculate the angle at which the end point is with respect to the horizontal axis

$$theta2 = arc cosine((d * d - L1 * L1 - L2 * L2) / (2 * L1 * L2))$$

L1 and L2 represent the lengths of arms 1 and 2 respectively.
This formula is used to calculate the angle between arm 2 and the continuation of the center line of arm 1.

$$theta1 = phi - arctangent(L2 * sine(theta2), L1 + L2 * cosine(theta2))$$

Finally, the angle of arm 1 with respect to the horizontal axis is calculated.

![Primer Paso](Imagenes/First_Step.png)
![Primer Paso](Imagenes/Second_Step.png)
![Primer Paso](Imagenes/Third_Step.png)
![Primer Paso](Imagenes/Fourth_Step.png)

Recreating the movement of the robot, the previous sequence of steps would look like:

![video](https://github.com/CristianMustone/3D-Printer-Robotic-Arm/assets/118086095/0ae3cb4a-db7a-4efa-9718-c974cb2a3142)


With the sequence of end points (15,15); (25,15); (25,25); (15.25) the angles of theta1 and theta2 should be as follows:

```sh
  float avanzar1 = ((theta1 - ultimo_step1) * 360)/(2 * PI);
  float avanzar2 = ((theta2 - ultimo_step2) * 360)/(2 * PI);

  int steps1 = avanzar1 / avance_motor;
  int steps2 = avanzar2 / avance_moto
```
Next, the angles that each motor must advance (or retreat) are calculated. This is calculated by converting the calculated angles to geometric degrees, since they are initially found in non-representative values, that is, values that cannot be used as geometric degrees.
The angle at which the motor is currently located will also be subtracted, reflected in the variables ultimo_step1 and ultimo_step2, which, after each movement, will be updated. For example, if motor counterpart to advance1 but stops motor 2)
Finally, the number of degrees to move in each motor is divided by the degrees per step of the motor (in this case it would be 1.8 degrees per step, which is stored in the variable advance_motor), obtaining the number of steps to be performed to advance that number of geometric degrees.
```sh
MoverBrazo(steps1, steps2);
```
Once the entire series of calculations is finished, the MoveArm function is called, which is responsible for coordinating the movements of motors 1 and 2 so that they reach their destination at the same time, generating a straight line as a trajectory.
```sh
void MoverBrazo(int pasosX, int pasosY){
  int timeX = 0;
  int timeY = 0;
  int timetotal = 0;
  if (pasosX!=0 && pasosY!=0){
    float relacion = abs(pasosX)/abs(pasosY);
    stepDelayX = stepDelayX * pow(relacion,(-1));
  	timetotal = abs(pasosX) * stepDelayX;
  } else if (pasosY==0 && pasosX!=0){
  	timetotal = abs(pasosX)* stepDelayX;
  } else {
    timetotal = abs(pasosY)* stepDelayY;
  }

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
```
For motor hands to reach the destination point at the same time, regardless of the number of steps each one must take, there were several possibilities, such as using the Arduino milis library, but in this case it was decided to make a function with a Similar operation but with very short delay.
The operation of the MoverRoborSCARA function calculates the ratio of steps that motor 1 and 2 must take, once obtained, it affects the delay or internal speed of the motor with fewer steps by that factor, and it is obtained that both motors take the same even if they take a different number of steps. It should be noted that both motors already have a minimum speed for movement, so the factor is always additive.
Once the time that both motors will take to complete their corresponding steps has been calculated, a for loop is created that iterates for each millisecond of the total calculated, and at the end a delay of 1 millisecond is placed, this will cause each cycle of the loop to be executed every 1 millisecond. This allows us to see if the delay of each motor, that is, the number of milliseconds it takes to take each step, corresponds to the cycle number that is being executed, the motor moves one step. This affects both engines at the same time.
When you have to move a step regardless of the motor, a conditional is added to know if you have to move clockwise or counterclockwise, it could also be said, if you have to move one step or less one step.
As you can see, the operation of the Arduino milis library is very similar but with the addition of greater control over the total duration time.


