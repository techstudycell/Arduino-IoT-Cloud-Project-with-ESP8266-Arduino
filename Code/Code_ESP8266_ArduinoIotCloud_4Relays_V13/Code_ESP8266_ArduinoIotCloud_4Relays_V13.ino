/**********************************************************************************
 *  TITLE: Arduino IoT Cloud + Alexa + IR + Manual control 4 Relays with DHT11 & Real-Time feedback using NodeMCU
 *  Click on the following links to learn more. 
 *  YouTube Video: https://youtu.be/WLSg9S1_3do
 *  Related Blog : https://iotcircuithub.com/esp8266-projects/
 *  by Tech StudyCell
 *  Preferences--> Aditional boards Manager URLs : 
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  
 *  Download Board ESP8266 NodeMCU : https://github.com/esp8266/Arduino
 *  Download the libraries
 *  ArduinoIoTCloud Library with all the dependencies: https://github.com/arduino-libraries/ArduinoIoTCloud
 **********************************************************************************/

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <SoftwareSerial.h>

//const char THING_ID[]           = ""; //Enter THING ID
const char DEVICE_LOGIN_NAME[]  = ""; //Enter DEVICE ID

const char SSID[]               = "";    //Enter WiFi SSID (name)
const char PASS[]               = "";    //Enter WiFi password
const char DEVICE_KEY[]         = "";    //Enter Secret device password (Secret Key)

// define the GPIO connected with Relays and switches


#define wifiLed    16   //D0
SoftwareSerial mySerial(13, 15); // RX, TX  D7, D8

bool connectedFlag = false;
String pinStatus = "000000.00";
String pinStatus_OLD = "0000";


float temperature1 = 0;
float humidity1   = 0;
int   reconnectFlag = 0;

void onSwitch1Change();
void onSwitch2Change();
void onSwitch3Change();
void onSwitch4Change();

CloudSwitch switch1;
CloudSwitch switch2;
CloudSwitch switch3;
CloudSwitch switch4;
CloudTemperatureSensor temperature;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  //ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(switch1, READWRITE, ON_CHANGE, onSwitch1Change);
  ArduinoCloud.addProperty(switch2, READWRITE, ON_CHANGE, onSwitch2Change);
  ArduinoCloud.addProperty(switch3, READWRITE, ON_CHANGE, onSwitch3Change);
  ArduinoCloud.addProperty(switch4, READWRITE, ON_CHANGE, onSwitch4Change);
  ArduinoCloud.addProperty(temperature, READ, 8 * SECONDS, NULL); //Update temperature value after every 8 seconds
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

void updateState(String state, String pre_state){

  if(state.substring(0,1) != pre_state.substring(0,1)){
    if (state.substring(0,1) == "1"){
      switch1 = 1;
    }
    else{
      switch1 = 0;
    }
  }
  if(state.substring(1,2) != pre_state.substring(1,2)){
    if (state.substring(1,2) == "1"){
      switch2 = 1;
    }
    else{
      switch2 = 0;
    }
  }
  if(state.substring(2,3) != pre_state.substring(2,3)){
    if (state.substring(2,3) == "1"){
      switch3 = 1;
    }
    else{
      switch3 = 0;
    }
  }
  if(state.substring(3,4) != pre_state.substring(3,4)){
    if (state.substring(3,4) == "1"){
      switch4 = 1;
    }
    else{
      switch4 = 0;
    }
  }
}


void doThisOnConnect(){
  /* add your custom code here */
  Serial.println("Board successfully connected to Arduino IoT Cloud");
}
void doThisOnSync(){
  /* add your custom code here */
  digitalWrite(wifiLed, LOW);
  Serial.println("Thing Properties synchronised");
}

void doThisOnDisconnect(){
  /* add your custom code here */
  digitalWrite(wifiLed, HIGH); //Turn off WiFi LED
  Serial.println("Board disconnected from Arduino IoT Cloud");
}

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);Serial.printf("\r\n\r\n");
  mySerial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  initProperties();
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::CONNECT, doThisOnConnect);
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::SYNC, doThisOnSync);
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::DISCONNECT, doThisOnDisconnect);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  pinMode(wifiLed, OUTPUT);
  digitalWrite(wifiLed, HIGH);
}

void loop() {

  ArduinoCloud.update();
  
  while(mySerial.available()) 
  {
    pinStatus = mySerial.readString();
    pinStatus_OLD = String(switch1) + String(switch2) + String(switch3) + String(switch4);
    //Serial.println(pinStatus.substring(0,4) + " " + pinStatus_OLD + " " + pinStatus.substring(4,8));
    if(pinStatus.substring(0,4) != pinStatus_OLD) {      
      updateState(pinStatus.substring(0,4), pinStatus_OLD);
      //pinStatus_OLD = pinStatus;
    }
    temperature = pinStatus.substring(4,8).toFloat();
    //connectedFlag = true;
  }
}

void onSwitch1Change() {
  mySerial.printf("%s", switch1?"A1":"A0");
  delay(20);
}

void onSwitch2Change() {
  mySerial.printf("%s", switch2?"B1":"B0");
  delay(20);
}

void onSwitch3Change() {
  mySerial.printf("%s", switch3?"C1":"C0");
  delay(20);
}

void onSwitch4Change() {
  mySerial.printf("%s", switch4?"D1":"D0");
  delay(20);
}
