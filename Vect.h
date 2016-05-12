#ifndef VECT_H
#define VECT_H


class Vect
{
    public:
        Vect();
        ~Vect();
        void ajoute(void*);
        int supp(void*);
    protected:
        void**tab;
        int nb;
    private:
};

#endif // VECT_H
