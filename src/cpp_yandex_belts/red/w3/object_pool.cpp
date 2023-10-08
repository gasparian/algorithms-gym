#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate() {
    if ( this->deallocated.size() ) {
      return this->Check();
    }
    T* result = new T;
    this->allocated.insert(result);
    return result;
  }

  T* TryAllocate() {
    if ( this->deallocated.size() ) {
      return this->Check();
    }
    return nullptr;
  }

  void Deallocate(T* object) {
    auto it = this->allocated.find(object);
    if ( it != this->allocated.end() ) {
      this->deallocated.push_back(*it);
      this->allocated.erase(it);
      return;
    }
    throw invalid_argument("");
  }

  ~ObjectPool() {
    for ( auto it=this->allocated.begin(); it!=this->allocated.end(); it++ ) {
      delete *it;
      this->allocated.erase(it);
    }

    while( !this->deallocated.empty() ) {
      delete this->deallocated.front();
      this->deallocated.pop_front();
    }
  }

private:
  set<T*> allocated;
  deque<T*> deallocated;

  T* Check() {
    T* result = this->deallocated.front();
    this->allocated.insert(result);
    this->deallocated.pop_front();
    return result;
  }
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}