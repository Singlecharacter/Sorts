#include "heap.h"

Heap::Heap()
{

}

Heap::~Heap()
{

}

void Heap::heapify(int ary[], int sizeOfAry)
{
    if(sizeOfAry > 0)
    {
        for(int i = 1; i < sizeOfAry; i++)
        {
            if(i % 2 == 0)
            {
                if(ary[i] < ary[i/2 - 1])
                {
                    int temp = ary[i];
                    ary[i] = ary[i/2 - 1];
                    ary[i/2 - 1] = temp;
                }
            }
            else
            {
                if(ary[i] < ary[(i+1)/2 - 1])
                {
                    int temp = ary[i];
                    ary[i] = ary[(i+1)/2 - 1];
                    ary[(i+1)/2 - 1] = temp;
                }
            }
        }
    }
}
