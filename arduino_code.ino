/* 
Enmre SURK
input -> 120,50,50
servolar bu açıya gelir.


*/

#include <Servo.h>

Servo servo1;  //pin:8   0 - 140
Servo servo2;  //pin:9   50 - 90
Servo servo3;  //pin:10  40 - 110

int middle1 = 120;
int middle2 = 50;
int middle3 = 60;

int potan1Pin = 15;
int potan2Pin = 14;
int potan3Pin = 13;

int potans1Value = 0;
int potans2Value = 0;
int potans3Value = 0;

int positions[7][3] = { 
  { middle1 , middle2 , middle3  },
  { middle1 + 40 , middle2 , middle3 + 20  },
  { middle1 + 40 , middle2 + 20 , middle3 - 20  },
  { middle1 + 40 , middle2 + 20 , middle3 + 20  },
  { middle1 - 40 , middle2 + 20 , middle3 - 20  },
  { middle1 - 40 , middle2 - 20 , middle3 + 20  },
  { middle1 - 40 , middle2 - 20 , middle3 - 20  }  
};

void setup() {
  servo1.attach( 8 ); 
  servo2.attach( 9 ); 
  servo3.attach( 10 ); 

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }  
  axisMove( 0 );
}

void loop() {
  
  //readPotans();
/*
  int i = 40;
  while(i < 140  ) {
    i++;
    axisMove( 3 , i );
      Serial.println( i );
      delay(100);

  }*/
  


   while (Serial.available() > 0) {

    String cmd = Serial.readString();
    char fchar = cmd.charAt(1);
    String number = "no";
    if ( fchar == ' ' ) {
      number = "yes";
      //Serial.println( "number sended." );
      int servoNumber = getValue( cmd , ' ' , 0).toInt();
      int degree = getValue( cmd , ' ' , 1).toInt();

      axisMove( servoNumber, degree ); 
      
    } else {
       
      String pos1str = getValue( cmd , ',' , 0);
      String pos2str = getValue( cmd , ',' , 1);
      String pos3str = getValue( cmd , ',' , 2);
  
      int pos1 = pos1str.toInt();
      int pos2 = pos2str.toInt();
      int pos3 = pos3str.toInt();
  
      axisMove( pos1 , pos2 , pos3 );
      
      //Serial.println( " komut : " + pos1str + "  ," + pos2str + "  ," + pos3str ); // 139,120,55
    }
   }
  
   
}

int readPotans(){
  delay(10);
  potans1Value  = analogRead(potan1Pin);
  potans1Value = map( potans1Value , 0 , 1000 , 0 , 180 );
  axisMove( 1 , potans1Value );

  potans2Value  = analogRead(potan2Pin);
  potans2Value = map( potans2Value , 0 , 1000 , 50 , 90 );
  axisMove( 2 , potans2Value );

  potans3Value  = analogRead(potan3Pin);
  potans3Value = map( potans3Value , 0 , 1000 , 40 , 110 );
  axisMove( 3 , potans3Value );

  Serial.println( potans3Value );
  
}

int axisMove( int positionIndex ) {  
  servo1.write( positions[positionIndex][0] );
  servo2.write( positions[positionIndex][1] );
  servo3.write( positions[positionIndex][2] );
  
  return 0;
}

int axisMove( int s1 , int s2 , int s3 ) {  
  servo1.write( s1 );
  servo2.write( s2 );
  servo3.write( s3 );
  
  return 0;
}

int axisMove( int servoNumber , int degree ) {
  
  if ( servoNumber == 1 ) {
      servo1.write(degree);
  }
  if ( servoNumber == 2 ) {
      servo2.write(degree);
  }
  if ( servoNumber == 3 ) {
      servo3.write(degree);
  }
  
}

String getValue(String data, char separator, int index){
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

























