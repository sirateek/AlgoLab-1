#include <iostream>

using namespace std;


int main() {
    int number;
    cin >> number;
    int cache_number = number;
    int reversed_number = 0;
    do {
        int digit = cache_number%10;
        reversed_number *= 10;
        reversed_number += digit;
        cache_number /= 10;
    } while(cache_number != 0);

    if (reversed_number == number) {
        cout << "yes";
    } else {
        cout << "no";
    }
    
}