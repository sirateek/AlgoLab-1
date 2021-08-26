#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  int n = 0;
  int k = 0;
  int prices[1000];
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  bool is_has_stock = false;
  int money = 0;
  int cache_money = 0;
  for (int i = 1; i < n; i++) {
    if (abs(prices[i] - prices[i - 1]) >= k) {
      if ((prices[i] - prices[i - 1]) < 0 && is_has_stock == true) {
        // Sell;
        money += prices[i] - cache_money;
        is_has_stock = false;
      } else if ((prices[i] - prices[i - 1]) > 0 && is_has_stock == false) {
        // Buy
        cache_money = prices[i];
        is_has_stock = true;
      }
    }
  }
  cout << money;
  return 0;
}
