// Define the pins for the motors

#include "BluetoothSerial.h"

//#define USE_PIN // Uncomment this to use PIN during pairing. The pin is specified on the line below
const char *pin = "1234"; // Change this to more secure PIN.

String device_name = "ESP32-BT-Slave";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

String my_str;
int Appbutton1;
int Appbutton2;


const int MOTOR1_CLOCKWISE_PIN = 33;
const int MOTOR1_COUNTERCLOCKWISE_PIN = 32;
const int DC_MTR2_CW = 21;
const int DC_MTR2_CCW = 23;

const int BUTTN_1 =4;
const int BUTTN_2 =5;


void setup() {
  Serial.begin(115200);
   SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  //Serial.printf("The device with name \"%s\" and MAC address %s is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str(), SerialBT.getMacString()); // Use this after the MAC method is implemented
  #ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
  #endif

  pinMode(MOTOR1_CLOCKWISE_PIN, OUTPUT);
  pinMode(MOTOR1_COUNTERCLOCKWISE_PIN, OUTPUT);
  pinMode(DC_MTR2_CW, OUTPUT);
  pinMode(DC_MTR2_CCW, OUTPUT);
  pinMode(BUTTN_1, INPUT_PULLUP);
  pinMode(BUTTN_2, INPUT_PULLUP);

  digitalWrite(MOTOR1_CLOCKWISE_PIN, HIGH);
  digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, HIGH);
  
}

void loop() {

  if(SerialBT.available())          
    {
    my_str=SerialBT.readString();
      if(my_str.startsWith("BUTTON1"))   
      {
        Appbutton1 = HIGH; 
      }
      if(my_str.startsWith("BUTTON2"))   
      {
        Appbutton2 = HIGH;              
      }
    my_str="";
    
    }


  if (digitalRead(BUTTN_1) == LOW || Appbutton1 == HIGH) {
    Serial.println("BUTTON FIRST PRESSED");
    delay(1000);
    digitalWrite(DC_MTR2_CCW, HIGH);
    delay(2000);
    digitalWrite(DC_MTR2_CCW, LOW);
    delay (2000);
     
    
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, LOW);
    delay(6000);
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, HIGH);
    delay(2000); 

    digitalWrite(MOTOR1_CLOCKWISE_PIN, LOW);
    delay(6000);
    digitalWrite(MOTOR1_CLOCKWISE_PIN, HIGH);
    delay(2000); 
    


    Appbutton1 = LOW; 
}
  if (digitalRead(BUTTN_2) == LOW || Appbutton2 == HIGH) {
    Serial.println("BUTTON SECOND PRESSED");


    
    digitalWrite(DC_MTR2_CW, HIGH);
    delay(5000);
    digitalWrite(DC_MTR2_CW, LOW);
    Appbutton2 = LOW;
     
}
}
