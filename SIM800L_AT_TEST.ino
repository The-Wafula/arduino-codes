
#include <SoftwareSerial.h>
 // SoftwareSerial gsmSerial(11,10);//tx,rx 
//SoftwareSerial gsmSerial(10,11);//tx,rx 
SoftwareSerial gsmSerial(2,3);// tx,rx
 int del=3000;
void setup() {
  Serial.begin(9600);
  while(!Serial);
   gsmSerial.begin(9600);
  delay(1000);   
gsmSerial.write("AT\r\n");
 delay(del);
 readsim();                      
start();
// Serial.println("initialize ussd mode");  
// gsmSerial.write("AT+CUSD=1\r\n"); // automatically answer call after 1 ring
// delay(del);
// readsim();
 //Serial.print("CALL A NIGGER"); 
  //gsmSerial.write("ATD+254702826107\r");
 //grab(5,"0741471713");
flash(); 
//bundlesbalance();
balance();
//smsbalance();
//smsbalance();
//subscribesms();
 //topup("1356640872235004");
//smsbalance();
//balance();
    // bundles();
    // Serial.print("activate DMTF decoding"); 
//gsmSerial.write("AT+DDET=1,1000,0,0\r\n"); // activate DMTF decoding
//  delay(del);
//  readsim();
    Serial.println("you may now put custom AT commands");  
}


void loop() {
  //Read SIM800 output (if available) and print it in Arduino IDE Serial Monitor
  if(gsmSerial.available()){
    Serial.write(gsmSerial.read());
  }
  //Read Arduino IDE Serial Monitor inputs (if available) and send them to SIM800
  if(Serial.available()){    
   gsmSerial.write(Serial.read());
  }
}

void flash(){
   delay(10000);
 Serial.println("//pleace call me");  
 gsmSerial.write("AT+CUSD=1,\"*130*0702826107#\"\r\n"); // automatically answer call after 1 ring
 delay(5000);
 readsim();
}

void start(){
     Serial.println("checking if simcaard is locked");  
gsmSerial.write("AT+CPIN? \r\n");
delay(del);
 readsim(); 
   Serial.println("checking if simcard is registered");  
gsmSerial.write("AT+CREG?\r\n");
 delay(del);
 readsim(); 
  Serial.println("checking if simcard  number");  
gsmSerial.write(" AT+CNUM  \r\n");
 delay(del);
 readsim();  
                    
   Serial.println("checking signal strength shouldbe 9 or higher");  
gsmSerial.write("AT+CSQ\r\n");
   delay(del);
 readsim();
   Serial.println("fetching gsm's serial number");  
 gsmSerial.write("AT+CGSN\r\n");//'AT+CMGL="ALL"'
  delay(3000);
 readsim(); 
    Serial.println("// automatically answer call after 1 ring");  
 gsmSerial.write("ATS0=2\r\n"); // automatically answer call after 1 ring
 delay(del);
 readsim();
//  Serial.println("initialize ussd mode");  
// gsmSerial.write("AT+CUSD=1\r\n"); // automatically answer call after 1 ring
// delay(del);
// readsim();
  Serial.println("Setup Complete!");
  // See if the SIM900 is ready
}
 void balance()
 {
 Serial.println("//check credit before grab");  
 gsmSerial.write("AT+CUSD=1,\"*144#\"\r\n"); // automatically answer call after 1 ring
 delay(4000);
  readsim();
   delay(5000);
 }
 void grab(int stash,String number){
   Serial.println("cash grab...");  
  
   Serial.println("//credit  relief");  
 gsmSerial.write("AT+CUSD=1,\"*140*");
 gsmSerial.print(stash);
gsmSerial.print("*");
gsmSerial.print(number);
gsmSerial.print("#"); // automatically answer call after 1 ring
 gsmSerial.print("\" \r\n"); 
 delay(5000);
 readsim();
  Serial.println("done");  
}
void topup(String card)
{
  Serial.println("topping up");  
 //gsmSerial.write("AT+CUSD=1,\"*544#\"\r\n"); // automatically answer call after 1 ring
 gsmSerial.write("AT+CUSD=1,\"*141*");
 gsmSerial.print(card);
  gsmSerial.print("#"); 
gsmSerial.print("\" \r\n"); 
  Serial.println("done topping up");  
// gsmSerial.print( "AT+CUSD=1,\"" +"*141*"+ card +"#"+ "\"\r\n");
 delay(5000);
 readsim();
}
void bundlesbalance()
{
  
 Serial.println("//check sms");  
 gsmSerial.write("AT+CUSD=1,\"*544#\"\r\n"); // automatically answer call after 1 ring
 delay(5000);
 readsim();
   Serial.println("//sms balance option");  
 gsmSerial.write(" AT+CUSD=1,\"98\"\r\n"); // automatically answer call after 1 ring
 delay(del);
 readsim();
 gsmSerial.write(" AT+CUSD=1,\"9\"\r\n"); // automatically answer call after 1 ring
 delay(5000);
  readsim();
gsmSerial.write("AT+CMGF=1\r\n");
  delay(1000);
  gsmSerial.write("AT+CMGl=\"REC UNREAD\"\r\n");
   //  gsmSerial.write("AT+CMGL='ALL'\r\n");//''
    delay(5000);
}
void subscribesms() {
  Serial.println("//check sms");  
 gsmSerial.write("AT+CUSD=1,\"*188#\"\r\n"); // automatically answer call after 1 ring
 delay(5000);
 readsim();
   Serial.println("//sms balance option");  
 gsmSerial.write(" AT+CUSD=1,\"2\"\r\n"); // automatically answer call after 1 ring
 delay(del);
 readsim();
 Serial.println("//sms balance option");  
 gsmSerial.write(" AT+CUSD=1,\"1\"\r\n"); // automatically answer call after 1 ring
 delay(del);
 readsim();
 Serial.println("//sms balance option");  
 gsmSerial.write(" AT+CUSD=1,\"1\"\r\n"); // automatically answer call after 1 ring
 delay(del);
 readsim();
//  Serial.println("//sms balance option");  
// gsmSerial.write(" AT+CUSD=1,\"1\"\r\n"); // automatically answer call after 1 ring
// delay(del);
// readsim();
 }
 void smsbalance() {
  Serial.println("//check sms");  
 gsmSerial.write("AT+CUSD=1,\"*188#\"\r\n"); // automatically answer call after 1 ring
 delay(5000);
 readsim();
   Serial.println("//sms balance option");  
 gsmSerial.write(" AT+CUSD=1,\"5\"\r\n"); // automatically answer call after 1 ring
 delay(5000);
 readsim();
  delay(7000);
  readsim();
gsmSerial.write("AT+CMGF=1\r\n");
  delay(3000);
    readsim();
  gsmSerial.write("AT+CMGl=\"REC UNREAD\"\r\n");
   //  gsmSerial.write("AT+CMGL='ALL'\r\n");//''
    delay(5000);
      readsim();

 }
 
