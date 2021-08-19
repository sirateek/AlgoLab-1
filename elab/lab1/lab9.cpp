#include <iostream>

using namespace std;

int main()
{
    int number_of_packages;
    int packages[50];
    cin >> number_of_packages;
    for (int i = 0; i < number_of_packages; i++)
    {
        cin >> packages[i];
    }

    int total_truck = 1;
    int cache_weight = 0;
    for (int i = 0; i < number_of_packages; i++)
    {
        if (packages[i] + cache_weight > 1000)
        {
            total_truck++;
            cache_weight = packages[i];
            continue;
        }
        cache_weight += packages[i];
    }
    cout << total_truck;
}