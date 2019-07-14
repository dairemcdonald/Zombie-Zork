#ifndef MUTANT_H
#define MUTANT_H


class mutant: public monster
{
public:
    mutant();

    void head(int);
    void arms(int);
    void legs(int);
    void torso(int);
};

#endif // MUTANT_H
