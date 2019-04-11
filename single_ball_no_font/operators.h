#ifndef OPERATORS_H
#define OPERATORS_H
#include "token.h"
#include <string>

using namespace std;

class Operators: public Token{
public: Operators(string symb):Token(){
        val = symb;
        instance = 2;
    }

    int instanceOf(){
        return instance;

    }

    void Print(ostream &outs) const{
        outs << val;
    }

    string getVal()const{
        return val;
    }

    virtual int getpriority(){
        if (val=="+"||val=="-"){
            return 1;
        }

        if (val=="*"||val=="/"){
            return 2;
        }
    }


private:
    int instance;
    string val;

};



#endif // OPERATORS_H
