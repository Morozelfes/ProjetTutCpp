#include "bouton.h"
#include "rect.h"
#include <iostream>
#include <string.h>
#include <allegro.h>

using namespace std;

bouton::bouton():rectangle(),ch()
{
    nb=0;
    xch=x;
    ych=y;
}

bouton::bouton(float px, float py, char* pch):rectangle(),ch(pch)
{
    float lch, hch;
    x=px;
    y=py;
    nb=strlen(pch);
    lch=text_length(font,pch);        // instruction allegro
    hch=text_height(font);            // instruction allegro
    xch=x-lch/2;
    ych=y-hch/2;
    l=lch+20;
    h=hch+10;
}

bouton::~bouton()
{}

bouton::bouton(const bouton& s):rectangle(s)
{
    ch=s.ch;
    nb=s.nb;
    xch=s.xch;
    ych=s.ych;
}

bouton& bouton::operator=(const bouton& s)
{
    if(this!=&s)            //compare les adresses
    {
        rectangle *mg;
        const rectangle *md;      //cast dynamique, force l'appel a la classe mere
        mg = this;
        md = &s;
        (*mg) = (*md);
    }
    ch=s.ch;
    nb=s.nb;
    xch=s.xch;
    ych=s.ych;
    return (*this);
}

void bouton::affiche()
{
    rectangle::affiche();
    //instruction graphique d'affichage de texte au point xch, ych
    cout << "ch = " << ch << endl;
    textprintf_ex(page, font, xch, ych, makecol(255,213,0), -1, "%s", ch.c_str());
}

void bouton::init(char * tab)
{
    float lch, hch;
    ch.append(tab);     //ch=tab;
    nb=strlen(tab);
    lch=text_length(font,tab);         // instruction allegro
    hch=text_height(font);
    xch=x-lch/2;
    ych=y-hch/2;
}

int bouton::selection()
{
    if((mouse_x >= x1) && (mouse_x <= x2) && (mouse_y >= y1) && (mouse_y <= y2))
    {
        if(mouse_b & 1)
            return 1;
    }
    return 0;
}
