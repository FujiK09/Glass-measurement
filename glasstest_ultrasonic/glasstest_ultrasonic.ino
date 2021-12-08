/*超音波センサとガラス板までの距離計測実験*/

const int TRIG_PIN = 10;
const int ECHO_PIN = 11;
float temp ; //温度
float duration;//往復距離
float distance;//センサとガラス間の距離
float sound;//音速

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
float analog , vout; 
  // アナログ０番ピンのデータを取得
  //ただしここで取得するデータは0から1023までの数値になっている
  analog = analogRead(0); 
  //電圧に変換しmv単位に修正
  vout = (analog*5*1000)/1023;
  //温度変化の計算式
  temp = (vout - 600)/10;
  //シリアルモニタに出力 
  //0.5秒に一度処理を行う
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  sound=331+0.6*temp;
  duration = duration/2.0;
  distance = duration*sound*100/1000000;
  Serial.print(distance);
  Serial.print("cm,");
  Serial.print(temp);
  Serial.print("℃,");
  Serial.print(sound);
  Serial.print("m/s\n");
  delay(1000);
}

//float tmp(){
//    float analog , vout; 
//  // アナログ０番ピンのデータを取得
//  //ただしここで取得するデータは0から1023までの数値になっている
//  analog = analogRead(0); 
//  //電圧に変換しmv単位に修正
//  vout = (analog*5*1000)/1023;
//  //温度変化の計算式
//  temp = (vout - 600)/10;
//  //シリアルモニタに出力 
//  //0.5秒に一度処理を行う git
//  return temp; 
//}
//
