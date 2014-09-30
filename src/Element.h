#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
    public:
        Element();
        void setIndexValue(int);
        void printSequence();
        bool searchDelete(int, bool);
        bool isFull;

    private:
        int bucketIndex[10];
};

#endif // ELEMENT_H