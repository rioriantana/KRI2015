//Sensor Depan
unsigned int EchoPin1 = 8;
unsigned int TrigPin1 = 9;
unsigned long Time_Echo_us1 = 0; 
unsigned long Distance1  = 0;
//contohs
//Sensor Belakang
unsigned int EchoPin2 = 10;
unsigned int TrigPin2 = 11;
unsigned long Time_Echo_us2 = 0;
unsigned long Distance2  = 0;

//Sensor Kiri
unsigned int EchoPin3 = 12;
unsigned int TrigPin3 = 13;
unsigned long Time_Echo_us3 = 0;
unsigned long Distance3  = 0;

//Sensor Kanan
unsigned int EchoPin4 = 2;
unsigned int TrigPin4 = 3;
unsigned long Time_Echo_us4 = 0; 
unsigned long Distance4  = 0;

//Sensor Depan Kiri
/*unsigned int EchoPin5 = 15;
unsigned int TrigPin5 = 16;
unsigned long Time_Echo_us5 = 0; 
unsigned long Distance5  = 0;*/

//Sensor Depan Kanan
/*unsigned int EchoPin6 = 17;
unsigned int TrigPin6 = 18;
unsigned long Time_Echo_us6 = 0; 
unsigned long Distance6  = 0;*/

//Motor
int E1 = 5;
int M1 = 4;
int E2 = 6;                      
int M2 = 7;

//PWM
int PWMmotor = 150;

void setup()
{ 
 Serial.begin(9600);
 pinMode(EchoPin1, INPUT); //Pin Sensor Depan
 pinMode(TrigPin1, OUTPUT);
 pinMode(EchoPin2, INPUT); //Pin Sensor Belakang
 pinMode(TrigPin2, OUTPUT);
 pinMode(EchoPin3, INPUT); //Pin Sensor Kiri
 pinMode(TrigPin3, OUTPUT);
 pinMode(EchoPin4, INPUT); //Pin Sensor Kanan
 pinMode(TrigPin4, OUTPUT);
 /*pinMode(EchoPin5, INPUT); //Pin Depan Kiri
 pinMode(TrigPin5, OUTPUT);
 pinMode(EchoPin6, INPUT); //Pin Depan Kanan
 pinMode(TrigPin6, OUTPUT); */
 pinMode(M1, OUTPUT); //Pin Motor
 pinMode(M2, OUTPUT);
}  

void loop()
{
  //sensordepan();
  if (Distance1 >= 0 && Distance1 <= 500)
  {
    mundur();
    delay(1000);
    belokkanan();
    delay(200);
  }
  if (Distance1 >= 501 && Distance1 <= 1000)
  {
    maju();
  }
  sensorbelakang();
  if (Distance2 >= 0 && Distance2 <= 500)
  {
    maju();
    delay(3000);
  }
  sensorkiri();
  if (Distance3 >= 0 && Distance3 <= 500)
  {
    belokkiri();
    delay(1000);
    maju();
    delay(3000);
  }
  sensorkanan();
  if (Distance4 >= 0 && Distance4 <= 500)
  {
    belokkanan();
    delay(1000);
    maju();
    delay(3000);
  }
}

//Konversi Ke Jarak Sensor depan
void sensordepan()
{
 digitalWrite(TrigPin1, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin1, LOW);
 Time_Echo_us1 = pulseIn(EchoPin1, HIGH);
 Distance1 = (Time_Echo_us1*34/100)/2;
 Serial.print("Present Distance is: ");
 Serial.print(Distance1, DEC);
 Serial.println("mm"); 
}

//Konversi Ke Jarak Sensor Belakang
void sensorbelakang()
{
 digitalWrite(TrigPin2, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin2, LOW);
 Time_Echo_us2 = pulseIn(EchoPin2, HIGH);
 Distance2 = (Time_Echo_us2*34/100)/2;
 Serial.print("Present Distance is: ");
 Serial.print(Distance2, DEC);
 Serial.println("mm"); 
}

//Konversi Ke Jarak Sensor Kiri
void sensorkiri()
{
 digitalWrite(TrigPin3, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin3, LOW);
 Time_Echo_us3 = pulseIn(EchoPin3, HIGH);
 Distance3 = (Time_Echo_us3*34/100)/2;
 Serial.print("Present Distance is: ");
 Serial.print(Distance3, DEC);
 Serial.println("mm"); 
}

//Konversi Ke Jarak Sensor Kanan
void sensorkanan()
{
 digitalWrite(TrigPin4, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin4, LOW);
 Time_Echo_us4 = pulseIn(EchoPin4, HIGH);
 Distance4 = (Time_Echo_us4*34/100)/2;
 Serial.print("Present Distance is: ");
 Serial.print(Distance4, DEC);
 Serial.println("mm"); 
}
/*
//Konversi Ke Jarak Sensor Depan Kiri
void sensordepankiri()
{
 digitalWrite(TrigPin5, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin5, LOW);
 Time_Echo_us5 = pulseIn(EchoPin5, HIGH);
 Distance5 = (Time_Echo_us5*34/100)/2;
 Serial.print("Present Distance is: ");
 Serial.print(Distance5, DEC);
 Serial.println("mm"); 
}

//Konversi Ke Jarak Sensor Depan Kanan
void sensordepankanan()
{
 digitalWrite(TrigPin6, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin6, LOW);
 Time_Echo_us6 = pulseIn(EchoPin6, HIGH);
 Distance6 = (Time_Echo_us6*34/100)/2;
 Serial.print("Present Distance is: ");
 Serial.print(Distance6, DEC);
 Serial.println("mm");
}*/

//Motor Maju
void maju()
{
  digitalWrite(M1,LOW);   
  digitalWrite(M2,LOW);       
  analogWrite(E1, PWMmotor);
  analogWrite(E2, PWMmotor);
}

//Motor Mundur
void mundur()
{
  digitalWrite(M1,HIGH);   
  digitalWrite(M2,HIGH);       
  analogWrite(E1, PWMmotor);
  analogWrite(E2, PWMmotor);
}

//Motor Belok Kiri
void belokkiri()
{
  digitalWrite(M1,HIGH);
  analogWrite(E1, PWMmotor);
  analogWrite(E2, 0);
}

//Motor Belok Kanan
void belokkanan()
{
  digitalWrite(M2,HIGH);       
  analogWrite(E1, 0);
  analogWrite(E2, PWMmotor);
}
