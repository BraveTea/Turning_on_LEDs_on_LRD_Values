const int PIN_COUNT = 6; 

int ledArr[PIN_COUNT] =  
{13, 8, 
 12, 7, 
 11, 5};

int lightPin = A0;


void setup()
{
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  for (int i = 0; i < 6; i++)
  {
    pinMode(ledArr[i], OUTPUT);
  }
}

void loop()
{
  sensValToLed(lightPin, 500);
}

void sensValToLed(int sensorPin, int beat)
{
  int val;
  int ledChange;
  int sensor;
  val = analogRead(sensorPin);
  ledChange = map(val, 200, 950, 0, 6);
  sensor = analogRead(sensorPin);
  Serial.print("LED NUMBER:\t");
  Serial.print(ledChange + 1);
  Serial.print("\t\tLRD Value is:\t");
  Serial.println(sensor);
  digitalWrite(ledArr[ledChange], HIGH);
  delay(beat);
  allOff();
}

void allOff()
{
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(ledArr[i], LOW);
  }
}

void testsLeds()
{
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(ledArr[i], HIGH);
  }
}

