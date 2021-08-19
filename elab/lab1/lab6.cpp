#include <iostream>

using namespace std;

void print_star_pyramid(int level, int total_level)
{
    for (int i = 0; i < (total_level - level); i++)
    {
        cout << " ";
    }

    for (int i = 0; i < level; i++)
    {
        cout << "*";
    }
    cout << endl;
}

int main()
{
    int number_of_level;
    cin >> number_of_level;
    for (int i = 1; i <= number_of_level; i++)
    {
        print_star_pyramid(i, number_of_level);
    }
}