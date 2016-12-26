#include <Math.h>
#include "joint.h"

#ifndef LEG_H
#define LEG_H

#define LEG_LEFT  0
#define LEG_RIGHT 1

class Leg
{
private:
    Joint *coxa;
    Joint *femur;
    Joint *tibia;

    int16_t x;
    int16_t y;
    int16_t z;

    uint8_t side;

    uint8_t lengthCoxa;
    uint8_t lengthFemur;
    uint8_t lengthTibia;

private:
    double calcL(double z_offset, double y);
    double calcAlpha(double L, double z_offset);
    double calcBeta(double L);
    double calcGamma(double x, double y);

public:
    Leg(Joint *_coxa, Joint *_femur, Joint *_tibia);
    void setGeometry(uint8_t _side, uint8_t _lengthCoxa, uint8_t _lenngthFemur, uint8_t _lengthTibia);
    bool reach(int16_t x, int16_t y, int16_t z);
    void setXLimits(int16_t minValue, int16_t maxValue);
    void setYLimits(int16_t minValue, int16_t maxValue);
    void setZLimits(int16_t minValue, int16_t maxValue);
    /*
    int16_t getMinX();
    int16_t getMaxX();
    int16_t getMinY();
    int16_t getMaxY();
    int16_t getMinZ();
    int16_t getMaxZ();
    */
    inline uint8_t getSide();
    inline int16_t getX();
    inline int16_t getY();
    inline int16_t getZ();
    inline Joint* getCoxa();
    inline Joint* getFemur();
    inline Joint* getTibia();
};

#endif
