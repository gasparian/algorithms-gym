#include <iostream>
#include <string>

class C {
public:
    C(const std::string& t = "C") : inner(t) {
        std::cout << "C constructed" << "; " << inner << std::endl;
    }
    ~C() {
        std::cout << "C destroyed (" << inner << ")" << std::endl;
    }

    const std::string inner;
};

class B : public C {
public:
    B(const std::string& t = "B") : C(t) {
        std::cout << "B constructed" << "; " << inner << std::endl;
    }
    ~B() {
        std::cout << "B destroyed (" << inner << ")" << std::endl;
    }
};

class A : public B {
public:
    A(const std::string& t = "A") : B(t) {
        std::cout << "A constructed" << "; " << inner << std::endl;
    }
    ~A() {
        std::cout << "A destroyed (" << inner << ")" << std::endl;
    }
};

int main() {
    // C testC;
    // std::cout << std::endl;
    // B testB;
    // std::cout << std::endl;
    A testA;
    std::cout << std::endl;
    return 0;
}