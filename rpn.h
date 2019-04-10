#ifndef RPN_H
#define RPN_H
#include "stack.h"
#include "queue.h"
#include "token.h"
#include "vector.h"

class RPN
{
public:
    RPN(const Queue<Token*>& pf);

    void show();

    double calculate(double xVal);



private:
Queue <Token*> q1;
Stack <Token*> s1;
};

#endif // RPN_H
