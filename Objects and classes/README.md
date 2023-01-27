# Objects and classes
**Exist two main concepts in OOP: Classes and objects.**

****Class : A class in C++ is the building block that leads to Object-Oriented programming.  
It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A C++ class is like a blueprint for an object. For Example: Consider the Class of Cars. There may be many cars with different names and brand but all of them will share some common properties like all of them will have 4 wheels, Speed Limit, Mileage range etc. So here, Car is the class and wheels, speed limits, mileage are their properties.****

****A Class is a user defined data-type which has data members and member functions.
Data members are the data variables and member functions are the functions used to manipulate these variables and together these data members and member functions defines the properties and behavior of the objects in a Class.
In the above example of class Car, the data member will be speed limit, mileage etc and member functions can be apply brakes, increase speed etc.****  

**An Object** : is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.

## Defining Class 

![Classes-and-Objects-in-C](https://user-images.githubusercontent.com/105644935/213048516-b58f0441-dc75-4e9c-a99c-ae2ce24e3023.png)


## Member Functions in Classes 

There are 2 ways to define a member function:
- Inside class definition
- Outside class definition

# example for (Inside class definition)
```cpp
class triangle{
  // the class is a blueprint for creating objects

  private: // the private access specifier is used to declare private members
    int x, y;

  public: // the public access specifier is used to declare public members
    
    // constructor is a special member function with the same name as of the class
    triangle(int x, int y){
      // this -> x is the x of the object itself and x is the x of the parameter
      this -> x = x;  // set the x of the object to the x of the parameter
      this -> y = y; // set the y of the object to the y of the parameter
    }

    // member functions (methods)
    
    int get_x(){ 
      return this -> x; // return the x of the object
    }

    int get_y(){
      return this -> y;
    }

    void set_x(int x){
      this -> x = x; // set the x of the object to the x of the parameter
    }

    void set_y(int y){
      this -> y = y;
    }

    void print(){
      // print the x and y of the object
      cout << this -> x << " " << this -> y << "\n";
    }    
};

```

# example for (Outside class definition)

```cpp
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
```

## Constructors:
Constructor in C++ is a special method that is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally. The constructor in C++ has the same name as the class or structure. Constructor is invoked at the time of object creation. It constructs the values i.e. provides data for the object which is why it is known as constructors.

Constructor does not have a return value, hence they do not have a return type.  


### Constructors can be defined inside or outside the class declaration:-

**The syntax for defining the constructor within the class: ` < class-name > (list-of-parameters) { // constructor definition }`**

**The syntax for defining the constructor outside the class: ` <class-name>: :<class-name> (list-of-parameters){ // constructor definition}`**

## Example for defining the constructor within the class

```cpp
class student {
  string name;
 
public:
    // Default constructor (no parameters)
    student(){
      cout << "Default constructor called" << "\n";
    }
};
```

## Example for defining the constructor outside  the class

```cpp
class student {
  string name;
 
public:
    student(); // constructor declaration
};

// constructor definition 
student::student(){
  cout << "Default constructor called" << "\n";
}
```



### A constructor is different from normal functions in following ways: 
- Constructor has same name as the class itself
- Default Constructors don’t have input argument however, Copy and Parameterized Constructors have input arguments
- Constructors don’t have return type
- A constructor is automatically called when an object is created
- It must be placed in public section of class.
- If we do not specify a constructor, C++ compiler generates a default constructor for object (expects no parameters and has an empty body).

![CPP-Constructors](https://user-images.githubusercontent.com/105644935/214370894-54fa3d9a-a39f-4750-bbc6-0412790b3632.png)

****Let us understand the types of constructors in C++ by taking a real-world example. Suppose you went to a shop to buy a marker. When you want to buy a marker, what are the options. The first one you go to a shop and say give me a marker. So just saying give me a marker mean that you did not set which brand name and which color, you didn’t mention anything just say you want a marker. So when we said just I want a marker so whatever the frequently sold marker is there in the market or in his shop he will simply hand over that. And this is what a default constructor is! The second method is you go to a shop and say I want a marker a red in color and XYZ brand. So you are mentioning this and he will give you that marker. So in this case you have given the parameters. And this is what a parameterized constructor is! Then the third one you go to a shop and say I want a marker like this(a physical marker on your hand). So the shopkeeper will see that marker. Okay, and he will give a new marker for you. So copy of that marker. And that’s what a copy constructor is!****

<br>

## Characteristics of the constructor:
- The name of the constructor is the same as its class name.
- Constructors are mostly declared in the public section of the class though it can be declared in the private section of the class.
- Constructors do not return values; hence they do not have a return type.
- A constructor gets called automatically when we create the object of the class.
- Constructors can be overloaded.
- Constructor can not be declared virtual.
- Constructor cannot be inherited.
- Addresses of Constructor cannot be referred.
- Constructor make implicit calls to new and delete operators during memory allocation.

<br>

## Types of Constructors
- Default Constructors:
- Parameterized Constructors: 
- Copy Constructor: 

<br>


### 1. **Default Constructors:** 
**Default constructor is the constructor which doesn’t take any argument. It has no parameters. It is also called a zero-argument constructor.**

```cpp
#include <bits/stdc++.h>
using namespace std; 

class temp {
public:
    int a, b;
 
    // Default Constructor (Called when no arguments are passed)
    temp(){
        a = 10; // Default value of a
        b = 20; // Default value of b
    }
};


int main()
{

  temp t1; // Default Constructor called
  cout << t1.a << " " << t1.b << "\n";
  
  return 0;
}
```
> **Note**: **Even if we do not define any constructor explicitly, the compiler will automatically provide a default constructor implicitly**.

<br>
<br>

### 2. **Parameterized Constructors:** 
**Parameterized Constructors: It is possible to pass arguments to constructors. Typically, these arguments help initialize an object when it is created. To create a parameterized constructor, simply add parameters to it the way you would to any other function. When you define the constructor’s body, use the parameters to initialize the object.** 

> **Note**: **when the parameterized constructor is defined and no default constructor is defined explicitly, the compiler will not implicitly call the default constructor and hence creating a simple object as**

#### Student s;
**Will flash an error**

<br>

```cpp
#include <bits/stdc++.h>
using namespace std; 

class Point {
private:
    int x, y;
 
public:

    // Parameterized Constructor 
    Point(int x1, int y1){
        x = x1;
        y = y1;
    }

    int getX() { return x; } // Getter function for x 
    int getY() { return y; } // Getter function for y
 
};

int main()
{

  // Point p; ->> error because no default constructor
  Point p(10, 20); // Parameterized constructor called
  cout << p.getX() << " " << p.getY();
  
  return 0;
}
```
<br>

**When an object is declared in a parameterized constructor, the initial values have to be passed as arguments to the constructor function. The normal way of object declaration may not work. The constructors can be called explicitly or implicitly.**

`Example p = Example(0, 50); // Explicit call`

`Example p(0, 50);           // Implicit call`

- ## Uses of Parameterized constructor: 
1. **It is used to initialize the various data elements of different objects with different values when they are created.**
2. **It is used to overload constructors.**

Can we have more than one constructor in a class? Yes, It is called Constructor Overloading.

### Constructor Overloading

```cpp
#include <bits/stdc++.h>
using namespace std; 

 
class construct{
 
public:
    float area;
     
    // Constructor with no parameters (Default constructor)
    construct(){
        area = 0;
    }
     
    // Constructor with two parameters (Parameterized constructor)
    construct(int a, int b){
        area = a * b;
    }
     
     // function to display the area
    void disp(){
        cout << "Area: " << area << "\n";
    }
};
 

int main()
{
 
  construct obj1; // Implicit call to constructor
  construct obj2(10, 20); // Implicit call to constructor
  construct obj3 = construct(20, 30); // Explicit call to constructor

  obj1.disp(); // calling member function
  obj2.disp(); // calling member function
  obj3.disp(); // calling member function
  
  
  return 0;
}
```

- Overloaded constructors essentially have the same name (exact name of the class) and different by number and type of arguments.
- A constructor is called depending upon the number and type of arguments passed.
- While creating the object, arguments must be passed to let compiler know, which constructor needs to be called. 


## 3. **Copy Constructor:** 
**A copy constructor is a member function that initializes an object using another object of the same class**

Whenever we define one or more non-default constructors( with parameters ) for a class, a default constructor( without parameters ) should also be explicitly defined as the compiler will not provide a default constructor in this case. However, it is not necessary but it’s considered to be the best practice to always define a default constructor. 

Copy constructor takes a reference to an object of the same class as an argument.

```cpp
#include <bits/stdc++.h>
using namespace std; 

 
class construct{
 
public:
    float area;
     
    // Constructor with no parameters (Default constructor)
    construct(){
        area = 0;
    }
     
    // Constructor with two parameters (Parameterized constructor)
    construct(int a, int b){
        area = a * b;
    }
     
    // copy Constructor
    construct(const construct &temp){
        area = temp.area;    
    }
    
    // function to display the area
    void disp(){
        cout << "Area: " << area << "\n";
    }

};
 

int main()
{
 
  construct obj1; // Implicit call to constructor
  construct obj2(10, 20); // Implicit call to constructor

  construct obj3(obj2); // Implicit call to copy constructor 

  obj3.disp();  
  
  return 0;
}
```


## Destructor:

A destructor is also a special member function as a constructor. Destructor destroys the class objects created by the constructor. Destructor has the same name as their class name preceded by a tilde (~) symbol. It is not possible to define more than one destructor. The destructor is only one way to destroy the object created by the constructor. Hence destructor can-not be overloaded. Destructor neither requires any argument nor returns any value. It is automatically called when the object goes out of scope.  Destructors release memory space occupied by the objects created by the constructor. In destructor, objects are destroyed in the reverse of object creation.

<br>

The syntax for defining the destructor within the class `~ <class-name>() {}`

The syntax for defining the destructor outside the class `<class-name>: : ~ <class-name>(){}`


```cpp
#include <iostream>
using namespace std;
 
class Test {
public:
  // constructor 
    Test() { cout << "\n Constructor executed"; }
 
    // destructor
    ~Test() { cout << "\n Destructor executed"; }
}; 

main()
{
    Test t; // constructor called
 
    return 0;
} // destructor called
```



### Characteristics of a destructor:
1. Destructor is invoked automatically by the compiler when its corresponding constructor goes out of scope and releases the memory space that is no longer required by the program.

2.  Destructor neither requires any argument nor returns any value therefore it cannot be overloaded.
3. Destructor  cannot be declared as static and const;
4. Destructor should be declared in the public section of the program.
5. Destructor is called in the reverse order of its constructor invocation.


#### other code for Destructor
```cpp
#include <bits/stdc++.h>
using namespace std; 
 
class rectangle{
  private:
   int height, width;
  
  public:
    rectangle(int h, int w){ // constructor (prameeterized constructor)
      height = h;
      width = w;
      cout << "constructor called" << "\n";
    }

    // function to calculate area
    int area(){ return height * width; }

    // function to get height 
    int get_height(){ return height; }

    // function to get width
    int get_width(){ return width; }  

    ~rectangle(){ // destructor to free memory
      cout << "destructor called" << " ";
    }

};

int main()
{
 
  rectangle r1(10, 5), r2(20, 10); // object
  cout << "r1 = " << r1.area() << " : " << r1.get_height() << " : " << r1.get_width() << "\n";
  cout << "r2 = " << r2.area() << " : " << r2.get_height() << " : " << r2.get_width() << "\n";

  return 0;
}

```

## Structures:
A structure is a user-defined data type in C/C++. A structure creates a data type that can be used to group items of possibly different types into a single type. 

![what-is-structure](https://user-images.githubusercontent.com/105644935/214913236-6c2d1b02-f05c-4fa0-8e90-737afa34ea52.png)

The `struct` keyword is used to create a structure. The general syntax to create a structure is as shown below:  

```cpp
struct structureName{
    member1;
    member2;
    member3;
    .
    .
    .
    memberN;
};
```

### Structures in C++ can contain two types of members:  
- Data Member: These members are normal C++ variables. We can create a structure with variables of different data types in C++.
- Member Functions: These members are normal C++ functions. Along with variables, we can also include functions inside a structure declaration.

Example 
```cpp
// Data Members
int roll;
int age;
int marks;
     
// Member Functions
void printDetails(){
    cout << "Roll = " << roll << "\n";
    cout << "Age = " << age << "\n";
    cout << "Marks = " << marks << "\n";
}
```

In the above structure, the data members are three integer variables to store roll number, age and marks of any student and the member function is printDetails() which is printing all of the above details of any student.


## declare structure variables:

A structure variable can either be declared with structure declaration or as a separate declaration like basic types.  

```cpp
// A variable declaration like basic data types
struct Point{
  int x, y;
  Point(int X = 0, int Y = 0){
     x = X, y = Y;
  }
};

int main(){

   Point p1; // The variable p2 is declared like a normal variable
   struct Point p2; // The variable p1 is declared like a normal variable
   
   cout << p1.x << " " << p1.y << endl; // print the value of x and y
   cout << p2.x << " " << p2.y << endl; // print the value of x and y

   return 0;
}
```

> **Note**
In C++, the struct keyword is optional before in declaration of a variable. In C, it is mandatory.

###  other syntax for declaring a member of a struct
```cpp
// A variable declaration like basic data types
struct Point{
  int x, y;
  Point(int X = 0, int Y = 0){
     x = X, y = Y;
  }
}p1; // The variable p1 is declared like a normal variable

int main(){

   p1.x = 10, p1.y = 20; // assign values to x and y   
   cout << p1.x << " " << p1.y << endl; // print the value of x and y

   return 0;
}
```

### Structure members are accessed using dot (.) operator. `p1.x`


## can make a array of struct:

#### code
```cpp
struct Point {
    int x, y; 
};


int main(){

  Point arr[3]; // array of 3 points
  for (int i = 0; i < 3; i++){
    cin >> arr[i].x >> arr[i].y; // input x and y of point i
  }

  for (int i = 0; i < 3; i++){
    cout << arr[i].x << " " << arr[i].y << "\n"; // output x and y of point i
  }
}
```

### What is a structure pointer? 
Like primitive types, we can have pointer to a structure. If we have a pointer to structure, members are accessed using arrow ( -> ) operator instead of the dot (.) operator.

```cpp
struct Point {
    int x, y; 
};

int main(){

   Point p1; // p1 is a variable of type Point
   p1.x = p1.y = 10; // Accessing members of p1 using dot operator and assigning values to them
 
   Point* p2 = &p1; // p2 is a pointer to a Point variable
   
   cout << p2 -> x << " " << p2 -> y << "\n"; // Accessing members of p1 using arrow operator
}
```

## Difference between class and struct

### Classes 
- Can support inheritance
- Are reference (pointer) types
- The reference can be null
- Have memory overhead per new instance


### Structs 
- Cannot support inheritance
- Are value types
- Are passed by value (like integers)
- Cannot have a null reference (unless Nullable is used)
- Do not have a memory overhead per new instance - unless 'boxed'

### Both Classes and Structs:
- Are compound data types typically used to contain a few variables that have some logical relationship
- Can contain methods and events
- Can support interfaces











