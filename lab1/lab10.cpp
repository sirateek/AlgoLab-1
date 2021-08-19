#include <iostream>

using namespace std;

int find_gcd(int number_1, int number_2){
    int smallest_number = number_1 < number_2 ? number_1 : number_2;
    int result_gcd = 2;
    for (int i=2; i<=smallest_number; i++) {
        if (number_1 % i == 0 && number_2 % i == 0) {
            if (i > result_gcd) {
                result_gcd = i;
            }
        }
    }
    return result_gcd;
}

int main()
{
    int number_1, number_2;
    cin >> number_1 >> number_2;
    int gcd = find_gcd(number_1, number_2);
    cout << number_1 / gcd << "/" << number_2 / gcd;

}
