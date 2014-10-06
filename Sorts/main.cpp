#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "heap.h"

void init_array(int[], int);
void print_array(int[], int);
bool check_array(int[], int);

void bubbleSort(int[], int);
void insertionSort(int[], int);
void selectionSort(int[], int);
void shellSort(int[], int);
void quickSort(int[], int, int);
void mergeSort(int[], int);
void heapSort(int[], int);
void bucketSort(int[], int, int, int);

int main()
{
    srand(time(NULL));

    int testSize = 10000;

    int test[testSize];

    //Bubble sort testing
    init_array(test,testSize);
    std::cout << "Pre bubble sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;
    bubbleSort(test,testSize);
    std::cout << "Post bubble sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;

    //Insertion sort testing
    init_array(test,testSize);
    std::cout << "Pre insertion sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;
    insertionSort(test,testSize);
    std::cout << "Post insertion sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;

    //Selection sort testing
    init_array(test,testSize);
    std::cout << "Pre selection sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;
    selectionSort(test,testSize);
    std::cout << "Post selection sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;

    //Shell sort testing
    init_array(test,testSize);
    std::cout << "Pre shell sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;
    shellSort(test,testSize);
    std::cout << "Post shell sort: " ;
    std::cout << check_array(test,testSize);
    std::cout << std::endl;

    //Quick sort testing
    init_array(test,testSize);
    std::cout << "Pre quick sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;
    quickSort(test,0,testSize-1);
    std::cout << "Post quick sort: " ;
    std::cout << check_array(test,testSize);
    std::cout << std::endl;

    //Merge sort testing
    init_array(test,testSize);
    std::cout << "Pre merge sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;
    mergeSort(test,testSize);
    std::cout << "Post merge sort: " ;
    std::cout << check_array(test,testSize);
    std::cout << std::endl;

    //Heap sort testing
    init_array(test,testSize);
    std::cout << "Pre heap sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;
    heapSort(test,testSize);
    std::cout << "Post heap sort: " ;
    std::cout << check_array(test,testSize);
    std::cout << std::endl;

    //Bucket sort testing
    init_array(test,testSize);
    std::cout << "Pre bucket sort: ";
    std::cout << check_array(test,testSize);
    std::cout << std::endl;
    bucketSort(test,testSize, 100, 10000);
    std::cout << "Post bucket sort: " ;
    std::cout << check_array(test,testSize);
    std::cout << std::endl;

    return 0;
}

void init_array(int ary[], int sizeOfAry)
{
    for(int i = 0; i < sizeOfAry; i++)
    {
        ary[i] = rand() % 10000;
    }
}

void print_array(int ary[], int sizeOfAry)
{
    for(int i = 0; i < sizeOfAry; i++)
    {
        std:: cout << ary[i] << " ";
    }
}

bool check_array(int ary[], int sizeOfAry)
{
    for(int i = 1; i < sizeOfAry; i++)
    {
        if(ary[i] < ary[i-1])
        {
            return false;
        }
    }

    return true;
}

void bubbleSort(int ary[], int sizeOfAry)
{
    while(true)
    {
        bool madeSwap = false;
        for(int i = 1; i < sizeOfAry; i++)
        {
            if(ary[i] < ary[i-1])
            {
                int temp = ary[i-1];
                ary[i-1] = ary[i];
                ary[i] = temp;
                madeSwap = true;
            }
        }
        if(!madeSwap)
        {
            break;
        }
    }
}

