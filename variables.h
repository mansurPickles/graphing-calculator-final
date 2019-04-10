#ifndef VARIABLES_H
#define VARIABLES_H
#include "token.h"
#include <string>
using namespace std;

class Variable: public Token{

public: Variable(string num):Token(){
        val = num;
        instance = 1;
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

    string sayHello(){
        cout << "saying hello\n";
    }



    friend ostream& operator <<(ostream& outs, const Variable& var){
        outs << var.val;
    }




private:
    int instance;
    string val;

};



#endif // VARIABLES_H
