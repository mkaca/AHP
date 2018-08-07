
#include <Sort.h>
#include <math.h>

/* NOTE: NEED TO MANUALLY CHANGE STATIC SORT CLASS LENGTH IN ORDER TO ALLOW ARRAY TO BE 
 *  RETURNED FROM .sortObject()
 *  
 */

  float arrayRandom[] = {40,6430,40,02,20,043,3.780};  //current length = 7
  int lengthArray = sizeof(arrayRandom)/sizeof(*arrayRandom);
  Sort sortObject = Sort(); 

void setup() {
  Serial.begin(9600);
  sortObject.test();
  delay(40);
  float* arrayFlex;
  arrayFlex = sortObject.sortArray(arrayRandom,lengthArray);
  delay(50);
  for (int i = 0; i < lengthArray; i++){
      Serial.println(arrayFlex[i]);
  }
}

void loop() {
  
  delay(5000);
  exit(0);

}
