#include <iostream>
using namespace std;

char *write_chars(char *dest, const char *st) {
  while (true) {
    if (*st == '\0') {
      break;
    }
    *dest = *st;
    dest++;
    st++;
  }
  return dest;
}

void escape(char *src, char *dest) {

  while (true) {
    if (*src == '<') {
      dest = write_chars(dest, "&lt;");
    } else if (*src == '>') {
      dest = write_chars(dest, "&gt;");
    } else if (*src == '"') {
      dest = write_chars(dest, "&quot;");
    } else {
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
  escape(st, out);

  cout << out << endl;
}