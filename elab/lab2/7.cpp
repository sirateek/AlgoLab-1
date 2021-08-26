#include <iostream>
using namespace std;

void remove_quotes(char *src, char *dest) {

  while (true) {
    if (*src != '"' && *src != '\'') {
      *dest = *src;
      dest++;
    }
    if (*src == '\0') {
      break;
    }
    src++;
  }
}

int main() {
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st, 1000);
  remove_quotes(st, out);

  cout << out << endl;
}