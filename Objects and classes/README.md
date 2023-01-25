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




