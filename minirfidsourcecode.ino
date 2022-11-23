#define BLYNK_TEMPLATE_ID "TMPL1_b8IfVm"
#define BLYNK_DEVICE_NAME "rfid"
#define BLYNK_AUTH_TOKEN "9KhpD7iqAJBG2aslCMAxywuHHVmluS9R"

#include<SPI.h>
#include<MFRC522.h>
#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Realme";
char pass[] = "pratapsingh24";


WidgetTerminal terminal(V2);
  String str1 = "793DF94E";
  String str2 = "32635B1A";
  String str3 = "A936F84E";
  String str4 = "793DF94E";
#define SS_PIN 4  //D2
#define RST_PIN 5 //D1
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  
                               
                                              Serial.begin(9600);         // Start the Serial communication to send messages to the computer
                                              delay(10);
                                              Serial.println('\n');
                                             servo.attach(15); //D8
                                              servo.write(0);
                                    
                                              Blynk.begin(auth, ssid, pass);
                                              // Connect to the network // Send the IP address of the ESP8266 to the computer
                                              SPI.begin();      // Initiate  SPI bus
                                              mfrc522.PCD_Init();   // Initiate MFRC522
}

void loop() { 
                      Serial.println("..................................................");
                    BLYNK_WRITE(V3);
                    BLYNK_WRITE(V4);
                    BLYNK_WRITE(V5);
                      Serial.print(" UID tag :");
                      String content= "";
                      byte letter;
                      if ( mfrc522.PICC_IsNewCardPresent()){
                        if ( mfrc522.PICC_ReadCardSerial()){
                      for (byte i = 0; i < mfrc522.uid.size; i++) 
                      {
                         Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
                         Serial.print(mfrc522.uid.uidByte[i], HEX);
                         content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ""));
                         content.concat(String(mfrc522.uid.uidByte[i], HEX));
                         
                      }
                      }
                      }
                      delay(1000);
                      content.toUpperCase();
                     
                     
                  




       Serial.println();
      if( content.equals(str1))
            {
                         Serial.println("Aryan");   //Enter User1 Name
                         Blynk.virtualWrite(V2, "Aryan" );   //Enter User1 Name
                         Blynk.logEvent("e3");
         
          
                                      servo.write(90);
                                      delay(2000);
                                      servo.write(0);
                                      delay(2000); 
                       
                         delay(3000); 
                       
           }
  
        else if(  content.equals(str2)  )
                  {
                   Serial.println("Ayush");   //Enter User2 Name 
                   Blynk.virtualWrite(V2, "Ayush" );   //Enter User2 Name
                   Blynk.logEvent("e3");
         
          
                                      servo.write(90);
                                      delay(2000);
                                      servo.write(0);
                                      
                       
                   delay(3000); 
                
                  }
        else if( content.equals(str3) )
        {
         Serial.println("Anuj");   //Enter User3 Name
         Blynk.virtualWrite(V2, "Anuj" );   //Enter User3 Name
        
         Blynk.logEvent("e3");
         
          
                                      servo.write(90);
                                      delay(2000);
                                      servo.write(0);
                                      delay(2000); 
                        
         delay(3000); 
        
        }
 
       else {
        Serial.println("Unregistered User");
         delay(3000);
        }
         Serial.println(".............................................................");
                      Serial.println();
                     
      }
                       
