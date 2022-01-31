/*****************************************************/
const byte pin_a = 3; //enkoder 1.sensor
const byte pin_b = 2; //enkoder 2.sensor
const int pin_inA = 8; //sürücü inA
const int pin_inB = 9; //sürücü inB
const int pin_inC = 10; //sürücü inA
const int pin_inD = 11; //sürücü inB
const int pin_pwmA = 5; //sürücü Ea;
const int pin_pwmB = 6; //sürücü Ea;

/*******************************/
int encoderA = 0;
int encoderB = 0;
double pv_speedA = 0;
double pv_speedB = 0;
double kp=0.186;
double ki=0.097;
double kd=0.0866;
double set_speedA=20;
double set_speedB=20;
double e_speedA = 0;
double e_speedB = 0;
double e_speed_preA = 0;
double e_speed_preB = 0;
double e_speed_sumA = 0;
double e_speed_sumB = 0;
double pwm_pulseA = 0;
double pwm_pulseB = 0;

int timer1_counter;

/*****************************/

void setup() {
  
 pinMode(pin_a,INPUT_PULLUP);
 pinMode(pin_b,INPUT_PULLUP);
 pinMode(pin_inA,OUTPUT);
 pinMode(pin_inB,OUTPUT);
 pinMode(pin_inC,OUTPUT);
 pinMode(pin_inD,OUTPUT);
 pinMode(pin_pwmA,OUTPUT);
 pinMode(pin_pwmB,OUTPUT);

 attachInterrupt(digitalPinToInterrupt(pin_a), detect_a, RISING);
 attachInterrupt(digitalPinToInterrupt(pin_b), detect_b, RISING);

 //--------------------------timer hazırlama
 noInterrupts();
 TCCR1A = 0;
 TCCR1B = 0;
 timer1_counter = 34286;
 TCNT1 = timer1_counter;
 TCCR1B |= (1 << CS12);
 TIMSK1 |= (1 << TOIE1);
 interrupts();
 //--------------------------timer hazırlama

 Serial.begin(9600);
 digitalWrite(pin_inA,0);
 digitalWrite(pin_inB,1);
 digitalWrite(pin_inC,1);
 digitalWrite(pin_inD,0);
}

void loop() {

  int set_speed=10;
  
    set_speedA = set_speed;
    set_speedB = set_speed;

}

void detect_a() {
 encoderA+=1;
 //m_direction = digitalRead(pin_b);
}

void detect_b() {
 encoderB+=1;
 //m_direction = digitalRead(pin_b);
}

ISR(TIMER1_OVF_vect)
{
 TCNT1 = timer1_counter;
 pv_speedA = 60*(encoderA/160.0)/0.5;
 encoderA=0;
 pv_speedB = 60*(encoderB/160.0)/0.5;
 encoderB=0;
 
 Serial.print(set_speedA);
 Serial.print("------");
 Serial.print(pv_speedA);
 Serial.print("------");
 Serial.print(pwm_pulseA);
 Serial.print("**************");
 Serial.print(set_speedB);
 Serial.print("------");
 Serial.print(pv_speedB);
 Serial.print("------");
 Serial.println(pwm_pulseB);
 
 //PID program
/**********************************************************/
 e_speedA = set_speedA - pv_speedA;
 pwm_pulseA = e_speedA*kp + e_speed_sumA*ki + (e_speedA - e_speed_preA)*kd;
 e_speed_preA = e_speedA;
 e_speed_sumA += e_speedA;
 
 if (e_speed_sumA >4000) e_speed_sumA = 4000;
 if (e_speed_sumA <-4000) e_speed_sumA = -4000;
/**********************************************************/
 e_speedB = set_speedB - pv_speedB;
 pwm_pulseB = e_speedB*kp + e_speed_sumB*ki + (e_speedB - e_speed_preB)*kd;
 e_speed_preB = e_speedB;
 e_speed_sumB += e_speedB;
 
 if (e_speed_sumB >4000) e_speed_sumB = 4000;
 if (e_speed_sumB <-4000) e_speed_sumB = -4000;
/***********************************************************/
 if (pwm_pulseA <=255 & pwm_pulseA >=0){
 analogWrite(pin_pwmA,pwm_pulseA);
 }
 else{
 if (pwm_pulseA>255){
 analogWrite(pin_pwmA,255);
 }
 else{
 analogWrite(pin_pwmA,0);
 }
 }
/*************************************************/
  if (pwm_pulseB <=255 & pwm_pulseB >=0){
 analogWrite(pin_pwmB,pwm_pulseB);
 }
 else{
 if (pwm_pulseB>255){
 analogWrite(pin_pwmB,255);
 }
 else{
 analogWrite(pin_pwmB,0);
 }
 }
/*************************************************/
}
 
