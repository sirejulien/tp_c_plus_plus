#ifndef VECTEUR_H
#define VECTEUR_H

struct Vecteur  //différence struct/class
{
    public:
        void operator +=(Vecteur const& other);
        void operator -=(Vecteur const& other);
        Vecteur operator * (float coefficient) const;
        static Vecteur speedFromAngle(float size, float angleInDegree);
        float x{0.f};
        float y{0.f};

    private:
};

#endif // VECTEUR_H
