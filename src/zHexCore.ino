#include "joint.h"
#include "leg.h"

#define SERVOS_COUNT 18
#define LEGS_COUNT 6

const int servoPins[SERVOS_COUNT] = {/*a*/ 25,26,31,32,37,38, /*b*/ 27,28,33,34,39,40, /*g*/ 23,24,29,30,35,36};

Servo servos[SERVOS_COUNT];
Joint *joints[SERVOS_COUNT];
Leg *legs[LEGS_COUNT];

void setup(void)
{
    for (uint8_t i = 0; i < SERVOS_COUNT; i++)
    {
        servos[i].attach(servoPins[i]);
        joints[i] = new Joint(&servos[i]);
    }
    for (uint8_t i = 0; i < LEGS_COUNT; i++)
    {
        legs[i] = new Leg(joints[LEGS_COUNT * 2 + i], joints[LEGS_COUNT * 0 + i], joints[LEGS_COUNT * 1 + i]);
        legs[i]->setGeometry((i % 2 == 0) ? LEG_RIGHT : LEG_LEFT, 40, 85, 115);
    }

    Serial.begin(57600);
}


void loop(void)
{
    while(Serial.available() >= 4)
    {
      int n = Serial.parseInt();
      int x = Serial.parseInt();
      int y = Serial.parseInt();
      int z = Serial.parseInt();
      Serial.print(n);
      Serial.print(" | ");
      Serial.print(x);
      Serial.print(" ");
      Serial.print(y);
      Serial.print(" ");
      Serial.print(z);
      Serial.print(" |");
      legs[n]->reach(x, y, z);
      Serial.println();
    }
}
