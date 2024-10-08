#include <iostream>
#include <vector>

std::vector<int> quick_array;

void quick_sort(int left, int right)
{
    int i = left;
    int j = right;
    int pivot = quick_array[(left+right)/2];
    int aux;
    do{
        while (quick_array[i] < pivot && i < right)
        {
            i++;
        }
        while (pivot < quick_array[j] && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            aux = quick_array[i];
            quick_array[i] = quick_array[j];
            quick_array[j] = aux;
            i++;
            j--;
        }

    }while (i <= j );

    if(left < j)
    {
        quick_sort(left, j);
    }
    if(i < right)
    {
        quick_sort(i, right);
    }
}

std::vector<int>quick_sort(std::vector<int> array_int)
{
    quick_array = array_int;
    quick_sort(0,quick_array.size());
    return quick_array;
}
