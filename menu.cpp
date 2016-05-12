#include "menu.h"
#include <string.h>

menu::menu(const char* ptab[],int pnb)
{
    float pasy,hint,xint,lmax,hmax;
    int taillemax,ind;
    nb=pnb;
    taillemax = text_length(font,ptab[0]);
    for(int i=0;i<nb;i++)
    {
        if(text_length(font,ptab[i])>taillemax)
        {
            taillemax = text_length(font,ptab[i]);
            ind = i;
        }
    }
    lmax = taillemax + 20;
    hmax = text_height(font) + 10;
    hint = taillemax + 10;
    xint = 20 + hint/2;
    pasy = (SCREEN_H)/(nb+1);
    tab = new bouton*[nb];
    for(int i=0;i<nb;i++)
    {
        tab[i] = new bouton(xint,(i+1)*pasy,ptab[i]);
        tab[i]->rectangle::init(lmax, hmax);
    }
}

menu::menu(const menu &S)
{
    nb=S.nb;
    tab=new bouton*[nb];
    for(int i=0;i<nb;i++)
        tab[i]=new bouton(*(S.tab[i]));
}

menu::~menu()
{
    for(int i=0;i<nb;i++)
        delete tab[i];
    delete tab;
}

void menu::affiche()
{
    for(int i=0;i<nb;i++)
        tab[i]->affiche();
}

menu& menu::operator=(const menu &S)
{
    if(this!=&S)
    {
        for(int i=0;i<nb;i++)
            delete tab[i];
        delete tab;
        nb=S.nb;
        tab=new bouton*[nb];
        for(int i=0;i<nb;i++)
            tab[i]=new bouton(*(S.tab[i]));
    }
    return (*this);
}

int menu::selection()
{
    int i;
    for(i=0;i<nb;i++)
    {
        if(tab[i]->selection()==1)
            return i+1;
    }
    return 0;
}
