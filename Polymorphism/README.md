- [polymorphism](#polymorphism)
- [Types-of-Polymorphism](#Types-of-Polymorphism)
- [Compile-Time Polymorphism](#Compile-Time-Polymorphism)
- [Runtime Polymorphism](#Runtime-Polymorphism)
- [Virtual Function](#Virtual-Function)
- [Some Key Points About Virtual Functions](#Some-Key-Points-About-Virtual-Functions)
- [Function Overloading vs Function Overriding](#Function-Overloading-vs-Function-Overriding)


## polymorphism
The word `polymorphism` means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. 
A real-life example of polymorphism is a person who at the same time can have different characteristics. A man at the same time is a father, a husband, and an employee. So the same person exhibits different behavior in different situations. This is called polymorphism. Polymorphism is considered one of the important features of Object-Oriented Programming.


## Types of Polymorphism
- Compile-time Polymorphism.
- Runtime Polymorphism.

![Polymorphism-in-CPP](https://user-images.githubusercontent.com/105644935/217147380-72994635-64a8-42a8-bb6d-96f6205bd62f.png)


## Compile-Time Polymorphism

This type of polymorphism is achieved by function overloading or operator overloading.


- Function Overloading
When there are multiple functions with the same name but different parameters, then the functions are said to be overloaded, hence this is known as Function Overloading. Functions can be overloaded by changing the number of arguments or/and changing the type of arguments. In simple terms, it is a feature of object-oriented programming providing many functions to have the same name but distinct parameters when numerous tasks are listed under one function name


### Below is the C++ program to show function overloading or compile-time polymorphism:

```cpp
// C++ program to demonstrate
// function overloading or
// Compile-time Polymorphism
#include <bits/stdc++.h>

using namespace std;
class Geeks {
public:

  // Function with 1 int parameter
  void func(int x){
	cout << "value of x is " <<	x << endl;
  }

  // Function with same name but
  // 1 double parameter
  void func(double x){
	cout << "value of x is " << x << endl;
  }

  // Function with same name and
  // 2 int parameters
  void func(int x, int y){
	cout << "value of x and y is " <<	x << ", " << y << endl;
  }
};


int main()
{
  Geeks obj1;

  // Function being called depends
  // on the parameters passed
  // func() is called with int value
  obj1.func(7);

  // func() is called with double value
  obj1.func(9.132);

  // func() is called with 2 int values
  obj1.func(85, 64);

  return 0;
}
```
`Output`
```cpp
 value of x is 7 
 value of x is 9.132
 value of x and y is 85, 64
```

#### Explanation: 
In the above example, a single function named function func() acts differently in three different situations, which is a property of polymorphism.


- Operator Overloading

C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can make use of the addition operator (+) for string class to concatenate two strings. We know that the task of this operator is to add two operands. So a single operator `+`, when placed between integer operands, adds them and when placed between string operands, concatenates them. 



#### Below is the C++ program to demonstrate operator overloading:

```cpp
// C++ program to demonstrate
// Operator Overloading or
// Compile-Time Polymorphism
#include <iostream>
using namespace std;

class Complex {
private:
  int real, imag;

public:
  Complex(int r = 0, int i = 0){
	real = r;
	imag = i;
  }

  // This is automatically called
  // when '+' is used with between
  // two Complex objects
  Complex operator+(Complex const& obj){
	Complex res;
	res.real = real + obj.real;
	res.imag = imag + obj.imag;
	return res;
  }

  void print(){
    cout << real << " + i" <<	imag << endl;
  }
};

int main()
{
  Complex c1(10, 5), c2(2, 4);

  // An example call to "operator+"
  Complex c3 = c1 + c2;
  c3.print();
  
  return 0;
}
```

`Output: 12 + i9`

#### Explanation:  
In the above example, the operator ‘+’ is overloaded. Usually, this operator is used to add two numbers (integers or floating point numbers), but here the operator is made to perform the addition of two imaginary or complex numbers. 


## 2. Runtime Polymorphism
This type of polymorphism is achieved by Function Overriding. Late binding and dynamic polymorphism are other names for runtime polymorphism. The function call is resolved at runtime in In contrast, with compile time polymorphism, the compiler determines which function call to bind to the object after deducing it at runtime.


- Function Overriding
Function Overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.


![FunctionOverridingAlgo-474x660](https://user-images.githubusercontent.com/105644935/217148514-744b3691-a8d0-4bd6-add6-a94284076617.png)

#### Below is the C++ program to demonstrate function overriding:  

```cpp
// C++ program for function overriding
#include <bits/stdc++.h>
using namespace std;

class base {
public:
  virtual void print(){
	cout << "print base class" << endl;
  }

  void show(){
    cout << "show base class" << endl;
  }
};

class derived : public base {
public:

  // print () is already virtual function in
  // derived class, we could also declared as
  // virtual void print () explicitly
  void print(){
	cout << "print derived class" << endl;
  }

  void show(){
    cout << "show derived class" << endl;
  }
};

int main()
{
  base* bptr;
  derived d;
  bptr = &d;

  // Virtual function, binded at
  // runtime (Runtime polymorphism)
  bptr->print();

  // Non-virtual function, binded
  // at compile time
  bptr->show();

  return 0;
}
```
`Output`
```cpp
 print derived class
 show base class
```

## Virtual Function
A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class. 


## Some Key Points About Virtual Functions
- irtual functions are Dynamic in nature
- They are defined by inserting the keyword “virtual” inside a base class and are always declared with a base class and overridden in a child class
- A virtual function is called during Runtime

#### Below is the C++ program to demonstrate virtual function:

```cpp
// C++ Program to demonstrate
// the Virtual Function
#include <iostream>
using namespace std;

// Declaring a Base class
class GFG_Base {

public:
  // virtual function
  virtual void display(){
	cout << "Called virtual Base Class function" << "\n\n";
  }

  void print(){
	cout << "Called GFG_Base print function" << "\n\n";
  }
};

// Declaring a Child Class
class GFG_Child : public GFG_Base {

public:
  void display(){
	cout << "Called GFG_Child Display Function" << "\n\n";
  }

  void print(){
	cout << "Called GFG_Child print Function" <<	"\n\n";
  }
};


int main()
{
  // Create a reference of class GFG_Base
  GFG_Base* base;

  GFG_Child child;

  base = &child;

  // This will call the virtual function
  base->GFG_Base::display();

  // this will call the non-virtual function
  base->print();
  
  return 0;
}
```

`Output`
```cpp
Called virtual Base Class function
Called GFG_Base print function
```

<br>

## Function Overloading vs Function Overriding 

| Function Overloading  | Function Overriding |
| :---: | :---: |
| Function Overloading provides multiple definitions of the function by changing signature. | Function Overriding is the redefinition of base class function in its derived class with same signature.  |
| An example of compile time polymorphism. | An example of run time polymorphism.  |
| Function signatures should be different. | Function signatures should be the same. |
| Overloaded functions are in same scope. | Overridden functions are in different scopes. |
| Overloading is used when the same function has to behave differently depending upon parameters passed to them. | Overriding is needed when derived class function has to do some different job than the base class function.  |
| A function has the ability to load multiple times.  | A function can be overridden only a single time. |
| In function overloading, we don’t need inheritance. | In function overriding, we need an inheritance concept. |










