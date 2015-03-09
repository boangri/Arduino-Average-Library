#include <Average.h>

#define N 10

Average sensor(N);

long n;
float summa, fn;

/*
 * returns normal random avg=0 sigma=1
 */
float norm ()
{
  long ns = 0; 
  float s;
  for (int i = 0; i < 12; i++) {
    ns += random(0, 1048576);
  }
  s = (float)ns;
  return (s - 6291450.) / 1048576.;  
}

void setup() 
{
    Serial.begin(9600);
    n = 0;
    summa = fn = 0.;
}

void loop()
{
    float value, sigma;
    
    sensor.putValue(norm());
    n++;
    fn += 1.0;
    if ((n % N) == 0) {
      value = sensor.getAverage();
      sigma = sensor.getSigma();
      summa += value;
      Serial.print(summa/fn*100.);
      Serial.print(" ");
      Serial.print(value);
      Serial.print(" ");
      Serial.println(sigma);
    }
    delay(30); 
}  