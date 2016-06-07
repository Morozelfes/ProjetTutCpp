#include "Vect.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

Vect::Vect()
{
    nb = 0;
    tab = NULL;
}

Vect::~Vect()
{}

void Vect::ajoute(void* elt)
{
    void**dtab;
    int i,j;
    dtab = new void*[nb+1];
    for(i=0;i<nb;i++)
        dtab[i]=tab[i];
    dtab[i] = elt;
    if(tab!=NULL)
        delete tab;
    tab = dtab;
    nb++;
}

int Vect::supp(void* s)
{
    void**dtab;
    int i, j, cpt, drap=0;

    if(tab!=NULL)
    {
        for(cpt=0, i=0; i<nb; i++)
            if (tab[i]==s) cpt++;

        if(cpt!=0)
        {

            if(nb>1)
            {

                dtab = new void*[nb-1];
                for(i=0, j=0; i<nb; i++)
                    if (tab[i]!=s) dtab[j++]=tab[i];
                nb -= cpt;

            }
            else {dtab=NULL; nb -=cpt;}
            drap = 1;
            delete tab;
            tab = dtab;
        }

    }
    return drap;

}
