#ifndef LINEARF_H
#define LINEARF_H

#include <limits>
#include <math.h>
#include <iostream>
#include <stdlib.h>

#define PI 3.14159265

class LinearF
{
    public:
    LinearF(float slope, float yint);
    LinearF(float xa, float xb, float ya, float yb);
    LinearF(float xa, float ya, float slope);
    LinearF(float xa, bool vertical);
    LinearF();
    ~LinearF();

    void setSlope (float slope);
    void setYinter (float yinter);
    void setAll (float slope, float yinter);
    float getSlope() const;
    float getYinter() const;
    float findy(float x);
    float getAngle() const;
    float getRAngle(LinearF* base) const;
    void orthoOnPoint (float xa, float ya, bool direction);
    void perpendicularOnPoint (float xa, float ya, LinearF* base);
    void parallelOnPoint (float xa, float ya, LinearF* base);
    void parallelWithDistance (LinearF* base, float distance);
    void withAngleOnPoint (float xa, float ya, float alpha);
    bool getIsVertical () const;
    bool getIsLimited () const;
    float getCloserDistanceFromPoint (float xa, float ya) const;


    private:

    float m_slope;
    float m_yinter;
    float m_lowLimit;
    float m_highLimit;
    bool m_isVertical;
    bool m_isLimited;
};


#endif
