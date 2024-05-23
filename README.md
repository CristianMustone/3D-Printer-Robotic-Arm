<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Centered Links</title>
    <style>
        .center {
            display: flex;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }
        .row {
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .row img {
            margin: 0 10px; /* Espaciado entre las imágenes */
        }
    </style>
</head>
<body>
    <div class="center">
        <div class="row">
            <img src="https://github.com/CristianMustone/3D-Printer-Robotic-Arm/assets/167147147/52afa1dd-452e-47d1-8668-557313117370" alt="Image 1">
            <img src="https://github.com/CristianMustone/3D-Printer-Robotic-Arm/assets/167147147/22f22362-cd1c-4a4e-b18e-6cb2c43ffeb1" alt="Image 2">
        </div>
        <div>
            <img src="https://github.com/CristianMustone/3D-Printer-Robotic-Arm/blob/785c0f15e5ba6de790ee7cee0f59c768cc939d11/Pruebas/robot.gif" alt="Video">
        </div>
    </div>
</body>
</html>
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
Este fragmento de código se utiliza para habilitar la lectura del puerto Serial del Arduino mientras se espera el mensaje enviado por el ESP32 con la cadena que contiene las líneas de código que debe ejecutar el robot.

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
A continuación, la primera función a utilizar es generar la Matriz de Movimiento, es decir, se crea una lista con las posiciones finales de cada eje para cada línea de código recibida. Esto genera una lista con 3 valores en cada elemento, siendo estos valores las posiciones finales de (X, Y, Z).

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

En el caso de la función moveRobotSCARA, es la que transforma las posiciones finales en el número de pasos para cada motor, solo en el caso de los motores 1 y 2 (por eso tiene 2 valores de entrada), representativos de los ejes X e Y, ya que, al ser definidos como ejes de tipo rotativo, es necesario realizar una transformación de coordenadas cartesianas a coordenadas polares para su uso.

Debido a la configuración de los ejes, se decidió utilizar el método geométrico para calcular los ángulos a rotar en cada motor con el fin de simplificar el cálculo. Podemos observar el desarrollo de este método en las primeras líneas de la función; al convertirlas a lenguaje matemático serían:

$$ d = x2+ y2 $$

Calcula la distancia desde el origen hasta el punto final donde se encuentra el extrusor.

$$phi = arc tangent (y,x)$$

Para calcular el ángulo en el que se encuentra el punto final con respecto al eje horizontal.

$$theta2 = arc cosine((d * d - L1 * L1 - L2 * L2) / (2 * L1 * L2))$$

L1 y L2 representan las longitudes de los brazos 1 y 2 respectivamente.
Esta fórmula se utiliza para calcular el ángulo entre el brazo 2 y la prolongación de la línea central del brazo 1.

$$theta1 = phi - arctangent(L2 * sine(theta2), L1 + L2 * cosine(theta2))$$

Finalmente, se calcula el ángulo del brazo 1 con respecto al eje horizontal.

![Primer Paso](Imagenes/First_Step.png)
![Primer Paso](Imagenes/Second_Step.png)
![Primer Paso](Imagenes/Third_Step.png)
![Primer Paso](Imagenes/Fourth_Step.png)


Recreando el movimiento del robot, la secuencia de pasos anterior se vería así:

![video](https://github.com/CristianMustone/3D-Printer-Robotic-Arm/assets/118086095/0ae3cb4a-db7a-4efa-9718-c974cb2a3142)


Con la secuencia de puntos finales (15,15); (25,15); (25,25); (15,25) los ángulos de theta1 y theta2 deberían ser los siguientes:

```sh
  float avanzar1 = ((theta1 - ultimo_step1) * 360)/(2 * PI);
  float avanzar2 = ((theta2 - ultimo_step2) * 360)/(2 * PI);

  int steps1 = avanzar1 / avance_motor;
  int steps2 = avanzar2 / avance_moto
```
A continuación, se calculan los ángulos que cada motor debe avanzar (o retroceder). Esto se calcula convirtiendo los ángulos calculados a grados geométricos, ya que inicialmente se encuentran en valores no representativos, es decir, valores que no pueden utilizarse como grados geométricos.

También se restará el ángulo en el que se encuentra actualmente el motor, reflejado en las variables "ultimo_step1" y "ultimo_step2", las cuales se actualizarán después de cada movimiento. Por ejemplo, si el motor correspondiente a avanzar1 se detiene pero el motor 2 sigue moviéndose.

Finalmente, el número de grados a mover en cada motor se divide por los grados por paso del motor (en este caso serían 1.8 grados por paso, que se almacena en la variable "advance_motor"), obteniendo así el número de pasos que se deben realizar para avanzar ese número de grados geométricos.

```sh
MoverBrazo(steps1, steps2);
```
Una vez que se completa toda la serie de cálculos, se llama a la función MoveArm, que se encarga de coordinar los movimientos de los motores 1 y 2 para que lleguen a su destino al mismo tiempo, generando una trayectoria recta como resultado.
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
Para lograr que las manos del motor alcancen el punto de destino al mismo tiempo, independientemente del número de pasos que cada una deba tomar, hubo varias posibilidades, como usar la biblioteca millis de Arduino, pero en este caso se decidió hacer una función con una operación similar pero con un retraso muy corto.

La operación de la función MoverRoborSCARA calcula la proporción de pasos que los motores 1 y 2 deben tomar; una vez obtenida, ajusta el retraso o velocidad interna del motor con menos pasos por ese factor, y se logra que ambos motores avancen al mismo tiempo, aunque tomen un número diferente de pasos. Cabe señalar que ambos motores ya tienen una velocidad mínima para el movimiento, por lo que el factor siempre es aditivo.

Una vez calculado el tiempo que ambos motores tardarán en completar sus pasos correspondientes, se crea un bucle for que itera para cada milisegundo del total calculado, y al final se coloca un retraso de 1 milisegundo; esto hace que cada ciclo del bucle se ejecute cada 1 milisegundo. Esto nos permite ver si el retraso de cada motor, es decir, el número de milisegundos que tarda en dar cada paso, corresponde al número de ciclo que se está ejecutando, y así el motor da un paso. Esto afecta a ambos motores al mismo tiempo.

Cuando se debe mover un paso sin importar el motor, se agrega una condición para saber si se debe mover en sentido horario o antihorario, también podría decirse, si se debe mover un paso o menos un paso.

Como puedes ver, la operación de la biblioteca millis de Arduino es muy similar, pero con el agregado de un mayor control sobre el tiempo total de duración.
