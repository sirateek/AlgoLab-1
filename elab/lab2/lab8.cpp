#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int numbers[1000];
    
    for (int i=0; i<n; i++) {
        numbers[i] = i + 1;
    }

    int start_pos = 0;
    for (int i=0; i<n; i++) {
        int cache_pos=start_pos;
        for (int j=0; j<n; j++) {
            cout << numbers[cache_pos];
            cache_pos++;
            if (cache_pos == n){
                cache_pos = 0;
            }
        }
        cout << "\n";
        start_pos++;
    }
}