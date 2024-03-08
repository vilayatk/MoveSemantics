#include <iostream>
using namespace std;

class Circle {

public:
    Circle(string r) {
        _radius = r;
    }

    ~Circle() {
    }

    Circle(const Circle& c) {
        _radius = c.radius();
        cout << endl << "Copy constructor with lvalue reference. Radius: " << _radius;
    }

    Circle(Circle&& c) noexcept {
        _radius = std::move(c._radius);
        _radius = _radius + "1";
        cout << endl << "Copy constructor with rvalue reference. Radius:" << _radius;
    }

    Circle& operator= (Circle&& c) noexcept {
        _radius = std::move(c._radius);
        _radius = _radius + "1";
        cout << endl << "assignment operator with rvalue reference. Radius:" << _radius;
        return  *this;
    }

    Circle&& ModifyValue(Circle&& c)
    {
        cout << endl << "called in function" << _radius;
        return std::move(c);
    }

    string radius() const {
        return _radius;
    }

private:
    string _radius;
};

//int main()
//{
//    Circle c1("2");
//    Circle c2(c1);
//    Circle c3(std::move(c2));
//    cout << endl << c2.radius();
//    cout << endl << c3.radius();
//    cout << endl << &c1;
//    cout << endl << &c2;
//}