#include <Arduino.h>
#include <ArxSmartPtr.h>

/*
Do not define a structure unless the type has all of the following characteristics:
1. It logically represents a single value, similar to primitive types (integer, double, and so on).
2. It has an instance size smaller than 16 bytes.
3. It is immutable.
4. It will not have to be boxed frequently.

Source: https://stackoverflow.com/questions/85553/when-should-i-use-a-struct-instead-of-a-class
*/

using namespace std;

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

shared_ptr<sensor1> s1(nullptr);
shared_ptr<sensor2> s2(nullptr);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  char name1[16] = "Sensor 1";
  strcpy(s1->label, name1);
  char name2[16] = "Sensor 2";
  strcpy(s1->label, name2);
}

void plus(float &x) {
  x += x;
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("Struct Program");
  int *p_data1;
  float *p_data2;

  s1->data = 5;
  s2->data = 8.2;

  p_data1 = &s1->data;
  p_data2 = &s2->data;

  plus(s2->data);

  Serial.println(s1->label);
  Serial.println(s1->data);
  Serial.println(s2->label);
  Serial.println(*p_data2);
  Serial.print("0x");
  Serial.print((long)&(s1->label), HEX);
  Serial.print(", ");
  Serial.print("0x");
  Serial.print((long)&(p_data1), HEX);
  Serial.print(", ");
  Serial.print("0x");
  Serial.print((long)&(s2->label), HEX);
  Serial.print(", ");
  Serial.print("0x");
  Serial.println((long)&(p_data2), HEX);
}