#ifndef RECT_H
#define RECT_H

#include "interface.h"
#include <allegro.h>

class rectangle : public point
{
    public:
        rectangle();
        rectangle(float,float,float,float,int=12,int=24);
        //rectangle(point,point)
        ~rectangle();
        rectangle(const rectangle& other);
        rectangle& operator=(const rectangle& other);
        void affiche();
        void init(float, float);

        float Getl() { return l; }
        void Setl(float val) { l = val; }
        float Geth() { return h; }
        void Seth(float val) { h = val; }
        int select();
    protected:
        float l;
        float h;
        float ci, ce;
        float x1, y1, x2, y2;
        void maj();
    private:
};

#endif // RECT_H
