#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include <chrono>
#include <iomanip>

#include "sort_methods/bubble_sort.cpp"
#include "sort_methods/select_sort.cpp"
#include "sort_methods/insert_sort.cpp"
#include "sort_methods/merge_sort.cpp"
#include "sort_methods/quick_sort.cpp"

#define ARRAY_SIZE 9999
#define RANGE_RANDOM_VALUES 999999


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
    std::vector<int>numbers(RANGE_RANDOM_VALUES);
    std::iota(numbers.begin(), numbers.end(), 0);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    std::vector<int> random_array(numbers.begin(), numbers.begin() + ARRAY_SIZE);
    return random_array;
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
