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
    
    void remove(Node<T>* p){Node<T>* d=p->next; p->next=d->next; delete d;}
    
    int count()
    {
        int counter=0;
        
        for(Node<T>* it=head; it != NULL; it=it->next)
            counter++;
        
        return counter;
    }
    
public:
    List(){head=NULL;}
    
    void show() const
    {
        for(Node<T>* it=head; it != NULL; it=it->next)
            cout<<it->data<<(it->next != NULL ? "->" : "");
    }
    
    void Remove_Dups()
    {
        if(head == NULL || head->next == NULL) // if singly-linked-list is empty or just includes head
            return;
        
        for(Node<T>* it1=head; it1->next != NULL; it1=it1->next) // for it1 @ head...(second-to-last)node in singly-linked-list
            for(Node<T>* it2=it1; it2 != NULL; it2=it2->next) // for it2 @ it1...tail in singly-linked-list
                while(it2->next != NULL && it1->data == it2->next->data) // while it2 isn't tail and it1 is equal to it2's next
                    remove(it2); // unlink and delete it2's next from singly-linked-list
    }
    
    const T &Return_Kth_to_Last(int k) // k is kth-to-last position in singly-linked-list
    {
        int size=count(); // size is size of singly-linked-list
        
        if(k < 1 || k > size) // if k is invalid
            throw "Function ended with exit code: "+ (head != NULL ? to_string(k) : to_string(0));
        
        Node<T>* kth=head; // kth points to head of singly-linked-list
        
        for(int c=size; c > k; kth=kth->next, c--); // kth points to kth-to-last node of singly-linked-list
        
        return kth->data; // return kth-to-last element in singly-linked-list
    }
    
    void pull(const T &e);
    ~List();
};

template<class T>
void List<T>::pull(const T &e)
{
    Node<T>* n=new Node<T>(e);
    
    if(head == NULL)
        head=n;
    else
    {
        Node<T>* it=head;
        
        for(; it->next != NULL; it=it->next);
        it->next=n;
    }
}

template<class T>
List<T>::~List()
{
    while(head != NULL)
    {
        Node<T>* it=head->next;
        
        delete head;
        head=it;
    }
}

#endif /* list_h */
