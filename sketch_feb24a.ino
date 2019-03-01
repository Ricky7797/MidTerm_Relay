int in1 = 6;
float Period;
float T_on;
float T_off;
int Amp;
int OS;
float avg;
int n=1;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  PWM_Time_Check(6,5,50);
}



void Blink(int x, int y){
  
  
  digitalWrite(x, LOW);
  delay(y);
  digitalWrite(x, HIGH);
  delay(y);
}

void PWM_Time_Check(int x, float y, float z){
  Period=1/y;
  T_on=(z*10)*Period;
  T_off=(Period*1000)-T_on;
  
 
  
  unsigned long start = millis();
  digitalWrite(x, LOW);
  delay(T_off);
  unsigned long off = millis();
  digitalWrite(x, HIGH);
  delay(T_on);
  unsigned long on = millis();
  
  float duty_cycle=float((on-off))/float((on-start));
  float error=float((T_on/10))-(duty_cycle*100);
  Serial.println(" ");
  Serial.print("Duty Cycle error is ");
  Serial.println(error);
  avg=(avg+error)/n;
  n=n+1;
  Serial.print("Average error is ");
  Serial.println(avg);
  Serial.print("Number of Samples= ");
  Serial.println(n);
  
}

void PWM_2(int Amp, int OS, float y, float z){
  
  Period=1/y;
  T_on=(z*10)*Period;
  T_off=(Period*1000)-T_on;

  if (Amp<=OS) {
        Serial.println("Error: Amplitude must be greater than offset");
        delay(10000);
      }
  
  else if (OS==0) {
      while (Amp==1) {
        digitalWrite(6, LOW);
        delay(T_off);
        digitalWrite(6, HIGH);
        delay(T_on);
      }
      while (Amp==2) {
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        delay(T_off);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        delay(T_on);
      }
      while (Amp==3) {
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        delay(T_off);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        delay(T_on);
      }
      while (Amp==3) {
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        delay(T_off);
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        delay(T_on);
      }
  }
  else if (OS==1) {
      digitalWrite(7, HIGH);
      while (Amp==2) {
        digitalWrite(6, LOW);
        delay(T_off);
        digitalWrite(6, HIGH);
        delay(T_on);
      }
      while (Amp==3) {
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        delay(T_off);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        delay(T_on);
      }
      while (Amp==4) {
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        delay(T_off);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        delay(T_on);
      }
  }
  else if (OS==2) {
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      while (Amp==3) {
        digitalWrite(5, LOW);
        delay(T_off);
        digitalWrite(5, HIGH);
        delay(T_on);
      }
      while (Amp==4) {
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        delay(T_off);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        delay(T_on);
      }
  }
  else if (OS==3) {
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
  }
        while (Amp==3) {
          digitalWrite(4, LOW);
          delay(T_off);
          digitalWrite(4, HIGH);
          delay(T_on);
      }
}






















