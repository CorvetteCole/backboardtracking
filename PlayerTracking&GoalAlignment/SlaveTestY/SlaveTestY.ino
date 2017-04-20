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
int input;

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
  Serial.println("y = 0, 1, 2, 3, 4, 5, 6");
}

void loop() {
while (Serial.available() == 0) {}
    input = Serial.parseInt();
    x = input;
    Serial.println(x);
    sendx();
}  

void sendx() {
  static int sendlength = 1;
  radio.send(TONODEID, &x, sendlength);
  Serial.println("Sent!");
}

