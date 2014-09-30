#include "Element.h"

class HashTable
{
    public:
        HashTable();
        void printTable();
        void addElement(int);
        bool searchDelete(int, bool);
    private:
        Element bucket[7];
};
