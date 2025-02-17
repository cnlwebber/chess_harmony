#include <iostream>


class Rectangle {
    int width, height;
    std::string name;
  public:
    void a_function (int, int);
    int area() {return width*height;}
};

void Rectangle::a_function (int the_x, int the_y) {
  width = the_x;
  height = the_y;
};

