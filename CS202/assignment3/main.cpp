#include <iostream>
#include "player.h"

using namespace std;

/*
    This code should work exactly the way it did with Assignment 2.
*/
int main () {
    Player player1("Naruto");
    Player player2("Goku");
    string name;
    player1.pickup(new Weapon("HammerAssault", AmmoType::MEDIUM, 31));
    player1.pickup(new Weapon("SidearmPistol", AmmoType::LIGHT, 25)); 
    player1.pickup(new Weapon("PumpShotgun", AmmoType::SHELLS, 103.2));
    player1.pickup(new Healing("Medkit",HealType::HP,100));
    player1.pickup(new Utility("FishingRod"));
    player1.pickup(new Healing("SmallShield", HealType::SHIELD, 25));
    player2.pickup(new Healing("Bandages",HealType::HP, 25));
    player2.pickup(new Weapon("SidearmPistol",AmmoType::LIGHT, 48));
    player1.showPlayer();
    player2.showPlayer();
    player1.drop(4);
    player1.pickup(new Healing("SmallShield", HealType::SHIELD, 25));
    player1.showPlayer();
    player2.drop(3);
    player1.useItem(3);
    player1.useItem(4);
    player2.useItem(0);
    player1.showPlayer();
    player2.showPlayer();
    player1.useItem(4);
    player1.useItem(1);
    player1.pickup(new Weapon("HeavySniper", AmmoType::HEAVY, 120));
    player1.showPlayer();
    player1.drop(1);
    player1.showPlayer();
    player2.pickup(new Weapon("DMR", AmmoType::MEDIUM, 80));
    player1.pickup(new Healing("ShieldPotion", HealType::SHIELD, 50));
    player1.showPlayer();
    player2.showPlayer();
    player2.drop(0);
    player2.pickup(new Healing("Keg",HealType::SHIELD,100));
    player2.showPlayer();
    player2.useItem(0);
    player2.showPlayer();
}