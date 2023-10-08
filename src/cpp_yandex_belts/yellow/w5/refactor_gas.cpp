#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
    Person(const string &nameIn, const string &kindIn) : 
        name(nameIn), kind(kindIn) {}
    virtual void Walk(const string &destination) const {
        cout << kind << ": " << name << " walks to: " << destination << endl;
    }

public:
    string name, kind;
};

class Student : public Person {
public:

    Student(const string &nameIn, const string &favouriteSong) : 
        Person(nameIn, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << kind << ": " << name << " learns" << endl;
    }

    void Walk(const string &destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << kind << ": " << name << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string &nameIn, const string &subject) :
        Person(nameIn, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << kind << ": " << name << " teaches: " << Subject << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string &nameIn) : Person(nameIn, "Policeman") {}

    void Check(const Person &t) const {
        cout << kind << ": " << name << " checks " << t.kind 
             << ". " << t.kind << "'s name is: " << t.name << endl;
    }
};


void VisitPlaces(Person &t, vector<string> places) {
    for (auto p : places) {
        t.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
