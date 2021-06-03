int potentiometer = A0;
int feedback = A1;
int PWM = 4;
int pwmValue = 0;

void setup() {
  pinMode(potentiometer, INPUT);
  pinMode(feedback, INPUT);
  pinMode(PWM, OUTPUT);  
  TCCR0B = TCCR0B & B11111000 | B00000001;    // pin 3 and 11 PWM frequency of 31372.55 Hz
}

void loop() {  
  float voltage = analogRead(potentiometer);
  float output  = analogRead(feedback);

  if ((voltage -5) > output)
   {
    pwmValue = pwmValue+1;
    pwmValue = constrain(pwmValue, 1, 254);
   }
   
  if ((voltage+5) < output)
   {
    pwmValue = pwmValue-1;
    pwmValue = constrain(pwmValue, 1, 254);
   }

   analogWrite(PWM,pwmValue);
}
