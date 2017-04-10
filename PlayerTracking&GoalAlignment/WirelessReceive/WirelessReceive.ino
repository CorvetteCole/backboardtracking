#include <RFM69.h>
#include <SPI.h>

#define NETWORKID     0   // Must be the same for all nodes
#define MYNODEID      1   // My node ID
#define TONODEID      2   // Destination node ID

// RFM69 frequency, uncomment the frequency of your module:

//#define FREQUENCY   RF69_433MHZ
#define FREQUENCY     RF69_915MHZ

// AES encryption (or not):

#define ENCRYPT       false // Set to "true" to use encryption
#define ENCRYPTKEY    "TOPSECRETPASSWRD" // Use the same 16-byte key on all nodes

// Use ACKnowledge when sending messages (or not):

#define USEACK        true // Request ACKs or not

// Create a library object for our RFM69HCW module:

RFM69 radio;

void setup()
{
  // Open a serial port so we can send keystrokes to the module:

  Serial.begin(9600);

  // Initialize the RFM69HCW:

  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW
 
}

void loop()
{

  if (radio.receiveDone()) // Got one!
  {
    // The actual message is contained in the DATA array,
    // and is DATALEN bytes in size:
    // NOTE: each element is an int (2 bytes), so need to recast the data as such...
    int *pData = (int*)radio.DATA;

    for (byte i = 0; i < radio.DATALEN; i+=2)
      Serial.print(*pData++);

    Serial.print("\n" );
  }
}
 
