- [friend class](#friend-class)
- [Friend Function](#Friend-Function)
- [Features of Friend Functions](#Features-of-Friend-Functions)
- [A Function Friendly to Multiple Classes](#A-Function-Friendly-to-Multiple-Classes)
- [Advantages of Friend Functions](#Advantages-of-Friend-Functions)
- [Disadvantages of Friend Functions](#Disadvantages-of-Friend-Functions)
- [Important Points About Friend Functions and Classes](#Important-Points-About-Friend-Functions-and-Classes)


## friend class
A friend class can access private and protected members of other classes in which it is declared as a friend. It is sometimes useful to allow a particular class to access private and protected members of other classes. For example, a LinkedList class may be allowed to access private members of Node.

We can declare a friend class in C++ by using the friend keyword.

Syntax:
```cpp
friend class class_name;    // declared in the base class
```
### Example:

```cpp
// fucntioning of a friend class
#include <iostream>
using namespace std;

class GFG {
private:
  int private_variable; // private variable

protected:
  int protected_variable; // protected variable

public:
// constructor
  GFG(){
    private_variable = 10;
    protected_variable = 99;
  }

  // friend class declaration
   friend class F;
};

// Here, class F is declared as a friend inside class GFG. Therefore, F is a friend of class GFG. Class F
// can access the private members of class GFG.

class F {
public:
   // function to access private and protected members of class GFG
  void display(GFG& t){
    cout << "The value of Private Variable = " << t.private_variable << "\n";
    cout << "The value of Protected Variable = " << t.protected_variable;
   }
};

int main()
{
  
  GFG g; // create an object of class GFG
  F fri; // create an object of class F
  fri.display(g); // call the display function of class F
  
  return 0;
}
```

```cpp
Output:
The value of Private Variable = 10
The value of Protected Variable = 99
```

> **Note**
We can declare friend class or function anywhere in the base class body whether its private, protected or public block. It works all the same.

<br>

## Friend Function
Like a friend class, a friend function can be granted special access to private and protected members of a class in C++. They are the non-member functions that can access and manipulate the private and protected members of the class for they are declared as friends.

A friend function can be:

- A global function
- A member function of another class

### Syntax:

```cpp
friend return_type function_name (arguments);    // for a global function 
friend return_type class_name::function_name (arguments);    // for a member function of another class
```
![friend_function_syntax](https://user-images.githubusercontent.com/105644935/215883140-9bbf22bc-66e9-4917-a629-185c7ae208ce.png)


- Global Function as Friend Function
We can declare any global function as a friend function. The following example demonstrates how to declare a global function as a friend function in C++:

### Example:


```cpp
#include <iostream>
using namespace std;

// create a class
class Crectangle{
private: // private members
  int width, height; // width and height of the rectangle
public:
  // friend functions can access private members of the class outside the class scope 

  // friend function to duplicate the rectangle object and return it (set variables width and height)
  friend Crectangle duplicate(int, int);  
  // friend function to duplicate the rectangle object and return it (set object variables width and height) 
  friend Crectangle duplicate(Crectangle); 

  // set the width and height of the rectangle
  void set_values(int, int); 

  // return the area of the rectangle
  int area(){ 
   return width * height;
  }
};  

// set the width and height of the rectangle
void Crectangle::set_values(int x, int y){
  width = x;
  height = y;
}

// duplicate the rectangle object and return it (set object variables width and height)
Crectangle duplicate(Crectangle rectparam){
  Crectangle rectres = rectparam;
  rectres.width *= 2;
  rectres.height *= 2;
  return rectres;
}

// duplicate the rectangle object and return it (set variables width and height)
Crectangle duplicate(int a, int b){
  Crectangle rectres;
  rectres.width = a * 2;
  rectres.height = b * 2;
  return rectres;
}


int main()
{

  Crectangle rect, rectb; // create two objects of the class Crectangle
  rect.set_values(2, 3); // set the width and height of the first object
  rectb = duplicate(rect); // duplicate the first object and return it to the second object
  cout << "rectb area: " << rectb.area() << "\n"; // print the area of the second object
  cout << "rect area: " << rect.area() << "\n"; // print the area of the first object
  rectb = duplicate(2, 3); // function duplicate with two parameters (width and height)
  cout << "rectb area: " << rectb.area() << "\n"; // print the area of the second object

  return 0;
}
```

```cpp
Output:
rectb area: 24    
rect area: 6      
rectb area: 24   
```

In the above example, we have used a global function as a friend function. In the next example, we will use a member function of another class as a friend function.

- Member Function of Another Class as Friend Function
We can also declare a member function of another class as a friend function in C++. The following example demonstrates how to use a member function of another class as a friend function in C++:

Example:

```cpp
// C++ program to create a member function of another class
// as a friend function

#include <iostream>
using namespace std;

class base; // forward definition needed another class in which function is declared

class anotherClass {
public:
  void memberFunction(base& obj); // member function declaration
};

// base class for which friend is declared
class base {
private:
  int private_variable; // private variable

protected:
  int protected_variable; // protected variable

public:
 // constructor to initialize variables
  base(){
    private_variable = 10; // initialize private variable to 10
    protected_variable = 99; // initialize protected variable to 99
  }

	// friend function declaration
  friend void anotherClass::memberFunction(base&);
};

// friend function definition
void anotherClass::memberFunction(base& obj){
  cout << "Private Variable: " << obj.private_variable << "\n";
  cout << "Protected Variable: " << obj.protected_variable << "\n";
}

int main()
{
  base object1; // object of base class
  anotherClass object2; // object of another class
  object2.memberFunction(object1); // calling member function

  return 0;
}
```

```cpp
Output:
Private Variable: 10
Protected Variable: 99
```

> **Note** 
The order in which we define the friend function of another class is important and should be taken care of. We always have to define both the classes before the function definition. Thats why we have used out of class member function definition.


## Features of Friend Functions

- A friend function is a special function in C++ that in spite of not being a member function of a class has the privilege to access the private and protected data of a class.

- A friend function is a non-member function or ordinary function of a class, which is declared as a friend using the keyword `friend` inside the class. By declaring a function as a friend, all the access permissions are given to the function.

- The keyword “friend” is placed only in the function declaration of the friend function and not in the function definition or call.

- A friend function is called like an ordinary function. It cannot be called using the object name and dot operator. However, it may accept the object as an argument whose value it wants to access.

- A friend function can be declared in any section of the class i.e. public or private or protected.


Below are some more examples of friend functions in different scenarios:

## A Function Friendly to Multiple Classes

```cpp
#include <iostream>
using namespace std;

class BRectangle; // Forward declaration
class ARectangle{
private: // Private members
  int width, height;

public:
  // Constructor to initialize the private members
  ARectangle(int width_, int height_){
   width = width_;
   height = height_;
  }
  // Friend function
  friend int area(ARectangle r, BRectangle s);
};


class BRectangle{
private: // Private members
  int width, height;

public:
  // Constructor to initialize the private members
  BRectangle(int width_, int height_){
    width = width_;
    height = height_;
  }
  // Friend function
  friend int area(ARectangle r, BRectangle s);
};

// Friend function definition (outside the class) to calculate the area of the rectangle
int area(ARectangle r, BRectangle s){
  ARectangle T = r;
  T.width *= s.width;
  T.height *= s.height;
  return T.width * T.height;
}


int main()
{

  ARectangle r(10, 5); // Create a rectangle
  BRectangle s(2, 3); // Create a other rectangle 
  cout << "The area of the Two rectangles is: " << area(r, s) << endl; // Print the area of the rectangle

  return 0;
}
```
`Output: The area of the Two rectangles is: 300`


The friend function provides us with a way to access private data but it also has its demerits. Following is the list of advantages and disadvantages of friend functions in C++:

## Advantages of Friend Functions
- A friend function is able to access members without the need of inheriting the class.
- The friend function acts as a bridge between two classes by accessing their private data.
- It can be used to increase the versatility of overloaded operators.
- It can be declared either in the public or private or protected part of the class.

## Disadvantages of Friend Functions
- Friend functions have access to private members of a class from outside the class which violates the law of data hiding.
- Friend functions cannot do any run-time polymorphism in their members.


## Important Points About Friend Functions and Classes

1. Friends should be used only for limited purposes. Too many functions or external classes are declared as friends of a class with protected or private data access lessens the value of encapsulation of separate classes in object-oriented programming.
2. Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
3. Friendship is not inherited. (See `this` for more details)
4. The concept of friends is not in Java.




![friend-func-vs-friend-class](https://user-images.githubusercontent.com/105644935/215818346-aa603789-6ec2-4cc7-b5b9-042621bc8aec.jpg)






