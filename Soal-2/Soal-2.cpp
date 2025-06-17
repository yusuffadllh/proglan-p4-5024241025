#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class ElementalDamage {
private:
    double baseDamage, elementalMultiplier;

public:
    ElementalDamage(double base = 0, double multiplier = 0)
        : baseDamage(base), elementalMultiplier(multiplier) {
    }

    ElementalDamage operator+(const ElementalDamage& other) const {
        return ElementalDamage(baseDamage + other.baseDamage,
                               elementalMultiplier + other.elementalMultiplier);
    }

    ElementalDamage operator-(const ElementalDamage& other) const {
        return ElementalDamage(baseDamage - other.baseDamage,
                               elementalMultiplier - other.elementalMultiplier);
    }

    ElementalDamage operator*(const ElementalDamage& other) const {
        double newBase = baseDamage * other.baseDamage - elementalMultiplier * other.elementalMultiplier;
        double newMultiplier = baseDamage * other.elementalMultiplier + elementalMultiplier * other.baseDamage;
        return ElementalDamage(newBase, newMultiplier);
    }

    ElementalDamage operator/(const ElementalDamage& other) const {
        double denom = other.baseDamage * other.baseDamage + other.elementalMultiplier * other.elementalMultiplier;
        if (denom == 0) {
            cout << "Error: Division by zero!" << endl;
            return ElementalDamage(0, 0);
        }
        double newBase = (baseDamage * other.baseDamage + elementalMultiplier * other.elementalMultiplier) / denom;
        double newMultiplier = (elementalMultiplier * other.baseDamage - baseDamage * other.elementalMultiplier) / denom;
        return ElementalDamage(newBase, newMultiplier);
    }

    bool operator==(const ElementalDamage& other) const {
        const double EPSILON = 1e-9;
        return abs(baseDamage - other.baseDamage) < EPSILON &&
               abs(elementalMultiplier - other.elementalMultiplier) < EPSILON;
    }

    friend istream& operator>>(istream& is, ElementalDamage& damage) {
        is >> damage.baseDamage >> damage.elementalMultiplier;
        return is;
    }

    friend ostream& operator<<(ostream& os, const ElementalDamage& damage) {
        os << fixed << setprecision(1);
        if (damage.elementalMultiplier >= 0)
            os << damage.baseDamage << " + " << damage.elementalMultiplier << "i";
        else
            os << damage.baseDamage << " - " << abs(damage.elementalMultiplier) << "i";
        return os;
    }
};

int main() {
    ElementalDamage d1, d2;
    cin >> d1 >> d2;

    cout << "Elemental Damage 1: " << d1 << endl;
    cout << "Elemental Damage 2: " << d2 << endl;
    cout << "Reaction (Addition): " << d1 + d2 << endl;
    cout << "Reaction (Subtraction): " << d1 - d2 << endl;
    cout << "Reaction (Multiplication): " << d1 * d2 << endl;
    cout << "Reaction (Division): " << d1 / d2 << endl;
    cout << "Apakah damage sama? " << (d1 == d2 ? "Ya" : "Tidak") << endl;

    return 0;
}