#include<Servo.h>
#include<SoftwareSerial.h>

#include <ESP8266WiFi.h>  
SoftwareSerial ESPserial(0, 1); // RX | TX
#define WIFI_SSID "C002"
#define WIFI_PASSWORD "GreenFinch"

Servo servo_1;
Servo servo_2;

const int LDR = A1;
int input_val = 0;

int servo_pin1 = 9;
int servo_pin2 = 8;
int pos = 0;
int pos1 = 0;
int pos2 = 0;

void setup() {
  // put your setup code here, to run once:
  ESPserial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());
  servo_1.attach(servo_pin1);
  servo_2.attach(servo_pin2);
  Serial.begin(9600); // start serial monitor
  servo_1.write(pos); 
  servo_2.write(pos);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  while(pos<=170)
  {
    input_val = analogRead(LDR);
    Serial.print((String)input_val+" ");
    delay(1000);
    pos1 = pos + 10;
    pos2 = pos + 5;
    servo_1.write(pos1);
    delay(2000);
    servo_2.write(pos2);
    delay(2000);
    pos = pos + 10;
  }
}
