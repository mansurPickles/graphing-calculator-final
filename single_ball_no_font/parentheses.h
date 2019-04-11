#ifndef PARENTHESES_H
#define PARENTHESES_H
#include "token.h"
#include <string>
#include "operators.h"

using namespace std;

class Parentheses: public Operators{

public: Parentheses(string symb):Operators(symb){
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
        if (val==")"||val=="}"){
            return 5;
        }
        else {
            return 0;
        }
    }



private:
    int instance;
    string val;

};





#endif // PARENTHESES_H
