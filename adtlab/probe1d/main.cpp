#include "probelib.h"
#include <iostream>

using namespace std;

int main() {
  int end = probe_init();
  int start = 0;

  while (true) {
    int mid = (start + end) / 2;
    if (probe_check(start, mid)) {
      end = mid;
    } else {
      start = mid + 1;
    }

    if (start == end) {
      break;
    }
  }
  probe_answer(start);
  return 0;
}
