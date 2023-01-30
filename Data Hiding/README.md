![Data Hiding](https://user-images.githubusercontent.com/105644935/215503513-8f239f35-da77-444d-8ebc-372cf4c000c4.png)

## Data Hiding in C++ 

Data hiding is a process of combining data and functions into a single unit. The ideology behind data hiding is to conceal data within a class, to prevent its direct access from outside the class. It helps programmers to create classes with unique data sets and functions, avoiding unnecessary penetration from other program classes.

Discussing data hiding & data encapsulation, data hiding only hides class data components, whereas data encapsulation hides class data parts and private methods.

Now you also need to know access specifier for understanding data hiding.

private, public & protected are three types of protection/ access specifiers available within a class. Usually, the data within a class is private & the functions are public. The data is hidden, so that it will be safe from accidental manipulation.

- `Private members/methods` can only be accessed by methods defined as part of the class. Data is most often defined as private to prevent direct outside access from other classes. Private members can be accessed by members of the class.

- `Public members/methods` can be accessed from anywhere in the program. Class methods are usually public which is used to manipulate the data present in the class. As a general rule, data should not be declared public. Public members can be accessed by members and objects of the class.

- `Protected member/methods` are private within a class and are available for private access in the derived class. 

### Example: Data Hiding in C++

```cpp
#include<iostream>
using namespace std;
class Base{
  private:   
    int num; // private data member

  public:
    void read(); // public member function
    void print(); // public member function
     
};
  
// member function definition  
void Base :: read(){
  cout << "Enter any Integer value " << "\n"; 
  cin >> num;   
}
  
// member function definition  
void Base :: print(){
  cout << "The value is " << num << "\n";
}
  
int main(){
 
  // creating object of the class
  Base obj;
    
  obj.read(); // calling member function
  obj.print(); // calling member function
     
  return 0;
}
```
```cpp
Output:
Enter any Integer value 10
The value is 10;
```


