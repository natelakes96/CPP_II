/*
* Name : Nathaniel Stone , 8000617279 , 202.1002 , ASSIGNMENT_ 2
* Description : Defines the functions used for the Inventory and Player
                clsses.
* Input : No input, just calling functions from a main function.
* Output : output in the terminal of player actions and attributes
*/

#include <iostream>
#include "player.h"

using namespace std;

/* ************************************************
    Inventory Class Definitions
* ************************************************/
/*
    The destructor must deallocate memory allocated to each
    slot. Use a loop to go through the slots array and deallocate
    memory for each Item.

    Write your code below this block (with documentation).
*/

/**
 * @brief Destructor for the Inventory class. Will deallocate memory for each new item.
 * @return Nothing.
 */
Inventory::~Inventory()
{
    for (int i = 0; i < 5; i++)
    {
        if (slots[i] != nullptr)
        {
            delete slots[i];
        }
    }
}

/*
    Implement the addItem(Item*) function. The item must be
    inserted in the first free slot found in the slots array.
    For example, if slots 0, 2, and 4 are filled, then the new
    item should be inserted into slot 1. Remember to decrement
    the emptySlots counter. This returns the slot number where
    the new item was inserted.

    Write your code below this block (with documentation).
*/

/**
 * @brief This adds an item to a players inventory
 * @param item a pointer to an item
 * @return an int that will either be -1 or the slot of inventory that was filled.
 */
int Inventory::addItem(Item *item)
{
    // checks if there are empty slots
    if (emptySlots == 0)
    {
        return -1; // returns -1 if there are zero empty slots
    }
    // checks for empty slots and puts the item in the first available slot
    else if (emptySlots > 0)
    {
        for (int i = 0; i < 5; i++) // loop to go through all the inventory slots
        {
            if (slots[i] != nullptr) // checks if item slot is a nullptr
            {
                continue; // continues to next loop
            }
            else if (slots[i] == nullptr) // checks if slot is a null ptr
            {
                slots[i] = item; // assigns the item slot ptr to the item
                emptySlots--;    // subracts one from empty slots
                return i;        // returns the slot that was filled
            }
        }
    }
    return -1;
}

/*
    Implement the removeItem(int) function. Removes the item
    from the slot number given in the function parameter. If
    no item is found at that slot, return false. Otherwise,
    remove the item and return true. Make sure to increment the
    emptySlots counter.

    Write your code below this block (with documentation).
*/

/**
 * @brief Removes an item from a players inventory.
 * @param slot The slot in the inventory that needs the item removed.
 * @return a bool saying it was successfull or not.
 */
bool Inventory::removeItem(int slot)
{
    if (getSlot(slot) != nullptr)
    {
        delete getSlot(slot);
        slots[slot] = nullptr;
        emptySlots++;
        return true;
    }
    else
    {
        return false;
    }
}
/* ************************************************
    Player Class Definitions
* ************************************************/

/*
    This function depends on the addItem(Item*) function
    from the Inventory class. It needs to be implemented
    for this to work.
*/
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

/*
    This function depends on the removeItem(int) function
    from the Inventory class. It needs to be implemented
    for this to work.
*/
/**
 * Drops an item from the given inventory slot.
 * If the slot is empty, nothing will be dropped.
 *
 * @param slot Slot number of item to drop.
 * @return None.
 */
void Player::drop(int slot)
{
    if (slot > 4 || slot < 0)
    {
        cout << playerName << ": Nothing to drop!\n";
    }
    else
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
}

/*
    Only Healing items can be used. Other items should
    make the player say "Cannot use <item name>". Note
    that when an item is used, it must be removed from
    the inventory. If there's no item in the slot, the
    player must say "No item in this slot." When a healing
    item is used, the player must say "Used <item name>".
    Use static_cast to cast parent class to the required
    subclass. See the showPlayer() function for reference.

    Note: Player can have infinite HP and Shields. We're
    playing in cheat mode.

    Write your code below this block (with documentation).
*/
/**
 * @brief This will use an item as long as its a healing item.
 * @param slot The slot of the item you would like to use.
 * @return Nothing.
 */
void Player::useItem(int slot)
{
    // cout << "start of use item" << endl;
    Item *item = inventory.getSlot(slot);
    // cout << "assigned item pointer" << endl;

    if (item != nullptr)
    {
        if (item->getItemType() != ItemType::HEALING)
        {
            cout << playerName << ": Cannot use " << item->getName() << endl;
        }
        else
        {
            cout << playerName << ": Used " << item->getName() << endl;
            if (static_cast<Healing *>(item)->getHealType() == HealType::HP)
            {
                // access and update hp
                hp = hp + static_cast<Healing *>(item)->getAmount();
            }
            else if (static_cast<Healing *>(item)->getHealType() == HealType::SHIELD)
            {
                shield = shield + static_cast<Healing *>(item)->getAmount();
            }

            inventory.removeItem(slot);
        }
    }
    else
    {
        cout << playerName << ": No item in slot " << slot << endl;
    }
}

/*
    Note the use of static_cast in this function. We can
    use static_cast to typecast a parent class to any of
    its subclasses. Static cast ensures that any casting
    errors are caught at compile time.
*/
/**
 * Prints the player's hp, shields and inventory.
 *
 * @return None.
 */
void Player::showPlayer() const
{
    Item *item;
    cout << "\n"
         << playerName << " : " << hp << "(" << shield << ")\n";
    cout << "Inventory: \n";
    for (int i = 0; i < 5; i++)
    {
        // cout << "Beginning of loop" << endl;
        item = inventory.getSlot(i);
        // cout << "Just after getSlot" << endl;
        if (item == nullptr)
        {
            // cout << "was flagged as nullptr" << endl;
            continue;
        }
        cout << i;
        // cout << "just before switch statement" << endl;
        switch (item->getItemType())
        {
        case ItemType::WEAPON:
            static_cast<Weapon *>(item)->printWeapon();
            break;
        case ItemType::HEALING:
            static_cast<Healing *>(item)->printHealing();
            break;
        case ItemType::UTILITY:
            static_cast<Utility *>(item)->printUtility();
            break;
        default:
            std::cout << "Unknown Item";
        }
        // cout << "end of loop" << endl;
    }
}