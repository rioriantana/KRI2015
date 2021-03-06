#include <LiquidCrystal.h>
#include <Servo.h> 

LiquidCrystal lcd(49, 47, 45, 43, 41, 39);

const int TombolAtas = 37;
const int TombolKanan = 35;
const int TombolBawah = 33;
const int TombolKiri = 31;
const int Reset = 30;

int stAtas = 0;
int stKanan = 0;
int stKiri = 0;
int stBawah = 0;

int menu = 0;
int submenu = 0;

int uvTron = 26;
int kipas1 = 25;
int kipas2 = 24;

Servo myservo;
unsigned int servo = 3;

//Sensor Depan
unsigned int EchoPin1 = 9;
unsigned int TrigPin1 = 8;
unsigned long Time_Echo_us1 = 0; 
unsigned long Distance1  = 0;

//Sensor Belakang
unsigned int EchoPin2 = 20;
unsigned int TrigPin2 = 21;
unsigned long Time_Echo_us2 = 0;
unsigned long Distance2  = 0;

//Sensor Kiri
unsigned int EchoPin3 = 13;
unsigned int TrigPin3 = 12;
unsigned long Time_Echo_us3 = 0;
unsigned long Distance3  = 0;

//Sensor Kanan
unsigned int EchoPin4 = 6;
unsigned int TrigPin4 = 7;
unsigned long Time_Echo_us4 = 0; 
unsigned long Distance4  = 0;

//Sensor Depan Kiri
unsigned int EchoPin5 = 11;
unsigned int TrigPin5 = 10;
unsigned long Time_Echo_us5 = 0; 
unsigned long Distance5  = 0;

//Sensor Depan Kanan
unsigned int EchoPin6 = 4;
unsigned int TrigPin6 = 5;
unsigned long Time_Echo_us6 = 0; 
unsigned long Distance6  = 0;

//Motor Kanan
int Arah1Kanan = 15; //Input 1
int Arah2Kanan = 14; //Input 2
int PWMKanan = 18;  //Enable A

//Motor Kiri
int Arah1Kiri = 16; //Input 3
int Arah2Kiri = 17; //Input 4
int PWMKiri = 19; //Enable B

//PWM
int PWMMotor = 150;




void setup(){
pinMode(TombolAtas, INPUT);
pinMode(TombolKanan, INPUT);
pinMode(TombolBawah, INPUT);
pinMode(TombolKiri, INPUT);
pinMode(Reset, OUTPUT);
pinMode(EchoPin1, INPUT); //Pin Sensor Depan
 pinMode(TrigPin1, OUTPUT);
 pinMode(EchoPin2, INPUT); //Pin Sensor Belakang
 pinMode(TrigPin2, OUTPUT);
 pinMode(EchoPin3, INPUT); //Pin Sensor Kiri
 pinMode(TrigPin3, OUTPUT);
 pinMode(EchoPin4, INPUT); //Pin Sensor Kanan
 pinMode(TrigPin4, OUTPUT);
 pinMode(EchoPin5, INPUT); //Pin Depan Kiri
 pinMode(TrigPin5, OUTPUT);
 pinMode(EchoPin6, INPUT); //Pin Depan Kanan
 pinMode(TrigPin6, OUTPUT);
 
  pinMode(uvTron, OUTPUT);
  pinMode(kipas1, OUTPUT);
  pinMode(kipas2, OUTPUT);
 
  pinMode(Arah1Kanan, OUTPUT);
  pinMode(Arah2Kanan, OUTPUT);
  pinMode(PWMKanan, OUTPUT);
  pinMode(Arah1Kiri, OUTPUT);
  pinMode(Arah1Kiri, OUTPUT);
  pinMode(PWMKiri, OUTPUT);
  
  sensordepan();
  sensorbelakang();
  sensorkiri();
  sensorkanan();
  sensordepankiri();
  sensordepankanan();
 lcd.begin(16, 2);
}

