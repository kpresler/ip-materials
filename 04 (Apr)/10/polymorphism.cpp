#include <iostream>
#include <ostream>
#include <cstdlib>

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

ostream & operator<< (ostream & out, const Sword & sw) {
    out << "This sword requires " << sw.getNumHands() << " hands and deals " << sw.getDamage() << " damage" << std::endl;
    return out;
}


using std::cout;
using std::endl;


void attackEnemy(Weapon & whichWeapon, int dist) {
    if (rand() % 10 == 1) cout << "Our Hero misses, and does no damage" << endl;

    else cout << "Our Hero does " << whichWeapon.damageFalloff(dist) << " damage to the space aliens" << endl;

}


int main (void) {
    Sword broadSword (20, 2, 4);

    LaserCannon plc (2000);

    attackEnemy(broadSword, 1);

    attackEnemy(plc, 100);

}
