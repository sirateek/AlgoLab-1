#include <iostream>
using namespace std;


int main() {

    int n;
    int heights[100];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> heights[i];
    }

    for(int i=0; i<n; i++){
        int current_height = heights[i];
        int count = 0;
        for(int j=0; j<n; j++){
            if (heights[j] > current_height) {
                count ++;
            }
        }
        cout << count << "\n";
    }
}
