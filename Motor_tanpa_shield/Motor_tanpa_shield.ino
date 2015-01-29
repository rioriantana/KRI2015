//Motor Kanan
//Tengah, Output 1 + dan Output 2 -
int Arah1Kanan = 7; //Input 1
int Arah2Kanan = 6; //Input 2
int PWMKanan = 10;  //Enable A

//Motor Kiri
//Kanan, Output 3 + dan Output 4 -
int Arah1Kiri = 5; //Input 3
int Arah2Kiri = 4; //Input 4
int PWMKiri = 9; //Enable B

//PWM Motor
int PWMMotor = 150;

void setup()
{
  Serial.begin(9600);
  pinMode(Arah1Kanan, OUTPUT);
  pinMode(Arah2Kanan, OUTPUT);
  pinMode(PWMKanan, OUTPUT);
  pinMode(Arah1Kiri, OUTPUT);
  pinMode(Arah1Kiri, OUTPUT);
  pinMode(PWMKiri, OUTPUT);
}

void loop()
{
  belokkanan();
  delay(1000);
  kiriberhenti();
  delay(1000);
  belokkiri();
  delay(1000);
  kananberhenti();
  delay(1000);
  kiriberhenti();
  delay(1000);
  maju();
  delay(1000);
  mundur();
  delay(1000);
  berhenti();
  delay(1000);
}

void belokkanan()
{
  analogWrite(PWMKanan, PWMMotor);
  digitalWrite(Arah1Kanan, LOW);
  digitalWrite(Arah2Kanan, HIGH);
}

void kananberhenti()
{
  analogWrite(PWMKanan, 0);
  digitalWrite(Arah1Kanan, LOW);
  digitalWrite(Arah2Kanan, LOW);
}

void belokkiri()
{
  analogWrite(PWMKiri, PWMMotor);
  digitalWrite(Arah1Kiri, HIGH);
  digitalWrite(Arah2Kiri, LOW);
}

void kiriberhenti()
{
  analogWrite(PWMKiri, 0);
  digitalWrite(Arah1Kiri, LOW);
  digitalWrite(Arah2Kiri, LOW);
}

void maju()
{
  analogWrite(PWMKanan, PWMMotor);
  digitalWrite(Arah1Kanan, LOW);
  digitalWrite(Arah2Kanan, HIGH);
  analogWrite(PWMKiri, PWMMotor);
  digitalWrite(Arah1Kiri, HIGH);
  digitalWrite(Arah2Kiri, LOW);
}

void mundur()
{
  analogWrite(PWMKanan, PWMMotor);
  digitalWrite(Arah1Kanan, HIGH);
  digitalWrite(Arah2Kanan, LOW);
  analogWrite(PWMKiri, PWMMotor);
  digitalWrite(Arah1Kiri, LOW);
  digitalWrite(Arah2Kiri, HIGH);
}

void berhenti()
{
  analogWrite(PWMKanan, 0);
  digitalWrite(Arah1Kanan, LOW);
  digitalWrite(Arah2Kanan, LOW);
  analogWrite(PWMKiri, 0);
  digitalWrite(Arah1Kiri, LOW);
  digitalWrite(Arah2Kiri, LOW);
}
