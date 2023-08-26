#ifndef ITEM_H
#define ITEM_H

enum class ItemType { WEAPON, HEALING, UTILITY };  // All possible item types.
enum class HealType { HP, SHIELD };  // Item can heal either HP or Shield.
enum class AmmoType {
  HEAVY,
  MEDIUM,
  LIGHT,
  SHELLS
};  // Type of ammo used by a weapon.

class Item {
  std::string name;  ///< Name of the Item.
  ItemType item;     ///< Item type. Either weapon, healing or utility.

 protected:
  Item(std::string setName, ItemType setItem) : name(setName), item(setItem){};
  static std::string getItemTypeAsString(ItemType);
  void printItem() const;

 public:
  ItemType getItemType() const { return item; }
  std::string getName() const { return name; }
};

class Weapon : public Item {
  double dmg;     ///< Damage done by the weapon.
  AmmoType ammo;  ///< Type of ammo the weapon can use.
  static std::string getAmmoTypeAsString(AmmoType);

 public:
  Weapon(std::string, AmmoType, double);
  void printWeapon() const;
};

class Healing : public Item {
  int amount;         ///< Amount of HP/Shield healed by this item.
  HealType healType;  ///< Is shield healed or HP?
  static std::string getHealTypeAsString(HealType);

 public:
  Healing(std::string, HealType, int);
  void printHealing() const;

  HealType getHealType() const { return healType; }
  int getAmount() const { return amount; }
};

class Utility : public Item {
 public:
  Utility(std::string name) : Item(name, ItemType::UTILITY){};
  void printUtility() const;
};

#endif