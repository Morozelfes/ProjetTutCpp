#include "gestaff.h"
#include <allegro.h>
extern BITMAP*page;

gestaff::gestaff(): Vect()
{}

gestaff::~gestaff()
{
    for(int i=0;i<nb;i++)
        delete((Tf*)tab[i]);
}

void gestaff::affiche()
{
    Tf* ptn;
    for(int i=0; i<nb ; i++)
    {
        ptn = (Tf*)tab[i];
        ptn -> affiche();
    }
    textprintf(page,font,550,460,makecol(255,0,0),"nb = %d",nb);
}

void gestaff::supp(Tf*s)
{
    if (Vect::supp(s)) delete(s);

}

Tf* gestaff::select()
{
    Tf* ptr;
    for(int i=0; i<nb; i++)
    {

        ptr = (Tf*)tab[i];
        if (ptr->select()==1) return (ptr);
    }
    return NULL;
}
