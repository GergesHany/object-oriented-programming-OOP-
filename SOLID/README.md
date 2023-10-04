**SOLID Principles**

- **Design pattern is a best practice to solve common problems in software design**.

- **5 SOLID Principles:**
  - S -> Single Responsibility Principle (This class should solve one problem)
  - O -> Open-Closed Principle (The class should be open for extension and closed for modification)
  - L -> Liskov Substitution Principle (The class should be replaceable with its subclasses without breaking the application)
  - I -> Interface Segregation Principle (The class should not be forced to implement interfaces they don't use)
  - D -> Dependency Inversion Principle (The class should not depend on concrete implementations, but on abstractions)

---

## **1 - Single Responsibility Principle (SRP)**

- Do one thing and do it well
- There should never be more than one reason for a class to change
- A class should have only one reason to change, meaning that a class should have only one job

### Example for Single Responsibility Principle

- **Bad Example:**

### This is a bad example because the class is doing more than one thing

```python
class User:
    def __init__(self, name: str, email: str, password: str):
        self.name = name
        self.email = email
        self.password = password

    def get_user_info(self):
        return f"Name: {self.name}, Email: {self.email}, Password: {self.password}"

    def save_user(self):
        with open("users.txt", "a") as file:
            file.write(self.get_user_info())
```

- **Good Example:**

### This is a good example because the class is doing one thing

```python
class User:
    def __init__(self, name: str, email: str, password: str):
        self.name = name
        self.email = email
        self.password = password

    def get_user_info(self):
        return f"Name: {self.name}, Email: {self.email}, Password: {self.password}"
```

<hr>

## **2 - Open-Closed Principle (OCP)**

- Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification
- Any new functionality should be implemented by adding new classes, instead of changing the existing one

### How to implement the Open-Closed Principle

- One may achieve this by adding new functionality to derived classes without modifying the existing code
- Allow clients to access the original class with an abstract interface

### Example for Open-Closed Principle

- **Bad Example:**

### This is a bad example because the class is not closed for modification

```python
class Employee:
    def __init__(self, name: str, salary: int):
        self.name = name
        self.salary = salary

    def get_name(self):
        return self.name

    def get_salary_for_manager(self):
        return self.salary * 1.5

    def get_salary_for_developer(self):
        return self.salary * 1.2
```

- **Good Example:**

### This is a good example because the class is closed for modification

```python
class Employee:
    def __init__(self, name: str, salary: int):
        self.name = name
        self.salary = salary

    def get_name(self):
        return self.name

    # This method is open for extension and closed for modification (OCP) principle
    def get_salary(self):
        pass


class Manager(Employee):
    def get_salary(self):
        return self.salary * 1.5



class Developer(Employee):
    def get_salary(self):
        return self.salary * 1.2
```

<hr>

## **3 - Liskov Substitution Principle (LSP)**

- If you have a base class and a derived class, then the base class and the derived class should be interchangeable without affecting the functionality of the program

### Example for Liskov Substitution Principle

- **Bad Example:**

### This is a bad example because the class is not interchangeable without affecting the functionality of the program

```python
class Rectangle:
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height

    def set_width(self, width: int):
        self.width = width

    def set_height(self, height: int):
        self.height = height

    def get_area(self):
        return self.width * self.height


class Square(Rectangle):
    def set_width(self, width: int):
        self.width = width
        self.height = width

    def set_height(self, height: int):
        self.width = height
        self.height = height
```

- **Good Example:**

### This is a good example because the class is interchangeable without affecting the functionality of the program

```python
class Shape:
    def get_area(self):
        pass


class Rectangle(Shape):
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height

    def set_width(self, width: int):
        self.width = width

    def set_height(self, height: int):
        self.height = height

    def get_area(self):
        return self.width * self.height


class Square(Shape):
    def __init__(self, side: int):
        self.side = side

    def set_side(self, side: int):
        self.side = side

    def get_area(self):
        return self.side * self.side
```

<hr>

## **4 - Interface Segregation Principle (ISP)**

- Clients should not be forced to depend on methods they do not use
- Avoid fat interface
- Client must not implement unnecessary methods

### Example for Interface Segregation Principle

- **Bad Example:**

## This is a bad example because the class is forced to implement unnecessary methods

```cpp

class Shape {
public:
    virtual double get_area() = 0;
    virtual double get_perimeter() = 0;
};

class Rectangle : public Shape {
public:
    double get_area() override {
        return width * height;
    }

    double get_perimeter() override {
        return 2 * (width + height);
    }

private:
    double width;
    double height;
};

class Square : public Shape {
public:
    double get_area() override {
        return side * side;
    }

    double get_perimeter() override {
        return 4 * side;
    }

private:
    double side;
};

```

- **Good Example:**

### This is a good example because the class is not forced to implement unnecessary methods

```cpp

class Shape {
public:
    virtual double get_area() = 0;
};

class ShapeWithPerimeter {
public:
    virtual double get_perimeter() = 0;
};

class Rectangle : public Shape, public ShapeWithPerimeter {
public:
    double get_area() override {
        return width * height;
    }

    double get_perimeter() override {
        return 2 * (width + height);
    }

private:
    double width;
    double height;
};

class Square : public Shape {
public:
    double get_area() override {
        return side * side;
    }

private:
    double side;
};
```

<hr>

## **5- Dependency Inversion Principle (DIP)**

- High-level modules should not depend on low-level modules. Both should depend on abstractions

### Bad Example for Dependency Inversion Principle because the class is very tightly coupled

<picture> <img align="center" src="Bad_DIP.png" width = 650px></picture>

```cpp
class MySQLDatabase {
public:
    void connect() {
        std::cout << "MySQLDatabase connected" << std::endl;
    }
};

class OracleDatabase {
public:
    void connect() {
        std::cout << "OracleDatabase connected" << std::endl;
    }
};

class DatabaseManager {
public:
    DatabaseManager() {
        mysql_database = new MySQLDatabase();
        oracle_database = new OracleDatabase();
    }

    void connectMySQLDatabase() {
        mysql_database->connect();
    }

    void connectOracleDatabase() {
        oracle_database->connect();
    }

private:
    MySQLDatabase* mysql_database;
    OracleDatabase* oracle_database;
};
```

<hr>

### Good Example of Dependency Inversion Principle because the class is cohesive and loosely coupled

<picture> <img align="center" src="Good_DIP.png" width = 650px></picture>

```cpp
class Database {
public:
    virtual void connect() = 0;
};

class MySQLDatabase : public Database {
public:
    void connect() override {
        std::cout << "MySQLDatabase connected" << std::endl;
    }
};

class OracleDatabase : public Database {
public:
    void connect() override {
        std::cout << "OracleDatabase connected" << std::endl;
    }
};

class DatabaseManager {
public:
    DatabaseManager(Database* database) {
        this->database = database;
    }

    void connectDatabase() {
        database->connect();
    }

private:
    Database* database;
};
```
