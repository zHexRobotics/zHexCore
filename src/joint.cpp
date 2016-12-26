#include "joint.h"

Joint::Joint(Servo *_servo)
{
    servo = _servo;
    angle = 0;
    minAngle = 0;
    maxAngle = 180;
}


inline void Joint::setMinAngle(uint8_t value)
{
    minAngle = value;
}


inline void Joint::setMaxAngle(uint8_t value)
{
    maxAngle = value;
}


bool Joint::setAngle(uint8_t value)
{
    //if ((value >= 0) && (value <= 180) && (value >= minAngle) && (value <= maxAngle))
    {
        angle = value;
        servo->write(angle);
        return true;
    }
    //else
    {
        return false;
    }
}


inline uint8_t Joint::getMinAngle()
{
    return minAngle;
}


inline uint8_t Joint::getMaxAngle()
{
    return maxAngle;
}


inline uint8_t Joint::getAngle()
{
    return angle;
}
