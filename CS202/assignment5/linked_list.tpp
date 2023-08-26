/**
 * @file linked_list.tpp
 * @author Nathaniel Stone, NSHE 8000617279
 * @brief This file will define the destructor, insert value
 *        insert node, pretty print, print, search, delete value,
 *        and delete node functions.
 *
 *
 */

using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

#include <iomanip>
using std::setfill;
using std::setw;

#include <stdexcept>
using std::exception;

class LinkedListException : public exception
{
  string message;

public:
  LinkedListException(string msg = "") : message(msg){};
  ~LinkedListException(){};
  const char *what() const noexcept { return message.c_str(); }
};

/**
 * @brief Destroy the linked list<T>::linked list object
 *
 * @tparam T
 */
template <typename T>
linked_list<T>::~linked_list()
{
  if (head == nullptr || tail == nullptr)
  {
    return;
  }
  else
  {
    while (head != tail)
    {
      head = head->next;
      delete head->prev;
    }
    delete head;
  }
}

/**
 * @brief creates a new node and inserts it into the linked list
 *
 * @tparam T tyoe of data to be stored in a node.
 * @param value the data to be stored in a node.
 */
template <typename T>
void linked_list<T>::insert_value(T value)
{
  ll_node<T> *point = new ll_node<T>(value);
  insert_node(point);
}

/**
 * @brief inserts a node into the linked list.
 *
 * @tparam T the type of data in the node
 * @param node pointer to a node you want to add to the list
 */
template <typename T>
void linked_list<T>::insert_node(ll_node<T> *node)
{
  // Check for empty list
  if (head == nullptr && tail == nullptr)
  {
    head = node;
    tail = node;
    return;
  }

  // Switch on sort order
  switch (order)
  {
  case UNORDERED: // If unordered insert at back
    // point current last to new node
    tail->next = node;
    // point the nodes next to tail
    node->prev = tail;
    // point tail to new node
    tail = node;
    break;

  case ASCENDING:
    // Input node is greater than or the same as the current maximum
    if (node->data >= tail->data)
    {
      tail->next = node;
      node->prev = tail;
      tail = node;
    }
    // Input node is less than or the same as the current minumum
    else if (node->data <= head->data)
    {
      node->next = head;
      head->prev = node;
      head = node;
    }
    else
    { // Otherwise parse the remainder of the list
      // The insert loction must be between head and tail
      ll_node<T> *iterator = head->next;
      while (iterator != nullptr)
      {
        // Search until the current iterator's data is greater than the
        // targets
        if (node->data > iterator->data)
        {
          iterator = iterator->next;
          continue;
        }
        node->prev = iterator->prev;
        node->next = iterator;
        iterator->prev->next = node;
        iterator->prev = node;
        break;
      }
    }
    break;

  case DESCENDING:
    // check if input head is greater than or equal to first node data
    if (node->data >= head->data)
    {
      // insert node
      node->next = head;
      head->prev = node;
      head = node;
    }
    // check if end data is smaller than
    else if (node->data <= tail->data)
    {
      // insert node
      tail->next = node;
      node->prev = tail;
      tail = node;
    }
    // go through the whole list and see where you can insert the node
    else
    {
      ll_node<T> *iterator = head->next;
      while (iterator != nullptr)
      {
        // Search until the current iterator's data is less than the
        // targets
        if (node->data < iterator->data)
        {
          iterator = iterator->next;
          continue;
        }
        node->prev = iterator->prev;
        node->next = iterator;
        iterator->prev->next = node;
        iterator->prev = node;
        break;
      }
    }

    break;
  default:
    cout << "FATAL ERROR :: Insertion option not recognized\n";
    break;
  }
}

/**
 * @brief
 *
 * @tparam T
 * @param out
 */
