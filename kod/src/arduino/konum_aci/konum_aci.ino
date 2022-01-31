#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;

double pwm_sol = 9;
double pwm_sag = 8;
const int inA = 7;
const int inB = 6;
const int inC = 5;
const int inD = 4;

double enkoder_sol = 0, enkoder_sag = 0;
double mesafe_sol = 0, mesafe_sag = 0;
boolean A,B,C,D;
byte durum_sol, durum_sag, durumy_sol, durumy_sag;

double ref_sol = 0, ref_sag = 0;
double hedef_sol = 0, hedef_sag = 0;
double mesafe = 0;

double now;
double LastTime=0;
double tur_hata_sol=0;
double tur_hata_sag=0;

double Kp = 4;
double Ki = 0.1;
double Kd = 0.000001;

float son_hata_sol = 0, son_hata_sag = 0;
float hata_sol = 0, hata_sag = 0;
float int_hata_sol = 0, int_hata_sag = 0;
float top_hata_sol = 0, top_hata_sag = 0;
float pid_sol = 0,pid_sag = 0;
float pids_sol = 0, pids_sag = 0;

double gelen_sol = 0;
double gelen_sag = 0;

void gelen_konum(const geometry_msgs::Twist& msg){
      enkoder_sol = 0;
      enkoder_sag = 0;
    ref_sol = (double)msg.angular.x;
    ref_sag = (double)msg.angular.y;
    mesafe  = (double)msg.linear.z;
  }

ros::Subscriber<geometry_msgs::Twist> sub("motor", gelen_konum);

void setup(){
  
    pinMode(18,INPUT_PULLUP);
    pinMode(19,INPUT_PULLUP);
    pinMode(20,INPUT_PULLUP);
    pinMode(21,INPUT_PULLUP);
    pinMode(pwm_sol, OUTPUT);
    pinMode(pwm_sag, OUTPUT);
    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
    pinMode(inC, OUTPUT);
    pinMode(inD, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(18),Akanali,CHANGE);
    attachInterrupt(digitalPinToInterrupt(19),Bkanali,CHANGE); 
    attachInterrupt(digitalPinToInterrupt(20),A2kanali,CHANGE);
    attachInterrupt(digitalPinToInterrupt(21),B2kanali,CHANGE); 
    nh.initNode();
    nh.subscribe(sub);
  }

int sayac = 0;

void loop(){

now=millis()*0.01;

    PID_sol();
    PID_sag();

    if(hedef_sol > ref_sol){
      digitalWrite(inA,LOW);
      digitalWrite(inB,HIGH);
      }else{
        digitalWrite(inA,HIGH);
        digitalWrite(inB,LOW);
        }
    if(hedef_sag > ref_sag){
      digitalWrite(inC,LOW);
      digitalWrite(inD,HIGH);
      }else{
        digitalWrite(inC,HIGH);
        digitalWrite(inD,LOW);
        }

     analogWrite(pwm_sol,pids_sol);
     analogWrite(pwm_sag,pids_sag);
     
    nh.spinOnce();
    delay(100);
  }

void PID_sol(){


  double dt=(double)(now-LastTime);

    hedef_sol    =   (267.0353756*enkoder_sol)/(160*4);
    
    hata_sol     =   ref_sol - hedef_sol;
    int_hata_sol +=   hata_sol * dt;
    
//    int_hata_sol =   hata_sol - son_hata_sol;
    tur_hata_sol =  (hata_sol-son_hata_sol)/dt;
//    top_hata_sol +=  hata_sol;
//    pid_sol      =   (Kp*hata_sol)+(Ki*top_hata_sol)+(Kd*int_hata_sol);
    pid_sol      =   (Kp*hata_sol)+(Ki*int_hata_sol)+(Kd*tur_hata_sol);
    pid_sol      =   constrain(pid_sol,-255,255);
    pids_sol     =   abs(pid_sol);
    son_hata_sol =   hata_sol;
    LastTime=now;
  }


void PID_sag(){
//
//    hedef_sag    =   (267.0353756*enkoder_sag)/(160*4);
//    hata_sag     =   ref_sag - hedef_sag;
//    int_hata_sag =   hata_sag - son_hata_sag;
//    top_hata_sag +=  hata_sag;
//    pid_sag      =   (Kp*hata_sag)+(Ki*top_hata_sag)+(Kd*int_hata_sag);
//    pid_sag      =   constrain(pid_sag,-255,255);
//    pids_sag     =   abs(pid_sag);
//    son_hata_sag =   hata_sag;


    double dt=(double)(now-LastTime);
    hedef_sag    =   (267.0353756*enkoder_sag)/(160*4);
    hata_sag     =   ref_sag - hedef_sag;
    int_hata_sag +=   hata_sag * dt;
    tur_hata_sag =  (hata_sag-son_hata_sag)/dt;
    pid_sag      =   (Kp*hata_sag)+(Ki*int_hata_sag)+(Kd*tur_hata_sag);
    pid_sag      =   constrain(pid_sag,-255,255);
    pids_sag    =   abs(pid_sag);
    son_hata_sag =   hata_sag;
    LastTime=now;
    
  }

