#ifndef VECTOR_H
#define VECTOR_H
#include <SFML/Graphics.hpp>
#include "random.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>
//#include "particle.h"

using namespace std;
template <class T>
class Vector
{
public:
    Vector<T>(){
        capacity = 200;
        array = new T [capacity];
        used =0;

    }

    ~Vector(){
//        cout << "vector destructor" << endl;

        delete [] array;
    }

    Vector &operator = (const Vector& RHS){
        ClearList();
        capacity = RHS.capacity;
        used = RHS.used;
        array = CopyList(RHS.array,RHS.capacity);
    }

    T* CopyList(T* ptr, int size){
        T* newlist;
        newlist = new T [size];

        for (int i=0; i< size; i++){
            newlist[i] = ptr[i];
        }

        return newlist;
    }

     T operator [](int order){
        return array[order];
    }

     void Insert(T item){

         if (used>=capacity-1){
             reScale();
         }
         array[used] = item;
         used++;
     }

     void reScale(){
         delete [] array;
         T* array2 = new T[capacity*2];

         for (int i=0; i< capacity; i++){
             array2[i] = array[i];
         }
         array = array2;
         capacity = capacity*2;


     }

//     void InsertCircle(int xpos, int ypos, int v1, int r, int g, int b){
//         array[used] = new Circle(xpos,ypos,v1,r,g,b);
//         used++;
//     }



     void ClearList(){
         for (int i=0; i< used; i++){
             delete array[i];
         }
     }


     T* get_header(){
         return array;
     }





private:
    T* array;
    int used;
    int capacity;

};


#endif // VECTOR_H
