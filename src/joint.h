#include <Servo.h>
#include <stdint.h>

#ifndef JOINT_H
#define JOINT_H

class Joint
{
private:
    Servo* servo;
    uint8_t minAngle;
    uint8_t maxAngle;
    uint8_t angle;
public:
    Joint(Servo *_servo);
    inline void setMinAngle(uint8_t value);
    inline void setMaxAngle(uint8_t value);
    bool setAngle(uint8_t value);
    inline uint8_t getMinAngle();
    inline uint8_t getMaxAngle();
    inline uint8_t getAngle();
};

#endif
