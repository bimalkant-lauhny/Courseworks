/**
* SOLID Design Principle 3 : Liskov Substitution Principle (LSP)
* Defn. Objects in a program should be replaceable with instances of their subtypes
* w/o altering the correctness of the program
*/ 

#include <iostream>

class Rectangle
{
protected:
  int width, height;
public:

  Rectangle(const int width, const int height)
    : width{width},
      height{height}
  {
  }


  virtual int GetWidth() const
  {
    return width;
  }

  virtual void SetWidth(const int width)
  {
    this->width = width;
  }

  virtual int GetHeight() const
  {
    return height;
  }

  virtual void SetHeight(const int height)
  {
    this->height = height;
  }

  int Area() const { return width*height; }
};

class Square : public Rectangle
{
public:
  Square(int size) : Rectangle{size,size} {}

  void SetWidth(const int width) override {
    this->width = height = width;
  }
  void SetHeight(const int height) override {
    this->height = width = height;
  }

};

void process(Rectangle& r)
{
  int w = r.GetWidth();
  r.SetHeight(10);
  /**
  * Note that when we pass a Square instance (commented out below in main()),
  * we get expected area different than the actual result. But according to
  * LSP, if we've a process function here which uses the attributes of a
  * Rectangle instance in a certain way, then process function must produce
  * expected results with subtypes of Rectangle.
  */
  std::cout << "expect area = " << (w * 10)
    << ", got " << r.Area() << std::endl;
}

/**
* As a solution, rather than making a Square subclass, we can make a factory.
* As given below, we create Square here by calling a different function as
* compare to creating a Rectangle.
*/
struct RectangleFactory
{
  static Rectangle CreateRectangle(int w, int h);
  static Rectangle CreateSquare(int size);
};

int main()
{
  Rectangle r{ 5,5 };
  process(r);

  /*Square s{ 5 };
  process(s);*/

  getchar();
  return 0;
}