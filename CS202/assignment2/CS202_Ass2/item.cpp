/*
* Name : Nathaniel Stone , 8000617279 , 202.1002 , ASSIGNMENT_ 2
* Description : Defines the functions used for the Item, Weapon,
                Healing and Utility clsses.
* Input : No input, just calling functions from a main function.
* Output : output in the terminal of player actions and attributes
*/

#include <iostream>
#include <iomanip>
#include "item.h"

using namespace std;

/* ************************************************
    Item Class Definitions
* ************************************************/

/*
    This is a helper class used for the printItem.
    It will return a string for the corresponding
    ItemType. Note that this is a static function
    so every object does not have an independent
    copy of it.
*/

/**
 * Returns the ItemType as a string.
 *
 * @param type ItemType enum value.
 * @return Corresponding string for ItemType enum value.
 */
string Item::getItemTypeAsString(ItemType type)
{
    switch (type)
    {
    case ItemType::WEAPON:
        return "Weapon";
    case ItemType::HEALING:
        return "Healing";
    case ItemType::UTILITY:
        return "Utility";
    default:
        return "Unknown";
    }
}

/**
 * Prints an item.
 *
 * @return None.
 */
void Item::printItem() const
{
    std::cout << setw(10) << getItemTypeAsString(item)
              << " : " << setw(20) << name;
}

/* ************************************************
    Weapon Class Definitions
* ************************************************/
/*
    Parameterized constructor for the Weapon class that
    calls the Item constructor to set name and item type.
    This has been provided to you as an example.
*/

/**
 * Parameterized constructor for Weapon class.
 *
 * @param name Name of the weapon.
 * @param ammo Ammo type used by the weapon.
 * @param dmg Damage done by the weapon.
 */
Weapon::Weapon(string name, AmmoType ammo, double dmg) : Item(name, ItemType::WEAPON)
{
    this->ammo = ammo;
    this->dmg = dmg;
}

/**
 * @brief This is a helper function to assisnt with the print function
 * @param type This is the type of ammo
 * @return This returns a string of the ammo type
 */
string Weapon::getAmmoTypeAsString(AmmoType type)
{
    switch (type)
    {
    case AmmoType::HEAVY:
        return "Heavy";
    case AmmoType::MEDIUM:
        return "Medium";
    case AmmoType::LIGHT:
        return "Light";
    case AmmoType::SHELLS:
        return "Shells";
    default:
        return "Unknown";
    }
}

/*
    Note that this print function uses the printItem() function
    from the parent class.
*/
/**
 * Prints the weapon.
 *
 * @return None.
 */
void Weapon::printWeapon() const
{
    Item::printItem();
    cout << " : AMMO " << setw(8) << getAmmoTypeAsString(ammo)
         << " : DMG " << setw(3) << dmg << endl;
}

/* ************************************************
    Healing Class Definitions
* ************************************************/
/*
    Implement the Healing class yourself. Use the examples given
    above to help you.
    # Implement the parameterized constructor.
    # Implement the getHealTypeAsString(HealType heal) function.
    # Implement the printHealing() function.
*/

/**
 * @brief This is a parameterized constructor for the healing class
 * @param name The name of the healing object
 * @param healType The type of healing that it gives
 * @param healAmount The amount of HP/Shield that it heals
 * @return Nothing at all
 */
Healing::Healing(string name, HealType healType, int healAmount) : Item(name, ItemType::HEALING)
{
    this->healType = healType;
    this->amount = healAmount;
}

/**
 * @brief This returns a string to assist the print funtion
 * @param heal the type of heal an object performs
 * @return a string of the Healing type
 */
string Healing::getHealTypeAsString(HealType heal)
{
    switch (heal)
    {
    case HealType::HP:
        return "HP";
    case HealType::SHIELD:
        return "Shields";
    default:
        return "Unknown";
    }
}

/**
 * @brief Prints out the type of healing and the amount of healing
 * @return Nothing.
 */
void Healing::printHealing() const
{
    Item::printItem();
    cout << " : TYPE " << setw(8) << getHealTypeAsString(healType)
         << " : AMT " << setw(3) << amount << endl;
}

/* ************************************************
    Utility Class Definitions
* ************************************************/
/*
    Constructor for this class has been given to you.
    Implement the printUtility() function. Make sure
    the output matches the Sample Output provided to
    you.
*/

/**
 * @brief Prints out a utility item
 * @return Nothing.
 */
void Utility::printUtility() const
{
    Item::printItem();
    cout << endl;
}
