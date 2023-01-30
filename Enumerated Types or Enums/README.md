## Enumerated Types or Enums in C++

![Enum-In-C++](https://user-images.githubusercontent.com/105644935/215512826-2809c545-e46f-42fd-a13f-c3d032273485.jpg)

Enumerated type (enumeration) is a user-defined data type which can be assigned some limited values. These values are defined by the programmer at the time of declaring the enumerated type.

If we assign a float value in a character value, then the compiler generates an error. In the same way if we try to assign any other value to the enumerated data types, the compiler generates an error. Enumerator types of values are also known as enumerators. It is also assigned by zero the same as the array. It can also be used with switch statements.
For example: If a gender variable is created with value male or female. If any other value is assigned other than male or female then it is not appropriate. In this situation, one can declare the enumerated type in which only male and female values are assigned.

Syntax:
```cpp
enum enumerated-type-name{value1, value2, value3…..valueN};
```

enum keyword is used to declare enumerated types after that enumerated type name was written then under curly brackets possible values are defined. After defining Enumerated type variables are created. It can be created in two types:-

- It can be declared during declaring enumerated types, just add the name of the variable before the semicolon. or,
- Beside this, we can create enumerated type variables as same as the normal variables.

```cpp
enumerated-type-name variable-name = value;
```

By default, the starting code value of the first element of enum is 0 (as in the case of array) . But it can be changed explicitly.

For example: enum enumerated-type-name{value1=1, value2, value3};

And, The consecutive values of the enum will have the next set of code value(s).

For example:
```cpp
//first_enum is the enumerated-type-name
enum first_enum{value1 = 1, value2 = 10, value3};

In this case, 
first_enum e;
e = value3;
cout << e;
```

`Output: 11`

- Example 1: 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
  // Defining enum Gender
  enum Gender { Male, Female };

  // Creating Gender type variable
  Gender gender = Male;

  switch (gender)
  {
    case Male:
     cout << "Gender is Male";
     break;
    case Female:
     cout << "Gender is Female";
     break;
    default:
     cout << "Value can be Male or Female";
  }
return 0;
}
```
`Output: Gender is Male`


- Example 2:

```cpp
#include <bits/stdc++.h>
using namespace std;

// Defining enum Year
enum year { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

// Driver Code
int main()
{
   // Traversing the year enum
   for (int i = Jan; i <= Dec; i++)
     cout << i << " ";
  return 0;
}
```
`Output: 0 1 2 3 4 5 6 7 8 9 10 11`

- Example 3:


```cpp
#include <bits/stdc++.h>
using namespace std;

// Defining enum Year
enum year { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};


// Driver Code
int main()
{
  // Traversing the year enum
  for (int i = Jan; i <= Dec; i++)
    cout << i << " ";

   return 0;
}
```
`Output: 1 2 3 4 5 6 7 8 9 10 11 12`

## Examlpe for Enum and class
```cpp
// protected access modifier
#include <bits/stdc++.h>
using namespace std;

// enumaration
enum days {sunday = 1, monday, tuesday, wednesday, thursday, friday, saturday};
// array of strings 
string dayss[7] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

// class week
class week{
  days d[7]; // array of days

 public:
  // constructor to initialize the array of days
  week(days Days[7]){
    for(int i = 0; i < 7; i++) 
      d[i] = Days[i];
  }

  void print(){
    for(int i = 0; i < 7; i++)  
      cout << d[i] << " " << dayss[i] << "\n";
  }

};


int main() {
	
  // array of days
  days d[7] = {sunday, monday, tuesday, wednesday, thursday, friday, saturday};
  week w(d); // object of week class
  w.print(); // print the days

 return 0;
}

```




