- [Exception Handling](#Exception-Handling)
- [Why Exception Handling](#Why-Exception-Handling)




## Exception Handling


One of the advantages of C++ over C is Exception Handling. Exceptions are runtime anomalies or abnormal conditions that a program encounters during its execution. There are two types of exceptions: a)Synchronous, b)Asynchronous (i.e., exceptions which are beyond the program’s control, such as disc failure, keyboard interrupts etc.). C++ provides the following specialized keywords for this purpose:

- `try:` Represents a block of code that can throw an exception. 
- `catch:` Represents a block of code that is executed when a particular exception is thrown.
- `throw:` Used to throw an exception. Also used to list the exceptions that a function throws but doesn’t handle itself

## Why Exception Handling
The following are the main advantages of exception handling over traditional error handling:

1. Separation of Error Handling code from Normal Code: In traditional error handling codes, there are always if-else conditions to handle errors. These conditions and the code to handle errors get mixed up with the normal flow. This makes the code less readable and maintainable. With try/catch blocks, the code for error handling becomes separate from the normal flow.

2. Functions/Methods can handle only the exceptions they choose: A function can throw many exceptions, but may choose to handle some of them. The other exceptions, which are thrown but not caught, can be handled by the caller. If the caller chooses not to catch them, then the exceptions are handled by the caller of the caller. In C++, a function can specify the exceptions that it throws using the throw keyword. The caller of this function must handle the exception in some way (either by specifying it again or catching it).

3.  Grouping of Error Types: In C++, both basic types and objects can be thrown as exceptions. We can create a hierarchy of exception objects, group exceptions in namespaces or classes and categorize them according to their types.

## C++ Exceptions:

When executing C++ code, different errors can occur: coding errors made by the programmer, errors due to wrong input, or other unforeseeable things.
When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: C++ will throw an exception (error).


## C++ try and catch:

Exception handling in C++ consists of three keywords: try, throw and catch:

The try statement allows you to define a block of code to be tested for errors while it is being executed.

The throw keyword throws an exception when a problem is detected, which lets us create a custom error.

The catch statement allows you to define a block of code to be executed if an error occurs in the try block.


The try and catch keywords come in pairs:

We use the try block to test some code: If the value of a variable “age” is less than 18, we will throw an exception, and handle it in our catch block.

In the catch block, we catch the error if it occurs and do something about it. The catch statement takes a single parameter. So, if the value of age is 15 and that’s why we are throwing an exception of type int in the try block (age), we can pass “int myNum” as the parameter to the catch statement, where the variable “myNum” is used to output the value of age.

If no error occurs (e.g. if age is 20 instead of 15, meaning it will be greater than 18), the catch block is skipped.


## Exception Handling in C++

### The following is a simple example to show exception handling in C++. The output of the program explains the flow of execution of try/catch blocks. 
```cpp
#include <iostream>
using namespace std;

int main()
{
int x = -1;

// Some code
cout << "Before try \n";
  try {
   cout << "Inside try \n";
   if (x < 0){
     throw x;
     cout << "After throw (Never executed) \n";
   }
  }catch (int x ) {
   cout << "Exception Caught \n";
  }

  cout << "After catch (Will be executed) \n";
return 0;
}
```

`Output:`
```cpp
Before try
Inside try
Exception Caught
After catch (Will be executed)
```

### There is a special catch block called the ‘catch all’ block, written as catch(…), that can be used to catch all types of exceptions. For example, in the following program, an int is thrown as an exception, but there is no catch block for int, so the catch(…) block will be executed. 

```cpp
#include <iostream>
using namespace std;

int main()
{
  try {
   throw 10;
  }
  catch (char *excp) {
    cout << "Caught " << excp;
  }
  catch (...) {
   cout << "Default Exception\n";
  }
	return 0;
}
```

`Output: Default Exception`

###  Implicit type conversion doesn’t happen for primitive types. For example, in the following program, ‘a’ is not implicitly converted to int. 

