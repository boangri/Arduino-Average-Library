#include <Average.h>

#define N 10

Average sensor(N);
int pin = A1;
long n;

void setup() 
{
    pinMode(pin, INPUT);
    Serial.begin(9600);
    n = 0;
}

void loop()
{
    float value, current, sigma;
     
    value = (float)analogRead(pin);
    current = (value - 510.5)*0.41/12;
    sensor.putValue(current);
    n++;
    if ((n % N) == 0) {
      current = sensor.getAverage();
      sigma = sensor.getSigma();
      Serial.print(current);
      Serial.print(" ");
      Serial.println(sigma);
    }
    delay(20); 
} 
