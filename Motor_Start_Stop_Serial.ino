const int stepX = 2;
const int dirX  = 5;
const int enPin = 8;

int check = 1;

void setup() {
  Serial.begin(9600);
  pinMode(stepX, OUTPUT);
  pinMode(dirX, OUTPUT);

  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  // put your setup code here, to run once:

}
int current = 0;
int s_current = 0;
bool running_status = false;
bool stop_status = false;

void loop() {

  if (Serial.available())
  {
    current = Serial.read();
    if (current == 49) //1
    {
      running_status = true;
    }
    else if (current == 48)
    {
      running_status = false;
    }

  }
  jane:

  if (running_status)
  {
    for (int x = 0; x < 3200; x++)
    {
      dev();
      if (stop_status)
      {
        goto jane;
      }
      digitalWrite(dirX, HIGH);
      digitalWrite(stepX, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepX, LOW);
      delayMicroseconds(1000);
    }
  }

 delay(1000);

}

void dev()
{
  if (Serial.available())
  {
    s_current = Serial.read();
    if (s_current == 48) //1
    {
      stop_status = true;
    }
    else if (s_current == 49)
    {
      stop_status = false;
    }
  }
}
