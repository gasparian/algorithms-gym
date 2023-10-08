#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string name;
    explicit Specialization(string nameIn) {
        name = nameIn;
    }
};

struct Course {
    string name;
    explicit Course(string nameIn) {
        name = nameIn;
    }
};

struct Week {
    string name;
    explicit Week(string nameIn) {
        name = nameIn;
    }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization spec, Course courseIn, Week weekIn) {
      specialization = spec.name;
      course = courseIn.name;
      week = weekIn.name;
  }
};

int main() {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
    return 0;
}