# Arduino-IoT-Cloud-Project-with-ESP8266-Arduino
In this IoT project, I have shown how to make an IoT-based Smart Home with Arduino IoT Cloud &amp; Alexa using ESP8266 Arduino to control 4 home appliances with voice commands, IR remote, and manual switches. If the internet is unavailable, you can control the home appliances from IR remote &amp; manual switches. In the article, I have shown all the steps to make this smart home system.

## Tutorial video on Arduino IoT Cloud Project
Video Link: https://youtu.be/IMb52-h4tzQ

### This Arduino Home Automation system has the following features:

1. Control appliances with Arduino IoT Cloud Dashboard.
2. Control appliances with Alexa.
3. Used Arduino EEPROM to remember previous states
4. Control appliances with IR remote.
5. Control appliances manually with switches or pushbuttons
6. Monitor real-time feedback and room temperature in the 7. Amazon Alexa app.
8. Control home appliances manually without internet.
9. All resources used for this project are FREE.

So if you follow all the steps, you can easily make this IoT project just by using Arduino UNO, NodeMCU, and relay module.

Although the PCB is not mandatory, I have used PCB to make the circuit compact and give the project a professional look.

## How Does This Arduino IoT Cloud Project Works?
This Arduino ESP8266 Home Automation works in the following steps.

1. When you ask Alexa to control appliances, it sends the signal to the Arduino IoT Cloud server.
2. NodeMCU will receive the signal from the Arduino IoT Cloudthrough the internet.
3. NodeMCU sends the same signal to Arduino through the serial terminal.
4. Arduino UNO will process that signal and turn the relays on or off.
5. Arduino sends the feedback to NodeMCU through Serial communication.
6. NodeMCU sends feedback to the Arduino IoT Cloud server through the internet.
7. Real-time feedback can be monitored in the Amazon Alexa app.

Required Components for this IoT Project (without PCB)

1. Arduino UNO
2. NodeMCU ESP8266
3. 1838 IR receiver (with metal case)
4. DHT11 Sensor
5. 4-channel 5V SPDT Relay Module
6. Switches or Push Buttons
7. 5V DC supply.

Required Components for the Arduino control Relay PCB:

1. Atmega328P microcontroller
2. ESP8266 ESP01
3. PC817 Optocuplors (4 no)
4. 510-ohm 0.25-watt Resistor (4 no) (R1 -- R4)
5. 1k 0.25-watt Resistors (6 no) (R5 -- R10)
6. 2k 0.25-watt Resistor
7. 4.7k 0.25-watt Resistor
8. 10k 0.25-watt Resistors (2no)
9. 22pF ceramic capacitor
10. 104 ceramic capacitor
11. 220uF 25V Capacitor (2no)
12. 1uF Box capacitor (1no)
13. 16MHz Crystal
14. LED 5-mm (6 no)
15. 1N4007 Diodes (4 no) (D1 -- D4)
16. Push Buttons (8 no)
17. BC547 Transistors (4 no)
18. Relays 5v (SPDT) (4 no)
19. Terminal Connectors
20. Jumper (5no)
21. Switch (1no)
22. Hi-link ac-dc 220v-5v

## Circuit Diagram of the ESP8266 Arduino Control Relays
The circuit is very simple, I have used the digital pins D4, D5, D6 & D7 to control the 4 relays.

And the digital pins D10, D11, D12 & D13 are connected with switches to control the 4 relays manually.

The output pin of the IR receiver is connected with A0 and the DHT11 sensor is connected with A1.

I have used the INPUT_PULLUP function in Arduino IDE instead of using the pull-up resistors.

I have used D2 as RX and D3 as TX for the serial communication with the NodeMCU module.

If you use the latched switches then just connect the pushbutton across the digital pins and GND instead of the pushbuttons.

I have used a 5V mobile charger to supply the smart relay module.

Please take proper safety precautions while working with high voltage.

## Alexa Control Relay Using ESP8266 NodeMCU
You can control the home appliances from Amazon Alexa App if the NodeMCU is connected to the WiFi.

