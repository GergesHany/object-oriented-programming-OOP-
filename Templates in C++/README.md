# Explanation videos
- [Template Function/Templates Function-Templates with Multiple Parameters](https://www.youtube.com/watch?v=vdTTGrBNJUg&list=PLCInYL3l2Aaiq1oLvi9TlWtArJyAuCVow&index=23)
- [Class template/Template specialization](https://www.youtube.com/watch?v=vdTTGrBNJUg&list=PLCInYL3l2Aaiq1oLvi9TlWtArJyAuCVow&index=24)

<hr><br>

# Content

- [Templates](#Templates)
- [How Do Templates Work](#How-Do-Templates-Work)
- [Class Templates](#Class-Templates)

<hr><br>

## Templates

`A template` is a simple yet very powerful tool in C++. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass data type as a parameter. 
C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by the keyword ‘class’.


How Do Templates Work

Templates are expanded at compiler time. This is like macros. The difference is, that the compiler does type checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class. 


![templates-cpp](https://user-images.githubusercontent.com/105644935/218393634-ae7b104a-898d-41f8-a99c-2371ffb44276.jpg)


Function Templates We write a generic function that can be used for different data types. Examples of function templates are `sort()`, `max()`, `min()`, `printArray()` 

```cpp
#include <iostream>
using namespace std;
// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded

template <typename T> T myMax(T x, T y){
  return (x > y) ? x : y;
}

int main()
{
  cout << myMax<int>(3, 7) << endl; // Call myMax for int
  cout << myMax<double>(3.0, 7.0) << endl; // call myMax for double
  cout << myMax<char>('g', 'e')	<< endl; // call myMax for char
	return 0;
}
```


## Below is the program to implement Bubble Sort using templates in C++

```cpp
// CPP code for bubble sort
// using template function
#include <iostream>
using namespace std;

// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T> void bubbleSort(T a[], int n){
  for (int i = 0; i < n - 1; i++)
   for (int j = n - 1; i < j; j--)
     if (a[j] < a[j - 1])
      swap(a[j], a[j - 1]);
}

// Driver Code
int main()
{

  int a[5] = { 10, 50, 30, 40, 20 };
  int n = sizeof(a) / sizeof(a[0]);

  // calls template function
  bubbleSort < int > (a, n);

  cout << " Sorted array : ";
  for (int i = 0; i < n; i++)
  cout << a[i] << " \n"[i == n - 1];
	return 0;
}
```

`Output: Sorted array : 10 20 30 40 50`

## Class Templates
Class Templates like function templates, class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like `LinkedList`, `BinaryTree`, `Stack`, `Queue`, `Array`, `etc`. 

## Following is a simple example of a template Array class. 

```cpp
#include <iostream>
using namespace std;

template <typename T> class Array {
private:
  T* ptr;
  int size;

public:
  Array(T arr[], int s);
  void print();
};

template <typename T> Array<T>::Array(T arr[], int s){
  ptr = new T[s];
  size = s;
  for (int i = 0; i < size; i++)
  ptr[i] = arr[i];
}

template <typename T> void Array<T>::print(){
  for (int i = 0; i < size; i++)
  cout << " " << *(ptr + i);
  cout << "\n";
}

int main()
{
  int arr[5] = { 1, 2, 3, 4, 5 };
  Array < int > a(arr, 5);
  a.print();
  return 0;
}
```

`Output: 1 2 3 4 5`


## Can there be more than one argument to templates? 

Yes, like normal parameters, we can pass more than one data type as arguments to templates. The following example demonstrates the same.

```cpp
#include <iostream>
using namespace std;

template <class T, class U> class A {
  T x;
  U y;
public:
  A() { 
   cout << "Constructor Called" << "\n"; 
  }
};

int main()
{
  A < char, char > a;
  A < int, double > b;
 return 0;
}
```
### Output
```cpp
Constructor Called
Constructor Called
```

Can we specify a default value for template arguments?

Yes, like normal parameters, we can specify default arguments to templates. The following example demonstrates the same. 

```cpp
#include <iostream>
using namespace std;

template <class T, class U = char> class A {
public:
  T x;
  U y;
  A() { 
    cout << "Constructor Called" << "\n"; 
  }
};

int main()
{
  A < char > a; // This will call A<char, char>
  return 0;
}
```

`Output: Constructor Called`

