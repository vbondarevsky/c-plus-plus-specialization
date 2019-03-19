#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <memory>
#include <cmath>

using namespace std;


class Figure {
public:
    virtual string Name() const = 0;

    virtual double Perimeter() const = 0;

    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c) : a_(a), b_(b), c_(c) {}

    string Name() const override {
        return "TRIANGLE";
    }

    double Perimeter() const override {
        return a_ + b_ + c_;
    }

    double Area() const override {
        double p = (Perimeter()) / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

private:
    int a_;
    int b_;
    int c_;
};

class Rect : public Figure {
public:
    Rect(int width, int height) : width_(width), height_(height) {}

    string Name() const override {
        return "RECT";
    }

    double Perimeter() const override {
        return (width_ + height_) * 2;
    }

    double Area() const override {
        return width_ * height_;
    }

private:
    int width_;
    int height_;
};

class Circle : public Figure {
public:
    Circle(int r) : r_(r) {}

    string Name() const override {
        return "CIRCLE";
    }

    double Perimeter() const override {
        return 2 * r_ * pi_;
    }

    double Area() const override {
        return pi_ * r_ * r_;
    }

private:
    int r_;
    const double pi_ = 3.14;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string fig;
    is >> fig;
    if (fig == "RECT") {
        int width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    } else if (fig == "TRIANGLE") {
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else {
        int R;
        is >> R;
        return make_shared<Circle>(R);
    }
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);) {
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