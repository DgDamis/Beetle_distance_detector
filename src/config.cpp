 #include <Arduino.h>
 //********************************************************************
    // Code configuration
    // Comment or uncomment to choose attached sensors
 //********************************************************************
//#define DEBUG_MODE            // Uncomment to get extended debugging messages via serial line
//#define DEBUG_PRINT_PIN_SENSE    // Uncomment to get additional debug info of pin measurements

// Attached devices
   // When uncommenting, uncomment sensor model number and appropriate pin
      // First device
         #define SHARP_GP2Y0A21YK0F        // Sharp GP2Y0A21YK0F analogue distance sensor - 0 to 80 cm
         int constexpr GP2Y0A21YK0F_pin = A0;
      // Second device
         //#define SHARP_GP2Y0A710K0F        // Sharp GP2Y0A710K0F analogue distance sensor - 1 to 5 m
         int constexpr GP2Y0A710K0F_pin = A1;


// Uncomment only one of the serial communication specifiers
#define Serial_as_serial    
//#define Serial_as_rows
int constexpr serial_speed = 9600;          // Set serial communication speed
int constexpr send_every_seconds = 1000;    // Set the delay for the communication

void loop();
void setup();
void debug_init();
void debug_print();
void print();