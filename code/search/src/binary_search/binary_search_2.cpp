/* Part of Cosmos by OpenGenus Foundation */

#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

/* Utility functions */

void fill(std::vector<int> &v)
{
    for (auto& elem : v)
        elem = rand() % 100;
}

void printarr(std::vector<int> &v)
{
    for (const auto& elem : v)
        std::cout << elem << " ";
    std::cout << "\n";
}

/* Binary search with fewer comparisons */
int binary_search(std::vector<int> &v, int key)
{
    int m;

    int l = 0, r = v.size();

    while (r - l > 1)
    {
        m = l + (r - l) / 2;

        if (v[m] > key)
            r = m;
        else
            l = m;
    }

    if (v[l] == key)
        return l;
    else
        return -1;
}

/* Driver program */
int main()
{
    int size;
    std::cout << "Enter the array size:";
    std::cin >> size;

    std::vector<int> v(size);
    fill(v);

    std::cout << "Array (sorted) : ";
    sort(v.begin(), v.end());
    printarr(v);

    std::cout << "Search for (input search key) : ";
    int key;
    std::cin >> key;

    std::cout << "Found " << key << " at index " << binary_search(v, key) << "\n";
}
