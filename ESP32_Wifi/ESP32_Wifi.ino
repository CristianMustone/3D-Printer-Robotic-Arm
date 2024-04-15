#include <HardwareSerial.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <string.h>

#define esp32TX 1  // Puedes ajustar los pines según tu configuración
#define esp32RX 3

#define WIFI_SSID "PCwifi"
#define WIFI_PASSWORD "ingmustone"
String GOOGLE_SCRIPT_ID = "AKfycbxiWrbWpRyaDDQQgARydaQq3UQNIaPEfO08l73xLwA0IrmX1_svnYCXUWWWk37KXSlUqg";

#define MAX_COMMAND_LENGTH 255

int SendMessage=0;
char gcode_string[1024]; // Tamaño suficiente para almacenar las líneas del archivo
int FileOk = 1;
const char* payloadCopy;
int Filas = 0;
int Movimientos[50][3]; // cantidad de filas que va contener se estima en 50 por ahora
char Mensaje[1024]="";

void setup() {
  Serial.begin(115200);
  Serial2.begin(2400, SERIAL_8N1, esp32RX, esp32TX);  // Inicializa Serial2 con pines personalizados

  String payload;

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando");
  }

  HTTPClient http;
  String url="https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?read";
	http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
	int httpCode = http.GET();
    if (httpCode > 0) { //Check for the returning code
        payload = http.getString();
        payloadCopy=payload.c_str();
        Serial.println("HTTP ok");
      }
	http.end();

}

void loop() {
  if (SendMessage==0){
  strcpy(gcode_string, payloadCopy);
  Serial.println("Armando Matriz de Moviminetos");
  MatrizDeMovimientos(gcode_string);
  Serial.println("Matriz Armada");
  
    for (int Fila=0; Fila<Filas; Fila++){
      char numero[20];
      sprintf(numero, "%d", Movimientos[Fila][0]);
      strcat(Mensaje, numero);
      strcat(Mensaje,",");
      sprintf(numero, "%d", Movimientos[Fila][1]);
      strcat(Mensaje, numero);
      strcat(Mensaje,",");
      sprintf(numero, "%d", Movimientos[Fila][2]);
      strcat(Mensaje, numero);
      strcat(Mensaje,";");
    }

  
    Serial2.println(Mensaje);
    SendMessage=1;
  }
}
