#include "interface.h"
#include <iostream>

using namespace std;

point::point():Tf()
{
    x=y=0;
}

point::point(float px, float py):Tf()
{
    x=px;
    y=py;
}

point::~point()
{}

point::point(const point& S)
{
    x=S.x;
    y=S.y;
}

point& point::operator=(const point& S)
{
    x=S.x;
    y=S.y;
    return *this;
}

void point::affiche()
{
    cout << x << "\t" << y << endl;
    putpixel(page,300,500,makecol(255,255,255));
}

void point::init(float px, float py)
{
    x=px;
    y=py;
}
