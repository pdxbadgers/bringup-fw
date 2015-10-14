
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <stdint.h>


#define TAIL_LED       0  //led 0
#define BACK_FOOT_LED  16 //led 1
#define FRONT_FOOT_LED 14 //led 2
#define NOSE_LED       5  //led 3

#define EYE_R          13
#define EYE_G          15
#define EYE_B          12

#define SPEAKER_PIN    4


void setup()
{
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  pinMode(TAIL_LED, OUTPUT);
  pinMode(BACK_FOOT_LED, OUTPUT);
  pinMode(FRONT_FOOT_LED, OUTPUT);
  pinMode(NOSE_LED, OUTPUT);
  pinMode(EYE_R, OUTPUT);
  pinMode(EYE_G, OUTPUT);
  pinMode(EYE_B, OUTPUT);

  pinMode(SPEAKER_PIN, OUTPUT);


  digitalWrite(TAIL_LED, LOW);
  digitalWrite(BACK_FOOT_LED, LOW);
  digitalWrite(FRONT_FOOT_LED, LOW);
  digitalWrite(NOSE_LED, LOW);
  digitalWrite(EYE_R, LOW);
  digitalWrite(EYE_G, LOW);
  digitalWrite(EYE_B, LOW);
}


void loop()
{
  Serial.print(F("This badge's MAC address is: "));
  Serial.println(WiFi.macAddress());

  Serial.println(F("Turning on regular LEDs"));
  digitalWrite(TAIL_LED, HIGH);
  digitalWrite(BACK_FOOT_LED, HIGH);
  digitalWrite(FRONT_FOOT_LED, HIGH);
  digitalWrite(NOSE_LED, HIGH);

  delay(2*1000);

  Serial.println(F("Turning on eye RED"));
  digitalWrite(EYE_R, HIGH);
  digitalWrite(EYE_G, LOW);
  digitalWrite(EYE_B, LOW);
  delay(2*1000);

  Serial.println(F("Turning on eye GREEN"));
  digitalWrite(EYE_R, LOW);
  digitalWrite(EYE_G, HIGH);
  digitalWrite(EYE_B, LOW);
  delay(2*1000);

  Serial.println(F("Turning on eye BLUE"));
  digitalWrite(EYE_R, LOW);
  digitalWrite(EYE_G, LOW);
  digitalWrite(EYE_B, HIGH);
  delay(2*1000);

  digitalWrite(EYE_R, LOW);
  digitalWrite(EYE_G, LOW);
  digitalWrite(EYE_B, LOW);

  Serial.println(F("Speaker test"));
  for (int i=0; i < 10000; i++) {
    digitalWrite(SPEAKER_PIN, HIGH);
    delay(10);
    digitalWrite(SPEAKER_PIN, LOW);
  }

  Serial.println(F("Done"));

  delay(2*1000);

}

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * mode: c++
 * c-basic-offset: 2
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=2 tabstop=8 expandtab:
 * :indentSize=2:tabSize=8:noTabs=true:
 */
