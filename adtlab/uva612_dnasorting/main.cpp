#include <iostream>

using namespace std;

struct DNA {
  string text;
  int inversion;
};

void find_inversion(DNA *dna, int length) {
  int inversion = 0;
  for (int i = 0; i < length - 1; i++) {
    // Loop each char
    for (int j = i + 1; j < length; j++) {
      if (dna->text[i] > dna->text[j]) {
        inversion++;
      }
    }
  }
  dna->inversion = inversion;
}

void sort_dna(DNA list[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0) {
      if (list[j].inversion < list[j - 1].inversion) {
        DNA cache = list[j];
        list[j] = list[j - 1];
        list[j - 1] = cache;
      } else {
        break;
      }
      j--;
    }
  }
}

int main() {
  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int text_length, num_text;
    cin >> text_length >> num_text;
    DNA dna[num_text];
    for (int j = 0; j < num_text; j++) {
      DNA dna_cache;
      cin >> dna_cache.text;
      find_inversion(&dna_cache, text_length);
      dna[j] = dna_cache;
    }
    sort_dna(dna, num_text);

    for (int j = 0; j < num_text; j++) {
      cout << dna[j].text << endl;
    }
    if (i + 1 < m) {
      cout << endl;
    }
  }
}
