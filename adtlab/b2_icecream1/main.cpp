#include <iostream>

using namespace std;

struct Customer {
  int id;
  Customer *next;

  Customer(int customerId, Customer *nextCustomer)
      : id(customerId), next(nextCustomer) {}
};

void add_customer(Customer *dummy_customer, int customer_id) {
  Customer *last_customer = dummy_customer;
  while (last_customer->next != nullptr) {
    last_customer = last_customer->next;
  }
  last_customer->next = new Customer(customer_id, nullptr);
}

void customer_arrive(Customer *dummy_customer) {
  int num_customer;
  cin >> num_customer;
  for (int i = 0; i < num_customer; i++) {
    int customer_id;
    cin >> customer_id;
    add_customer(dummy_customer, customer_id);
  }
}

void serve_customer(Customer *dummy_customer) {
  Customer *first_customer = dummy_customer->next;
  cout << first_customer->id << endl;
  dummy_customer->next = first_customer->next;
  delete first_customer;
}

int main() {
  int m;
  cin >> m;

  Customer *dummy_customer = new Customer(-1, nullptr);

  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      customer_arrive(dummy_customer);
    } else {
      serve_customer(dummy_customer);
    }
  }

  int count = 0;
  while (dummy_customer->next != nullptr) {
    dummy_customer = dummy_customer->next;
    count++;
  }
  cout << count;
  return 0;
}