void insertionSort(int ary[], int sizeOfAry)
{
    for(int i = 1; i < sizeOfAry; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(ary[j] < ary[j-1])
            {
                int temp = ary[j];
                ary[j] = ary[j-1];
                ary[j-1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

void selectionSort(int ary[], int sizeOfAry)
{
    for(int j = 0; j < sizeOfAry; j++)
    {
        int smallest = ary[j];
        int smallestIndex = j;
        for(int i = j; i < sizeOfAry; i++)
        {
            if(ary[i] < smallest)
            {
                smallest = ary[i];
                smallestIndex = i;
            }
        }

        int temp = ary[j];
        ary[j] = ary[smallestIndex];
        ary[smallestIndex] = temp;
    }
}

void shellSort(int ary[], int sizeOfAry)
{
    //Uses Martin Ciura's gap sequence

    //initialize the gap array
    int gapsSize = 8;
    int gaps[gapsSize];
    gaps[0] = 701;
    gaps[1] = 301;
    gaps[2] = 132;
    gaps[3] = 57;
    gaps[4] = 23;
    gaps[5] = 10;
    gaps[6] = 4;
    gaps[7] = 1;

    for(int k = 0; k < gapsSize; k++)
    {
        //size of each subarray
        int size_current = sizeOfAry/gaps[k];
        //Some arrays will be of size size_current - 1 to avoid array overflow, cutoff determines where these begin
        int cutoff = sizeOfAry % gaps[k] + 1;

        //build and sort the subarrays of full size
        for(int j = 0; j < cutoff; j++)
        {
            int ary_current[size_current];
            for(int i = 0; i < size_current; i++)
            {
                ary_current[i] = ary[j+(i*gaps[k])];
            }
            insertionSort(ary_current,size_current);
            for(int i = 0; i < size_current; i++)
            {
                ary[j+(i*gaps[k])] = ary_current[i];
            }
        }

        //build and sort the subarrays of size size_current - 1
        for(int j = cutoff; j < gaps[k]; j++)
        {
            int ary_current[size_current];
            for(int i = 0; i < size_current - 1; i++)
            {
                ary_current[i] = ary[j+(i*gaps[k])];
            }
            insertionSort(ary_current,size_current);
            for(int i = 0; i < size_current - 1; i++)
            {
                ary[j+(i*gaps[k])] = ary_current[i];
            }
        }
    }
}

void quickSort(int ary[], int left, int right)
{
    //If there are elements to sort
    if(left < right)
    {
        //Choose the leftmost element as pivot, put it on the right of the section to be sorted
        int pivot = ary[left];
        int temp = ary[left];
        ary[right] = ary[left];
        ary[left] = temp;

        //storeIndex keeps track of where the pivot should be inserted
        int storeIndex = left;

        //put all elements less than the pivot on the left side of the area being sorted
        for(int i = left; i < right; i++)
        {
            if(ary[i] < pivot)
            {
                temp = ary[i];
                ary[i] = ary[storeIndex];
                ary[storeIndex] = temp;
                storeIndex++;
            }
        }

        //Put the pivot in place if necessary
        if(storeIndex < right)
        {
            temp = ary[right];
            ary[right] = ary[storeIndex];
            ary[storeIndex] = temp;
        }

        //sort the sublists on either side of the pivot
        quickSort(ary,left,storeIndex-1);
        quickSort(ary,storeIndex+1,right);
    }
}

void _merge(int ary[], int left, int right, int stop)
{
    //std::cout << "Left: " << left << std::endl;
    //std::cout << "Right: " << right << std::endl;
    //std::cout << "Stop: " << stop << std::endl;
    //std::cout << "Stop - left: " << stop - left << std::endl;
    int copyArray[stop-left];
    int i0 = left;
    int i1 = right;
    for(int i = 0; i < stop - left; i++)
    {
        //std::cout << "i0: " << i0 << std::endl;
        //std::cout << "i1: " << i1 << std::endl;
        //If there are still elements in the left list
        if(i0 < right)
        {
            //If there are still elements in the right list
            if(i1 < stop)
            {
                //If the current left list element is <= the current right list element
                if(ary[i0] <= ary[i1])
                {
                    copyArray[i] = ary[i0];
                    i0++;
                }
                else
                {
                    copyArray[i] = ary[i1];
                    i1++;
                }
            }
            else
            {
                copyArray[i] = ary[i0];
                i0++;
            }
        }
        else
        {
            copyArray[i] = ary[i1];
            i1++;
        }
    }

    //copy the sorted array back to the passed array
    for(int i = 0; i < stop - left; i++)
    {
        ary[left+i] = copyArray[i];
    }
}

void mergeSort(int ary[], int sizeOfAry)
{
    for(int i = 1; i < sizeOfAry; i = i * 2)
    {
        for(int j = 0; j < sizeOfAry; j += i * 2)
        {
            if(j+2*i < sizeOfAry)
            {
                _merge(ary,j,j+i,j+2*i);
            }
            else if(j + i < sizeOfAry)
            {
                _merge(ary,j,j+i,sizeOfAry);
            }
            else
            {
                _merge(ary,j,sizeOfAry,sizeOfAry);
            }
        }
    }
}

void heapSort(int ary[], int sizeOfAry)
{
    Heap h;
    h.heapify(ary, sizeOfAry);

    for(int i = 0; i < sizeOfAry; i++)
    {
        ary[i] = h.extractMin();
    }
}

void bucketSort(int ary[], int sizeOfAry, int bucketSize, int highVal)
{
    int bucketLow = 0;
    int bucketHigh = bucketSize;
    std::vector<int> copyVector;
    while(bucketHigh <= highVal)
    {
        std::vector<int> bucket;

        for(int i = 0; i < sizeOfAry; i++)
        {
            if(ary[i] >= bucketLow && ary[i] < bucketHigh)
            {
                bucket.push_back(ary[i]);
            }
        }

        int bucketAry[bucket.size()];
        for(int i = 0; i < bucket.size(); i++)
        {
            bucketAry[i] = bucket[i];
        }

        quickSort(bucketAry,0,bucket.size()-1);

        for(int i = 0; i < bucket.size(); i++)
        {
            copyVector.push_back(bucketAry[i]);
        }

        bucketLow += bucketSize;
        bucketHigh += bucketSize;
    }

    for(int i = 0; i < sizeOfAry; i++)
    {
        ary[i] = copyVector[i];
    }
}
