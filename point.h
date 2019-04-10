#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

struct point {
public: point(double x, double y){
        this->x = x;
        this->y =y;
    }
public: point(){
        this->x = 0;
        this->y =0;
    }

public: double getx(){
        return x;
    }

public: double gety(){
        return y;
    }



private: double x;
         double y;


public:

         point operator =(point a){
             this->x = a.x;
             this->y = a.y;
         }

         friend ostream& operator <<(ostream& outs, const point& p){
            outs << "(" << p.x << "," << p.y << ")";
            return outs;

         }

//         friend istream& operator >>(istream& ins, Poly& p);



};

#endif // POINT_H
