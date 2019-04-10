#ifndef LIST_H
#define LIST_H

#include"linked_list_functions.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

template <class T>
class List
{
public:

    class Iterator{
    public:
        friend class List;                              //give access to list to access _ptr
        Iterator():_ptr(NULL){}

            //default ctor
        Iterator(node<T>* p):_ptr(p){}


//        operator bool();                                //casting operator: true if _ptr not NULL
//                                                        //      this turned out to be a pain!

        T& operator *(){
            return _ptr->_item;
        }
            //dereference operator
//        T* operator ->(){
//            node<T>* ptr = _ptr->_next;
//            return ptr;
//        }
            //member access operator

        bool is_null();                                 //true if _ptr is NULL

        friend bool operator !=(const Iterator& left,
                                const Iterator& right){
            if (left._ptr!=right._ptr){
                return true;
            }

            else {
                return false;
            }
        }

        friend bool operator ==(const Iterator& left,
                                const Iterator& right){
            if (left._ptr==right._ptr){
                return true;
            }
            else {
                return false;
            }
        }

        Iterator& operator++(){
            _ptr = _ptr->_next;

        }
            //member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator& it,
                                   int unused){
            it = it._ptr->_next;
            return it;
        }
            //friend operator: it++

    private:
        node<T>* _ptr;                          //pointer being encapsulated

    };

    List();
    List(Iterator ptr);
    List(bool ascneding, bool unique);
    List& operator =(const List& RHS);
    ~List();
    Iterator insert_head(const T& item);
    Iterator Begin() const;
    Iterator End() const;
    Iterator LastNode() const;
    Iterator NextNode(Iterator iMark) const;

    Iterator Search(const T& item) const;

    Iterator _insertBefore(const T& item,Iterator iMark);

    Iterator _previousNode(Iterator iMark);

    Iterator _InsertAfter(const T& key, Iterator iMark);
    Iterator _DeleteNode(List<T>::Iterator ptr,List<T>::Iterator iMarker);

    Iterator Insert(const T& key);
    Iterator Insert_and_add(const T& item);

    node<T>* _endsearch(node<T>*& ptr,
                                  node<T>* walker);


    template<class U>
    friend ostream& operator <<(ostream& outs, List<U> print_me);

public:
    node<T>* _head_ptr;
    bool _order;
    bool _unique;
};



template <class T>
List<T>::List(){
    _head_ptr = NULL;
    bool _order=true;
    bool _unique=false;
}

template <class T>
List<T>::List(Iterator ptr){
    _head_ptr = ptr._ptr;
//    bool _order=true;
//    bool _unique=false;
}

template <class T>
List<T>::List(bool ascneding, bool unique){
    _head_ptr = NULL;
    _order=ascneding;
    _unique=unique;
}


template <class T>
typename List<T>::Iterator List<T>::insert_head(const T& item){
   node<T>*ptr = _insert_head(_head_ptr,item);
   _head_ptr = ptr;
   return Iterator(_head_ptr);

}

template <class T>
typename List<T>::Iterator List<T>::Insert(const T& item){
    node<T>* temp = InsertSorted(_head_ptr,item,_order,_unique);
    return Iterator(temp);
}

template <class T>
typename List<T>::Iterator List<T>::Insert_and_add(const T& item){
    node<T>* temp = InsertSorted_and_add(_head_ptr,item);
    return Iterator(temp);
}

template <class T>
typename List<T>::Iterator List<T>::NextNode(Iterator iMark) const{
    node<T>* temp = iMark._ptr;
    temp = temp->_next;
    return Iterator(temp);
}

template <class T>
typename List<T>::Iterator List<T>::Begin()const{
    return Iterator(_head_ptr);
}

template <class T>
typename List<T>::Iterator List<T>::End() const{
    return Iterator(NULL);
}

template <class T>
typename List<T>::Iterator List<T>::LastNode() const{
    node<T>* walker = _head_ptr;
    while(walker->_next!=NULL){
        walker = walker->_next;
    }

    return Iterator(walker);
}

template <class ITEM_TYPE>
List<ITEM_TYPE>& List<ITEM_TYPE>::operator =(const List<ITEM_TYPE>& RHS){
    if (this != &RHS){
        _head_ptr = _CopyList(RHS._head_ptr);
    }
    return *this;
}

template <class T>
List<T>::~List(){
delete _head_ptr;

}


template <class T>
typename List<T>::Iterator List<T>::Search (const T& item)const{
        node<T>*ptr = SearchList(_head_ptr, item);
    return Iterator(ptr);
}


template <class T>
typename List<T>::Iterator List<T>:: _insertBefore(const T& item,Iterator iMark){
node<T>* ptr = _head_ptr;
node<T>* walker = iMark._ptr;

    //PROCESSING - uses insertbefore if not walker == head_ptr
    walker = InsertBefore(ptr,walker,item);
    node<T>* anchor = walker;

    if (anchor->_next==_head_ptr){
        _head_ptr = anchor;
    }

    return Iterator(walker);

    }


template <class T>
typename List<T>::Iterator List<T>::_InsertAfter(const T& key, Iterator iMark){

    if (iMark==NULL){
        node<T>* temp = iMark._ptr;
        return (this->insert_head(key));
    }


    node<T>* nextptr = iMark._ptr;
    InsertAfter(_head_ptr,nextptr,key);
    nextptr = nextptr->_next;
    return Iterator(nextptr);
}

template <class T>
typename List<T>::Iterator List<T>::_previousNode(Iterator iMark){
    node<T>* ptr = PreviousNode(_head_ptr,iMark._ptr);
    return Iterator(ptr);

}
template <class T>
typename List<T>::Iterator List<T>:: _DeleteNode(List<T>::Iterator start,List<T>::Iterator iMarker){

    //PROCESSING - checks to see if head_ptr is == to walker
    //if so it deletes the head_ptr -> node and moves the walker up one
    //returns walker
    node<T>* walker = iMarker._ptr;
    node<T>* ptr = start._ptr;
    if (ptr==walker){
//        cout << "equals";
        walker = walker->_next;
//        delete ptr;
        return Iterator (walker);
    }

    //PROCESSING - deletes node and returns head_ptr
    else{
    node<T> *anchor = walker;
    anchor = PreviousNode(ptr,anchor);
    DeleteNode(ptr,walker);
    walker = anchor;
    return Iterator(ptr);
}
}

template <class T>
node<T>* _endsearch(node<T>*& ptr,
                              node<T>* walker){
    node<T>* anchor = walker;
    while (anchor->_next!= NULL){
        anchor = anchor->_next;
    }
    cout << *anchor;
    return anchor;
}



template<class U>
ostream& operator <<(ostream& outs, List<U> print_me){
    print_list(print_me._head_ptr);
}


#endif // LIST_H
