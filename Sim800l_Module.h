
#include <string.h>
//volatile char response[20]; // Buffer for receiving response from the SIM800 module
volatile char command[20];

// Initialize the serial port for communication with the SIM800 module
void initSerial()
{
  TMOD = 0x20; // Use Timer 1 in Mode 2 (8_bit_auto-reload)
	TH1 = 0xFD;
  SCON = 0x50; // Enable serial port with 8_bit_data and variable baud rate
	TR1 = 1; // Start timer 1

}


// Send a character to the SIM800 module
void sendChar(char c_send)
{
  SBUF = c_send; // Load the character to be sent into the serial buffer
  while(!TI); // Wait for the transmission to complete
  TI = 0; // Clear the transmission flag
}

// Send a null-terminated string to the SIM800 module
void sendString(char *str_Send)
{
  unsigned char i;
  for(i = 0; str_Send[i] != '\0'; i++) {
       sendChar(str_Send[i]);
   }
   //sendChar('\r');
   //sendChar('\n');
}


void sim_delay()
{
    unsigned int i,j;
    for(i=0;i<40000;i++);
	{
		for(j=0;j<1275;j++);
	}
}
// Receive a character from the SIM800 module
/*
char receiveCharacter()
{
  while(RI==0); // Wait for a character to be received
  RI = 0; // Clear the receive flag
  return SBUF; // Return the received character
}

// Receive a string of specified length from the SIM800 module
void receive_GSM(char *str_Receive)
{
  char c_Receive;
  unsigned int i;
i=0;
  do {
    c_Receive = receiveCharacter(); // Receive a character
    str_Receive[i++] = c_Receive; // Store the received character
  } while(c_Receive != '\n' || c_Receive != '\r' || c_Receive == '>');
str_Receive[i] = '\0'; // Terminate the string with null character
}
*/