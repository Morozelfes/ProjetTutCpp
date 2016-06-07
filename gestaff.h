#ifndef GESTAFF_H
#define GESTAFF_H
#include "Tf.h"
#include "Vect.h"


class gestaff : public Vect
{
    public:
        gestaff();
        ~gestaff();
        void affiche();
        void supp(Tf*);
        Tf* select();
    protected:
    private:
};

#endif // GESTAFF_H
