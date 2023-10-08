#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

/////////////////////////////////////////////////////////////////////////////

// int get_GCD(int A, int B) {

//     while (A > 0 && B > 0) {
//         if (A > B) {
//             A = A % B;
//         } else {
//             B = B % A;
//         }
//     }
//     return A + B;
// }

// class Rational {
// public:
//     Rational() {
//         numerator = 0;
//         denominator = 1;
//     }

//     Rational(int numeratorIn, int denominatorIn) {
//         int gcd = get_GCD(abs(numeratorIn), abs(denominatorIn));
//         numerator = numeratorIn / gcd;
//         denominator = denominatorIn / gcd;
//         if ( numerator == 0) {
//             denominator = 1;
//         } else if ( ((denominator < 0) && (numerator > 0)) || ((denominator < 0) && (numerator < 0)) ) {
//             numerator *= -1;
//             denominator *= -1;
//         } 
//     }

//     int Numerator() const {
//         return numerator;
//     }

//     int Denominator() const {
//         return denominator;
//     }

// private:
//     int numerator;
//     int denominator;
// };

////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& stream, const Rational& rat) {
    string res = to_string(rat.Numerator()) + "/" + to_string(rat.Denominator());
    stream << res;
    return stream;
}

bool operator==(Rational a, Rational b) {
    if ( (a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()) )
        return true;
    else
        return false;
}

bool operator!=(Rational a, Rational b) {
    return a == b ? false : true;
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

void TestDefaultConstructor() {
    Rational a;
    Rational b(0, 1);
    AssertEqual(a, b, "Default constructor must give `0/1`");
}

void TestFractionReduction() {
    Rational a(10, 8);
    Rational b(5, 4);
    AssertEqual(a, b, "Rational must be reduced");
}

void TestNegative() {
    Rational a(1, -2);
    AssertEqual(a.Numerator(), -1, "Numerator must be negative");
}

void TestPositive() {
    Rational a(-2, -3);
    Rational b(2, 3);
    AssertEqual(a, b, "Numerator and denominator must be positive");
}

void TestDenominator() {
    Rational a(0, 4);
    AssertEqual(a.Denominator(), 1, "If numerator is `0` then denominator must be `1`");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
  runner.RunTest(TestFractionReduction, "TestFractionReduction");
  runner.RunTest(TestNegative, "TestNegative");
  runner.RunTest(TestPositive, "TestPositive");
  runner.RunTest(TestDenominator, "TestDenominator");
  return 0;
}