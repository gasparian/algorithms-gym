#include <iostream>
#include <map>
#include <set>
#include <sstream>
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

bool IsPalindrom(const string& s) {
    string res;
    if (s.length() == 0) {
        return true;
    }
    for (int i=s.length()-1; i >= 0; i--) {
        res += s[i];
    }
    if (res == s) {
        return true;
    } else {
        return false;
    }
}

void TestEmpty() {
    bool a = IsPalindrom("");
    AssertEqual(a, true, "Empty is string is palindrom");
}

void TestSingle() {
    bool a = IsPalindrom("1");
    AssertEqual(a, true, "Single is string is palindrom");
}

void TestSpaces() {
    bool a = IsPalindrom("1 1");
    bool b = IsPalindrom(" ");
    AssertEqual(a, true, "Spaces are count");
    AssertEqual(b, true, "Spaces are count");
}

void TestErrors() {
    AssertEqual(IsPalindrom("  ABsioisBA"), false, "");
    AssertEqual(IsPalindrom("baobab"), false, "");
    AssertEqual(IsPalindrom("ab"), false, "");
    AssertEqual(IsPalindrom("   "), true, "");
    AssertEqual(IsPalindrom("zabcdeedcba"), false, "");
    AssertEqual(IsPalindrom(" AaA "), true, "");
    AssertEqual(IsPalindrom("а роза упала на лапу азора"), false, "");
    AssertEqual(IsPalindrom("//"), true, "");
    AssertEqual(IsPalindrom(" AaA AbA AaA "), true, "");
    AssertEqual(IsPalindrom("ABasdfABBAasdfBA"), false, "");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "TestEmpty");
  runner.RunTest(TestSingle, "TestSingle");
  runner.RunTest(TestSpaces, "TestSpaces");
  runner.RunTest(TestErrors, "TestErrors");
  return 0;
}