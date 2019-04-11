#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

using namespace std;

class Token
{
public:
    Token();

    friend ostream& operator <<(ostream& outs, Token* token);
    friend ostream& operator <<(ostream& outs, const Token& token);
    virtual void Print(ostream& outs) const;
    virtual int instanceOf(){}
    virtual string getVal() const;


};

#endif // TOKEN_H