void loop(){
  stAtas = digitalRead(TombolAtas);
  int oke;
    if(stAtas == HIGH){
    menu = menu-1;
    delay(500);
    }
    stKiri = digitalRead(TombolKiri);
    if(stKiri == HIGH){
    digitalWrite(Reset, HIGH);
    }
    stBawah = digitalRead(TombolBawah);
    if(stBawah == HIGH){
    menu = menu+1;
    delay(500);
    }
    stKanan = digitalRead(TombolKanan);
    if(menu > 4){
      menu = 4;
    }
    if(menu < 0){
      menu = 0;
    }
  switch(menu){
    case 0:
    lcd.setCursor(0,0);
    lcd.print("Pilih Menu");
    lcd.setCursor(0,1);
    lcd.print("Kalibrasi US");
        if(stKanan == HIGH){
          if(stAtas == HIGH){
            submenu = submenu-1;
            delay(500);
            }
           if(stBawah == HIGH){
            submenu = submenu+1;
            delay(500);
            }
           if(submenu < 0){
              submenu = 0;
            }
            
           if(submenu > 5){
              submenu = 5;
            }
          switch(submenu){
            case 0:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("US Depan");
              if(stKanan == HIGH){
                kalibrasiSensordepan();
              }
            break;
            case 1:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("US Kanan Depan");
              if(stKanan == HIGH){
                kalibrasiSensordepankanan();
              }
            break;
            case 2:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("US Kanan");
              if(stKanan == HIGH){
                kalibrasiSensorkanan();
              }
            break;
            case 3:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("US Belakang");
              if(stKanan == HIGH){
                kalibrasiSensorbelakang();
              }
            break;
            case 4:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("US Kiri");
              if(stKanan == HIGH){
                kalibrasiSensorkiri();
              }
            break;
            case 5:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("US Kiri Depan");
              if(stKanan == HIGH){
                kalibrasiSensordepankiri();
              }
            break;
            
          }
      }
    break;
    case 1:
    lcd.setCursor(0,0);
    lcd.print("Pilih Menu");
    lcd.setCursor(0,1);
    lcd.print("Kalibrasi Line");
        if(stKanan == HIGH){
          if(stAtas == HIGH){
            submenu = submenu-1;
            delay(500);
            }
           if(stBawah == HIGH){
            submenu = submenu+1;
            delay(500);
            }
           if(submenu < 0){
              submenu = 0;
            }
            
      }
    break;
    case 2:
    lcd.setCursor(0,0);
    lcd.print("Pilih Menu");
    lcd.setCursor(0,1);
    lcd.print("Cek Peka UV");
        if(stKanan == HIGH){
          int cekUv = digitalRead(uvTron);
            delay(500);
          if(cekUv == LOW){
            digitalWrite(kipas1, HIGH);
            digitalWrite(kipas2, HIGH);
            delay(500);
          }
            
      }
    break;
    case 3:
    lcd.setCursor(0,0);
    lcd.print("Pilih Menu");
    lcd.setCursor(0,1);
    lcd.print("Cek Motor");
        if(stKanan == HIGH){
          maju();
          delay(4000);
          mundur();
          delay(4000);
          belokkiri();
          delay(4000);
          belokkanan();
          delay(4000);
          berhenti();
          delay(4000);
      }
    break;
    case 4:
    lcd.setCursor(0,0);
    lcd.print("Pilih Menu");
    lcd.setCursor(0,1);
    lcd.print("Pilih Metode");
    if(stKanan == HIGH){
          if(stAtas == HIGH){
            submenu = submenu-1;
            delay(500);
            }
           if(stBawah == HIGH){
            submenu = submenu+1;
            delay(500);
            }
           if(submenu < 0){
              submenu = 0;
            }
            
           if(submenu > 5){
              submenu = 5;
            }
          switch(submenu){
            case 0:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("Arena Kiri 1");
              if(stKanan == HIGH){
                //Logic Perintah
              }
            break;
            case 1:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("Arena Kiri 2");
              if(stKanan == HIGH){
                //Logic Perintah
              }
            break;
            case 2:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("Arena Kiri 3");
              if(stKanan == HIGH){
                //Logic Perintah
              }
            break;
            case 3:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("Arena Kanan 1");
              if(stKanan == HIGH){
                //Logic Perintah
              }
            break;
            case 4:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("Arena Kanan 2");
              if(stKanan == HIGH){
                //Logic Perintah
              }
            break;
            case 5:
              lcd.setCursor(0,0);
              lcd.print("Pilih Submenu");
              lcd.setCursor(0,1);
              lcd.print("Arena Kanan 3");
              if(stKanan == HIGH){
                //Logic Perintah
              }
            break;
          }
    }
    break;
  } 
    
}

