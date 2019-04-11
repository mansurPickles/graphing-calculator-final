#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"
#include <string>

using namespace std;

class Number: public Token{

public: Number(string num):Token(){
        val = stod(num);
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
        return to_string(val);

    }

    friend ostream& operator <<(ostream& outs, const Number& num){
        outs << num.val;
    }



private:
    int instance;
    double val;

};




#endif // NUMBER_H