template <typename T>
void linked_list<T>::pretty_print() const
{
  const int width = 8;
  string next_arrow = u8" |       \n \u22C1      ";
  string prev_arrow = u8"      \u22C0  \n      | ";
  string both_arrow = u8" |    \u22C0  \n \u22C1    | ";

  ll_node<T> *p = head;

  cout << setfill('-') << setw(width) << '-' << endl
       << "| HEAD |" << endl
       << setw(width) << '-' << endl
       << next_arrow << endl;

  while (p != nullptr)
  {
    cout << setw(width) << '-' << endl
         << setfill(' ') << "|" << setw(width - 2) << p->data << "|" << endl
         << setfill('-') << setw(width) << '-' << endl;

    p = p->next;
    if (p == nullptr)
      break;
    cout << both_arrow << endl;
  }

  cout << prev_arrow << endl
       << setw(width) << '-' << endl
       << "| TAIL |" << endl
       << setw(width) << '-' << endl;
}

/**
 * @brief prints a linked list based off starting point being
 *        tail or head.
 *
 * @tparam T
 * @param path where the print funciton should start iterating from.
 */
template <typename T>
void linked_list<T>::print(print_style path) const
{
  if (head == nullptr || tail == nullptr)
    return;

  ll_node<T> *iterator;
  const int W = 4;
  if (path == HEAD)
  {
    iterator = head;
    cout << "Head";
    do
    {
      cout << "-> " << setw(W) << iterator->data;
      iterator = iterator->next;
    } while (iterator != nullptr);
    cout << endl;
  }
  else
  {
    iterator = tail;
    cout << "Tail";
    do
    {
      cout << "-> " << setw(W) << iterator->data;
      iterator = iterator->prev;
    } while (iterator != nullptr);
    cout << endl;
  }
}

/**
 * @brief performs a linear search to find a node with a specific value.
 *
 * @tparam T type of value searched for.
 * @param target The value to be searched for.
 * @return ll_node<T>*
 */
template <typename T>
ll_node<T> *linked_list<T>::search(T value) const
{
  string msg = "Value " + to_string(value) + " not found in list!";
  // see if list is empty
  try
  {
    if (head == nullptr && tail == nullptr)
    {
      throw LinkedListException("This list is empty!");
    }
  }
  catch (const LinkedListException)
  {
    throw;
  }

  // linear search of list
  try
  {
    // temp node
    ll_node<T> *iterator = head;
    // while data is not equal to the value
    while (iterator->data != value)
    {
      // check if we are at the end of the list
      if (iterator->next == nullptr)
      {
        throw LinkedListException(msg);
      }

      // assign iterator to point to the next node
      iterator = iterator->next;
    }

    return iterator;
  }
  catch (const LinkedListException)
  {
    throw;
  }
}

/**
 * @brief This deletes a value from a linked list.
 *
 * @tparam T the type of the value to be deleted
 * @param value the value that is to be deleted
 */
template <typename T>
void linked_list<T>::delete_value(T value)
{
  ll_node<T> *target = nullptr;
  try
  {
    target = search(value);
  }
  catch (LinkedListException lle)
  {
    cout << "Error :: " << lle.what() << endl;
    return;
  }
  delete_node(target);
}

/**
 * @brief This deletes a node that is passed in.
 *
 * @tparam the type that is to be deleted
 * @param target a pointer to the node that is to be deleted.
 */
template <typename T>
void linked_list<T>::delete_node(ll_node<T> *target)
{
  // if target is the head
  if (target->next == nullptr && target->prev == nullptr)
  {
    delete target;
    head = nullptr;
    tail = nullptr;
  }
  else if (target == head)
  {
    head = target->next;
    target->next->prev = nullptr;
    delete target;
  }
  // if target is the tail
  else if (target == tail)
  {
    tail = target->prev;
    target->prev->next = nullptr;
    delete target;
  }
  // if list has one element
  // if target is in middle of list
  else
  {
    target->prev->next = target->next;
    target->next->prev = target->prev;
    delete target;
  }
}
