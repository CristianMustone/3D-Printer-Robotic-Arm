#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Repetidor";
const char* password = "53EW9e527c2fAeBb3a2d";
const char* spreadsheetId = "13_MIWFoQno4I7jppms3PyK7UoSv1RYUoeWZiwnOPLt0";
const char* sheetName = "Hoja 1";
const char* apiKey = "0e1c00f2a8ca7bc3949755c1b3a4f3386d19e63f";

void setup() {
  Serial.begin(115200);
  delay(2000);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }

  Serial.println("Conectado a WiFi");

  sendDataToGoogleSheets("Hola mundo");
}

void loop() {
  // No se requiere ninguna acción en el bucle principal
}

void sendDataToGoogleSheets(const String& data) {
  HTTPClient http;

  // Construir la URL de solicitud
  String url = "https://sheets.googleapis.com/v4/spreadsheets/";
  url += spreadsheetId;
  url += "/values/";
  url += sheetName;
  url += ":append?valueInputOption=USER_ENTERED&key=";
  url += apiKey;

  // Configurar la solicitud HTTP
  http.begin(url);
  http.addHeader("Content-Type", "application/json");

  // Construir el cuerpo de la solicitud
  String jsonBody = "{\"values\": [[\"";
  jsonBody += data;
  jsonBody += "\"]]}";

  // Enviar la solicitud HTTP POST
  int httpResponseCode = http.POST(jsonBody);

  if (httpResponseCode > 0) {
    Serial.print("Datos enviados a Google Sheets. Código de respuesta: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error en la solicitud. Código de error: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}