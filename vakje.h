#ifndef VAKJE_H
#define VAKJE_H


class vakje
{
public:
    int x;
    int y;
    bool isBom;
    bool flagged;
    int buren;
    bool geheim;
    bool ontploft;
    vakje();
    vakje(int, int, bool);
    void actie(char);
};


#endif // VAKJE_H
