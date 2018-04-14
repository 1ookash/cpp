#include <iostream>
#include <ctime>

using namespace std;

void quickSort(int array[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2];
    int tmp;


    while (i <= j)
    {
        while(array[i] < pivot)
        {
            i ++;
        }
        while(array[j] > pivot)
        {
            j --;
        }
        if(i <= j)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i ++;
            j --;
        }
    }


    if(left < j)
    {
        quickSort(array, left, j);
    }
    if(right > i)
    {
        quickSort(array, i, right);
    }
}

void printArray(int array[], int size)
{
    for(int i = 0; i < size; i ++)
    {
        cout << array[i] << " ";
    }
}

void fillArray(int array[], int size)
{
    for(int i = 0; i < size; i ++)
    {
        array[i] = rand() % 100 + 1;
    }
}

int main() {
    int array[20];


    srand(time(NULL));


    fillArray(array, 20);
    printArray(array, 20);
    quickSort(array, 0, 19);
    cout << endl;
    printArray(array, 20);
    return 0;
}