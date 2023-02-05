- [Inheritance](#Inheritance) 
- [Why and when to use inheritance](#Why-and-when-to-use-inheritance)
- [Implementing inheritance](#Implementing-inheritance)
- [Example define member function without argument within the class](#Example-define-member-function-without-argument-within-the-class)
- [Modes of Inheritance There are 3 modes of inheritance](#Modes-of-Inheritance-There-are-3-modes-of-inheritance)
- [Example public Inheritance](#Example-public-Inheritance)
- [Accessibility in public Inheritance](#Accessibility-in-public-Inheritance)
- [Accessibility in protected Inheritance](#Accessibility-in-protected-Inheritance)
- [Example private Inheritance](#Example-private-Inheritance)
- [Accessibility in private Inheritance](#Accessibility-in-private-Inheritance)



## Inheritance 

The capability of a [class](https://github.com/GergesHany/object-oriented-programming-OOP-/tree/main/Objects%20and%20classes) to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important features of Object-Oriented Programming. 

Inheritance is a feature or a process in which, new classes are created from the existing classes. The new class created is called “derived class” or “child class” and the existing class is known as the “base class” or “parent class”. The derived class now is said to be inherited from the base class.

When we say derived class inherits the base class, it means, the derived class inherits all the properties of the base class, without changing the properties of base class and may add new features to its own. These new features in the derived class will not affect the base class. The derived class is the specialized class for the base class.

- `Sub Class`: The class that inherits properties from another class is called Subclass or Derived Class. 
- `Super Class`: The class whose properties are inherited by a subclass is called Base Class or Superclass. 

## Why and when to use inheritance

Consider a group of vehicles. You need to create classes for Bus, Car, and Truck. The methods fuelAmount(), capacity(), applyBrakes() will be the same for all three classes. If we create these classes avoiding inheritance then we have to write all of these functions in each of the three classes as shown below figure: 
![inheritance](https://user-images.githubusercontent.com/105644935/216793458-8f91a65c-eec7-4509-9a09-72fe2dea8e69.png)

You can clearly see that the above process results in duplication of the same code 3 times. This increases the chances of error and data redundancy. To avoid this type of situation, inheritance is used. If we create a class Vehicle and write these three functions in it and inherit the rest of the classes from the vehicle class, then we can simply avoid the duplication of data and increase re-usability. Look at the below diagram in which the three classes are inherited from vehicle class:

![inheritance2](https://user-images.githubusercontent.com/105644935/216793476-edc4b052-6b43-491b-a1f4-fb6cd6d39827.png)

Using inheritance, we have to write the functions only one time instead of three times as we have inherited the rest of the three classes from the base class (Vehicle).

## Implementing inheritance 

Derived Classes: A Derived class is defined as the class derived from the base class.

`Syntax:`

```cpp
class  <derived_class_name> : <access-specifier> <base_class_name> {
        //body
}
```

Where
class      — keyword to create a new class
derived_class_name   — name of the new class, which will inherit the base class
access-specifier  — either of private, public or protected. If neither is specified, PRIVATE is taken as default
base-class-name  — name of the base class
Note: A derived class doesn’t inherit access to private data members. However, it does inherit a full parent object, which contains any private members which that class declares.


### Example:
```cpp
class ABC : private XYZ{   //private derivation    

}

class ABC : public XYZ{  //public derivation

}
             
class ABC : protected XYZ{ //protected derivation                         

}
            
            
class ABC: XYZ { //private derivation by default           

}
```

> **Note**
When a base class is privately inherited by the derived class, public members of the base class becomes the private members of the derived class and therefore, the public members of the base class can only be accessed by the member functions of the derived class. They are inaccessible to the objects of the derived class.
On the other hand, when the base class is publicly inherited by the derived class, public members of the base class also become the public members of the derived class. Therefore, the public members of the base class are accessible by the objects of the derived class as well as by the member functions of the derived class.

## Example define member function without argument within the class
 
```cpp
#include<iostream>
using namespace std;

// define (base, super) class Person
class Person{
// private data members  
  int id;
  char name[100];

  // public member functions
public:
  // define member function without argument within the class
  void set_p(){
    cout << "Enter the Id:"; // input id
    cin >> id; // input id
    fflush(stdin); // clear the buffer of the input stream
    cout << "Enter the Name:";
    cin.get(name,100); // input name with getline function because it can read spaces
  }

  // define member function without argument within the class to display the data
  void display_p(){
    cout << endl << id << "\t" << name << "\t";
  }
};

// define (derived, sub) class Student
class Student: private Person{
  // private data members  
  int fee;
  char course[50];
	
public:
  // define member function without argument within the class 	
  void set_s(){
    set_p(); // call the member function of the base class to set the data
    cout << "Enter the Course Name:"; // input course name
    fflush(stdin); // clear the buffer of the input stream
    cin.getline(course,50); // input course name with getline function because it can read spaces
    cout << "Enter the Course Fee:"; // input course fee
    cin >> fee; // input course fee
  }
  
   // define member function without argument within the class to display the data
   void display_s(){
     display_p();
     cout << course << "\t" << fee << "\n";
   }
};

main()
{
	

  Student s; // create an object of the derived class
  s.set_s(); // call the member function of the derived class to set the data
  s.display_s(); // call the member function of the derived class to display the data

  return 0;
}
```

`Output:`
```cpp
  Enter the Id: 101
  Enter the Name: Dev
  Enter the Course Name: GCS
  Enter the Course Fee: 70000
  101      Dev     GCS    70000
```
 

## Modes of Inheritance There are 3 modes of inheritance

- `Public Mode:` If we derive a subclass from a `public` base class. Then the `public` member of the base class will become `public` in the derived class and `protected` members of the base class will become `protected` in the derived class.

- `Protected Mode:` If we derive a subclass from a `Protected` base class. `Then both public members and protected` members of the base class will become `protected` in the derived class.

- `Private Mode:` If we derive a subclass from a `Private` base class. `Then both public members and protected members of the base class will become Private` in the derived class.

> **Note**
The `private members` in the base class `cannot be directly accessed` in the derived class, while `protected` members can be directly accessed. For example, Classes B, C, and D all contain the variables x, y, and z in the below `example. It is just a question of access`.  

```cpp
// C++ Implementation to show that a derived class doesn’t inherit access to private data members.
// However, it does inherit a full parent object.
class A {
public:
  int x;

protected:
  int y;

private:
  int z;
};

class B : public A {
  // x is public
  // y is protected
  // z is not accessible from B
};

class C : protected A {
  // x is protected
  // y is protected
  // z is not accessible from C
};

class D : private A{  // 'private' is default for classes
  // x is private
  // y is private
  // z is not accessible from D
};
```

|  Base class member access specifier  |  | typs of inheritance |  |
| :---: | :---: |  :---:   | :---: |
|       | public | protected | private |
|public| public | protected | private |
|protected| protected | protected | private |
|private| Not accessible (Hidden)  | Not accessible (Hidden)  | Not accessible (Hidden)  |




## Example public Inheritance

```cpp
// C++ program to demonstrate the working of public inheritance

#include <iostream>
using namespace std;

class Base {
  private:
    int pvt = 1;

  protected:
    int prot = 2;

  public:
    int pub = 3;

    // function to access private member
    int getPVT() {
      return pvt;
    }
};

class PublicDerived : public Base {
  public:
    // function to access protected member from Base
    int getProt() {
      return prot;
    }
};

int main() {
  PublicDerived object1;
  cout << "Private = " << object1.getPVT() << endl;
  cout << "Protected = " << object1.getProt() << endl;
  cout << "Public = " << object1.pub << endl;
  return 0;
}
```
`Output`
```cpp
 Private = 1
 Protected = 2
 Public = 3
```
- Here, we have derived `PublicDerived` from `Base` in public mode. As a result, in `PublicDerived`:
- `prot` is inherited as `protected`
- `pub` and `getPVT()` are inherited as `public.`
- `pvt` is inaccessible since it is `private` in `Base`.

#### Since private and protected members are not accessible from main(), we need to create public functions getPVT() and getProt() to access them:

```cpp
// Error: member "Base::pvt" is inaccessible
cout << "Private = " << object1.pvt;

// Error: member "Base::prot" is inaccessible
cout << "Protected = " << object1.prot;
```

Notice that the `getPVT()` function has been defined inside `Base`. But the `getProt()` function has been defined inside `PublicDerived.`

This is because `pvt`, which is private in `Base`, is inaccessible to `PublicDerived`.

However, `prot` is accessible to `PublicDerived` due to public inheritance. So, getProt() can access the protected variable from within `PublicDerived`

## Accessibility in public Inheritance


| Accessibility | private members	 | protected members | public members |
| :---: | :---: |  :---:   | :---: |
| Base Class | Yes | Yes | Yes |
|Derived Class| No | Yes | Yes |


## Example protected Inheritance

```cpp
// C++ program to demonstrate the working of protected inheritance

#include <iostream>
using namespace std;

class Base {
  private:
    int pvt = 1;

  protected:
    int prot = 2;

   public:
    int pub = 3;

    // function to access private member
    int getPVT() {
      return pvt;
    }
};

class ProtectedDerived : protected Base {
  public:
    // function to access protected member from Base
    int getProt() {
      return prot;
    }

    // function to access public member from Base
    int getPub() {
      return pub;
    }
};

int main() {
  ProtectedDerived object1;
  cout << "Private cannot be accessed." << endl;
  cout << "Protected = " << object1.getProt() << endl;
  cout << "Public = " << object1.getPub() << endl;
  return 0;
}
```

`Output`
```cpp
 Private cannot be accessed. 
 Protected = 2
 Public = 3
```

Here, we have derived `ProtectedDerived` from `Base` in `protected mode`.

As a result, in `ProtectedDerived`:

- `prot`, `pub` and `getPVT()` are inherited as `protected`
- `pvt` is inaccessible since it is `private` in `Base`.

As we know, `protected` members cannot be directly accessed from outside the class. As a result, we cannot use `getPVT()` from `ProtectedDerived`

That is also why we need to create the `getPub()` function in `ProtectedDerived` in order to access the `pub` variable.

```cpp
// Error: member "Base::getPVT()" is inaccessible
cout << "Private = " << object1.getPVT();

// Error: member "Base::pub" is inaccessible
cout << "Public = " << object1.pub;
```

## Accessibility in protected Inheritance

| Accessibility | private members | protected members | public members |
| :---: | :---: |  :---:   | :---: |
| Base Class | Yes | Yes | Yes |
|Derived Class| No | Yes | Yes (inherited as protected variables) |


## Example private Inheritance
```cpp
// C++ program to demonstrate the working of private inheritance

#include <iostream>
using namespace std;

class Base {
  private:
    int pvt = 1;

  protected:
    int prot = 2;

  public:
    int pub = 3;

    // function to access private member
    int getPVT() {
      return pvt;
    }
};

class PrivateDerived : private Base {
  public:
    // function to access protected member from Base
    int getProt() {
      return prot;
    }

    // function to access private member
    int getPub() {
      return pub;
    }
};

int main() {
  PrivateDerived object1;
  cout << "Private cannot be accessed." << endl;
  cout << "Protected = " << object1.getProt() << endl;
  cout << "Public = " << object1.getPub() << endl;
  return 0;
}
```

`Output`
```cpp
  Private cannot be accessed.
  Protected = 2
  Public = 3
```

Here, we have derived `PrivateDerived` from `Base` in `private mode`.
As a result, in `PrivateDerived:`

- `prot`, `pub` and `getPVT()` are inherited as `private`.
- `pvt` is inaccessible since it is `private` in `Base`

As we know, private members cannot be directly accessed from outside the class. As a result, we cannot use `getPVT()` from `PrivateDerived`.

That is also why we need to create the `getPub()` function in PrivateDerived in order to access the `pub` `variable`.

```cpp
// Error: member "Base::getPVT()" is inaccessible
cout << "Private = " << object1.getPVT();

// Error: member "Base::pub" is inaccessible
cout << "Public = " << object1.pub;
```
## Accessibility in private Inheritance

| Accessibility | private members | protected members | public members |
| :---: | :---: |  :---:   | :---: |
| Base Class | Yes | Yes | Yes |
|Derived Class| No | Yes (inherited as private variables) | Yes (inherited as protected variables) |



















