#include <SoftwareSerial.h>

SoftwareSerial mySerial(0,1);

char temp = '0';

//variable initializtion
int xpin = A5;
int xadc = 0;
int xmax = 0;
int xmin = 1023;

int ypin = A6;
int yadc = 0;
int ymax = 0;
int ymin = 1023;

int FLEX_PIN1 = A0; 
int flexADC1 = 0; 
int sensorMin1 = ; 
int sensorMax1 = 0;

int FLEX_PIN2 = A1; 
int flexADC2 = 0; 
int sensorMin2 = 1023; 
int sensorMax2 = 0;

int FLEX_PIN3 = A2; 
int flexADC3 = 0; 
int sensorMin3 = 1023; 
int sensorMax3 = 0;

int FLEX_PIN4 = A3; 
int flexADC4 = 0; 
int sensorMin4 = 1023; 
int sensorMax4 = 0;

int FLEX_PIN5 = A4; 
int flexADC5 = 0; 
int sensorMin5 = 1023; 
int sensorMax5 = 0;


void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  while (!Serial) 
  {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
}


void printfun(char cp) //to avoid printing repeating symbols
{
if(cp!=temp)
{
  mySerial.print(cp);
  temp=cp;
}
}

void loop() 
{
// reading sensor value
float flexADC1 = analogRead(FLEX_PIN1);
float flexADC2 = analogRead(FLEX_PIN2);
float flexADC3 = analogRead(FLEX_PIN3);
float flexADC4 = analogRead(FLEX_PIN4);
float flexADC5 = analogRead(FLEX_PIN5);



float angle1= map(flexADC1, sensorMin1, sensorMax1, 0, 90);
float angle2= map(flexADC2, sensorMin2, sensorMax2, 0, 90);
float angle3= map(flexADC3, sensorMin3, sensorMax3, 0, 90);
float angle4= map(flexADC4, sensorMin4, sensorMax4, 0, 90);
float angle5= map(flexADC5, sensorMin5, sensorMax5, 0, 90); 

xadc = analogRead(xpin);
yadc = analogRead(ypin);
Serial.print("Thumb:");
Serial.println(flexADC1);
Serial.print("Index:");
Serial.println(flexADC2);
Serial.print("Middle:");
Serial.println(flexADC3);
Serial.print("Ring:");
Serial.println(flexADC4);
Serial.print("Pinky:");
Serial.println(flexADC5);
Serial.println();

if(flexADC2>=10.0 &&  flexADC2 <= 20.0 && flexADC3 >= 25.0 && flexADC4 >= 15.00 && flexADC5 <= 10.00 )
{
  Serial.println("all the best for your exams");
}

else if(flexADC2<=10.0 &&  flexADC2 <= 15.0 && flexADC3 >= 20.0 && flexADC4 >= 20.00 && flexADC5 <= 5.00 )
{
  Serial.println("welcome to dsce");
}



delay(4500);

}
