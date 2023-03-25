#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

class Shape {
protected:
    double x, y; // координаты центра фигуры
    string color; // цвет фигуры
public:
    Shape(double x, double y, string color) {
        this->x = x;
        this->y = y;
        this->color = color;
    }
    virtual double area() = 0; // виртуальный метод для вычисления площади фигуры
    virtual void print() {
        cout << "Shape: " << color << endl;
        cout << "Center: (" << x << ", " << y << ")" << endl;
    }
};

class Triangle : public Shape {
private:
    double a, b, c; // стороны треугольника
public:
    Triangle(double x, double y, string color, double a, double b, double c) : Shape(x, y, color) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
            std::cout << "Invalid triangle parameters!";
            std::exit(1);
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double area() {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    void print() {
        Shape::print();
        cout << "Type: Triangle" << endl;
        cout << "Sides: " << a << ", " << b << ", " << c << endl;
        cout << "Area: " << area() << "\n\n";
    }
};

class Rectangle : public Shape {
private:
    double width, height; // ширина и высота прямоугольника
public:
    Rectangle(double x, double y, string color, double width, double height) : Shape(x, y, color) {
        if (width <= 0 || height <= 0) {
            std::cout << "Invalid rectangle parameters!";
            std::exit(1);
        }
        this->width = width;
        this->height = height;
    }
    double area() {
        return width * height;
    }
    void print() {
        Shape::print();
        cout << "Type: Rectangle" << endl;
        cout << "Width: " << width << ", Height: " << height << endl;
        cout << "Area: " << area() << "\n\n";
    }
};

class Circle : public Shape {
private:
    double radius; // радиус круга
public:
    Circle(double x, double y, string color, double radius) : Shape(x, y, color) {
        if (radius <= 0) {
            std::cout << "Invalid circle parameters!";
            std::exit(1);
        }
        this->radius = radius;
    }
    double area() {
        return M_PI * radius * radius;
    }
    void print() {
        Shape::print();
        cout << "Type: Circle" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << "\n\n";
    }
};


int main() {
    Shape* shapes[] = {
        new Triangle(3, 4, "red", 3, 4, 5),
        new Rectangle(0, 0, "green", 2, 6),
        new Circle(0, 0, "blue", 5)
    };
    for (int i = 0; i < 3; i++) {
        shapes[i]->print();
    }
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }


    return 0;
}
