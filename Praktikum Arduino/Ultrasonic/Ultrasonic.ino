#define echoPin 8 // echopin
#define trigPin 7 //triggerpin

int maximumRange = 200;
int minimumRange = 0;
long duration,distance;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin,HIGH);
  distance = duration/58.2;
  Serial.println(duration);
  Serial.println(distance);
  delay(50);
}
