/*---------------------------------------------------------------------------------------------

  Open Sound Control (OSC) library for the ESP8266/ESP32

  Example for receiving open sound control (OSC) bundles on the ESP8266/ESP32
  Send integers '0' or '1' to the address "/led" to turn on/off the built-in LED of the esp8266.

  This example code is in the public domain.

--------------------------------------------------------------------------------------------- */
#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>

char ssid[] = "Jonnys iPhone Mini";          // your network SSID (name)
char pass[] = "DerHammer";                    // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;

const unsigned int localPort = 12000;        // local port to listen for UDP packets (here's where we send the packets)


OSCErrorCode error;

unsigned int message;

#define REST 16
#define GELBER_SACK 5
#define PAPIER 4
#define BIO 0

void setup() {
  pinMode(REST, OUTPUT);
  pinMode(GELBER_SACK, OUTPUT);
  pinMode(PAPIER, OUTPUT);
  pinMode(BIO, OUTPUT);

  Serial.begin(115200);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  digitalWrite(REST, HIGH);
  digitalWrite(GELBER_SACK, HIGH);
  digitalWrite(PAPIER, HIGH);
  digitalWrite(BIO, HIGH);
  delay(5000);
  digitalWrite(REST, LOW);
  digitalWrite(GELBER_SACK, LOW);
  digitalWrite(PAPIER, LOW);
  digitalWrite(BIO, LOW);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
#ifdef ESP32
  Serial.println(localPort);
#else
  Serial.println(Udp.localPort());
#endif

}


void leds(OSCMessage &msg) {
  message = msg.getFloat(0);
  switch (message) {
    case 1:
      digitalWrite(REST, HIGH);
      Serial.println(1);
      delay(5000);
      digitalWrite(REST, LOW);
      break;
    case 2:
      digitalWrite(GELBER_SACK, HIGH);
      Serial.println(2);
      delay(5000);
      digitalWrite(GELBER_SACK, LOW);
      break;
    case 3:
      digitalWrite(PAPIER, HIGH);
      Serial.println(3);
      delay(5000);
      digitalWrite(PAPIER, LOW);
      break;
    case 4:
      digitalWrite(BIO, HIGH);
      Serial.println(4);
      delay(5000);
      digitalWrite(BIO, LOW);
      break;
  }
  digitalWrite(message, LOW);
  Serial.print("/led: ");
  Serial.println(message);
}

void loop() {
  OSCBundle bundle;
  int size = Udp.parsePacket();

  if (size > 0) {
    while (size--) {
      bundle.fill(Udp.read());
    }
    if (!bundle.hasError()) {
      bundle.dispatch("/led", leds);
    } else {
      error = bundle.getError();
      Serial.print("error: ");
      Serial.println(error);
    }
  }
}
