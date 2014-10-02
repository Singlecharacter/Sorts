#include <cstdlib>
#include <ctime>
#include <iostream>

void init_array(int[], int);
void print_array(int[], int);
bool check_array(int[], int);

void bubbleSort(int[], int);
void insertionSort(int[], int);
void selectionSort(int[], int);

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

    return 0;
}

void init_array(int ary[], int sizeOfAry)
{
    for(int i = 0; i < sizeOfAry; i++)
    {
        ary[i] = rand() % 500;
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
