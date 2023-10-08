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
            throw invalid_argument("Invalid argument");
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
        throw domain_error("Division by zero");
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

void ShowRational(const Rational& a){
	  cout << a.Numerator()<< "/" << a.Denominator()<< endl;
  }

int main() {
    try {
        string s;
        char z;
        Rational r1, r2, res;
        getline(cin, s);
        stringstream ss(s);

        ss >> r1;
        ss >> z;
        ss >> r2;

        if(z == '+') res = r1+r2;
        if(z == '*') res = r1*r2;
        if(z == '/') res = r1/r2;
        if(z == '-') res = r1-r2;
        ShowRational(res);

    } catch (exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}