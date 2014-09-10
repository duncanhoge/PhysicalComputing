import processing.serial.*;
import org.firmata.*;
import cc.arduino.*;

//create vars - Arduino is class, arduino is the instance
Arduino arduino;

//led
int ledPin = 13;

void setup(){
  size(600,300);
  println(Arduino.list()); //static method: called class instead of instance to talk to all arduino ports
  arduino = new Arduino(this, Arduino.list()[4], 57600); //this is the specific port we want to talk to -- comment this out and just run the line above to see which one to use. in this case it is 4.
  arduino.pinMode(ledPin, Arduino.OUTPUT);
}

void draw(){
   background(255);
}

void mousePressed(){
  arduino.digitalWrite(ledPin, Arduino.HIGH);
}

void mouseReleased(){
  arduino.digitalWrite(ledPin, Arduino.LOW);
}
