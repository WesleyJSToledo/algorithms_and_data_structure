#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>

#include "sort_methods/bubble_sort.cpp"
#include "sort_methods/select_sort.cpp"
#include "sort_methods/insert_sort.cpp"
#include "sort_methods/merge_sort.cpp"
#include "sort_methods/quick_sort.cpp"

#define ARRAY_SIZE 9999
#define RANGE_RANDOM_VALUES 99999


void print_list(std::vector<int> array)
{
    std::cout << "[ ";
    for(int i = 0; i < array.size(); i++)
    {
        std::cout << array.at(i);
        if(i != array.size() - 1)
        {
            std::cout<< ", ";
        }
    }
    std::cout << " ]\n";
}

bool is_duplicate(std::vector<int>array, int value)
{
    for(int a : array)
    {
        if(a == value)
        {
            return true;
        }
    }
    return false;
}

std::vector<int> random_array()
{
    std::vector<int> array;

    srand(time(0));
    int i = 0;
    while (i < ARRAY_SIZE)
    {
        int value = rand() % RANGE_RANDOM_VALUES;
        if(!is_duplicate(array, value))
        {
            array.push_back(value);
            i++;
        }
    }
    return array;
}

void search_methods()
{

}

void sort_methods()
{
    std::vector<int> array;
    std::vector<int> sorted_array;

    double time_taken;

    array = random_array();

    auto start = std::chrono::high_resolution_clock::now();
    sorted_array = bubble_sort(array);
    auto end = std::chrono::high_resolution_clock::now();
    time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

    std::cout << "Bubble Sort: " << std::fixed << time_taken << std::setprecision(10) << " seg\n";



    start = std::chrono::high_resolution_clock::now();
    sorted_array = select_sort(array);
    end = std::chrono::high_resolution_clock::now();
    time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

    std::cout << "Select Sort: " << std::fixed << time_taken << std::setprecision(10) << " seg\n";


    start = std::chrono::high_resolution_clock::now();
    sorted_array = insert_sort(array);
    end = std::chrono::high_resolution_clock::now();
    time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

    std::cout << "Insert Sort: " << std::fixed << time_taken << std::setprecision(9) << " seg\n";

    start = std::chrono::high_resolution_clock::now();
    sorted_array = merge_sort(array);
    end = std::chrono::high_resolution_clock::now();
    time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

    std::cout << "Merge Sort: " << std::fixed << time_taken << std::setprecision(9) << " seg\n";

    start = std::chrono::high_resolution_clock::now();
    sorted_array = quick_sort(array);
    end = std::chrono::high_resolution_clock::now();
    time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

    std::cout << "Quick Sort: " << std::fixed << time_taken << std::setprecision(9) << " seg\n";

    system("read -p \"Press ENTER\" exit");
}

int main(int argc, char *argv[])
{
    std::string menu = "0 - Exit \n1 - Search Methods \n2 - Sort Methods\n##############################\n";

    int choice;
    do{
        system("clear");
        std::cout << menu;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            search_methods();
            break;
        case 2:
            sort_methods();
            break;

        }
    }while(choice != 0 );
}
