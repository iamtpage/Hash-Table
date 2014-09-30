#include <iostream>

#include "Element.h"
#include "HashTable.h"

using namespace std;

HashTable::HashTable(){}

void HashTable::addElement(int num)
{

    //Error checking to see if number is within range
    if(num < 0 || num > 10)
    {
        cout << "Error! number is out of range (0-9)" << endl;
        return;
    }

    //not out of range
    else
    {
        //hash x^2 mod B where B=7
        int key = (num*num) % 7;

        //cycle through the buckets
        for(int i = 0; i < 7; i++)
        {
            //check the class flag to see if its full
            if(!bucket[key].isFull)
            {
                //set it once
                bucket[key].setIndexValue(num);
                break;
            }
        }
    }
}

//search and destroy,  I combined the search and
//delete function to keep it simple, since they both
//use the same mechanism.
bool HashTable::searchDelete(int num, bool del)
{
    bool flag = false;
    for(int i = 0; i < 6; i++)
    {
        //search for it
        //searchDelete = search and destroy
        //num = number to search for, del = if we want to delete it or not
        if(bucket[i].searchDelete(num,del))
        {
            flag = true;
            break;
        }
    }
    //return our results
    return flag;
}

void HashTable::printTable()
{
    for(int i = 0; i < 7; i++)
    {
        //format it correctly when printing
        cout << "(";
        bucket[i].printSequence();
        cout << ")";

        //only add dashes when necessary
        if(i < 5)
        {
            cout << "-";
        }
    }
}