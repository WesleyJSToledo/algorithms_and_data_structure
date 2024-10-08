#include <iostream>
#include <vector>

std::vector<int> insert_sort(std::vector<int> array)
{
    for(int i = 0; i < array.size(); i++)
    {
        int temp = array[i];
        int j = i;
        while ((j > 0) && (array[j - 1] > temp))
        {
            array[j] = array[j-1];
            j = j - 1;
        }
        array[j] = temp;
    }
    return array;
}