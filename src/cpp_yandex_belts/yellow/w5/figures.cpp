#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Figure {
public:
    Figure(const string nameIn) : name(nameIn) {}
    virtual string Name() { return name; };
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;

private:
    const string name;
};

class Triangle : public Figure {
public:
    Triangle(const int aIn, const int bIn, const int cIn, const string nameIn ) : 
        a(aIn), b(bIn), c(cIn), Figure(nameIn) {}
    double Perimeter() const override { 
        return a + b + c;
    }
    double Area() const override { 
        double s = this->Perimeter() / 2.0;
        s = sqrt(s * (s - a) * (s - b) * (s - c));
        return s;
    }
private:
    const int a, b, c;
};

class Rect : public Figure {
public:
    Rect(const int wIn, const int hIn, const string nameIn) : 
        w(wIn), h(hIn), Figure(nameIn) {}
    double Perimeter() const override {
        return (w + h) * 2.0;
     }
    double Area() const override { 
        return w * h;
     }
private:
    const int w, h;
};

class Circle : public Figure {
public:
    Circle(const int rIn, const string nameIn) : 
        r(rIn), Figure(nameIn) {}
    double Perimeter() const override { 
        return pi * r * 2.0;
    }
    double Area() const override { 
        return pi * r * r;
    }
private:
    const int r;
    const double pi = 3.14;
};

shared_ptr<Figure> CreateFigure(istream& is) {
    string fig;
    is >> fig;
    shared_ptr<Figure> res;
    
    if ( fig == "RECT" ) {
        int w, h;
        is >> w >> h;
        res = make_shared<Rect>(w, h, fig);

    } else if ( fig == "TRIANGLE" ) {
        int a, b, c;
        is >> a >> b >> c;
        res = make_shared<Triangle>(a, b, c, fig);

    } else if ( fig == "CIRCLE" ) {
        int r;
        is >> r;
        res = make_shared<Circle>(r, fig);
    }

    return res;
}

int main() {

    // ADD RECT 2 3
    // ADD TRIANGLE 3 4 5
    // ADD RECT 10 20
    // ADD CIRCLE 5
    // PRINT

    // RECT 10.000 6.000
    // TRIANGLE 12.000 6.000
    // RECT 60.000 200.000
    // CIRCLE 31.400 78.500

    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
            cout << fixed << setprecision(3)
                 << current_figure->Name() << " "
                 << current_figure->Perimeter() << " "
                 << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}