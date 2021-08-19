#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int number_of_house, focused_distance;
    cin >> number_of_house >> focused_distance;
    int house_positions[number_of_house];
    for (int i = 0; i < number_of_house; i++)
    {
        cin >> house_positions[i];
    }

    int count = 0;
    for (int i = 0; i < number_of_house; i++)
    {
        for (int j = 0; j < number_of_house; j++)
        {
            if (i != j && abs(house_positions[i] - house_positions[j]) <= focused_distance)
            {
                count++;
            }
        }
    }
    cout << count / 2;
}