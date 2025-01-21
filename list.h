//
//  list.h
//  CTCI 2.2 Return Kth to Last
//
//  Created by daniel saghbine on 1/16/25.
//

#ifndef list_h
#define list_h

#include <iostream>
using namespace std;

template<class T>
class List;

template<class T>
class Node
{
    T data;
    Node<T>* next;
    
    Node(const T &e){data=e; next=NULL;}
    
    friend class List<T>;
};

template<class T>
class List
{
    Node<T>* head;
    
    void pop();
    
public:
    List(){head=NULL;}
    void push(const T &e){Node<T>* n=new Node<T>(e); n->next=head; head=n;}
    
    const T &Return_Kth_to_Last(int k) const // k is kth-to-last T in singly linked list
    {
        if(k < 1) // if k isn't positive
            throw "Function ended with exit code: " + to_string(k); // throw exception
        
        int counter=0; // to count size of singly linked list
        
        for(Node<T>* n=head; n != NULL; n=n->next) // for node n at head...tail in singly linked list
            counter++; // increment counter
        
        if(k > counter) // if k is greater than size of singly linked list
            throw "Function ended with exit code: " + to_string(k); // throw exception
        
        Node<T>* kth=head; // to return kth-to-last's data
            
        for(int i=counter; i > k; kth=kth->next, i--); // for node kth at head...kth-to-last in singly linked list
            
        return kth->data; // return kth-to-last's data
    }
    
    void show() const
    {
        for(Node<T>* n=head; n != NULL; n=n->next)
            cout<<n->data<<(n->next != NULL ? "->" : "");
        
        if(head != NULL)
            cout<<endl;
    }
    
    ~List()
    {
        while(head != NULL)
            pop();
    }
};

template<class T>
void List<T>::pop()
{
    if(head != NULL)
    {
        Node<T>* n=head->next;
        
        delete head;
        head=n;
    }
}

#endif /* list_h */
