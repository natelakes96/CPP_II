#include "item.h"

#include <iomanip>
#include <iostream>

using namespace std;

/**
 * Returns the AmmoType as a string.
 *
 * @param type AmmoType enum value.
 * @return Corresponding string for AmmoType enum value.
 */
string Weapon::getAmmoTypeAsString(AmmoType ammo) {
  switch (ammo) {
    case AmmoType::HEAVY:
      return "Heavy";
    case AmmoType::MEDIUM:
      return "Medium";
    case AmmoType::LIGHT:
      return "Light";
    case AmmoType::SHELLS:
      return "Shells";
    default:
      return "Invalid";
  }
}
/**
 * Prints an item.
 *
 * @return None.
 */
void Weapon::printItem() const {
  cout << setw(10) << "Weapon"
       << " : " << setw(20) << name << " : AMMO " << setw(8)
       << getAmmoTypeAsString(ammo) << " : DMG " << setw(3) << dmg << endl;
}

/**
 * Returns the HealType as a string.
 *
 * @param type HealType enum value.
 * @return Corresponding string for HealType enum value.
 */
string Healing::getHealTypeAsString(HealType heal) {
  switch (heal) {
    case HealType::HP:
      return "HP";
    case HealType::SHIELD:
      return "Shield";
    default:
      return "Invalid";
  }
}
/**
 * Prints an item.
 *
 * @return None.
 */
void Healing::printItem() const {
  cout << setw(10) << "Healing"
       << " : " << setw(20) << name << " : TYPE " << setw(8)
       << getHealTypeAsString(healType) << " : AMT " << setw(3) << amount
       << endl;
}
/**
 * Prints an item.
 *
 * @return None.
 */
void Utility::printItem() const {
  cout << setw(10) << "Utility"
       << " : " << setw(20) << name;
}