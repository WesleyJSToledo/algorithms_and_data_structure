#include <iostream>
#include <vector>


std::vector<int> merge_array;

void intercalation(int begin, int mid, int end)
{
    std::vector<int> aux = std::vector<int>(merge_array.size());
    int i = begin;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= end)
    {
        if(merge_array[i] < merge_array[j])
        {
            aux[k++] = merge_array[i++];
        }
        else
        {
            aux[k++] = merge_array[j++];
        }
    }
    while (i <= mid )
    {
        aux[k++] = merge_array[i++];
    }
    while (j <= end )
    {
        aux[k++] = merge_array[j++];
    }
    for(i = 0; i < (end - begin + 1); i++)
    {
        merge_array[begin + i] = aux[i];
    }
}

void merge_sort(int begin, int end)
{
    if(begin == end) return;
    int mid = (begin + end) / 2;
    merge_sort(begin, mid);
    merge_sort(mid+1, end);
    intercalation(begin, mid, end);

}

std::vector<int>merge_sort(std::vector<int> array_int)
{
    merge_array = array_int;
    merge_sort(0, static_cast<int>(merge_array.size()));
    return merge_array;
}
