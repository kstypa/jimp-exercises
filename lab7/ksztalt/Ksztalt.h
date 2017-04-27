//
// Created by karol on 4/27/17.
//

#ifndef JIMP_EXERCISES_KSZTALT_H
#define JIMP_EXERCISES_KSZTALT_H


class Ksztalt {
public:
    virtual void rysuj() = 0;

};

class Trojkat : public Ksztalt {
public:
    Trojkat();
    Trojkat(double h);
    ~Trojkat();

    virtual void rysuj();

private:
    double h_;
};

class Kwadrat : public Ksztalt {
public:
    Kwadrat();
    Kwadrat(double a);
    ~Kwadrat();

    virtual void rysuj();

private:
    double a_;
};

class Kolo : public Ksztalt {
public:
    Kolo();
    Kolo(double r);
    ~Kolo();

    virtual void rysuj();

private:
    double r_;
};


#endif //JIMP_EXERCISES_KSZTALT_H
