int x;
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
  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  // Initialize the RFM69HCW:
  x = 0;
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW

  // Turn on encryption if desired:

  if (ENCRYPT)
    radio.encrypt(ENCRYPTKEY);
}

void loop()
{
 if ((digitalRead(8)) == 1) || (digitalRead(7))) {
  
  if (digitalRead(8) == 1) {
    x = 1;                    //y slave will be from 0 to 6, x slave will be from -3 to 3
  }
  if (digitalRead(7) == 1) {  //add digitalreads as needed
    x = 2;
  }
  sendx();
  
 }
}  

void sendx() {
  x = x + 30; //only activate this code if this slave is the x slave
  static int sendlength = 1;
  radio.send(TONODEID, &x, sendlength);
}


