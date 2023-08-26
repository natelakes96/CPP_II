#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"


class Inventory {
    Item* slots[5];     ///< Number of inventory slots.
    int emptySlots;    ///< Number of empty slots
public:
    Inventory() : slots(), emptySlots(5) {};
    ~Inventory();
    int addItem(Item *item);
    bool removeItem(int slot);
    Item* getSlot(int slot) const { return slots[slot]; }
};

class Player {
    std::string playerName; ///< Player name given during creation.
    Inventory inventory;    ///< Player's inventory (5 slots).
    int hp;                 ///< Player's current HP. Starts at 100.
    int shield;             ///< Player's current shield. Starts at 0.
public:
    Player(std::string name) : playerName(name), hp(100), shield(0)  {};
    void pickup(Item*);
    void drop(int);
    void useItem(int slot);
    void showPlayer() const;
};

#endif  

