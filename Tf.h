#ifndef TF_H
#define TF_H


class Tf
{
    public:
        Tf();
        virtual ~Tf();
        virtual void affiche()=0;
        virtual int select()=0;
    protected:
    private:
};

#endif // TF_H
