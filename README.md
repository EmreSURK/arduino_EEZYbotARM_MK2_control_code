# arduino_EEZYbotARM_MK2_control_code

An Arduino based control sofware for EEZYBotArm MK2.
Ready to use, just download it send command via serial monitor(Arduino IDE).


![alt text](https://raw.githubusercontent.com/EmreSURK/arduino_EEZYbotARM_MK2_control_code/master/mk2.jpg)
![alt text](https://github.com/EmreSURK/arduino_EEZYbotARM_MK2_control_code/blob/master/serialmonitor.png?raw=true)

## How to setup
Join servos' signal cables(yellow cables) 8 and 9, 10 pins.

1. Click green button named "Clone or download"
2. Click "Download ZIP"
3. Double click to downloaded Zip file(name is "arduino_EEZYbotARM_MK2_control_code-master.zip") and open it
4. Double click to "arduino_code.ino", Arduino ide will show up
5. click Upload button of Arduino ide and send codes to arduino

Now, you are ready!


## Control From Serial Monitor
Open the serial monitor,
Set bounds rate to 9600
You can send one of two type of commands;

```
140,160,120
```

Sets the tree servos angles you give; 140 and 160, 120.

```
1 40
```
Sets 1. servo to 40 degrees. You can use that command for 2. and 3. servos, too.


## Control Via Potentiometers.
1. Connect potans to 13 and 14, 15 pins.

2. Change code a bit;
Comment out that line;
```
//readPotans();
```
Should look like that;
```
readPotans();
```

Comment these lines;
```
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
```
Should look like these;

```
/*
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
*/

```


And you ready!
Just rotate the potans and see the magic! 
