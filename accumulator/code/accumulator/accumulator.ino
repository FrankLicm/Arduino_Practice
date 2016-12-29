#include <Arduino.h>
#define a 1
#define b 2
#define c 3
#define d 4
#define e 5
#define f 6
#define g 7
#define p 8
//设置阳极接口
#define d4 9
#define d3 10
#define d2 11
#define d1 12
#define KEY 0

int SUM = 0;
int Flag_up = 1;

unsigned char table[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,0,1,0,0 }   // = 9
                             }; 

void setup()
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
}


void loop()
{
  if( ScanKey() == 1)
  {
    SUM++;
    if(SUM>9999)
    {
      SUM = 9999;
    }
  }
  Display(1,SUM/1000);
  delay(3);
  Display(2,SUM%1000/100);
  delay(3);
  Display(3,SUM%100/10);
  delay(3);
  Display(4,SUM%10);
  delay(3);
}

unsigned char ScanKey()
{
  if(Flag_up  && digitalRead(KEY) == LOW)
  {
    Flag_up = 0;
    delay(20);
    if(digitalRead(KEY) == LOW)
    {
      return 1;
    }
  }
  if(digitalRead(KEY) == HIGH)
  {
    Flag_up = 1;
  }
  return 0;
}

void Display(unsigned char com,unsigned char num)
{
	digitalWrite(a,HIGH);			//去除余晖
	digitalWrite(b,HIGH);
	digitalWrite(c,HIGH);
	digitalWrite(d,HIGH);
	digitalWrite(e,HIGH);
	digitalWrite(f,HIGH);
	digitalWrite(g,HIGH);
	digitalWrite(p,HIGH);

	switch(com)						//选通位选
	{
		case 1:
			digitalWrite(d1,HIGH);		//选择位1
			digitalWrite(d2,LOW);
			digitalWrite(d3,LOW);
			digitalWrite(d4,LOW);
			break;
		case 2:
			digitalWrite(d1,LOW);
			digitalWrite(d2,HIGH);		//选择位2
			digitalWrite(d3,LOW);
			digitalWrite(d4,LOW);
			break;
		case 3:
			digitalWrite(d1,LOW);
			digitalWrite(d2,LOW);
			digitalWrite(d3,HIGH);		//选择位3
			digitalWrite(d4,LOW);
			break;
		case 4:
			digitalWrite(d1,LOW);
			digitalWrite(d2,LOW);
			digitalWrite(d3,LOW);
			digitalWrite(d4,HIGH);		//选择位4
			break;
		default:break;
	}

	digitalWrite(a,table[num][0]);			//a查询码值表
	digitalWrite(b,table[num][1]);
	digitalWrite(c,table[num][2]);
	digitalWrite(d,table[num][3]);
	digitalWrite(e,table[num][4]);
	digitalWrite(f,table[num][5]);
	digitalWrite(g,table[num][6]);
}

