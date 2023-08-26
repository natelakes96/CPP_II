/**
 * @file main.cpp
 * @author Benjamin Zofcin
 * @brief
 * Provides unit testing the linked list data structure
 * methods implemented in linked_list.tpp.
 *
 * Feel free to expand this file if you want to implement 
 * other checks. At the very least, every in this file should
 * print out with no issue
 * @version 0.1
 * @date 2023-08-04
 */

#include <random>

#include "linked_list.h"

void print_empty() {
  linked_list<int> LL;
  LL.print();
  // LL.pretty_print();
}

void test_ordered_insert(sort_order order) {
  linked_list<int> LL(order);
  LL.insert_value(18);
  LL.insert_value(3);
  LL.insert_value(6);
  LL.insert_value(6);
  LL.insert_value(10);
  LL.insert_value(0);
  LL.print(HEAD);
  LL.print(TAIL);
}

void delete_value(int S, int E, int T) {
  linked_list<int> LL;
  for (int i = S; i <= E; i++) LL.insert_value(i);
  cout << "List Before Deletion" << endl;
  LL.print();
  LL.print(TAIL);

  LL.delete_value(T);
  cout << "List After Deletion" << endl;
  LL.print();
  LL.print(TAIL);
}

void search_list(int S, int E, int T) {
  linked_list<int> LL;
  for (int i = S; i <= E; i++) LL.insert_value(i);
  cout << LL.search(T)->data << endl;
}

template <typename T>
void template_ll_creation(int S, int E) {
  std::random_device rdev{};
  std::default_random_engine num{rdev()};
  std::uniform_real_distribution<double> randomNum{1, 10};

  linked_list<T> LL(DESCENDING);
  for (int i = S; i <= E; i++) {
    LL.insert_value(randomNum(num));
  }
  LL.print();
  LL.print(TAIL);
}

void succesful_checks() {
  cout << "Printing an Empty list " << endl;
  print_empty();

  cout << "\nUnordered Sort\n";
  test_ordered_insert(UNORDERED);

  cout << "\nAscending Order \n";
  test_ordered_insert(ASCENDING);

  cout << "\nDescending Order \n";
  test_ordered_insert(DESCENDING);

  cout << "\nSingle value delete\n";
  delete_value(1, 1, 1);

  cout << "\nDelete Head\n";
  delete_value(1, 3, 1);

  cout << "\nDelete Tail\n";
  delete_value(1, 3, 3);

  cout << "\nDelete Mid\n";
  delete_value(1, 3, 2);

  cout << "\nSearching for data\n";
  search_list(1, 3, 1);
  search_list(1, 3, 2);
  search_list(1, 3, 3);

  cout << "\nAttempt double type linked list\n";
  template_ll_creation<double>(1, 5);
  cout << "\n";
}

void error_checking() {
  linked_list<int> LL;

  // Error should mention an empty list
  LL.delete_value(0);

  LL.insert_value(0);

  // Error should mention it could not find a node with given value
  LL.delete_value(1);
}

int main(int argc, char const *argv[]) {
  succesful_checks();
  error_checking();
  return 0;
}
