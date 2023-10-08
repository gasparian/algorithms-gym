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

// int SolveQuadradicEquation(double a, double b, double c) {
//     double D = b * b - 4 * a * c;
//     if ( D > 0 ) {
//         // -(b / a) || (-b +- sqrt(D)) / (2 * a)
//         int x1 = (-b - sqrt(D)) / (2 * a);
//         int x2 = (-b + sqrt(D)) / (2 * a);
//         return x1 == x2 ? 1 : 2;
//     } else if ( D < 0 ) {
//         return 0;
//     } else {
//         return 1;
//     }
        
// }

// int SolveLinearEquation(double b, double c) {
//     if ( b != 0 )
//         // -c / b
//         return 1; 
//     else
//         return 0;
// }

// int GetDistinctRealRootCount(double a, double b, double c) {
//     // ax^2 + bx + c = 0
//     int root_count = 0;
//     if ( a != 0 )
//         root_count = SolveQuadradicEquation(a, b, c);
//     else 
//         root_count = SolveLinearEquation(b, c);
//     return root_count;
// }

void TestABZeros() {
    return AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "Has 0 real roots");
}

void TestACZeros() {
    return AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "Has 1 real root");
}

void TestBCZeros() {
    return AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "Has 1 real root");
}

void TestBZero() {
    return AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "Has 0 real roots");
}

void TestCZero() {
    return AssertEqual(GetDistinctRealRootCount(1, 1, 0), 2, "Has 2 real roots");
}

void TestAZero() {
    return AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, "Has 1 real roots");   
}

void TestAllNonZero() {
    return AssertEqual(GetDistinctRealRootCount(2, 5, 2), 2, "Has 2 real roots");   
}

int main() {
  TestRunner runner;
  runner.RunTest(TestABZeros, "test AB zeros");
  runner.RunTest(TestACZeros, "test AC zeros");
  runner.RunTest(TestBCZeros, "test BC zeros");
  runner.RunTest(TestBZero, "test B zeros");
  runner.RunTest(TestCZero, "test C zeros");
  runner.RunTest(TestAZero, "test A zeros");
  runner.RunTest(TestAllNonZero, "test all non-zeros");
  return 0;
}