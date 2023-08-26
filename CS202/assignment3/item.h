#ifndef ITEM_H
#define ITEM_H

#include <iostream>

enum class HealType {HP, SHIELD, INVALID};                    // Item can heal either HP or Shield.
enum class AmmoType {HEAVY, MEDIUM, LIGHT, SHELLS, INVALID};  // Type of ammo used by a weapon.

class Item {    // ABSTRACT CLASS
protected:
    std::string name;    ///< Name of the Item.
public:
    Item(std::string setName) : name(setName) {};
    virtual ~Item() {};                             // Try removing the virtual keyword to see what happens.
    virtual void printItem() const = 0;
    virtual HealType getHealType() const = 0;
    virtual int getHealAmount() const = 0;
    std::string getName() { return name; }
};

class Weapon : public Item {
    AmmoType ammo;  ///< Type of ammo the weapon can use.
    double dmg;     ///< Damage done by the weapon.
    static std::string getAmmoTypeAsString(AmmoType);

public:
    Weapon(std::string name, AmmoType type, double setDmg) : Item(name), ammo(type), dmg(setDmg) {};
    void printItem() const;
    HealType getHealType() const { return HealType::INVALID; }
    int getHealAmount() const { return -1; }
};

class Healing : public Item {
    HealType healType;  ///< Is shield healed or HP?
    int amount;         ///< Amount of HP/Shield healed by this item.
    static std::string getHealTypeAsString(HealType);

public:
    Healing(std::string name, HealType type, int amt) : Item(name), healType(type), amount(amt) {};
    void printItem() const;

    HealType getHealType() const { return healType; }
    int getHealAmount() const { return amount; }
};

class Utility : public Item { 
public:
    Utility(std::string name) : Item(name) {};
    void printItem() const;
    HealType getHealType() const { return HealType::INVALID; }
    int getHealAmount() const { return -1; }

};

#endif