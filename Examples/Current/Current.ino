int pin = A1;

void setup() 
{
    pinMode(pin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    float value;
    
    value = (float)analogRead(pin);
    Serial.println(value);
    delay(1000);
    
}  
