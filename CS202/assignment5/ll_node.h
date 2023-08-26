/**
 * @file ll_node.h
 * @author Benjamin Zofcin
 * @brief
 * Temploid node for a doulbly linked list
 * @date 2023-08-04
 */

/**
 * @brief
 * Each doulbly linked list node will encapsulate
 * data of some type T and 2 pointers to reference
 * the precursor and successor nodes.
 *
 * @tparam T 
 * Can be of any type in the system
 * 
 * Ensure to overload the comparison (<,>,<=,>=) 
 * operators for the linked lists that you wish
 * to store class objects.
 */
template <typename T>
struct ll_node {
  T data;
  ll_node<T> *next;
  ll_node<T> *prev;

  ll_node(T d) : data(d), next(nullptr), prev(nullptr){};
};
