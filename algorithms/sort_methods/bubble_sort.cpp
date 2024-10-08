#include <iostream>
#include <vector>


std::vector<int> bubble_sort(std::vector<int>array)
{
    for(int i = 0; i < array.size() - 1; i++)
    {
        for(int j = 0; j < array.size() - 1; j++)
        {
            if(array.at(j) > array.at(j + 1))
            {
               int temp = array.at(j);
               array.at(j) = array.at(j + 1);
               array.at(j + 1) = temp;
            }
        }
    }
    return array;
}

