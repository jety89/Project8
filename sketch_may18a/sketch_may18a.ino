#include "max6675.h"

//heater pins
int gnd = 6; ////
int vcc = 5; ////
int sig = 4; ////

double a, b;
int hspeed, aver, tmax, timer, time1b, t1;

//temp sensor pins
int thermoDO = 8;
int thermoCS = 9;
int thermoCLK = 10;

String start;
unsigned int val=0;

unsigned long ms;
//int debug;

//timer=0;
//time1b=100;
int tmin = 35;
//tmax = 60;
//t1=45;
//aver=8;


MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  
  pinMode(gnd, OUTPUT);  ////
  pinMode(vcc, OUTPUT);////
  digitalWrite(vcc, HIGH);////
  digitalWrite(gnd, LOW);/////
  
  pinMode(sig, OUTPUT);

  waitconnect:
 if (Serial.available() > 0) {
    // read the incoming byte:
   char inc;
  while (Serial.available()) { // Get characters
    inc = Serial.read();
	delay(5);
    if (inc >= '0' && inc <= '9') {
      val = 10*val + (inc-'0');
    } else {
      switch (toupper(inc)) {
      
	   case 'A':
        hspeed = val;
        Serial.print(hspeed);
        Serial.print("C");
        Serial.print("01");
        Serial.println("D");
		    delay(500);
       break;
		
       case 'B':
        aver = val;
        Serial.print(aver);
        Serial.print("C");
        Serial.print("02");
        Serial.println("D");
        delay(500);
        break;
		
       case 'C':
        tmin = val;
        Serial.print(tmin);
        Serial.print("C");
        Serial.print("03");
        Serial.println("D");
        delay(500);
        break;
		
       case 'D':
        tmax = val;
        Serial.print(tmax);
        Serial.print("C");
        Serial.print("04");
        Serial.println("D");
        delay(500);
        break;
      
       case 'E':
        t1 = val;
        Serial.print(t1);
        Serial.print("C");
        Serial.print("05");
        Serial.println("D");
        delay(500);
       break;
       
	    case 'F':
        time1b = val;
        Serial.print(time1b);
        Serial.print("C");
        Serial.print("06");
        Serial.println("D");
        delay(500);
	    break;
       
	   default :
       break; // handle blanks, returns, etc
      }
      val = 0;  // Set val to zero after any non-digit
    }
  }
  }
  else
  {
    delay(1000);
    goto waitconnect;
  }
             
//  Serial.print("T_min = ");
//  Serial.println(tmin);

wait:
a = thermocouple.readCelsius();
if ( a > tmin)
{
      // Serial.print(int(tmin*100));
        Serial.print(int(a * 100));
        Serial.print("C");
        Serial.print("09");
        Serial.println("D");
        delay(5000);
        
//  Serial.println("device too hot");
//  Serial.println(a, 4);
//  delay(5000);
  goto wait;
}

prepare: 
a = thermocouple.readCelsius();
    if (a > tmin) 
     {
      digitalWrite(sig, LOW);
      //await start
      Serial.print(millis());
      Serial.print("A");
      Serial.print(int(a*100));
      Serial.print("B");
      Serial.print("07");
      Serial.println("D");
     }
      else
      {
      if (a < tmin)       
      {
       digitalWrite(sig, HIGH);
       Serial.print(millis());
       Serial.print("A");
       Serial.print(int(a*100));
       Serial.print("B");
       Serial.print("07");
       Serial.println("D");
      }
      }
      delay(249);
goto prepare;

   start:
 if (Serial.available() > 0) {
  start = Serial.readString();
  if (start = "Start") {
    Serial.print(millis());
    Serial.print("A");
    Serial.print("10");
    Serial.println("D");
   
//    Serial.println(start);
 
    }
  } else
  {
       Serial.print(millis());
       Serial.print("A");
       Serial.print("08");
       Serial.println("D");
    delay(999);
    goto start;
    }
}
//void(* resetFunc) (void) = 0; //declare reset function @ address 0

void loop(){ 
 // start = Serial.readString();
  //if (start = "Reset") {
   // Serial.print(millis());
   // Serial.print("C");
   // Serial.print("07");
   // Serial.println("D");
   // resetFunc();
//    Serial.println(start);
 
   
  a=0;

  //this is two seconds
  for (int i = 1; i < aver+1; i++)
  { 
    a = a + thermocouple.readCelsius();
    delay(249);
//  Serial.println(a/i, 4);
  }
   a=a/aver;

    //temp and time
    // Serial.println(a, 4);
    Serial.print(millis());
    Serial.print("A");
    Serial.print(int(a*100));
    Serial.println("B");
    
    if (a < tmin) {
    digitalWrite(sig, HIGH);
    //Serial.println("Heater on");
    Serial.print("11");
    Serial.println("D");
    timer=0;
    }  else {
   if(a > tmax) {
     digitalWrite(sig, LOW);
   //Serial.println("Heater off");
     Serial.print("12");
     Serial.println("D");
    }
    }
    
    if ((a > t1) && (timer < time1b))
     {
      digitalWrite(sig, LOW);
      timer = timer+1;
      //Serial.println("timer on");
      Serial.print(timer);
      Serial.print("C");
      Serial.print("13");
      Serial.println("D");
      }
      else
      {
      if ((a < t1) &&( timer > 0.0) && (timer < time1b))      
      {
       digitalWrite(sig, HIGH);
       timer = timer+1;
       //test
       //Serial.print("else");
       //Serial.println(timer);
       Serial.print(timer);
       Serial.print("C");
       Serial.print("13");
       Serial.println("D");
      }
              
      if (timer == time1b)
       {
        digitalWrite(sig, HIGH);
        timer = timer+1;
        //Serial.println("timer off");
        Serial.print("14");
        Serial.println("D");
       }
     }
       //delay(1000);
      }

      
