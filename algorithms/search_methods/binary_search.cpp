#include <iostream>
#include <vector>
#include "../sort_methods/quick_sort.cpp"

int search(std::vector<int> array, int key)
{
    int low = 0 , higth = static_cast<int>(array.size());

    while (low <= higth){
        int mid = (low + higth) / 2;
        if(array.at(mid) == key)
        {
            return mid;
        }

        if(array.at(mid) > key)
        {
            higth = mid - 1;
        } else
        {
            low = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int key;
    std::vector<int> array {7, 23, 1, 65389, 9, 3, 40, 5, 10};

   array = quick_sort(array);

    std::cout << "Digite um valor: ";
    std::cin >> key;

    std::cout << "Position: " << search (array, key) << std::endl;
    return 0;
}
