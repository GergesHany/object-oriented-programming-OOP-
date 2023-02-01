- [Operator Overloading](#Operator-Overloading)
- [What is the difference between operator functions and normal functions](#What-is-the-difference-between-operator-functions-and-normal-functions)
- [Can we overload all operators](#Can-we-overload-all-operators)
- [Operators that can be overloaded](#Operators-that-can-be-overloaded)
- [Why can’t the above-stated operators be overloaded](#Why-can’t-the-above-stated-operators-be-overloaded)
- [Important points about operator overloading](#Important-points-about-operator-overloading)
- [implementation all Binary Arithmetic Operators overloading](#implementation-all-Binary-Arithmetic-Operators-overloading)
- [implementation all Unary Arithmetic Operators overloading](#implementation-all-Unary-Arithmetic-Operators-overloading)
- [implementation all Bit-wise Operators overloading](#implementation-all-Bit-wise-Operators-overloading)



## Operator Overloading

In C++, we can make operators work for user-defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can overload an operator `+` in a class like String so that we can concatenate two strings by just using `+`. Other example classes where arithmetic operators may be overloaded are Complex Numbers, Fractional Numbers, Big Integer, etc.

Operator overloading is a compile-time polymorphism. It is an idea of giving special meaning to an existing operator in C++ without changing its original meaning.

Example:

```cpp
int a;
float b, sum;
sum = a + b;
```

Here, variables `a` and `b` are of types `int` and `float`, which are built-in data types. Hence the addition operator `+` can easily add the contents of `a` and `b`. This is because the addition operator `+` is predefined to add variables of built-in data type only.

Now, consider another example

```cpp
class A{
public:
  int x;
};

int main()
{
  A  a1, a2, a3;

  a3 = a1 + a2;

  return 0;
}

```

In this example, we have 3 variables `a1`, `a2` and `a3` of type `class A`. Here we are trying to add two objects `a1` and `a2`, which are of user-defined type i.e. of type `class A` using the `+` operator. This is not allowed, because the addition operator `+` is predefined to operate only on built-in data types. But here, `class A` is a user-defined type, so the compiler generates an error. This is where the concept of `Operator overloading` comes in. 
Now, if the user wants to make the operator `+` to add two class objects, the user has to redefine the meaning of the `+` operator such that it adds two class objects. This is done by using the concept `Operator overloading`. So the main idea behind `Operator overloading` is to use c++ operators with class variables or class objects. Redefining the meaning of operators really does not change their original meaning; instead, they have been given additional meaning along with their existing ones.

## A simple and complete example 

```cpp
#include<iostream>
using namespace std;

// create a class
class Complex {
private:
  int real, imag; // real and imaginary part of complex number
public:
  // constructor 
  Complex(int r = 0, int i = 0) {real = r; imag = i;}

  // This is automatically called when '+' is used with between two Complex objects

  Complex operator + (Complex const &obj) {
    Complex res; // create a new object to store the result
    res.real = real + obj.real; // add real part of both objects
    res.imag = imag + obj.imag; // add imaginary part of both objects
    return res; // return the result
  }

// print function to print the complex number
void print() { cout << real << " + i" << imag << '\n'; }
};

int main()
{
  Complex c1(10, 5), c2(2, 4); // create two complex numbers
  Complex c3 = c1 + c2; // add two numbers using operator overloading
  c3.print(); // print the result
}
```

`Output: 12 + i9`

## What is the difference between operator functions and normal functions
Operator functions are the same as normal functions. The only differences are, that the name of an operator function is always the operator keyword followed by the symbol of the operator and operator functions are called when the corresponding operator is used. 
Following is an example of a global operator function. 

## Can we overload all operators
Almost all operators can be overloaded except a few. Following is the list of operators that cannot be overloaded. 

- sizeof
- typeid
- Scope resolution (::)
- Class member access operators (.(dot), .* (pointer to member operator))
- Ternary or conditional (?:)

## Operators that can be overloaded
We can overload:
- Unary operators
- Binary operators
- Special operators ( [ ], () etc)


But, among them, there are some operators that cannot be overloaded. They are
- Scope resolution operator                                : :
- Member selection operator                               
- Member selection through                                   *                               

### Pointer to member variable
- Conditional operator                                         ? :
- Sizeof operator                                             sizeof()

## Operators that can be overloaded

- Binary Arithmetic     `->`     `(+, -, *, /, %)`
- Unary Arithmetic     `->`     `(+, -, ++, —)`
- Assignment     `->`    `(=, +=,*=, /=,-=, %=)`
- Bit- wise      `->`     `(& , | , << , >> , ~ , ^)`
- De-referencing     `->`     `(->)`
- Dynamic memory allocation and De-allocation     ->     `(New, delete)` 
- Subscript     `->`     `[ ]`
- Function call     `->`     `()`
- Logical      `->`     `(&,  | |, !)`
- Relational     `->`     `(>, < , = =, <=, >=)`



## Why can’t the above-stated operators be overloaded

1. `sizeof` – This returns the size of the object or datatype entered as the operand. This is evaluated by the compiler and cannot be evaluated during runtime. The proper incrementing of a pointer in an array of objects relies on the sizeof operator implicitly. Altering its meaning using overloading would cause a fundamental part of the language to collapse.

2. `typeid:` This provides a CPP program with the ability to recover the actual derived type of the object referred to by a pointer or reference. For this operator, the whole point is to uniquely identify a type. If we want to make a user-defined type ‘look’ like another type, polymorphism can be used but the meaning of the typeid operator must remain unaltered, or else serious issues could arise.

3. `Scope resolution (::):` This helps identify and specify the context to which an identifier refers by specifying a namespace. It is completely evaluated at runtime and works on names rather than values. The operands of scope resolution are note expressions with data types and CPP has no syntax for capturing them if it were overloaded. So it is syntactically impossible to overload this operator.

4. Class member access operators `(.(dot), .* (pointer to member operator)):` The importance and implicit use of class member access operators can be understood 
 
 
## through the following example:

```cpp
#include <iostream>
using namespace std;

class ComplexNumber{
private:
  int real, imaginary; // real and imaginary part of the complex number

public:
  // Constructor to initialize the complex number
  ComplexNumber(int real, int imaginary){
    this -> real = real;  
    this -> imaginary = imaginary;
  }

  void print(){
    cout << real << " + i" << imaginary << "\n";
  }

  ComplexNumber operator+ (ComplexNumber c2){
    ComplexNumber c3(0,0);
    c3.real = this -> real + c2.real;
    c3.imaginary = this -> imaginary + c2.imaginary;
    return c3;
  }
};

int main() {
	
	
  ComplexNumber c1(3, 5), c2(2, 4); // 3 + i5 and 2 + i4
  ComplexNumber c3 = c1 + c2; // 3 + i5 + 2 + i4
  c3.print(); // print 5 + i9

  return 0;
}

```

`Output: 5 + i9`

The statement ComplexNumber `c3 = c1 + c2` is internally translated as ComplexNumber `c3 = c1.operator+ (c2)` in order to invoke the operator function. The argument c1 is implicitly passed using the `.` operator. The next statement also makes use of the dot operator to access the member function print and pass c3 as an argument. Thus, in order to ensure a reliable and non-ambiguous system of accessing class members, the predefined mechanism using class member access operators is absolutely essential. Besides, these operators also work on names and not values and there is no provision (syntactically) to overload them.


5. `Ternary or conditional (?:):` The ternary or conditional operator is a shorthand representation of an if-else statement. In the operator, the true/false expressions are only evaluated on the basis of the truth value of the conditional expression. conditional statement ? expression1 (if statement is TRUE) : expression2 (else)
A function overloading the ternary operator for a class say ABC using the definition
ABC operator ?: (bool condition, ABC trueExpr, ABC falseExpr);
would not be able to guarantee that only one of the expressions was evaluated. Thus, the ternary operator cannot be overloaded.




## Important points about operator overloading 

1. For operator overloading to work, at least one of the operands must be a user-defined class object.
2. Assignment Operator: Compiler automatically creates a default assignment operator with every class. The default assignment operator does assign all members of the right side to the left side and works fine in most cases (this behaviour is the same as the copy constructor).
3. Conversion Operator: We can also write conversion operators that can be used to convert one type to another type. 

```cpp
#include <iostream>
using namespace std;
class Fraction{
private:
  int num, den; // numerator and denominator
public:
  // Constructor
  Fraction(int n, int d) { num = n; den = d; }

  // Conversion operator: return float value of fraction
  operator float() const {
    return float(num) / float(den);
  }
};

int main() {
	
  Fraction f(2, 5); // create fraction object
  float val = f; // convert fraction to float using conversion operator
  cout << val << '\n'; // print float value

  return 0;
}
```

`Output: 0.4`

Overloaded conversion operators must be a member method. Other operators can either be the member method or the global method.

4. Any constructor that can be called with a single argument works as a conversion constructor, which means it can also be used for implicit conversion to the class being constructed. 

```cpp
#include <iostream>
using namespace std;
class Point{
private:
	int x, y; // Two coordinates
public:
  // Constructor;
  Point(int i = 0, int j = 0) {
   x = i; y = j;
 }
  // print the coordinates
  void print() {
   cout << "x = " << x << ", y = " << y << '\n';
  }
};

int main() {

  Point t(20, 20); // Create a point with coordinates (20, 20)
  t.print(); // Print the coordinates
  t = 30; // Assign 30 to x and y with the default values
  t.print(); // Print the coordinates
  
	return 0;
}

```

```cpp
Output:
x = 20, y = 20
x = 30, y = 0
```

##  implementation all Binary Arithmetic Operators overloading

```cpp
#include <iostream>
using namespace std;

class complex{
private:
  int real, imag;
public:   
  
  // constructor to initialize real and imaginary part
  complex(int r = 0, int i = 0) {
    real = r;
    imag = i;
  }

  // operator overloading plus (+) operator to add two complex numbers
  complex operator + (complex const &obj) {
    complex res; // res is the result of the addition
    res.real = real + obj.real; // real part of the result
    res.imag = imag + obj.imag; // imaginary part of the result
    return res; // return the result
  }

  // operator overloading minus (-) operator to subtract two complex numbers
  complex operator - (complex const &obj) {
    complex res; // res is the result of the subtraction
    res.real = real - obj.real; // real part of the result
    res.imag = imag - obj.imag; // imaginary part of the result
    return res; // return the result
  }

  // operator overloading multiplication (*) operator to multiply two complex numbers
  complex operator * (complex const &obj) {
    complex res; // res is the result of the multiplication
    res.real = real * obj.real - imag * obj.imag; // real part of the result
    res.imag = real * obj.imag + imag * obj.real; // imaginary part of the result
    return res; // return the result
  }

  // operator overloading division (/) operator to divide two complex numbers
  complex operator / (complex const &obj) {
    complex res; // res is the result of the division
    res.real = (real * obj.real + imag * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag); // real part of the result
    res.imag = (imag * obj.real - real * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag); // imaginary part of the result
    return res; // return the result
  }

  // print the complex number in the form of a + bi 
  void print() {
	cout << real << " + i" << imag << endl;
  }

};


int main() {

  complex c1(10, 5), c2(2, 4);

  complex c3 = c1 + c2; // add two complex numbers
  cout << "The sum of two complex numbers is: "; c3.print();  

  complex c4 = c1 - c2; // subtract two complex numbers
  cout << "The subtraction of two complex numbers is: "; c4.print();

  complex c5 = c1 * c2; // multiply two complex numbers
  cout << "The multiplication of two complex numbers is: "; c5.print();

  complex c6 = c1 / c2; // divide two complex numbers
  cout << "The division of two complex numbers is: "; c6.print();

  return 0;
}

```
output:

- The sum of two complex numbers is: 12 + i9
- The subtraction of two complex numbers is: 8 + i1
- The multiplication of two complex numbers is: 0 + i50
- The division of two complex numbers is: 2 + i-1



## implementation all Unary Arithmetic Operators overloading

```cpp
#include <iostream>
using namespace std;

// x++ -> is a post-increment operator
// ++x -> is a pre-increment operator
// x-- -> is a post-decrement operator
// --x -> is a pre-decrement operator

class complex{
private:
  int real, imag;
public:   
  
  // constructor to initialize real and imaginary part
  complex(int r = 0, int i = 0) {
    real = r;
    imag = i;
  }
  
  // operator overloading for unary arithmetic operators 


  // unary + operator overloading to return the same object
  complex operator + () {
    return complex(real, imag);
  }

  // unary - operator overloading to return the negative object
  complex operator - () {
    return complex(-real, -imag);
  }

  // unary ++ operator overloading to return the incremented object pre-increment
  complex operator ++ () {
    return complex(++real, ++imag);
  }

  // unary -- operator overloading to return the decremented object pre-decrement
  complex operator -- () {
    return complex(--real, --imag);
  }

  // unary ++ operator overloading to return the incremented object post-increment
  complex operator ++ (int) {
    return complex(real++, imag++);
  }

  // unary -- operator overloading to return the decremented object post-decrement
  complex operator -- (int) {
    return complex(real--, imag--);
  }

  // print function to print the complex number
  void print() {
    cout << real << " + i" << imag << endl;
  }

};


int main() {


  complex c1(10, 5), c2(2, 4);

  // calling unary + operator to return the same object
  complex c3 = +c1;
  cout << "The complex number 1 is: ";
  c3.print();

  // calling unary - operator to return the negative object
  complex c4 = -c2;
  cout << "The complex number 2 is: ";
  c4.print();

  // calling unary ++ operator to return the incremented object
  complex c5 = ++c1;
  cout << "The complex number 1 after pre-increment is: ";
  c5.print();

  // calling unary -- operator to return the decremented object
  complex c6 = --c2;
  cout << "The complex number 2 after pre-decrement is: ";
  c6.print();

  // calling unary ++ operator to return the incremented object
  complex c7 = c1++;
  cout << "The complex number 1 after post-increment is: ";

  // calling unary -- operator to return the decremented object
  complex c8 = c2--;
  cout << "The complex number 2 after post-decrement is: ";
  c8.print();

  return 0;
}

```

output:
- The complex number 1 is: 10 + i5
- The complex number 2 is: -2 + i-4
- The complex number 1 after pre-increment is: 11 + i6
- The complex number 2 after pre-decrement is: 1 + i3
- The complex number 1 after post-increment is: The complex number 2 after post-decrement is: 1 + i3


## implementation all Unary Assignment Operators overloading

```cpp
#include <iostream>
using namespace std;

class complex{
private:
  int real, imag;
public:   
  
  // constructor to initialize real and imaginary part
  complex(int r = 0, int i = 0) {
    real = r;
    imag = i;
  }
  
  // operator overloading for Assignment operator
  complex operator = (const complex &c) {
    real = c.real; // real part of complex number
    imag = c.imag; // imaginary part of complex number
    return *this; // return the current object 
  }

  // operator overloading for Addition operator
  complex operator += (const complex &c) {
    real += c.real; // add real part of complex number c to real part of current object
    imag += c.imag;  // add imaginary part of complex number c to imaginary part of current object
    return *this; // return the current object 
  }

  // operator overloading for Subtraction operator
  complex operator -= (const complex &c) {
    real -= c.real; // subtract real part of complex number c from real part of current object
    imag -= c.imag; // subtract imaginary part of complex number c from imaginary part of current object
    return *this; // return the current object
  }

  // operator overloading for Multiplication operator
  complex operator *= (const complex &c) {
    real *= c.real; // multiply real part of complex number c to real part of current object
    imag *= c.imag; // multiply imaginary part of complex number c to imaginary part of current object
    return *this; // return the current object
  }

  // operator overloading for Division operator
  complex operator /= (const complex &c) {
    // check if the divisor is zero or not 
    if (c.real == 0 || c.imag == 0) {
      // if the divisor is zero, print error message and return the current object	
      cout << "Division by zero is not possible" << "\n";
      return *this; 
    }

    real /= c.real; // divide real part of current object by real part of complex number c
    imag /= c.imag; // divide imaginary part of current object by imaginary part of complex number c
    return *this; // return the current object
  }

  // operator overloading for modulus operator
  complex operator %= (const complex &c) {
    real %= c.real; // modulus real part of current object by real part of complex number c
    imag %= c.imag; // modulus imaginary part of current object by imaginary part of complex number c
    return *this; // return the current object
  }

  // function to print the complex number
  void print() {
    cout << real << " + i" << imag << endl;
  }

};


int main() {
   
   complex c1(10, 5), c2(2, 4);
   c1 += c2;
   cout << "The result of c1 += c2 is: "; c1.print();
   c1 -= c2;
   cout << "The result of c1 -= c2 is: "; c1.print();
   c1 *= c2;
   cout << "The result of c1 *= c2 is: "; c1.print();
   c1 /= c2;
   cout << "The result of c1 /= c2 is: "; c1.print();
   c1 %= c2;
   cout << "The result of c1 %= c2 is: "; c1.print();
   c1 = c2;
   cout << "The result of c1 = c2 is: "; c1.print();

  return 0;
}

```

output:
- The result of c1 += c2 is: 12 + i9
- The result of c1 -= c2 is: 10 + i5
- The result of c1 *= c2 is: 20 + i20
- The result of c1 /= c2 is: 10 + i5
- The result of c1 %= c2 is: 0 + i1
- The result of c1 = c2 is: 2 + i4


## implementation all Bit-wise Operators overloading

```cpp
#include <iostream>
using namespace std;

// bitwise operators overloading
// left shift (<<) 1 << 2 = 4 (1 * pow(2, 2))  -> pow(2, 3) = 2 * 2 * 2 = 8
// right shift (>>) 4 >> 2 = 1 (4 / pow(2, 2))
// bitwise AND (&) 5 & 3 = 1 (0101 & 0011 = 0001)
// bitwise OR (|) 5 | 3 = 7 (0101 | 0011 = 0111)
// bitwise XOR (^) 5 ^ 3 = 6 (0101 ^ 0011 = 0110)
// bitwise NOT (~) ~5 = -6 (00000000 00000000 00000000 00000101 = 11111111 11111111 11111111 11111010 + 1 = 11111111 11111111 11111111 11111011)


class complex{
private:
  int real, imag;
public:   
  
  // constructor to initialize real and imaginary part
  complex(int r = 0, int i = 0) {
	real = r;
	imag = i;
  }
  
  // Bit- wise AND
  complex operator & (complex const &obj) {
	complex res;
	res.real = real & obj.real;
	res.imag = imag & obj.imag;
	return res;
  }

  // Bit- wise OR
  complex operator | (complex const &obj) {
	complex res;
	res.real = real | obj.real;
	res.imag = imag | obj.imag;
	return res;
  }

  // Bit- wise XOR
  complex operator ^ (complex const &obj) {
	complex res;
	res.real = real ^ obj.real;
	res.imag = imag ^ obj.imag;
	return res;
  }

  // Bit- wise NOT
  complex operator ~ () {
	complex res;
	res.real = ~real;
	res.imag = ~imag;
	return res;
  }

  // Bit- wise Left Shift
  complex operator << (int const &obj) {
	complex res;
	res.real = real << obj;
	res.imag = imag << obj;
	return res;
  }

  // Bit- wise Right Shift
  complex operator >> (int const &obj) {
	complex res;
	res.real = real >> obj;
	res.imag = imag >> obj;
	return res;
  }

  // function to print the complex number
  void print() {
	cout << real << " + i" << imag << endl;
  }

};


int main() {
   
  complex c1(10, 5), c2(2, 4);
  complex c3 = c1 & c2;
  complex c4 = c1 | c2;
  complex c5 = c1 ^ c2;
  complex c6 = ~c1;
  complex c7 = c1 << 2;
  complex c8 = c1 >> 2;
  cout << "The Bit- wise AND of c1 and c2 is: "; c3.print();
  cout << "The Bit- wise OR of c1 and c2 is: "; c4.print();
  cout << "The Bit- wise XOR of c1 and c2 is: "; c5.print();
  cout << "The Bit- wise NOT of c1 is: "; c6.print();
  cout << "The Bit- wise Left Shift of c1 is: "; c7.print();
  cout << "The Bit- wise Right Shift of c1 is: "; c8.print();
  

  return 0;
}
```

output:
- The Bit- wise AND of c1 and c2 is: 2 + i4
- The Bit- wise OR of c1 and c2 is: 10 + i5
- The Bit- wise XOR of c1 and c2 is: 8 + i1
- The Bit- wise NOT of c1 is: -11 + i-6
- The Bit- wise Left Shift of c1 is: 40 + i20
- The Bit- wise Right Shift of c1 is: 2 + i1










