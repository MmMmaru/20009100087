void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}
void loop(){
    int incomingByte,pin;
    int array[10][7]={
        {1,1,1,1,1,1,0},
        {0,1,1,0,0,0,0},
        {1,1,0,1,1,0,1},
        {1,1,1,1,0,0,1},
        {0,1,1,0,0,1,1},
        {1,0,1,1,0,1,1},
        {1,0,1,1,1,1,1},
        {1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1},
        {1,1,1,1,0,1,1}
    };
    if (Serial.available() > 0) 
        incomingByte = Serial.read();
    incomingByte=incomingByte-'0';
    if(incomingByte<=9&&incomingByte>=0){
        for(pin=7;pin<=13;pin++)
            digitalWrite(pin,array[incomingByte][pin-7]);
    };
}