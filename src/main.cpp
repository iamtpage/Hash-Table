#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "HashTable.h"

using namespace std;

void runPrompt();
void addElement(int num);
void searchDelete(int num, bool flag);
void printTable();
void error(string s);

HashTable* hashTable = new HashTable();

//this is where i will store the string tokens
string strarray[10];

int main()
{
	runPrompt();
}

void runPrompt()
{
	string input = "";
	int index;

	while(input != "quit")
	{
	    index = 0;
		cout << "set> ";
		//get the input and split into iss stream
		getline(cin,input);
		istringstream iss(input);

		while(iss)
		{
			//gather strings delimited by ' ' and store in array
			//index starts at 0, so increment after
			iss >> strarray[index];
			index++;
		}

		if(input.find("add") != string::npos)
		{

			//add num aka strarray[1]
           int numadd = atoi(strarray[1].c_str());
            addElement(numadd);
		}

		if(input.find("delete") != string::npos)
		{
			//remove
			//strarray[0] = remove
			//[1] = num
            int numrem = atoi(strarray[1].c_str());
            searchDelete(numrem, true);
		}


		if(input.find("show") != string::npos)
		{
			printTable();
		}

        if(input.find("search") != string::npos)
        {
            int searchnum = atoi(strarray[1].c_str());
            searchDelete(searchnum, false);
        }

		if(input.find("quit") != string::npos)
        {
			break;
		}

		if(input.find("quit") == string::npos && input.find("show") == string::npos
                && input.find("delete") == string::npos && input.find("add") == string::npos
                && input.find("search") == string::npos)
		{
			error(input);
		}
	}
}

void printTable()
{
    hashTable->printTable();
    cout << endl;
}

void addElement(int num)
{
    hashTable->addElement(num);
}

void searchDelete(int num, bool flag)
{
    //flag is true when we want to delete, and false when we want to search
    if(!flag)
    {
        //search
        if(hashTable->searchDelete(num, flag))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    if(flag)
    {
        //destroy

        //Only if returned false, else don't print anything
        if(!hashTable->searchDelete(num, true))
        {
            cout << "WARNING: target value not found: " << num << endl;
        }
    }
}

void error(string input)
{
		cout << "Error!  Command not found: " << input <<endl;
}