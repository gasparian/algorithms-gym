#include <iostream>
#include <exception>
#include <map>
#include <set>
#include <vector>
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
        if (denominatorIn == 0) {
            throw invalid_argument("0 division"); 
        } 
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

bool operator>(Rational a, Rational b) {
    Rational diff = a - b;
    if ( diff.Numerator() > 0 )
        return true;
    else
        return false;
}

bool operator<(Rational a, Rational b) {
    Rational diff = a - b;
    if ( diff.Numerator() < 0 )
        return true;
    else
        return false;
}

Rational operator*(Rational a, Rational b) {
    int numerator = a.Numerator() * b.Numerator();
    int denominator = a.Denominator() * b.Denominator();
    Rational res(numerator, denominator);
    return res;
}

Rational operator/(Rational a, Rational b) {
    if ( b.Numerator() == 0 ) {
        throw domain_error("denominator == 0");
    }
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}