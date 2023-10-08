#include <iostream>
#include <algorithm>
using namespace std;

int get_GCD(int A, int B) {

    while (A > 0 && B > 0) {
        if (A > B) {
            A = A % B;
        } else {
            B = B % A;
        }
    }
    return A + B;
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numeratorIn, int denominatorIn) {
        int gcd = get_GCD(abs(numeratorIn), abs(denominatorIn));
        numerator = numeratorIn / gcd;
        denominator = denominatorIn / gcd;
        if ( numerator == 0) {
            denominator = 1;
        } else if ( ((denominator < 0) && (numerator > 0)) || ((denominator < 0) && (numerator < 0)) ) {
            numerator *= -1;
            denominator *= -1;
        } 
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator==(Rational a, Rational b) {
    if ( (a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()) )
        return true;
    else
        return false;
}

Rational operator+(Rational a, Rational b) {
    int denominator = a.Denominator() * b.Denominator();
    int numerator = a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator();
    Rational res(numerator, denominator);
    return res;
}

Rational operator-(Rational a, Rational b) {
    int denominator = a.Denominator() * b.Denominator();
    int numerator = a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator();
    Rational res(numerator, denominator);
    return res;
}

Rational operator*(Rational a, Rational b) {
    int numerator = a.Numerator() * b.Numerator();
    int denominator = a.Denominator() * b.Denominator();
    Rational res(numerator, denominator);
    return res;
}

Rational operator/(Rational a, Rational b) {
    int numerator = a.Numerator() * b.Denominator();
    int denominator = a.Denominator() * b.Numerator();
    Rational res(numerator, denominator);
    return res;
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}