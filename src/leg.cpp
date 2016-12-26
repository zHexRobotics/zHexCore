#include "leg.h"
#include <HardwareSerial.h>

double Leg::calcL(double z_offset, double y)
{
  return sqrt(z_offset * z_offset + (y - lengthCoxa) * (y - lengthCoxa));
}


double Leg::calcAlpha(double L, double z_offset)
{
  double alpha_1 = acos(z_offset / L);
  double alpha_2 = acos((lengthTibia * lengthTibia - lengthFemur * lengthFemur - L * L) / (-2.0 * lengthFemur * L));
  return (alpha_1 + alpha_2) * 180.0 / 3.14;
}


double Leg::calcBeta(double L)
{
  return acos((L * L - lengthTibia * lengthTibia - lengthFemur * lengthFemur) / (-2.0 * lengthTibia * lengthFemur)) * 180.0 / 3.14;
}


double Leg::calcGamma(double x, double y)
{
  return atan(x / y) * 180.0 / 3.14;
}


Leg::Leg(Joint *_coxa, Joint *_femur, Joint *_tibia)
{
    coxa  = _coxa;
    femur = _femur;
    tibia = _tibia;
}


void Leg::setGeometry(uint8_t _side, uint8_t _lengthCoxa, uint8_t _lenngthFemur, uint8_t _lengthTibia)
{
    side = _side;
    lengthCoxa  = _lengthCoxa;
    lengthFemur = _lenngthFemur;
    lengthTibia = _lengthTibia;
}


bool Leg::reach(int16_t x, int16_t y, int16_t z)
{
    x = x;
    y = y;
    z = z;
    double L = calcL(z, y);
    int alpha = calcAlpha(L, z);
    int beta =  calcBeta(L);
    int gamma = calcGamma(x, y);
    Serial.print(alpha);
    Serial.print(" ");
    Serial.print(beta);
    Serial.print(" ");
    Serial.print(gamma);
    Serial.print(" |");
    if ((!isnan(alpha)) && (!isnan(beta)) && (!isnan(gamma)))
    {
        if (side == LEG_LEFT)
        {
            gamma = (90  - gamma);
            alpha = (0   + alpha);
            beta =  (180 - beta);
        }
        else
        {
            gamma = (90  + gamma);
            alpha = (180 - alpha);
            beta =  (0   + beta);
        }
        coxa ->setAngle(gamma);
        femur->setAngle(alpha);
        tibia->setAngle(beta);
        return true;
    }
    else
    {
        return false;
    }
}

/*
void Leg::setXLimits(int16_t minValue, int16_t maxValue);
void Leg::setYLimits(int16_t minValue, int16_t maxValue);
void Leg::setZLimits(int16_t minValue, int16_t maxValue);
int16_t Leg::getMinX();
int16_t Leg::getMaxX();
int16_t Leg::getMinY();
int16_t Leg::getMaxY();
int16_t Leg::getMinZ();
int16_t Leg::getMaxZ();
*/

inline uint8_t Leg::getSide()
{
    return side;
}


inline int16_t Leg::getX()
{
    return x;
}


inline int16_t Leg::getY()
{
    return y;
}


inline int16_t Leg::getZ()
{
    return z;
}

inline Joint* Leg::getCoxa()
{
    return coxa;
}


inline Joint* Leg::getFemur()
{
        return femur;
}


inline Joint* Leg::getTibia()
{
    return tibia;
}