void readsim() {
   //gsmSerial.println("AT\r\n"); //the newline and CR added
 delay(10);  //arbitrary value

 if(gsmSerial.available()) // check if the esp is sending a message 
 {
 while(gsmSerial.available())
  {
    // The esp has data so display its output to the serial window 
    char c = gsmSerial.read(); // read the next character.
    Serial.write(c);
  } 
 } 
 }

 /*
///////////////General commands (3GPP TS 27.007, section 5)///////////////////////////////////////////
Command  Description
AT+CGMI Request manufacturer information
AT+CGMM Request model identification
AT+CGMR Request revision identification
AT+CGSN Request product serial number identification (of the device, not SIM card)
AT+CSCS Select TE character set
AT+CIMI Request international mobile subscriber identity
AT+CMUX Multiplexing mode

//////////////////////////////////////////////////////////Call control commands (3GPP TS 27.007, section 6)//////////////////////////////////////////////////////////////////////////////////////
Command Description
ATDnnn; Dial "nnn" in voice mode
ATDnnn  Dial "nnn" in data mode
ATH Hangup the current call
ATA Answer an incoming call
AT+CBST Select bearer service type
AT+CRC  Cellular result codes
RING, +CRING  Unsolicited result codes for incoming ring notifications
NO CARRIER, NO ANSWER, NO DIALTONE, BUSY  Unsolicited result codes that indicate call termination
Note: When the ATD command is used with a trailing ';', it is highly recommended that it immediately return to command mode after command processing. Some modems have been known to wait until the receiving party answers the call, or busy is detected, before returning to command mode. Such modems are not compliant with the 3GPP specification but can still be supported by overriding QModemCallProvider::atdBehavior() in the modem vendor plug-in.

The 3GPP TS specification permits ATD to be used in a special mode for dialing directly from phone books. This mode is not required as Qt Extended implements its own algorithm for converting phone book entries to numbers.

It is important that ATD recognize numbers starting with + as international, and all other numbers as being local.

///////////////////////////////////////////////////////Network service related commands (3GPP TS 27.007, section 7)/////////////////////////////////////////////////////////////////
Command Description
AT+CNUM Subscriber number
AT+CREG Network registration
+CREG Unsolicited result code for network registration events
AT+COPS Operator (PLMN) selection
AT+CLCK Facility lock
AT+CPWD Change password
AT+CLIP Calling line identification presentation
+CLIP Unsolicited result code for caller identification presentation
AT+CLIR Calling line identification restriction
AT+COLP Connected line identification presentation
+COLP Unsolicited result code for connected line identification presentation
AT+CCFC Call forwarding number and conditions
AT+CCWA Call waiting
+CCWA Unsolicited result code for call waiting
AT+CHLD Call related supplementary services
AT+CTFR Call deflection
AT+CUSD Unstructured supplementary service data
+CUSB Unsolicited result code for unstructured supplementary service events
AT+CAOC Advice of charge
+CCCM Unsolicited result code for advice of charge indications
AT+CSSN Supplementary service notifications
+CSSI Unsolicited result code for mobile-originated call setup supplementary services
+CSSU Unsolicited result code for mobile-terminated call setup supplementary services
AT+CLCC List current calls
AT+CPOL Preferred PLMN list
AT+CPLS Selection of preferred PLMN list
AT+COPN Read operator names

/////////////////////////////////////////////////////Mobile termination control and status commands (3GPP TS 27.007, section 8)///////////////////////////////////////////////////////////////
Command Description
AT+CFUN Set phone functionality
AT+CPIN Enter PIN
AT+CBC  Battery charge
+CBC  Unsolicited result code for battery charge notifications
AT+CSQ  Signal quality
+CSQ  Unsolicited result code for signal quality notifications
AT+CIND Indicator control
+CIEV Unsolicited result code for indicator control events
AT+CMER Mobile termination event reporting
AT+CPBS Select phone book memory storage
AT+CPBR Read phone book entries
AT+CPBW Write phone book entry
AT+CSIM Generic SIM access
AT+CRSM Restricted SIM access
AT+CVIB Vibrator mode
AT+CACM Accumulated call meter
AT+CAMM Accumulated call meter maximum
AT+CPUC Price per unit and currency table
AT+CCWE Call meter maximum event
+CCWV Unsolicited result code for call meter maximum events
AT+CSVM Set voice mail number
AT+CTZR Time zone reporting
+CTZV Unsolicited result code for time zone change events
The phone book commands are intended for accessing phone books stored on SIM cards, typically the SM phone book. Qt Extended provides its own mechanisms for managing phone books stored within the phone memory.

//////////////////////////////////////////////////////////////////////////Mobile termination errors (3GPP TS 27.007, section 9)/////////////////////////////////////////////////////////////////
Command Description
AT+CMEE Report mobile termination error
Commands for packet domain, GPRS (3GPP TS 27.007, section 10)
Command Description
AT+CGDCONT  Define PDP context
AT+CGATT  PS attach or detach
AT+CGREG  GPRS network registration status
+CGREG  Unsolicited result code for GPRS network registration status
AT+CGSMS  Select service for MO SMS messages
ATD*99*...  Request packet domain service

///////////////////////////////////////////////////////////////////////////////////SMS commands (3GPP TS 27.005)//////////////////////////////////////////////////////////////////////////////////////
Command Description
AT+CPMS Preferred message storage
AT+CMGF Message format (we use format 0: PDU)
AT+CSCA Service centre address
AT+CSCB Select cell broadcast message types
AT+CNMI New message indications to TE
AT+CMGL List messages
AT+CMGR Read message
AT+CMGS Send message
AT+CMGD Delete message
AT+CMMS More messages to send
+CMTI Notification of SMS message delivery
+CMT  Notification of a directly delievered SMS message
+CDSI Notification of an SMS status report message
+CBM  Notification of a directly delivered cell broadcast message
It is assumed that incoming SMS messages are stored in a temporary storage area on the device and that Qt Extended will retrieve the messages using the AT+CMGL and AT+CMGR commands.

///////////////////////////////////////////////////////////////////////////////////////Multiplexing commands (3GPP TS 07.10)//////////////////////////////////////////////////////////////////
Qt Extended expects to use 3GPP TS 07.10 multiplexing to establish multiple communications paths with the modem. The modem needs to support the AT+CMUX command plus the basic packet mode in 3GPP TS 07.10. If the modem supports some other form of multiplexing, then it is necessary to implement a multiplexer plug-in.

Other commands (3GPP TS 27.007, Appendix C)
Command Description
AT+FCLASS Select mode
AT+VGR  Receive gain selection
AT+VGT  Transmit gain selection
AT+VTS  DTMF and tone generation

  * /
  */
