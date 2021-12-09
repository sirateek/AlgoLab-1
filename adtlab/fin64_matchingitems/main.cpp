#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> items_store;
set<int> items;
int n, q;

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    items.insert(p);
    items_store.push_back(p);
  }

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--;

    int buy_price = items_store[x];
    int at_most = buy_price + y;
    auto upper = items.upper_bound(at_most);
    auto lower = items.lower_bound(at_most);
    upper--;
    int upper_data = *upper;
    int lower_data = *lower;
    if (upper_data <= at_most) {
      cout << lower_bound(items_store.begin(), items_store.end(), upper_data) -
                  items_store.begin() + 1
           << endl;
    } else {
      cout << lower_bound(items_store.begin(), items_store.end(), lower_data) -
                  items_store.begin() + 1
           << endl;
    }
  }
  return 0;
}
