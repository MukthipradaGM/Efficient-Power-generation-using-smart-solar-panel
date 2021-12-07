//  Arduino pin 2 (RX) to ESP8266 TX
//  Arduino pin 3 to voltage divider then to ESP8266 RX
//  Connect GND from the Arduiono to GND on the ESP8266
//  Pull ESP8266 CH_PD HIGH
//
// When a command is entered in to the serial monitor on the computer
// the Arduino will relay it to the ESP8266
//
#include <ESP8266WiFi.h>  
#include <SoftwareSerial.h>
SoftwareSerial ESPserial(0, 1); // RX | TX
#define WIFI_SSID "C002"
#define WIFI_PASSWORD "GreenFinch"

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);     // communication with the host computer
    //while (!Serial)   { ; }
 
    // Start the software serial for communication with the ESP8266
    ESPserial.begin(115200); 
 
  // initialize digital pin LED_BUILTIN as an output.
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
}
 
void loop()
{
    // listen for communication from the ESP8266 and then write it to the serial monitor
   // if ( ESPserial.available() )   {  Serial.write( ESPserial.read() );  }
 
    // listen for user input and send it to the ESP8266
//    if ( Serial.available() )       {  ESPserial.write( Serial.read() );  }
}
