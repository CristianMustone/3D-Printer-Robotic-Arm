import math
import time
import matplotlib.pyplot as plt
import numpy as np

def moverRobotSCARA( x,  y) :
    global ultimo_step1
    global ultimo_step2
    
    # x=abs(x - ultimo_step1)
    # y=abs(y - ultimo_step2)

    x = abs(x)
    y = abs(y)

    d = math.sqrt(x ** 2 + y ** 2)
    phi = math.atan2(y, x)

    # Calcular los ángulos de las articulaciones mediante cinemática inversa
    acos = (d ** 2 - L1 ** 2 - L2 ** 2) / (2 * L1 * L2)
    theta2 = math.acos(acos)
    theta1 = phi - math.atan2(L2 * math.sin(theta2), L1 + L2 * math.cos(theta2))
    # Convertir los ángulos a pasos para los motores paso a paso
    avanzar1 = (((theta1 - ultimo_step1) * 360)/(2 * math.pi))
    avanzar2 = (((theta2 - ultimo_step2) * 360)/(2 * math.pi))
    steps1 = round(avanzar1/avance_motor,0)
    steps2 = round(avanzar2/avance_motor,0)

    MoverBrazo(steps1,steps2)

    ultimo_step1 = theta1
    ultimo_step2 = theta2
    steps1 = 0
    steps2 = 0

def MoverBrazo( pasosX,  pasosY) :
    timeX = 0
    timeY = 0
    timetotal = 0
    stepDelayX = 50
    stepDelayY = 50
  
    if pasosX!=0  and pasosY!=0 :
        relacion = abs(pasosX) / abs(pasosY)
        if pasosX > pasosY :
            stepDelayY = stepDelayY * relacion
            timetotal = abs(pasosY) * stepDelayY
        else :
            stepDelayX = stepDelayX * pow(relacion, (-1))
            timetotal = abs(pasosX) * stepDelayX
    elif pasosY == 0 and pasosX != 0 :
        timetotal = abs(pasosX) * stepDelayX
    else :
        timetotal = abs(pasosY) * stepDelayY

    for i in range(int(timetotal)):
        if (i - timeX >= stepDelayX) :
            if (pasosX > 0) :
                #motor1.step(1)
                GraficarScara(angulo1=1.8)
            elif pasosX < 0 :
                #motor1.step(-1)
                GraficarScara(angulo1=-1.8)
            timeX = i
        
        if (i - timeY >= stepDelayY) :
            if (pasosY > 0) :
                GraficarScara(angulo2=1.8)
            elif (pasosY < 0) :
                GraficarScara(angulo2=-1.8)
            timeY = i
        
        time.sleep(0.001)
    
    # print(f'Tiempo en X: {timeX}, en Y {timeY}')

angulo1_2 = 0
angulo2_2 = 0

def GraficarScara(angulo1 = 0, angulo2 = 0):
    global angulo1_2
    global angulo2_2

    angulo1_2 = angulo1_2 + angulo1
    angulo2_2 =  angulo2_2 + (angulo1 + angulo2)

    x_values = [0,L1*np.cos(np.radians(angulo1_2)),L1*np.cos(np.radians(angulo1_2))+L2*np.cos(np.radians(angulo2_2))]
    y_values = [0,L1*np.sin(np.radians(angulo1_2)),L1*np.sin(np.radians(angulo1_2))+L2*np.sin(np.radians(angulo2_2))]

    # print(f'Punto Final: ({round(x_values[2],2)}, {round(y_values[2],2)})')

    line.set_xdata(x_values)
    line.set_ydata(y_values)
    plt.draw()
    plt.pause(0.01)

stepsPerRevolution = 200

stepsMotor1 = stepsPerRevolution * 1 # Una vuelta
stepsMotor2 = stepsPerRevolution * 1 # Dos vueltas 
stepsMotor3 = stepsPerRevolution * 1 # Tres vueltas

filas = 0
columnas = 3

L1 = 21.0 # Longitud del primer eslabón en unidades de longitud
L2 = 20.0 # Longitud del segundo eslabón en unidades de longitud

SecX = 1
SecY = 1
SecZ = 1

ultimo_step1 = 0
ultimo_step2 = 0
ultimo_step3 = 0

avance_motor = 1.8

angulo1o = 0
angulo2o = angulo1o + 0
L1 = 21
L2 = 20

x_values = [0,L1*np.cos(np.radians(angulo1o)),L1*np.cos(np.radians(angulo1o))+L2*np.cos(np.radians(angulo2o))]
y_values = [0,L1*np.sin(np.radians(angulo1o)),L1*np.sin(np.radians(angulo1o))+L2*np.sin(np.radians(angulo2o))]

# Crear la figura y los ejes
fig, ax = plt.subplots()

# Dibujar la línea que conecta los puntos
line, = ax.plot(x_values, y_values, marker='o', linestyle='-')
plt.draw()
plt.pause(1)
ax.set_xlim(-41, 41)
ax.set_ylim(-10, 50)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_title('Grafico SCARA')

plt.grid(True)

x_puntos = [15, 25, 25, 15]
y_puntos = [15, 15, 25, 25]

# Agregar los puntos al gráfico existente
ax.plot(x_puntos, y_puntos, 'ro')  # 'ro' significa puntos rojos


for i in range(5):
    print("primera posicion")
    moverRobotSCARA(15,15)
    print("segunda posicion")
    moverRobotSCARA(25,15)
    print("tercera posicion")
    moverRobotSCARA(25,25)
    print("cuarta posicion")
    moverRobotSCARA(15,25)

plt.show()