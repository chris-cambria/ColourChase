
 
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 7

int redPin=11;
int greenPin=10;
int bluePin=6;
int rcolourstrength=0;
int gcolourstrength=0;
int bcolourstrength=0;



void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}

void loop() {
  // Setting red colour to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  rcolourstrength= pulseIn(sensorOut, LOW);
  rcolourstrength=255-rcolourstrength;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(rcolourstrength);//printing RED color frequency
  Serial.print("  ");
  delay(100);

  // Setting Green colour to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  gcolourstrength = pulseIn(sensorOut, LOW);
  gcolourstrength=255-gcolourstrength;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(gcolourstrength);//printing GREEN color frequency
  Serial.print("  ");
  delay(100);

  // Setting Blue colour to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bcolourstrength = pulseIn(sensorOut, LOW);
  bcolourstrength=255-bcolourstrength;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(bcolourstrength);//printing BLUE color strength
  Serial.println("  ");
  delay(100);


  if(rcolourstrength>gcolourstrength && gcolourstrength>bcolourstrength ){
    rcolourstrength=255;
    gcolourstrength=gcolourstrength/2;
    bcolourstrength=0;
  }
    if(rcolourstrength>bcolourstrength && bcolourstrength>gcolourstrength ){
    rcolourstrength=255;
    bcolourstrength=bcolourstrength/2;
    gcolourstrength=0;
  }
    if(gcolourstrength>rcolourstrength && rcolourstrength>bcolourstrength ){
    gcolourstrength=255;
    rcolourstrength=rcolourstrength/2;
    bcolourstrength=0;
  }
    if(gcolourstrength>bcolourstrength && bcolourstrength>rcolourstrength ){
    gcolourstrength=255;
    bcolourstrength=bcolourstrength/2;
    rcolourstrength=0;
  }
    if(rcolourstrength>bcolourstrength && bcolourstrength>gcolourstrength ){
    rcolourstrength=255;
    bcolourstrength=bcolourstrength/2;
    gcolourstrength=0;
  }
    if(bcolourstrength>rcolourstrength && rcolourstrength>gcolourstrength ){
    bcolourstrength=255;
    rcolourstrength=rcolourstrength/2;
    gcolourstrength=0;
  }
    if(bcolourstrength>gcolourstrength && gcolourstrength>rcolourstrength ){
    bcolourstrength=255;
    gcolourstrength=gcolourstrength/2;
    rcolourstrength=0;
  }
  analogWrite(redPin,rcolourstrength);
  analogWrite(greenPin,gcolourstrength);
  analogWrite(bluePin,bcolourstrength);
  delay(100);
}