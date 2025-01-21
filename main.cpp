//
//  main.cpp
//  CTCI 2.2 Return Kth to Last
//
//  Created by daniel saghbine on 1/16/25.
//

#include "list.h"
#include <cstdlib>

int main()
{
    cout<<"problem\n-------\n\tImplement an algorithm to find the kth to last element of a singly linked list.\n\n";
    
    cout<<"input\n-----\n\t";
    List<int> l;
    srand(int(time(0)));
    
    for(int i=1; i <= 10; i++)
        l.push(rand()%10+1);
    
    l.show();
    
    cout<<"\noutput\n------\n";
    
    try
    {
        l.Return_Kth_to_Last(0);
    }
    catch(const string &s)
    {
        cout<<'\t'<<s<<endl<<endl;
    }
    
    try
    {
        for(int i=1; i <= 10; i++)
        {
            cout<<"\tThe "<<i;
            
            switch(i)
            {
                case 1: cout<<"st";
                    break;
                case 2: cout<<"nd";
                    break;
                case 3: cout<<"rd";
                    break;
                default: cout<<"th";
            }
            
            cout<<"-to-last integer in the singly linked list is "<<l.Return_Kth_to_Last(i)<<".\n";
        }
        
        l.Return_Kth_to_Last(11);
    }
    catch(const string &s)
    {
        cout<<"\n\t"<<s<<endl<<endl;
    }
    
    cout<<"solution\n--------\n\tAuxiliary space complexity: O(1); time complexity: O(n).\n\n";
    
    return 0;
}
