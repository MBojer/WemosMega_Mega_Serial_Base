#include <Arduino.h>


// ------------------------------ MB_Queue() ------------------------------
#include <MB_Queue.h>

#define Max_Queue_Size 15
MB_Queue Serial_Queue(Max_Queue_Size);


// ############################## Serial_Manager() ##############################
void Serial_Manager() {

  if (Serial_Queue.Queue_Is_Empthy == false) {

    Serial.println(Serial_Queue.Pop());
    Serial.flush();
  }

} // Serial_Manager()


// ############################## serialEvent3() ##############################
void serialEvent3() {
  while (Serial3.available()) {
      String Serial_String = Serial3.readStringUntil('\n');
      Serial_Queue.Push(Serial_String);
  }
}


// ############################## setup() ##############################
void setup() {

    // ------------------------------ Serial ------------------------------
    Serial.begin(250000);
    Serial.println("Mega - Booting");

    // ------------------------------ Serial 3 - Wemos  ------------------------------
    Serial3.setTimeout(50); // Might need adjustment
    Serial3.begin(500000); // To Wemos

    // ------------------------------ Boot done ------------------------------
    Serial.println("Mega - Boot done");

} // setup()



// ############################## loop() ##############################
void loop() {

  Serial_Manager();

} // loop()
