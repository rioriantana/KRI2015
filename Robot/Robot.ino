#include <LiquidCrystal.h>
#include <Servo.h> 

Servo myservo;
unsigned int servo = 17;

//Sensor Depan
unsigned int EchoPin1 = 9;
unsigned int TrigPin1 = 8;
unsigned long Time_Echo_us1 = 0; 
unsigned long Distance1  = 0;

//Sensor Belakang
unsigned int EchoPin2 = 2;
unsigned int TrigPin2 = 3;
unsigned long Time_Echo_us2 = 0;
unsigned long Distance2  = 0;

//Sensor Kiri
unsigned int EchoPin3 = 13;
unsigned int TrigPin3 = 12;
unsigned long Time_Echo_us3 = 0;
unsigned long Distance3  = 0;

//Sensor Kanan
unsigned int EchoPin4 = 29;
unsigned int TrigPin4 = 31;
unsigned long Time_Echo_us4 = 0; 
unsigned long Distance4  = 0;

//Sensor Depan Kiri
unsigned int EchoPin5 = 11;
unsigned int TrigPin5 = 10;
unsigned long Time_Echo_us5 = 0; 
unsigned long Distance5  = 0;

//Sensor Depan Kanan
unsigned int EchoPin6 = 25;
unsigned int TrigPin6 = 27;
unsigned long Time_Echo_us6 = 0; 
unsigned long Distance6  = 0;

//Motor
int E1 = 5;
int M1 = 4;
int E2 = 6;                      
int M2 = 7;

//PWM
int PWMmotor = 150;

//Pin LCD
LiquidCrystal lcd(53, 51, 49, 47, 45, 43);

//Integer Konstan Tombol
const int TombolAtas = 41;
const int TombolKanan = 39;
const int TombolBawah = 37;
const int TombolKiri = 35;

int ButtonState1 = 0;
int ButtonState2 = 0;
int ButtonState3 = 0;
int ButtonState4 = 0;


void setup()
{ 
 Serial.begin(9600);
 f
 
 
 pinMode(TombolAtas, INPUT);
 pinMode(TombolKanan, INPUT);
 pinMode(TombolBawah, INPUT);
 pinMode(TombolKiri, INPUT);
 
 lcd.begin(16, 2);
 
 myservo.attach(23); //Pin 31 untuk Servo
 myservo.write(0); //Memulai dengan 0 derajat
 }  

void loop()
{
  
  //Tampilan LCD Sensor Depan
  lcd.setCursor(0,0);
  lcd.print("PROTA :D");  
  sensordepan();
  lcd.setCursor(0,1);
  lcd.print(Distance1);
  lcd.print("mm");
  delayMicroseconds(50);
  
  if (Distance1 >= 0 && Distance1 <= 500)
  {
    mundur();
    delay(2000);
    belokkanan();
    delay(200);
    maju();
    myservo.write(90);
    delay(1000);
    myservo.write(0);
    delay(1000);
  }
  else
  {
    maju();
    delay(3000);
  }
   
  if (Distance2 >= 0 && Distance2 <= 500)
  {
    maju();
    delay(3000);
  }
  
  if (Distance3 >= 0 && Distance3 <= 500)
  {
    belokkiri();
    delay(1000);
    maju();
    delay(3000);
  }
  
  if (Distance4 >= 0 && Distance4 <= 500)
  {
    belokkanan();
    delay(1000);
    maju();
    delay(3000);
  }
  
  sensordepankiri();
  if (Distance5 >= 0 && Distance5 <= 500)
  {
    belokkiri();
    delay(500);
    maju();
    delay(500);
  }

  sensordepankanan();
  if (Distance6 >= 0 && Distance6 <= 500)
  {
    belokkanan();
    delay(500);
    maju();
    delay(500);
  }


  ButtonState1 = digitalRead(TombolAtas);
  ButtonState2 = digitalRead(TombolKanan);
  ButtonState3 = digitalRead(TombolBawah);
  ButtonState4 = digitalRead(TombolKiri);
  
  //Kalibrasi Sensor
  if (ButtonState1 == HIGH)
  {
    sensordepan();  
    lcd.setCursor(0,1);
    lcd.print(Distance1);
    lcd.print("mm");
    delay(250);
  } 
  if(ButtonState2 == HIGH)
  {
    sensorbelakang();  
    lcd.setCursor(0,1);
    lcd.print(Distance2);
    lcd.print("mm");
    delay(250);
  }
  if(ButtonState3 == HIGH)
  {
    sensorkiri();  
    lcd.setCursor(0,1);
    lcd.print(Distance3);
    lcd.print("mm");
    delay(250);
  }
  if(ButtonState4 == HIGH)
  {
    sensorkanan();  
    lcd.setCursor(0,1);
    lcd.print(Distance4);
    lcd.print("mm");
    delay(250);
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
}

//Motor Maju
void maju()
{
  digitalWrite(M1,HIGH);   
  digitalWrite(M2,HIGH);       
  analogWrite(E1, PWMmotor);
  analogWrite(E2, PWMmotor);
}

//Motor Mundur
void mundur()
{
  digitalWrite(M1,LOW);   
  digitalWrite(M2,LOW);       
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

//Motor Berhenti
void berhenti()
{
  digitalWrite(M1,LOW);   
  digitalWrite(M2,LOW);       
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}

