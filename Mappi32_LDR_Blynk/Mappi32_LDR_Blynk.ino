#define BLYNK_TEMPLATE_ID "TMPLk3fYDD5x"
#define BLYNK_DEVICE_NAME "Light Dependent Resistor"
#define BLYNK_AUTH_TOKEN "dvFMP2cUBOjqr10qIsfYBACqJgoUTkZi"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h> //pembacaan mappi ke sensor

int sensorPin = 36 ;
int sensorValue = 0;

#define pinLED  5
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "KMTek";   // Nama Hotspot / WiFi
char pass[] = "KMTek123"; // Password WiFi

BlynkTimer timer;


void myTimerEvent()
{
  Blynk.virtualWrite(V5, millis() / 1000);
}

void setup () {

  Wire.begin();
  Serial.begin(112500);
    pinMode(5 , OUTPUT);
  Blynk.begin(auth, ssid, pass);
  Wire.begin();


}
void loop () {
  Blynk.run();
  timer.run();

  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value : ");
  Serial.println(sensorValue);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.print("Voltage:");
  Serial.println(voltage);
  delay (1000);

  Blynk.virtualWrite(V0, sensorValue);
  Blynk.virtualWrite(V1, voltage);



  if (voltage >= 5) {
    digitalWrite (5, HIGH);
  }
  else {
    digitalWrite (5, LOW);
  }
  delay (1000);
}