You can also ask Alexa to turn on and off the appliances from anywhere in the world.

You don't need any Echo DOT or other Alexa devices for this home automation project.

You can also control the home appliances from the Arduino IoT Cloud web dashboard and Arduino IoT Cloud Remote mobile app if the NodeMCU is connected with WiFi.

## Control Relays With IR Remote & Manual Switches
You can always control the relays with IR remote and manual switches.

I will explain how to get the IR codes (HEX codes) from any remote in the following steps.

And if the NodeMCU is connected to Wi-Fi, you can monitor the real-time feedback in the Amazon Alexa App & Arduino cloud dashboard.

If the WiFi is unavailable, you can still control the relays with IR remote and manual switches.

When the WiFi is available, the NodeMCU will automatically reconnect with the WiFi.

## Design the PCB for This Smart Home System
To make the circuit compact and give a professional look, I have designed the PCB after testing all the features of the smart relay module.

You can download the PCB Gerber file of this home automation project from the following link:

https://github.com/techstudycell/Arduino-IoT-Cloud-Project-with-ESP8266-Arduino/blob/main/PCB_Gerber/PCB_Gerber_Arduino_NodeMCU_Sensors_V13.zip

## Why you should use JLC SMT Service?

On JLCPCB's one-stop online platform, customers enjoy low-cost & high-quality & fast SMT service at an $8.00 setup fee($0.0017 per joint).

$27 New User coupon & $24 SMT coupons every month.

Visit https://jlcpcb.com/RAB

JLCPCB SMT Parts Library 200k+ in-stock components (689 Basic components and 200k+ Extended components)

Parts Pre-Order service https://support.jlcpcb.com/article/164-what-is-jlcpcb-parts-pre-order-service

Build a Personal library Inventory, save parts for now or the future

Assembly will support 10M+ parts from Digikey, mouser.

## Steps to Order the PCB Assembly from JLCPCB
1. Visit https://jlcpcb.com/RAB and Sign in / Sign up.
2. Click on the QUOTE NOW button.
3. Click on the "Add your Gerber file" button. Then browse and select the Gerber file you have downloaded.
4. Set the required parameter like Quantity, PCB masking color, etc.
5. Select the Assemble side and SMT Quantity.
6. Now upload the BOM and PickAndPlace files.
7. Now confirm all the components which you want to be soldered by SMT services.
8. Click on SAVE TO CART button.
9. Type the Shipping Address.
10. Select the Shipping Method suitable for you.
11. Submit the order and proceed with the payment.

You can also track your order from the JLCPCB.
My PCBs took 3 days to get manufactured and arrived within a week using the DHL delivery option.
PCBs were well packed and the quality was really good at this affordable price.

## Create Arduino IoT Cloud FREE Account
For this smart house project, I have used the Arduino Cloud Free plan.

Click on the following link to create an Arduino IoT Cloud account.

https://store.arduino.cc/digital/create

Click on "Create one".
1. Enter your birthday, then click on "Next".
2. Enter the email ID, user name, set password. Then click on "Sign Up".
3. Now click on "IoT Cloud".

## Add NodeMCU ESP8266 Device in the Arduino IoT Cloud
1. Click on the Select Device on the right side.
2. Select "Set up a third Party device", then select device 3. type as ESP8266 and device model as NodeMCU 1.0.
4. You will get a Device ID and Secret Key which will be required in the code.
5. Click on "Continue", You will find the device added.
You can see, the device added.

## Add Variable in Arduino IoT Cloud
Now to control 4 relays, you have to add 4 variables.

Click on the "ADD VARIABLE" button.
Enter a name, then select Alexa compatible switch type. Variable Permission will be "Read & Write" and Variable Update Policy will be "On Change".
In a similar way, you have to add the next 3 variables.
For the room temperature reading, select Alexa compatible Temperature Sensor. Variable Update Policy will be "Periodically", and mention the interval time.