```cpp
#include <iostream>
using namespace std;

int main()
{
  try {
   throw 'a';
  }
  catch (int x) {
   cout << "Caught " << x;
  }
  catch (...) {
   cout << "Default Exception\n";
  }
  return 0;
}
```

`Output: Default Exception`

### If an exception is thrown and not caught anywhere, the program terminates abnormally. For example, in the following program, a char is thrown, but there is no catch block to catch the char.  

```cpp
#include <iostream>
using namespace std;

int main()
{
  try {
   throw 'a';
  }
  catch (int x) {
   cout << "Caught ";
  }
  return 0;
}
```
`Output:`
```cpp
terminate called after throwing an instance of 'char'

This application has requested the Runtime to terminate it in an 
unusual way. Please contact the application's support team for 
more information.
```

- A derived class exception should be caught before a base class exception. See [this](https://www.geeksforgeeks.org/catching-base-and-derived-classes-as-exceptions-in-cpp-and-java/) for more details.

- Like Java, the C++ library has a [standard exception class](https://cplusplus.com/reference/exception/exception/) which is the base class for all standard exceptions. All objects thrown by the components of the standard library are derived from this class. Therefore, all standard exceptions can be caught by catching this type

- Unlike Java, in C++, all exceptions are unchecked, i.e., the compiler doesn’t check whether an exception is caught or not (See [this](https://www.geeksforgeeks.org/checked-vs-unchecked-exceptions-in-java/) for details). So, it is not necessary to specify all uncaught exceptions in a function declaration. Although it’s a recommended practice to do so. For example, the following program compiles fine, but ideally the signature of fun() should list the unchecked exceptions. 

```cpp
#include <iostream>
using namespace std;

// This function signature is fine by the compiler, but not recommended.
// Ideally, the function should specify all uncaught exceptions and function
// signature should be "void fun(int *ptr, int x) throw (int *, int)"
void fun(int *ptr, int x){
  if (ptr == NULL)
   throw ptr;
  if (x == 0)
   throw x;
  /* Some functionality */
}

int main()
{
  try {
   fun(NULL, 0);
  }
  catch(...) {
   cout << "Caught exception from fun()";
  }
  return 0;
}
```
`Output: Caught exception from fun()`

### A better way to write the above code: 

```cpp
void fun(int *ptr, int x) throw (int *, int) { // Dynamic Exception specification
  if (ptr == NULL)
   throw ptr;
  if (x == 0)
   throw x;
  /* Some functionality */
}

int main()
{
  try {
   fun(NULL, 0);
  }
  catch(...) {
   cout << "Caught exception from fun()";
  }
  return 0;
}
```

> **Note** The use of Dynamic Exception Specification has been deprecated since C++11. One of the reasons for it may be that it can randomly abort your program. This can happen when you throw an exception of another type which is not mentioned in the dynamic exception specification. Your program will abort itself because in that scenario, it calls (indirectly) terminate(), which by default calls abort().

`Output: Caught exception from fun()`

### in C++, try/catch blocks can be nested. Also, an exception can be re-thrown using “throw; “. 

```cpp
#include <iostream>
using namespace std;

int main()
{
  try {
   try {
    throw 20;
  }
   catch (int n) {
    cout << "Handle Partially ";
     throw; // Re-throwing an exception
   }
  }
  catch (int n) {
   cout << "Handle remaining ";
 }
  return 0;
}
```

`Output: Handle Partially Handle remaining`

A function can also re-throw a function using the same “throw; ” syntax. A function can handle a part and ask the caller to handle the remaining.

### When an exception is thrown, all objects created inside the enclosing try block are destroyed before the control is transferred to the catch block.

```cpp
#include <iostream>
using namespace std;

class Test {
public:
  Test() {  
     cout << "Constructor of Test " << endl; 
  }
  ~Test() { 
    cout << "Destructor of Test " << endl; 
  }
};

int main()
{
  try {
   Test t1;
    throw 10;
  }
   catch (int i) {
    cout << "Caught " << i << endl;
  }
}
```
`Output:`

```cpp
Constructor of Test
Destructor of Test
Caught 10
```











