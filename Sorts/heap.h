#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap
{
public:

    Heap();
    ~Heap();

    void heapify(int[], int);
    void add(int);
    int extractMin();
    int peekMin();
    void deleteMin();

    void print();

private:

    std::vector<int> heap;

};

#endif // HEAP_H
