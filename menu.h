#ifndef MENU_H
#define MENU_H

#include "bouton.h"
#include <allegro.h>

class menu
{
    public:
        menu(const char*[],int);
        menu(const menu&);
        ~menu();
        menu&operator=(const menu&);
        void affiche();
        int selection();
    private:
        bouton **tab;
        int nb;
};


#endif // MENU_H
