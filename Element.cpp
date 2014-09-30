#include <iostream>
#include "Element.h"

using namespace std;

Element::Element()
{
    //Since the hash function will never be negative
    //I can use -1 as a "deleted" or invisible spot
    
    //Set it all to -1 to start
    for(int i = 0; i < 9; i++)
    {
        bucketIndex[i] = -1;
    }

    //We just started, so we aren't full
    isFull = false;
}

void Element::printSequence()
{
    for( int i =0; i < 9; i++)
    {
        //if the spot is "empty"
        if(bucketIndex[i] == -1)
        {
            cout << "";
        }

        else
        {
            cout << bucketIndex[i];
            
            //only put commas if there is an actual number
            //afterwards and it is not the last number in 
            // the list
            if(bucketIndex[i+1] != -1 && bucketIndex[i] != 8)
            {
                cout << ",";
            }
        }
    }
}

bool Element::searchDelete(int num, bool del)
{
    bool flag = false;
    for(int i = 0; i < 9; i++)
    {
        //match
        if(bucketIndex[i] == num)
        {
            flag =  true;
            if(del)
            {
                bucketIndex[i] = -1;
            }
        }
    }
    return flag;
}

void Element::setIndexValue(int num)
{
    bool fullflag = true;
    bool dupe = false;

    for(int i = 0; i < 9; i++)
    {
        if(bucketIndex[i] == num)
        {
            cout << "Warning: duplicate number: " << num << endl;
            dupe = true;

            //we don't want to keep looking, so break
            break;
        }

        //empty spot found, and not a duplicate number
        if(bucketIndex[i] == -1 && !dupe)
        {
            //set it
            bucketIndex[i] = num;
            
            //we aren't full this round, so set it false
            fullflag = false;
            
            //we only want to set the number to one spot, so
            //break after setting the first one
            break;
        }
    }

    //if the bucket is full
    if(fullflag && !dupe)
    {
        //set the class flag to true, so we can skip it in the Hash Table
        isFull = true;
        
        //print out the error
        cout << "Error!  The bucket for number "<< num << " is full!" << endl;
    }
}