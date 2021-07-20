#include <MsTimer2.h>  
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
int tick=0;
void ontimer(){
  tick++;
}
void setup(){
    MsTimer2::set(1000, ontimer); //设置中断，每1000ms tick+1
    MsTimer2::start(); //开始计时
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
  	pinMode(11,OUTPUT);
  	pinMode(12,OUTPUT);
  	pinMode(2,INPUT);
  	Serial.begin(9600);
};
void showNumber(int control,int n){
    int pin;
    digitalWrite(control,LOW);
    int array[10][4]={
        {0,0,0,0},
        {0,0,0,1},
        {0,0,1,0},
        {0,0,1,1},
        {0,1,0,0},
        {0,1,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,0,0},
        {1,0,0,1},
    };
    for(pin=IN1;pin<=IN4;pin++)
        digitalWrite(pin,array[n][IN4-pin]);
    digitalWrite(control,HIGH);
};
void loop(){
    int tens,single;
    single=tick%10;
    tens=tick/10;
  	Serial.print(digitalRead(2));
    Serial.print(tens);
  	Serial.println(single);
    showNumber(11,single);
    showNumber(12,tens);
  	if(digitalRead(2)==1)tick=0;
}