
#include <iostream>  // ostream

#include "ll_node.h"  // No additional inclusion

using std::ostream;

enum sort_order { UNORDERED, ASCENDING, DESCENDING };
enum print_style { HEAD, TAIL };

template <typename T>
class linked_list {
 private:
  ll_node<T> *head;
  ll_node<T> *tail;
  sort_order order;

 public:
  /*** Constructors ***/
  linked_list(sort_order order = UNORDERED)
      : head(nullptr), tail(nullptr), order(order) {}
  ~linked_list();

  /*** Mutator Functions ***/
  void insert_value(T);
  void delete_value(T);

  /*** Accessor Functions ***/
  void pretty_print() const;
  void print(print_style = HEAD) const;
  ll_node<T> *search(T) const;

 private:
  /*** Mutators ***/
  void insert_node(ll_node<T> *);
  void delete_node(ll_node<T> *);
};

#include "linked_list.tpp"