void sensordepan()
{
 digitalWrite(TrigPin1, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin1, LOW);
 Time_Echo_us1 = pulseIn(EchoPin1, HIGH);
 Distance1 = (Time_Echo_us1*34/100)/2;
}

//Konversi Ke Jarak Sensor Belakang
void sensorbelakang()
{
 digitalWrite(TrigPin2, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin2, LOW);
 Time_Echo_us2 = pulseIn(EchoPin2, HIGH);
 Distance2 = (Time_Echo_us2*34/100)/2;
}

//Konversi Ke Jarak Sensor Kiri
void sensorkiri()
{
 digitalWrite(TrigPin3, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin3, LOW);
 Time_Echo_us3 = pulseIn(EchoPin3, HIGH);
 Distance3 = (Time_Echo_us3*34/100)/2;
}

//Konversi Ke Jarak Sensor Kanan
void sensorkanan()
{
 digitalWrite(TrigPin4, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin4, LOW);
 Time_Echo_us4 = pulseIn(EchoPin4, HIGH);
 Distance4 = (Time_Echo_us4*34/100)/2;
}

//Konversi Ke Jarak Sensor Depan Kiri
void sensordepankiri()
{
 digitalWrite(TrigPin5, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin5, LOW);
 Time_Echo_us5 = pulseIn(EchoPin5, HIGH);
 Distance5 = (Time_Echo_us5*34/100)/2;
}

//Konversi Ke Jarak Sensor Depan Kanan
void sensordepankanan()
{
 digitalWrite(TrigPin6, HIGH);
 delayMicroseconds(50);
 digitalWrite(TrigPin6, LOW);
 Time_Echo_us6 = pulseIn(EchoPin6, HIGH);
 Distance6 = (Time_Echo_us6*34/100)/2;
}
//Display kalibrasi

void kalibrasiSensordepan()
{
 Serial.print("Present Distance is: ");
 Serial.print(Distance1, DEC);
 Serial.println("mm"); 
}

void kalibrasiSensorbelakang()
{
 Serial.print("Present Distance is: ");
 Serial.print(Distance2, DEC);
 Serial.println("mm"); 
}

void kalibrasiSensorkiri()
{
 Serial.print("Present Distance is: ");
 Serial.print(Distance3, DEC);
 Serial.println("mm"); 
}

void kalibrasiSensorkanan()
{
 Serial.print("Present Distance is: ");
 Serial.print(Distance4, DEC);
 Serial.println("mm"); 
}

void kalibrasiSensordepankiri()
{
 Serial.print("Present Distance is: ");
 Serial.print(Distance5, DEC);
 Serial.println("mm"); 
}

void kalibrasiSensordepankanan()
{
 Serial.print("Present Distance is: ");
 Serial.print(Distance6, DEC);
 Serial.println("mm");
}
//Motor Maju
void maju()
{
  analogWrite(PWMKanan, PWMMotor);
  digitalWrite(Arah1Kanan, LOW);
  digitalWrite(Arah2Kanan, HIGH);
  analogWrite(PWMKiri, PWMMotor);
  digitalWrite(Arah1Kiri, HIGH);
  digitalWrite(Arah2Kiri, LOW);
}

//Motor Mundur
void mundur()
{
  analogWrite(PWMKanan, PWMMotor);
  digitalWrite(Arah1Kanan, HIGH);
  digitalWrite(Arah2Kanan, LOW);
  analogWrite(PWMKiri, PWMMotor);
  digitalWrite(Arah1Kiri, LOW);
  digitalWrite(Arah2Kiri, HIGH);
}

//Motor Belok Kiri
void belokkiri()
{
  analogWrite(PWMKiri, PWMMotor);
  digitalWrite(Arah1Kiri, HIGH);
  digitalWrite(Arah2Kiri, LOW);
}

//Motor Belok Kanan
void belokkanan()
{
  analogWrite(PWMKanan, PWMMotor);
  digitalWrite(Arah1Kanan, LOW);
  digitalWrite(Arah2Kanan, HIGH);
}

//Motor Berhenti
void berhenti()
{
  analogWrite(PWMKanan, 0);
  digitalWrite(Arah1Kanan, LOW);
  digitalWrite(Arah2Kanan, LOW);
  analogWrite(PWMKiri, 0);
  digitalWrite(Arah1Kiri, LOW);
  digitalWrite(Arah2Kiri, LOW);
}

