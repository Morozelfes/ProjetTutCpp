#ifndef INTERFACE_H
#define INTERFACE_H
#include "Tf.h"
#include <allegro.h>
extern BITMAP*page;

class point : public Tf
{
    public:
        point();
        point(float,float);
        ~point();
        point(const point&);
        point& operator=(const point&);
        void affiche();
        void init(float,float);

        float Getx() { return x; }
        void Setx(float val) { x = val; }
        float Gety() { return y; }
        void Sety(float val) { y = val; }
    protected:
        float x;
        float y;
    private:
};

#endif // INTERFACE_H
