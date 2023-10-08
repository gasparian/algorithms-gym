#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
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
        setRational(numeratorIn, denominatorIn);
    }

    void setRational(int numeratorIn, int denominatorIn) {
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

ostream& operator<<(ostream& stream, const Rational& rat) {
    string res = to_string(rat.Numerator()) + "/" + to_string(rat.Denominator());
    stream << res;
    return stream;
}

istream& operator>>(istream& stream, Rational& rat) {
    if (stream.tellg() == -1) 
        return stream;
    int numerator = 0;
    int denominator = 1;
    stream >> numerator;
    stream.ignore(1);
    stream >> denominator;
    rat.setRational(numerator, denominator);
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}