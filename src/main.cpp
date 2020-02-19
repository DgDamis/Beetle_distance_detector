#include <Arduino.h>
#include "config.cpp"

// Include the library:
#include <SharpIR.h>
// Create variable to store the distance:
int distance_cm_1080;
int distance_cm_100500;
/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/
#ifdef SHARP_GP2Y0A21YK0F
    SharpIR IRsensor_close(SharpIR::GP2Y0A21YK0F, GP2Y0A21YK0F_pin);
#endif
#ifdef SHARP_GP2Y0A710K0F
    //! Does not work
     //! SharpIR IRsensor_far(SharpIR::GP2Y0A710K0F, GP2Y0A710K0F_pin);
#endif

uint64_t readings_timer = 0;


void setup() {
  Serial.begin(serial_speed);
  #ifdef DEBUG_MODE
    delay(2000);
    debug_init();
  #endif
  #ifdef SHARP_GP2Y0A21YK0F
    pinMode(GP2Y0A21YK0F_pin,INPUT);
    if(analogRead(GP2Y0A21YK0F_pin) > 200){
      Serial.println(F("ERROR - Sensor GP2Y0A21YK0F is not connected! Check the connection or change the pin in config!"));
    }
  #endif
  #ifdef SHARP_GP2Y0A710K0F
    pinMode(GP2Y0A710K0F_pin,INPUT);
    if(analogRead(GP2Y0A710K0F_pin) > 200){
      Serial.println(F("ERROR - Sensor GP2Y0A710K0F is not connected! Check the connection or change the pin in config!"));
    }
  #endif
}

void loop() {
  // Get a distance measurement and store it as distance_cm:
  #ifdef SHARP_GP2Y0A21YK0F
    distance_cm_1080 = IRsensor_close.getDistance();
  #endif
  #ifdef SHARP_GP2Y0A710K0F
    distance_cm_100500 = IRsensor_far.getDistance();
  #endif
  if(readings_timer + send_every_seconds < millis()){
    #ifdef DEBUG_MODE
      debug_print();
    #else
      print();
    #endif
    readings_timer = millis();
  }
}

void debug_init() {
    #ifdef SHARP_GP2Y0A21YK0F
      Serial.println(F("Sharp GP2Y0A21YK0F properly initialiazed."));
    #endif
    #ifdef SHARP_GP2Y0A710K0F
      Serial.println(F("Sharp GP2Y0A710K0F properly initialiazed."));
    #endif
    #ifndef SHARP_GP2Y0A21YK0F
      #ifndef SHARP_GP2Y0A21YK0F
        #warning You need to specify the used sensors!
        Serial.println(F("No sensor initialiazed! Check the code configuration!"));
      #endif
    #endif
}

void debug_print(){
  // Print the measured distance to the serial monitor:
  #ifdef SHARP_GP2Y0A21YK0F
    Serial.print("GP2Y0A21YK0F - Mean distance: ");
    Serial.print(distance_cm_1080);
    Serial.println(" cm");
    #ifdef DEBUG_PRINT_PIN_SENSE
      Serial.print(F("Voltage measured on pin "));
      Serial.print(GP2Y0A21YK0F_pin);
      Serial.print(F(": "));
      Serial.println(analogRead(GP2Y0A21YK0F_pin));
    #endif
  #endif
  #ifdef SHARP_GP2Y0A710K0F
    Serial.print("GP2Y0A710K0F - Mean distance: ");
    Serial.print(distance_cm_100500);
    Serial.println(" cm");
    #ifdef DEBUG_PRINT_PIN_SENSE
      Serial.print(F("Voltage measured on pin "));
      Serial.print(GP2Y0A710K0F_pin);
      Serial.print(F(": "));
      Serial.println(analogRead(GP2Y0A710K0F_pin));
    #endif
  #endif
}

void print(){
  #ifdef SHARP_GP2Y0A21YK0F
    if(distance_cm_1080 != 0){
      #ifdef Serial_as_serial
        Serial.print(distance_cm_1080);
        Serial.print(";");
      #endif
      #ifdef Serial_as_rows
        Serial.println(distance_cm_1080);
      #endif
    }
  #endif
  #ifdef SHARP_GP2Y0A710K0F
    else {
      #ifdef Serial_as_serial
        Serial.print(distance_cm_100500);
        Serial.print(";");
      #endif
      #ifdef Serial_as_rows
        Serial.println(distance_cm_100500);
      #endif
    }
  #endif
}
