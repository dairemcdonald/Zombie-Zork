#ifndef GOON_H
#define GOON_H


class goon: public monster
{
public:
    goon();

    void head(int);
    void arms(int);
    void legs(int);
    void torso(int);
};

#endif // GOON_H
