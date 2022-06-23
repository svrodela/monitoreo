#include <WiFi.h>
#include <HTTPClient.h> // nos permite hacer peticiones http
#include <ArduinoJson.h>

// credenciales de la red a la cual nos conectaremos
const char* ssid = "Redsita";
const char* password = "1234567890";
//const char* ssid = "Tenda_3DE948";
//const char* password = "18264838";

//Temperatura
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();


void setup() {
 Serial.begin(115200);

    // conexión a la red
    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
    }
    Serial.println("");
    Serial.print("Conectado a la red con la IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

}

void loop() {
  if(WiFi.status()== WL_CONNECTED ){ 
 //se agregan valores al documento
DynamicJsonDocument doc(2048);
  float c= ((temprature_sens_read() - 32) / 1.8);
  doc["icalor"] = c;
  doc["iruido"] = touchRead(T0);
  doc["igas"] =  hallRead();
  //doc["fecha"] = rtc.getDate();

// documento serializado
String json;
serializeJson(doc, json);

WiFiClient client;  // or WiFiClientSecure for HTTPS
HTTPClient http;
// Send request
http.begin("https://dry-fjord-94565.herokuapp.com/insertar");
//cabeceras JSON
http.addHeader("Content-Type", "application/json");
int res = http.POST(json);

Serial.println(json);
// respuesta
Serial.println(http.getString());
Serial.println(res);
// desconecta
http.end();
delay(60000);
}
}
