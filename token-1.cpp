#include "token.h"
#include <iostream>

Token::Token(){

}

ostream& operator <<(ostream& outs, Token* token){

    token->Print(outs);
    return outs;
}

ostream& operator <<(ostream& outs, const Token& token){

    token.Print(outs);
    return outs;
}

void Token::Print(ostream& outs) const{
outs << "shouldnt be here\n";
}

string Token::getVal() const{

}



