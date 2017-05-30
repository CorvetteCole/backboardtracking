int x, prevx;
void sendx(void);
#include <RFM69.h>
#include <RFM69registers.h>
#include <RFM69_ATC.h> 
// Addresses for this node. CHANGE THESE FOR EACH NODE!

#define NETWORKID     0   // Must be the same for all nodes
#define MYNODEID      3   // My node ID
#define TONODEID      1   // Destination node ID (1 is the master arduino)

// RFM69 frequency, uncomment the frequency of your module:

//#define FREQUENCY   RF69_433MHZ
#define FREQUENCY     RF69_915MHZ

// AES encryption (or not):

#define ENCRYPT       false // Set to "true" to use encryption
#define ENCRYPTKEY    "TOPSECRETPASSWRD" // Use the same 16-byte key on all nodes

// Use ACKnowledge when sending messages (or not):

#define USEACK        false // Request ACKs or not

// Create a library object for our RFM69HCW module:

RFM69 radio;

void setup()
{
  // Open a serial port so we can send keystrokes to the module:

  Serial.begin(9600);
  Serial.print("Node ");
  Serial.print(MYNODEID,DEC);
  Serial.println(" ready");  
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  // Initialize the RFM69HCW:
  x = 0;
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW

  // Turn on encryption if desired:

  if (ENCRYPT)
    radio.encrypt(ENCRYPTKEY);
}

void loop() {
  if (digitalRead(3) == 1) {
    x = 0;
    sendx();
  }
  if (digitalRead(4) == 1) {
    x = 4;
    sendx();
  }
  if (digitalRead(5) == 1) {
    x = 3;
    sendx();
  }
  if (digitalRead(6) == 1) {
    x = 2;
    sendx();
  }
  if (digitalRead(7) == 1) {
    x = 1;
    sendx();
  }
  //if (digitalRead(8) == 1) {
  //  x = 5;
  //  sendx();                   
  //}
  //if (digitalRead(9) == 1) {  
  //  x = 6;
  //  sendx();
  //}  
}  

void sendx() {
  //if (prevx != x) {
  Serial.println(x);
  static int sendlength = 1;
  radio.send(TONODEID, &x, sendlength);
  //}
  prevx = x;
}



