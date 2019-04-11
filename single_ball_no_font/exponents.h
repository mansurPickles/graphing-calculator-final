#ifndef EXPONENTS_H
#define EXPONENTS_H
#include "token.h"
#include <string>
#include "operators.h"

using namespace std;

class Exponents: public Operators{
public: Exponents(string symb): Operators(symb){
        val = symb;
        instance = 2;
    }
    int instanceOf(){
        return instance;

    }

    void Print(ostream &outs) const{
        //        cout << "here in number print\n";
        outs << val;
    }

    string getVal()const{
        return val;

    }

    int getpriority(){
        return 3
                ;
    }



private:
    int instance;
    string val;

};



#endif // EXPONENTS_H
