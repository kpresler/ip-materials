#include <iostream>
#include <ostream>

using std::ostream;

class Weapon {
    public:
        Weapon (int damage) : damage (damage) {}

        Weapon (int damage, bool ranged ) : damage (damage), ranged (ranged) {}

        int getDamage() { return damage; }

        int damageFalloff(int distance) { return 0; }

    protected:
        int damage;
        bool ranged;
};


class MeleeWeapon : public Weapon {
    public:
        MeleeWeapon (int damage, int length) : 
            Weapon (damage, false), 
            length (length) 
            { }

        int damageFalloff(int distance) {
            if (distance < length / 2.) return 1.2 * damage; // bonus damage if very close
            if (distance <= length) return damage; // normal damage if otherwise in range
            else return 0; // no damage past range
        }

    private:
        int length;

};

class Sword : public MeleeWeapon {
    public:
        Sword (int damage, int numHands, int length) : 
            MeleeWeapon (damage, length), 
            numHands (numHands) 
            { }
            
        int getNumHands() { 
            return numHands; 
        }

    private:
        int numHands;
};


class LaserCannon : public Weapon {
    public:
        LaserCannon (int damage) :
            Weapon(damage, true) {}

        int damageFalloff (int distance) { 
            // lasers do not obey laws of physics and suffer no falloff
            return damage; 
        } 

};

ostream & operator<< (ostream & out,  Sword & sw) {
    out << "This sword requires " << sw.getNumHands() << " hands and deals " << sw.getDamage() << " damage" << std::endl;
    return out;
}


using std::cout;
using std::endl;

int main (void) {
    Sword broadSword (20, 2, 4);

    Sword dagger (7, 1, 1); // sort-of like a small sword

    cout << broadSword;

    cout << dagger;

    cout << "Attacking an enemy at distance 1, the broadsword does " << broadSword.damageFalloff(1) << " damage" << endl;
    cout << "Attacking an enemy at distance 5, the broadsword does " << broadSword.damageFalloff(5) << " damage" << endl;

    LaserCannon plc (2000);

    cout << "Attacking an enemy at distance 5, the laser cannon does " << plc.damageFalloff(5) << " damage" << endl;


}
