#include <iostream>

using namespace std;

int main() {
    string line;
    string total_text;
    while (getline(cin, line)) { 
        total_text += line + "\n";
    }
    
    bool is_first = true;
    string result_text;
    for (int i = 0;i<total_text.size(); i++) {
        char focused_text = total_text[i];
        if (focused_text == '"') {
            if (is_first) {
                result_text += "``";
            } else {
                result_text += "''";
            }
            is_first = !is_first;
        } else {
            result_text += focused_text;
        }
    }
    cout << result_text;
  return 0;
}
