#include "rect.h"
#include <iostream>

using namespace std;

rectangle::rectangle()
{
    x=y=100;
    l=30;
    h=20;
    ce=ci=12;
    maj();
}

rectangle::rectangle(float px, float py, float pl, float ph, int pce, int pci):point(px,py)
{
    l=pl;
    h=ph;
    ce=pce;
    ci=pci;
    maj();
}

rectangle::~rectangle()
{}

rectangle::rectangle(const rectangle& S):point(S)
{
    l=S.l;
    h=S.h;
    ce=S.ce;
    ci=S.ci;
    maj();
}

rectangle& rectangle::operator=(const rectangle& S)
{
    point *mg=this; const point *md=&S;
    *mg=*md;
    l=S.l;
    h=S.h;
    ce=S.ce;
    ci=S.ci;
    maj();
    return *this;
}

void rectangle::maj()
{
    x1=x-l/2;
    y1=y-h/2;
    x2=x+l/2;
    y2=y+h/2;
}

void rectangle::affiche()
{
    point::affiche();
    cout << "largeur =" << l << "hauteur =" << h << endl;
    rectfill(page,x1,y1,x2,y2,makecol(0,128,255));
}

void rectangle::init(float pl, float ph)
{
    l=pl;
    h=ph;
    maj();
}

int rectangle::select()
{

    if ((mouse_x>=x1) && (mouse_x<=x2) && (mouse_y>=y1) && (mouse_y<=y2)) return 1;

}
