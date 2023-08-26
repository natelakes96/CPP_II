/*
* Name : Nathaniel Stone , 8000617279 , 202.1002 , ASSIGNMENT_ 3
* Description : Defines the functions used for the Inventory and Player
                classes.
* Input : No input, just calling functions from a main function.
* Output : output in the terminal of player actions and attributes
*/

#include "player.h"

#include <iostream>

using namespace std;

/**
 * @brief Destroy the Inventory object
 *
 */
Inventory::~Inventory()
{
  if (emptySlots < 5)
  {
    for (Item *slot : slots)
    {
      if (slot != nullptr)
      {
        delete slot;
      }
    }
  }
}

/**
 * Add an item to the inventory.
 * This will be added to the first empty slot found.
 *
 * @param item Pointer to a valid item.
 * @return int Slot index where the item was inserted.
 */
int Inventory::addItem(Item *item)
{
  if (emptySlots > 0)
  {
    for (int i = 0; i < 5; i++)
    {
      if (slots[i] == nullptr)
      {
        slots[i] = item;
        emptySlots -= 1;
        return i;
      }
    }
  }
  return -1;
}

/**
 * Removes an item from an inventory slot.
 *
 * Deallocates memory as needed and increments emptySlots.
 *
 * @param slot Slot index to remove from.
 * @return true if the item was removed.
 * @return false if there was no item to remove.
 */
bool Inventory::removeItem(int slot)
{
  if (slots[slot] != nullptr)
  {
    delete slots[slot];
    slots[slot] = nullptr;
    emptySlots += 1;
    return true;
  }
  return false;
}

/**
 * Adds an item to the player inventory.
 * Player will only pickup items if the inventory has
 * space. If not, the item will not be picked up.
 *
 * @param item Pointer to a weapon, healing, or utlility item.
 * @return None.
 */
void Player::pickup(Item *item)
{
  if (inventory.addItem(item) != -1)
  {
    cout << playerName << ": Picked up " << item->getName() << "!\n";
  }
  else
  {
    cout << playerName << ": My inventory is full!\n";
    delete item;
  }
}

/**
 * Drops an item from the given inventory slot.
 * If the slot is empty, nothing will be dropped.
 *
 * @param slot Slot number of item to drop.
 * @return None.
 */
void Player::drop(int slot)
{
  Item *item = inventory.getSlot(slot);
  if (item)
  {
    cout << playerName << ": Dropped " << item->getName() << "!\n";
    inventory.removeItem(slot);
  }
  else
  {
    cout << playerName << ": Nothing to drop!\n";
  }
}

/*
    This function works exactly like the way it did in
    Assignment 2. The only difference is that we won't
    have to use static_cast here because of the way we
    have derived these functions from an abstract base
    class. Go through item.h to understand how this works.

    Use the inventory.getSlot() function to get an item
    from the respective slot. If it's a nullptr, make the
    player say "No item in slot <slot index>" and then
    return. If there is an item in the slot, call the
    getHealType() function directly. If it's HealType::INVALID,
    then the item is not a Healing item and can't be used.
    If it's a HealType::HP item then add the amount to the
    player's HP, otherwise if it's a HealType::SHIELD item
    then add the amount to the player's shield. Remove the item
    from the inventory using the removeItem function. Make
    sure to print the appropriate messages for all above
    cases.

    Write your code below this block (with documentation).
*/

/**
 * @brief Uses an item, as long as its a Healing item.
 * @param slot Index of the item that you want to use.
 * @return Nothing.
 */
void Player::useItem(int slot)
{
  Item *item = inventory.getSlot(slot);

  if (item == nullptr)
  {
    cout << playerName << ": No item in slot " << slot << endl;
    return;
  }
  else
  {
    if (item->getHealType() == HealType::INVALID)
    {
      cout << playerName << ": Cannot use " << item->getName() << endl;
    }
    else if (item->getHealType() == HealType::HP)
    {
      hp = hp + item->getHealAmount();
      cout << playerName << ": Used " << item->getName() << endl;
      inventory.removeItem(slot);
    }
    else if (item->getHealType() == HealType::SHIELD)
    {
      shield = shield + item->getHealAmount();
      cout << playerName << ": Used " << item->getName() << endl;
      inventory.removeItem(slot);
    }

    return;
  }
}

/*
    This function has been partially implemented for you.
    Use a for loop to go through the inventory, get the item,
    and then call the printItem function if it's not a nullptr.
    Make sure to also print the index the way it was done in
    assignment 2. Note that you won't have to use static_cast
    or switch case here.
*/
/**
 * Prints the player's hp, shields and inventory.
 *
 * @return None.
 */
void Player::showPlayer() const
{
  Item *item = nullptr;
  cout << "\n"
       << playerName << " : " << hp << "(" << shield << ")\n";
  cout << "Inventory: \n";

  for (int i = 0; i < 5; i++)
  {
    item = inventory.getSlot(i);
    if (item != nullptr)
    {
      cout << i;
      item->printItem();
    }
    else
    {
      continue;
    }
  }
}