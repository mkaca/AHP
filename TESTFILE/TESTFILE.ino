#include <Sort.h>

  //float arrayRandom[] = {0,32,264,3.5};
  float arrayRandom[] = {0,6430,40,03,0,043,3.780};
  int lengthArray = sizeof(arrayRandom)/sizeof(*arrayRandom);
  Sort sortObject = Sort(); 
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  sortObject.test();
  delay(100);
  sortObject.sortArray(arrayRandom,lengthArray);
  delay(1000);

}