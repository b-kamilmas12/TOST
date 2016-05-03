#define echoPin 8 // echopin
#define trigPin 7 //triggerpin

int maximumRange = 200;
int minimumRange = 0;
long duration =0;
long distance =0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

}

void AntoDectector(unsigned char distance){
  int piezopin = 9;
  tone(piezopin,1000,50);
  delay(1000-distance*100);
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

  if(distance<10){
    tone(9,1000,50);
    delay(distance*100-distance*75);
  }
}