void Akanali() 
{
  A = digitalRead(18);
  B = digitalRead(19);

  if ((A==HIGH)&&(B==HIGH)) durum_sol = 1;
  if ((A==HIGH)&&(B==LOW)) durum_sol = 2;
  if ((A==LOW)&&(B==LOW)) durum_sol = 3;
  if((A==LOW)&&(B==HIGH)) durum_sol = 4;
  switch (durum_sol)
  {
    case 1:
    {
      if (durumy_sol == 2) enkoder_sol++;
      if (durumy_sol == 4) enkoder_sol--;
      break;
    }
    case 2:
    {
      if (durumy_sol == 1) enkoder_sol--;
      if (durumy_sol == 3) enkoder_sol++;
      break;
    }
    case 3:
    {
      if (durumy_sol == 2) enkoder_sol --;
      if (durumy_sol == 4) enkoder_sol ++;
      break;
    }
    default:
    {
      if (durumy_sol == 1) enkoder_sol++;
      if (durumy_sol == 3) enkoder_sol--;
    }
  }
  durumy_sol = durum_sol;
  
}

void Bkanali()
{
  A = digitalRead(18);
  B = digitalRead(19);

  if ((A==HIGH)&&(B==HIGH)) durum_sol = 1;
  if ((A==HIGH)&&(B==LOW)) durum_sol = 2;
  if ((A==LOW)&&(B==LOW)) durum_sol = 3;
  if((A==LOW)&&(B==HIGH)) durum_sol = 4;
  switch (durum_sol)
  {
    case 1:
    {
      if (durumy_sol == 2) enkoder_sol++;
      if (durumy_sol == 4) enkoder_sol--;
      break;
    }
    case 2:
    {
      if (durumy_sol == 1) enkoder_sol--;
      if (durumy_sol == 3) enkoder_sol++;
      break;
    }
    case 3:
    {
      if (durumy_sol == 2) enkoder_sol --;
      if (durumy_sol == 4) enkoder_sol ++;
      break;
    }
    default:
    {
      if (durumy_sol == 1) enkoder_sol++;
      if (durumy_sol == 3) enkoder_sol--;
    }
  }
  durumy_sol = durum_sol;

}

void A2kanali() 
{
  C = digitalRead(20);
  D = digitalRead(21);

  if ((C==HIGH)&&(D==HIGH)) durum_sag = 1;
  if ((C==HIGH)&&(D==LOW)) durum_sag = 2;
  if ((C==LOW)&&(D==LOW)) durum_sag = 3;
  if((C==LOW)&&(D==HIGH)) durum_sag = 4;
  switch (durum_sag)
  {
    case 1:
    {
      if (durumy_sag == 2) enkoder_sag++;
      if (durumy_sag == 4) enkoder_sag--;
      break;
    }
    case 2:
    {
      if (durumy_sag == 1) enkoder_sag--;
      if (durumy_sag == 3) enkoder_sag++;
      break;
    }
    case 3:
    {
      if (durumy_sag == 2) enkoder_sag --;
      if (durumy_sag == 4) enkoder_sag ++;
      break;
    }
    default:
    {
      if (durumy_sag == 1) enkoder_sag++;
      if (durumy_sag == 3) enkoder_sag--;
    }
  }
  durumy_sag = durum_sag;
  
}

void B2kanali()
{
  C = digitalRead(20);
  D = digitalRead(21);

  if ((C==HIGH)&&(D==HIGH)) durum_sag = 1;
  if ((C==HIGH)&&(D==LOW)) durum_sag = 2;
  if ((C==LOW)&&(D==LOW)) durum_sag = 3;
  if((C==LOW)&&(D==HIGH)) durum_sag = 4;
  switch (durum_sag)
  {
    case 1:
    {
      if (durumy_sag == 2) enkoder_sag++;
      if (durumy_sag == 4) enkoder_sag--;
      break;
    }
    case 2:
    {
      if (durumy_sag == 1) enkoder_sag--;
      if (durumy_sag == 3) enkoder_sag++;
      break;
    }
    case 3:
    {
      if (durumy_sag == 2) enkoder_sag --;
      if (durumy_sag == 4) enkoder_sag ++;
      break;
    }
    default:
    {
      if (durumy_sag == 1) enkoder_sag++;
      if (durumy_sag == 3) enkoder_sag--;
    }
  }
  durumy_sag = durum_sag;

}
