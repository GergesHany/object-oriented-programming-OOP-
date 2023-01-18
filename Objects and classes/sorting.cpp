#include <bits/stdc++.h>
using namespace std; 


class triangle{
  // the class is a blueprint for creating objects

  private: // the private access specifier is used to declare private members
    int x, y;

  public: // the public access specifier is used to declare public members
    
  // The constructor and the function is not defined inside class definition
  triangle();
  triangle(int x, int y);
  void print();
  void setX(int x);
  int getX();
  void setY(int y);
  int getY();

};

// Definition of triangle constructor using scope resolution operator ::
triangle::triangle(int x, int y){
  this->x = x;
  this->y = y;
}

// Definition of print function using scope resolution operator ::
void triangle::print(){
  cout << "x = " << x << " y = " << y << endl;
}

void triangle::setX(int x){
  this->x = x;
}

int triangle::getX(){
  return x;
}

void triangle::setY(int y){
  this->y = y;
}

int triangle::getY(){
  return y;
}


int main()
{

  // the object is created using the constructor
  triangle t1(10, 15); // calling the parameterized constructor 
  t1.print(); // calling the print function
  t1.setX(20); // calling the setX function
  t1.setY(25); // calling the setY function
  t1.print(); // calling the print function
  // calling the getX and getY function
  cout << "x = " << t1.getX() << " y = " << t1.getY() << endl;

  return 0;
}