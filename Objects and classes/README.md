# Objects and classes
Exist two main concepts in OOP: Classes and objects.

**Class** : A class in C++ is the building block that leads to Object-Oriented programming.  
It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A C++ class is like a blueprint for an object. For Example: Consider the Class of Cars. There may be many cars with different names and brand but all of them will share some common properties like all of them will have 4 wheels, Speed Limit, Mileage range etc. So here, Car is the class and wheels, speed limits, mileage are their properties.

A Class is a user defined data-type which has data members and member functions.
Data members are the data variables and member functions are the functions used to manipulate these variables and together these data members and member functions defines the properties and behavior of the objects in a Class.
In the above example of class Car, the data member will be speed limit, mileage etc and member functions can be apply brakes, increase speed etc.  

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