## Set Up Arduino IoT Cloud Dashboard
1. Now click on Dashboard on the top to set up the Arduino cloud dashboard.
2. Then click on Build Dashboard.
3. After that click on the EDIT icon. Then click on ADD and select Switch.
4. Give a name to this Switch, then link a variable with this switch widget.
5. Then click on Done.
In a similar way, you have to add total 4 Switch widgets to control 4 relays.
For the temperature, select Gauge widgets and link the Temperature variable. You can also set the MIN and MAX limits.

##Get the IR Codes (HEX Code) From Remote
Now, to get the HEX codes from the remote, first, we have to connect the IR receiver output pin with the A0 pin of Arduino UNO.And give the 5V across the VCC and GND. The IR receiver must have a metallic casing, otherwise, you may face issues.

##Then follow the following steps to get the HEX codes:
1. Install the IRremote libraryIn Arduino IDE.
2. Download the attached code, and upload it to Arduino UNO.
3. Open Serial Monitor with Baud rate 9600.
4. Now, press the IR remote button.
5. The respective HEX code will populate in the serial monitor.
6. Save all the HEX codes in a text file. You have to update these HEX codes in the main sketch.

## Program the ESP8266 NodeMCU With Arduino IDE
To program the NodeMCU, I have used Arduino IDE.

Download the attached code.

First, you have to install the ArduinoIoTCloud library. During installation, it may ask to install other dependencies. Then click on Install All.
In the code, enter the following details
const char DEVICE_LOGIN_NAME[] = ""; //Enter DEVICE ID
const char SSID[]        = "";  //Enter WiFi SSID (name)
const char PASS[]        = "";  //Enter WiFi password
const char DEVICE_KEY[]     = "";  //Enter Secret device password (Secret Key)
the DEVICE_LOGIN_NAME[] and DEVICE_KEY[] from the PDF which you have downloaded during adding the device to the Arduino IoT cloud.

I have shown all the steps in the tutorial video. After doing all these changes, you can upload the code to NodeMCU.

## Program the Arduino UNO or ATmega328P With Arduino IDE
In the PCB I have used an ATmega328P microcontroller, so I have used FTDI232 USB to TTL board to program the microcontroller (Refer to tutorial video).
But if you don't use PCB then you can directly connect the Arduino UNO with the laptop.

For the main sketch, you need to install the following libraries

1. IRremote 3.5.2 Library
2. AceButton 1.9.1 Library
3. Arduino-timer 2.3.1 Library
Then you have to update the HEX code in the sketch for IR remote control.

For momentary switch use the code: Code_ArduinoUNO_EEPROM_WiFi_IR_Button_4Relay.ino

and for latched switch use the code: Code_ArduinoUNO_EEPROM_WiFi_IR_Switch_4Relay.ino

## Configure the Alexa App for Arduino IoT Cloud
Download and install the Amazon Alexa App from the Google play store or App Store.

1. Tap on "More".
2. Then select "Skills & Games".
3. Search for Arduino and tap on "Arduino".
4. Tap on "ENABLE TO USE".

## Connecting Arduino Cloud Devices With Alexa
Log in with the Arduino Cloud credentials.

1. Tap on CLOSE.
2. Tap on "DISCOVER DEVICES". It will take a minute to add devices. During this time the NodeMCU should be connected to the WiFi.
3. Tap on "Devices", and tap on "Switches" to see all the devices.
Thus, all the devices from Arduino IoT Cloud will be added to Amazon Alexa App.

## Connect the Home Appliances
Connect the 4 home appliances with the relay module as per the circuit diagram.

Please take proper safety precautions while working with high voltage.

Connect the 110V/230V supply with the PCB.

## Finally!! the Arduino Cloud Smart Home System Is Ready
Now you can control your home appliances in a smart way.

I hope you have liked this Arduino IoT and Alexa control home automation project. I have shared all the required information for this project.

I will really appreciate it if you share your valuable feedback. Also if you have any queries please write in the comment section.

Thank you & Happy Learning.
