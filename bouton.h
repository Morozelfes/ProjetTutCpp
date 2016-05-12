#ifndef BOUTON_H
#define BOUTON_H

#include "rect.h"
#include <iostream>
#include <allegro.h>

using namespace std;

class bouton : public rectangle
{
    public:
        bouton();
        bouton(float, float, char*);
        ~bouton();
        bouton(const bouton&);
        bouton& operator=(const bouton&);
        void init(char*);
        void affiche();
        int selection();

        string Getch() { return ch; }
        void Setch(string val) { ch = val; }
        int Getnb() { return nb; }
        void Setnb(int val) { nb = val; }
        float Getxch() { return xch; }
        void Setxch(float val) { xch = val; }
        float Getych() { return ych; }
        void Setych(float val) { ych = val; }
    protected:
        string ch;
        int nb;
        float xch;
        float ych;
};

#endif // BOUTON_H
