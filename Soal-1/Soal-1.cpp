#include <iostream>
#include <iomanip>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D operator/(double scalar) const {
        if (scalar == 0) {
            cerr << "Error: Pembagian dengan nol.\n";
            return Vector2D();
        }
        return Vector2D(x / scalar, y / scalar);
    }

    bool operator==(const Vector2D& other) const {
        return (abs(x - other.x) < 1e-6) && (abs(y - other.y) < 1e-6);
    }

    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        os << fixed << setprecision(2);
        os << "Vector(" << v.x << ", " << v.y << ")";
        return os;
    }
};

int main() {
    double x1, y1, x2, y2, scalar;

    cin >> x1 >> y1 >> x2 >> y2 >> scalar;

    Vector2D v1(x1, y1);
    Vector2D v2(x2, y2);

    cout << "Vektor 1: " << v1 << endl;
    cout << "Vektor 2: " << v2 << endl;
    cout << "Penjumlahan: " << v1 + v2 << endl;
    cout << "Pengurangan: " << v1 - v2 << endl;
    cout << "Perkalian dengan " << scalar << ": " << v1 * scalar << endl;
    cout << "Pembagian dengan " << scalar << ": " << v1 / scalar << endl;
    cout << "Apakah sama? " << (v1 == v2 ? "Ya" : "Tidak") << endl;

    return 0;
}
