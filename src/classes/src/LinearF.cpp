#include "../LinearF.h"

LinearF::LinearF(float slope, float yinter):m_slope(slope),m_yinter(yinter),m_isVertical(false),m_isLimited(false)
{

}

LinearF::LinearF(float xa, float xb, float ya, float yb)
{
    m_slope=0;
    m_yinter=0;
    m_isVertical=false;
    m_isLimited=false;
    m_lowLimit=0;
    m_highLimit=0;
    if(xb>xa)
    {
        m_slope=(yb-ya)/(xb-xa);
        m_yinter=ya-(m_slope*xa);
    }
    else if(xb<xa)
    {
        m_slope=(ya-yb)/(xa-xb);
        m_yinter=yb-(m_slope*xb);
    }
    else if(xb=xb)
    {
        m_slope=std::numeric_limits<float>::max();
        m_yinter=xb;
        m_isVertical=true;
    }

}

LinearF::LinearF(float xa, float ya, float slope)
{
    m_slope=0;
    m_yinter=0;
    m_isVertical=false;
    m_isLimited=false;
    m_lowLimit=0;
    m_highLimit=0;
    if(slope<999999)
    {
        m_slope=slope;
        m_yinter=ya-(m_slope*xa);
    }
    else
    {
        m_slope=std::numeric_limits<float>::max();
        m_yinter=xa;
        m_isVertical=true;
    }

}

LinearF::LinearF(float xa, bool vertical)
{
    m_slope=std::numeric_limits<float>::max();
    m_yinter=xa;
    m_isVertical=true;
    m_isLimited=false;
    m_lowLimit=0;
    m_highLimit=0;
}

LinearF::LinearF()
{
    m_slope=0;
    m_yinter=0;
    m_isVertical=false;
    m_isLimited=false;
    m_lowLimit=0;
    m_highLimit=0;
}

LinearF::~LinearF()
{

}


void LinearF::setSlope (float slope)
{
    if(slope<1000000)
    {
        m_slope=slope;
        m_isVertical=false;
    }
    else
    {
        m_slope=std::numeric_limits<float>::max();
        m_isVertical=true;
        m_yinter=0;
    }
}

void LinearF::setYinter (float yinter)
{
    m_yinter=yinter;
}

void LinearF::setAll (float slope, float yinter)
{
    if(slope<1000000)
    {
        m_slope=slope;
        m_yinter=yinter;
        m_isVertical=false;
    }
    else
    {
        m_slope=std::numeric_limits<float>::max();
        m_yinter=yinter;
        m_isVertical=true;
    }
}

float LinearF::getSlope() const
{
        return m_slope;
}

float LinearF::getYinter() const
{
    return m_yinter;
}

float LinearF::findy(float x)
{
    if (!m_isVertical)
    {
        return (x*m_slope) + m_yinter;
    }
    else
    {
        return m_yinter;
    }
}

float LinearF::getAngle() const
{
    if(m_slope==0)
    {
        return 0;
    }
    else if(m_isVertical)
    {
        return PI/2;
    }
    else if(m_slope>0)
    {
        float tangeante;
        tangeante=(m_slope+m_yinter);
        return atan(tangeante);
    }
    else if(m_slope<0)
    {
        float tangeante;
        tangeante=(m_slope+m_yinter);
        return atan(tangeante)+2*PI;
    }
    else
    {
        std::cout<<"Problème de détermination d'angle dans la classe LinearF, à la méthode getAngle() const."<<std::endl;
        exit(EXIT_FAILURE);
    }
}

float LinearF::getRAngle(LinearF* base) const
{
    float abase=base->getAngle();
    float athis=this->getAngle();
    angleA=abase-athis;
    angleB=(abase+(2*Pi))-athis;
    if(angleA>angleB)
    {
        return angleB;
    }
    else
    {
        return angleA;
    }

}

void LinearF::orthoOnPoint (float xa, float ya, bool direction)
{
    if(!direction)
    {
        m_slope=0;
        m_yinter=ya;
        m_isVertical=false;
    }
    else
    {
        m_slope=std::numeric_limits<float>::max();
        m_isVertical=true;
        m_yinter=xa;
    }
}

void LinearF::perpendicularOnPoint (float xa, float ya, LinearF* base)
{
    if(base->getIsVertical())
    {
        m_isVertical=false;
        m_slope=0;
        m_yinter=ya;
    }
    else if(base->getSlope()==0)
    {
        m_isVertical=true;
        m_slope=std::numeric_limits<float>::max();
        m_yinter=xa;
    }
    else
    {
        m_slope=(-1)/(base->getSlope());
        m_yinter=ya-(m_slope*xa);
        m_isVertical=false;
    }
}

void LinearF::parallelOnPoint (float xa, float ya, LinearF* base)
{
    if(base->getIsVertical())
    {
        m_isVertical=true;
        m_slope=std::numeric_limits<float>::max();
        m_yinter=xa;
    }
    else
    {
        m_slope=base->getSlope();
        m_yinter=ya-(m_slope*xa);
        m_isVertical=false;
    }
}

void LinearF::parallelWithDistance (LinearF* base, float distance)
{
    if(base->getIsVertical)
    {
        m_isVertical=true;
        m_slope=std::numeric_limits<float>::max();
        m_yinter=base->getYinter + distance;
    }
    else if(base->getSlope==0)
    {
        m_isVertical=false;
        m_slope=0;
        m_yinter=base->getYinter + distance;
    }
    else
    {
        float x(0),y(0);
        slope=(-1)/(base->getSlope());
        yinter=base->getYinter();
    }
    ////////A FINIR//////////////////
}

void LinearF::withAngleOnPoint (float xa, float ya, float alpha)
{

}

bool LinearF::getIsVertical () const
{

}

bool LinearF::getIsLimited () const
{

}

float LinearF::getCloserDistanceFromPoint (float xa, float ya) const
{

}
