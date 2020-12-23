void setup() {
pinMode(7,OUTPUT);//trigger pin S1 left 
pinMode(8,INPUT);//echo pin S1 left 
pinMode(12,OUTPUT);//buzzer1 left
pinMode(10,OUTPUT);//trigger pin S2 right 
pinMode(11,INPUT);//echo pin S2 right 
pinMode(13,OUTPUT);//buzzer2 right+ 
Serial.begin(9600);
}


void loop() {
  digitalWrite(7,LOW); 
  delayMicroseconds(2);
  digitalWrite(7,HIGH);
  delayMicroseconds(10); 
  digitalWrite(7,LOW);

int duration = pulseIn(8,HIGH); 
int distance = (duration*.0343)/2; 
Serial.print("Distance: "); 
Serial.println(distance);

digitalWrite(10,LOW); 
delayMicroseconds(2); 
digitalWrite(10,HIGH);
delayMicroseconds(10); 
digitalWrite(10,LOW);
int duration1 = pulseIn(11,HIGH); 
int distance1 = (duration1*.0343)/2; 
Serial.print("Distance1: "); 
Serial.println(distance1);

if(distance>0&&distance<23)
{// digitalWrite(4,HIGH);
  tone(12,2000);
}

else{
//digitalWrite(4,LOW); 
noTone(12);
}
if(distance1>0&&distance1<23)
{// digitalWrite(9,HIGH); 
  tone(13,1500);
}

else{
// digitalWrite(9,LOW); 
noTone(13);
}
}
