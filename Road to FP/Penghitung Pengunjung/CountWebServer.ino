#include <SPI.h>
#include <Ethernet.h>
#define echoPin1 8 // echopin
#define trigPin1 7 //triggerpin
#define echoPin2 9 // echopin
#define trigPin2 5 //triggerpin

int maximumRange = 20;
int minimumRange = 0;
long duration1 =0;
long distance1 =0;
long duration2 =0;
long distance2 =0;
int Counter=0;
int Setout=0;
int Reload=0;
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
}


void loop() {
  Setout=Counter;
  Reload=0;
  while (Counter == Setout && Reload <30) {
    digitalWrite(trigPin1,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1,HIGH);
    delayMicroseconds(10);
    duration1 = pulseIn(echoPin1,HIGH);
    distance1 = duration1/58.2;
    if (distance1 < maximumRange) {
      for (int restart=0; restart<20;restart++) {
        digitalWrite(trigPin2,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin2,HIGH);
        delayMicroseconds(10);
        duration2 = pulseIn(echoPin2,HIGH);
        distance2 = duration2/58.2;
        if (distance2 < maximumRange) {
          Counter++;
          restart=20;
          Reload=30;
          Serial.println(Counter);
        }
        delay(100);
      }
    }
    else {
    digitalWrite(trigPin2,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2,HIGH);
    delayMicroseconds(10);
    duration2 = pulseIn(echoPin2,HIGH);
    distance2 = duration2/58.2;
    if (distance2 < maximumRange) {
      for (int restart=0; restart<20;restart++) {
        digitalWrite(trigPin1,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin1,HIGH);
        delayMicroseconds(10);
        duration1 = pulseIn(echoPin1,HIGH);
        distance1 = duration1/58.2;
        if (distance1 < maximumRange) {
          Counter--;
          restart=20;
          Reload=30;
          Serial.println(Counter);
        }
        delay(100);
      }
    }
    delay(100);
    Reload++;
    }
  }
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 1");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("Current Visitor : ");
          client.println(Counter);
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
    Ethernet.maintain();
  }
}

