#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <iostream>

using namespace std;
template <class T>
struct node{
    T _item;
    node<T>* _next;
    node(T item = T());
    template <class U>
    friend ostream& operator <<(ostream& outs, const node<U>& print_me);
};

template <class T>
node<T>::node(T item):_item(item), _next(NULL){

}
template <class U>
ostream& operator <<(ostream& outs, const node<U>& print_me){
    outs << print_me._item;

    return outs;
}
template <class T>
node<T>* _insert_head(node<T>* & head_ptr, const T& item){
    //1. create a new node(item)
    node<T>* temp = new node<T>(item);
    //2. temp's next points to where head is pointing to:
    temp->_next = head_ptr;
    //3.point head_ptr to this new node:
    head_ptr = temp;

    return head_ptr;
}

template <class T>
node<T>* _get_header(node<T>* & head_ptr){
    return head_ptr;
}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>*& head,
                              node<ITEM_TYPE>* beforeThis,
                              const ITEM_TYPE &key);


     //return ptr to key or NULL

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,
                                const ITEM_TYPE &key);

     //insert at the head of list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* InsertHead(node<ITEM_TYPE> *&head,
                                const ITEM_TYPE &key);

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>*& head,
                                 node<ITEM_TYPE> *afterThis,
                                 const ITEM_TYPE &key);
    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>*& head_ptr,
                                  node<ITEM_TYPE>* beforeThis,
                                  const ITEM_TYPE &key);

    //insert sorted
   template <typename ITEM_TYPE>
   node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE> *&head,
                               const ITEM_TYPE &key);

    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* head,
                                  node<ITEM_TYPE>* prevToThis);

    //delete, return item
    template <typename ITEM_TYPE>
    ITEM_TYPE DeleteNode(node<ITEM_TYPE>*&head,
                         node<ITEM_TYPE>* deleteThis);


    //duplicate the list...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* CopyList(node<ITEM_TYPE>* head);

    //sorted and added...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* InsertSorted_and_add (node<ITEM_TYPE>* head, const ITEM_TYPE &key);

     //delete all the nodes
    template <typename ITEM_TYPE>
    void ClearList(node<ITEM_TYPE>*& head);

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos);

    //delete all the nodes
    template <typename ITEM_TYPE>
      void ClearList(node<ITEM_TYPE>*& head);

template<class T>
void print_list(node<T>* head_ptr){
    //1. walker to head_ptr
    node<T>* walker = head_ptr;
    //loop and print until walker hits NULL;
    while (walker!=NULL){
        T temp = walker->_item;
//    if (walker == head_ptr){
//        cout << "{" <<  temp << "}->";
//        walker = walker->_next; //go to the next node
//    }
//    else {
        cout<<*walker << " ";          //print this node

        walker = walker->_next; //go to the next node
//    }
}
}

//ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* head,
                              node<ITEM_TYPE>* prevToThis){

    node<ITEM_TYPE>* PreviousNode = NULL;
    if (prevToThis == head) return NULL;
    node<ITEM_TYPE>* walker = head;

    while (walker->_next != prevToThis){
                   walker = walker->_next;
        }

         return walker;

}

//return ptr to key or NULL
template <typename ITEM_TYPE>
    node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,
                                const ITEM_TYPE &key){

        node<ITEM_TYPE>* walker = head;

        while (walker->_item!= key){
            walker = walker->_next;

            if (walker->_item == key){
                return walker;
            }
        }

        return walker;
    }
//insert after
template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>*& head,
     node<ITEM_TYPE> *afterThis, const ITEM_TYPE &key){

    //1. create a new node(item)
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(key);
    //2. temp's next points to where head is pointing to:
    temp->_next = afterThis->_next;
    //3.point head_ptr to this new node:
    afterThis->_next = temp;
    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE> *&head,
                           const ITEM_TYPE &key, bool ascending, bool unique){
    node<ITEM_TYPE> *walker = head;
    node<ITEM_TYPE> *anchor = head;
    bool duplicate_found = false;

    while (anchor!=NULL){
        if (anchor->_item ==key && unique){
            duplicate_found = true;
        }
        anchor = anchor->_next;
    }

    if (duplicate_found){
        return walker = InsertSorted_and_add(head,key);
    }

    if (!duplicate_found){


    if (ascending){

    while (walker!=NULL){


    if (key < walker->_item){
        return InsertBefore(head,walker,key);
    }

    walker = walker->_next;

}
    return InsertBefore(head,walker,key);
    }

    if (!ascending){
    while (walker!=NULL){

        if (key > walker->_item){
            return InsertBefore(head,walker,key);
        }

        walker = walker->_next;

    }
    return InsertBefore(head,walker,key);

}


}
}

   //insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>*& head_ptr,
                              node<ITEM_TYPE>* beforeThis,
                              const ITEM_TYPE &key){

    node<ITEM_TYPE>* previous = PreviousNode(head_ptr,beforeThis);

    if (head_ptr == beforeThis){
        _insert_head(head_ptr,key);
    }

    else {
    //1. create a new node(item)
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(key);
    //2. temp's next points to where head is pointing to:
    temp->_next = previous->_next;
    //3.point head_ptr to this new node:
    previous->_next = temp;
    return temp;

}
}

//delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE DeleteNode(node<ITEM_TYPE>*&head_ptr,
                     node<ITEM_TYPE>* deleteThis){
    node<ITEM_TYPE>* previous = PreviousNode(head_ptr,deleteThis);
    if (deleteThis==head_ptr){
        previous->_next = deleteThis->_next;
        ITEM_TYPE r_int = deleteThis->_item;
        delete head_ptr;
        return r_int;
    }
    else {
    previous->_next = deleteThis->_next;
    ITEM_TYPE r_int = deleteThis->_item;
    delete deleteThis;
    return r_int;
    }
}

//duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE>* CopyList(node<ITEM_TYPE>* head_ptr){
    node<ITEM_TYPE>* walker = head_ptr;
    node<ITEM_TYPE>*ptr2 = NULL;
    while (walker!=NULL){
        //1. create a new node(item)
        node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(walker->_item);
        //2. temp's next points to where head is pointing to:
        temp->_next = ptr2;
        //3.point head_ptr to this new node:
        ptr2 = temp;

        walker = walker->_next;
    }
            return ptr2;
}
node<int>* give_me_a_list(int n);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add (node<ITEM_TYPE>* head, const ITEM_TYPE &key){
    node<ITEM_TYPE>* walker = head;

    while (walker!= NULL){
        if (walker->_item==key){
            walker->_item = walker->_item*2;
        }
        walker = walker->_next;
    }

    return walker;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head){           //duplicate the list...
    if (head == NULL)                       // ends on null
        return NULL;
    node<ITEM_TYPE>* copied = new node<ITEM_TYPE>;          // makes new node
    copied->_item = head->_item;            // copies _item
    copied->_next = _CopyList(head->_next);  // sets ptr to _next, call itself to keep going until hits null
    return copied;
}

#endif // LINKED_LIST_FUNCTIONS_H
