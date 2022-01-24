#include <Arduino.h>

/*
Do not define a structure unless the type has all of the following characteristics:
1. It logically represents a single value, similar to primitive types (integer, double, and so on).
2. It has an instance size smaller than 16 bytes.
3. It is immutable.
4. It will not have to be boxed frequently.

Source: https://stackoverflow.com/questions/85553/when-should-i-use-a-struct-instead-of-a-class
*/

struct sensor1 {
  // data
  char label[16];
  int data;
};

struct sensor2 {
  // data
  char label[16];
  float data;
};

struct sensor1* temp1 = NULL;
struct sensor2* temp2 = NULL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  temp1 = (struct sensor1*) malloc(sizeof(struct sensor1));
  temp2 = (struct sensor2*) malloc(sizeof(struct sensor2));

  char name1[16] = "Sensor 1";
  strcpy(temp1->label, name1);
  char name2[16] = "Sensor 2";
  strcpy(temp2->label, name2);
}

void plus(float &x) {
  x *= 2;
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("Struct Program");
  temp1->data = 5;
  temp2->data = 8.2;

  plus(temp2->data);

  Serial.println(temp1->label);
  Serial.println(temp1->data);
  Serial.println("");
  Serial.println(temp2->label);
  Serial.println(temp2->data);
  Serial.println("");
  Serial.print("0x");
  Serial.print((long)&(temp1->label), HEX);
  Serial.print(", ");
  Serial.print("0x");
  Serial.print((long)&(temp1->data), HEX);
  Serial.print(", ");
  Serial.print("0x");
  Serial.print((long)&(temp2->label), HEX);
  Serial.print(", ");
  Serial.print("0x");
  Serial.println((long)&(temp2->data), HEX);
  Serial.println("");

  delay(1000);
}