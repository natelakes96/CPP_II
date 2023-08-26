#include <iostream>
#include "player.h"

using namespace std;

/*
    This is a sample driver code. You do not need to submit this file, so
    feel free to make changes here to test your code.
*/
int main () {
    Player player1("Player 1");
    string name;
    player1.pickup(new Weapon("HammerAssault", AmmoType::MEDIUM, 31));
    player1.pickup(new Weapon("SidearmPistol", AmmoType::LIGHT, 25)); 
    player1.pickup(new Weapon("PumpShotgun", AmmoType::SHELLS, 103.2));
    player1.pickup(new Healing("Medkit",HealType::HP,100));
    player1.pickup(new Utility("FishingRod"));
    player1.pickup(new Healing("SmallShield", HealType::SHIELD, 25));
    player1.showPlayer();
    player1.drop(4);
    player1.pickup(new Healing("SmallShield", HealType::SHIELD, 25));
    player1.showPlayer();
    player1.useItem(3);
    player1.useItem(4);
    player1.showPlayer();
    player1.useItem(4);
    player1.useItem(1);
    player1.pickup(new Weapon("HeavySniper", AmmoType::HEAVY, 120));
    player1.showPlayer();
    player1.drop(1);
    player1.showPlayer();
    player1.pickup(new Healing("ShieldPotion", HealType::SHIELD, 50));
    player1.showPlayer();
}