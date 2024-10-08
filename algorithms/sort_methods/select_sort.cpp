#include <iostream>
#include <vector>

int select_min(std::vector<int> array)
{
    int small_index = 0;

    for(int i = 0; i < array.size(); i++)
    {
        if(array.at(i) < array.at(small_index)){
            small_index = i;
        }
    }
    return small_index;
}

std::vector<int> select_sort(std::vector<int> array)
{
    std::vector<int> sort_array;
    int size = static_cast<int>(array.size());
    for(int i = 0; i < size; i++)
    {
        int j = select_min(array);
        sort_array.push_back(array.at(j));
        array.erase(std::next(array.begin(), j));
    }
    return sort_array;
}
