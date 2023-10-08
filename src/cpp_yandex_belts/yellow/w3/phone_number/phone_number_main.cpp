#include "../../../unit_test.h"
#include "phone_number.h"

void TestGood() {
    PhoneNumber number_1("+7-495-111-22-33");
    AssertEqual(number_1.GetInternationalNumber(), "+7-495-111-22-33", "Local number can consist `-`");
    PhoneNumber number_2("+7-495-1112233");
    AssertEqual(number_2.GetInternationalNumber(), "+7-495-1112233", "Local number can consist only of digits");
    PhoneNumber number_3("+1-2-coursera-cpp");
    AssertEqual(number_3.GetInternationalNumber(), "+1-2-coursera-cpp", "Local number can be a string");
}

void TestNoPlus() {
    PhoneNumber number_4("1-2-333");
}

void TestNoLocal() {
    PhoneNumber number_4("+7-1233");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestGood, "Good examples");
    runner.RunTest(TestNoPlus, "TestNoPlus");
    runner.RunTest(TestNoLocal, "TestNoLocal");
}
