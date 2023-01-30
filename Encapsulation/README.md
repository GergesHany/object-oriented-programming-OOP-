- [Encapsulation](#Encapsulation)
- [Features of Encapsulation](#Features-of-Encapsulation)
- [Role of Access Specifiers in Encapsulation](#Role-of-Access-Specifiers-in-Encapsulation)




## Encapsulation

Encapsulation in C++ is defined as the wrapping up of data and information in a single unit. In Object Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.

Consider a real-life example of encapsulation, in a company, there are different sections like the accounts section, finance section, sales section, etc. Now,

- The finance section handles all the financial transactions and keeps records of all the data related to finance.
- Similarly, the sales section handles all the sales-related activities and keeps records of all the sales.

Now there may arise a situation when for some reason an official from the finance section needs all the data about sales in a particular month.

In this case, he is not allowed to directly access the data of the sales section. He will first have to contact some other officer in the sales section and then request him to give the particular data.

This is what `Encapsulation` is. Here the data of the sales section and the employees that can manipulate them are wrapped under a single name `sales section`. 

<br>

### Features of Encapsulation
1. We can not access any function from the class directly. We need an object to access that function that is using the member variables of that class.
1. The function which we are making inside the class must use only member variables, only then it is called encapsulation.
1. If we don’t make a function inside the class which is using the member variable of the class then we don’t call it encapsulation.
1. Increase in the security of data
1. It helps to control the modification of our data members.

![encapsulation-image](https://user-images.githubusercontent.com/105644935/215284659-5203cf23-347f-4e95-8ad8-d8141df3a490.jpg)


Encapsulation also leads to [data abstraction](https://github.com/GergesHany/object-oriented-programming-OOP-/blob/main/abstraction/README.md). Using encapsulation also hides the data, as in the above example, the data of the sections like sales, finance, or accounts are hidden from any other section.

<br>

#### In C++, encapsulation can be implemented using classes and [access modifiers](https://github.com/GergesHany/object-oriented-programming-OOP-/tree/main/Access%20Modifiers)

Example:
```cpp
// Encapsulation
#include <iostream>
using namespace std;

class Encapsulation {
private:
  // Data hidden from outside world
  int x;

public:
  // Function to set value of variable x
  void set(int a) { x = a; }

  // Function to return value of variable x
  int get() { return x; }
};

int main()
{
	
  Encapsulation obj; // Creating object of class
  obj.set(5); // Setting value of variable x using member function
  cout << obj.get(); // Getting value of variable x using member function

	return 0;
}
```
```cpp
Output: 5
```


### Explanation: 
In the above program, the variable x is made private. This variable can be accessed and manipulated only using the functions get() and set() which are present inside the class. Thus we can say that here, the variable x and the functions get() and set() are bound together which is nothing but encapsulation.

```cpp
#include <iostream>
using namespace std;

// declaring class
class Circle {
	// access modifier
private:
  // Data Member
  float area;
  float radius;

public:
  // Member Function
  
  void getRadius(){
    cout << "Enter radius ";
    cin >> radius;
    cout << "\n";
  }

  void findArea(){
    area = 3.14 * radius * radius; // formula of area of circle to find area
    cout << "Area of circle = " << area << "\n";
  }
};
int main()
{
  Circle cir; // creating instance(object) of class
  cir.getRadius(); // calling function
  cir.findArea(); // calling function
}
```

```cpp
Output:

Enter radius -> (for example radius equal 10)   
Area of circle = 314

```


### Role of Access Specifiers in Encapsulation

Access specifiers facilitate Data Hiding in C++ programs by restricting access to the class member functions and data members. There are three types of access specifiers in C++:

- Private
- Protected
- Public

By default, all data members and member functions of a class are made private by the compiler.

Points to Consider
As we have seen in the above example, access specifiers play an important role in implementing encapsulation in C++. The process of implementing encapsulation can be sub-divided into two steps:

- Creating a class to encapsulate all the data and methods into a single unit.
- Hiding relevant data using access specifiers.











