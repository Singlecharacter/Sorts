#include "heap.h"

Heap::Heap()
{

}

Heap::~Heap()
{

}

void Heap::heapify(int ary[], int sizeOfAry)
{
    heap.resize(0);
    heap.assign(sizeOfAry,-1);
    if(sizeOfAry > 0)
    {
        for(int i = 0; i < sizeOfAry; i++)
        {
            add(ary[i]);
        }
    }
}

void Heap::add(int newVal)
{
    if(heap.at(heap.size()-1) != -1)
    {
        heap.push_back(-1);
    }

    int i = 0;
    while(true)
    {
        bool inserted = false;

        for(int j = i; j < 2 * i + 1; j++)
        {
            if(heap.at(j) == -1)
            {
                heap[j] = newVal;
                inserted = true;
                break;
            }
        }

        if(!inserted)
        {
            for(int j = i; j < 2 * i + 1; j++)
            {
                if(newVal < heap.at(j))
                {
                    int temp = heap[j];
                    heap[j] = newVal;
                    newVal = temp;
                }
            }
        }
        else
        {
            break;
        }
        i = 2 * i + 1;
    }
}

int Heap::peekMin()
{
    return heap.at(0);
}

void Heap::deleteMin()
{
    int i = 0;
    while(true)
    {
        if(2*i+2 >= heap.size())
        {
            if(2*i+1 >= heap.size())
            {
                heap[i] = -1;
            }
            else
            {
                heap[i] = heap.at(2*i+1);
                heap[2*i+1] = -1;
            }
            break;
        }

        if(heap.at(2*i+1) == -1 && heap.at(2*i+2) == -1)
        {
            heap[i] = -1;
            break;
        }

        if(heap.at(2*i+1) <= heap.at(2*i+2) && heap.at(2*i+1) != -1)
        {
            heap[i] = heap.at(2*i+1);
            i = 2*i + 1;
        }
        else if(heap.at(2*i+2) != -1)
        {
            heap[i] = heap.at(2*i+2);
            i = 2*i + 2;
        }
        else
        {
            heap[i] = heap.at(2*i+1);
            i = 2*i + 1;
        }
    }
}

int Heap::extractMin()
{
    int heapMin = heap.at(0);
    deleteMin();

    return heapMin;
}

void Heap::print()
{
    for(int i = 0; i < heap.size(); i++)
    {
        std::cout << heap.at(i) << " ";
    }
    std::cout << std::endl;
}
