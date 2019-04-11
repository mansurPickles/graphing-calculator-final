#ifndef FUNCTION_H
#define FUNCTION_H
#include "operators.h"
using namespace std;

class Functions: public Operators{
public: Functions(string symb):Operators(symb){
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

    int getpriority(){
        return 4;
    }

private:
    int instance;
    string val;

};

#endif // FUNCTION_H
