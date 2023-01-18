#include <bits/stdc++.h>
using namespace std; 


class car{
  // private members are not accessible from outside the class
  private:
   int max_speed, price;
   string name, color, model;

  // public members are accessible from outside the class
  public:
   // default constructor (empty constructor) 
    car(){
      max_speed = price = 0;
      name = color = model = "";
    }

   // parameterized constructor 
   car(int max_speed, int price, string name, string color, string model){
     this -> max_speed = max_speed;
     this -> price = price;
     this -> name = name;
     this -> color = color;
     this -> model = model;
   }
   
   // functions to set and get private members
   // this pointer is used to access the current object in a member function 

   void set_max_speed(int max_speed){
     this -> max_speed = max_speed;
   }

    void set_price(int price){
      this -> price = price;
    }

    void set_name(string name){
      this -> name = name;
    }

    void set_color(string color){
      this -> color = color;
    }

    void set_model(string model){
      this -> model = model;
    }

    int get_max_speed(){
      return max_speed;
    }

    int get_price(){
      return price;
    }

    string get_name(){
      return name;
    }

    string get_color(){
      return color;
    }

    string get_model(){
      return model;
    }

   void print(){
     cout << "Name: " << name << endl;
     cout << "Color: " << color << endl;
     cout << "Model: " << model << endl;
     cout << "Max Speed: " << max_speed << endl;
     cout << "Price: " << price << endl;
   }   
};


int main()
{

  // creating an object of class car
  car c; // default constructor is called
  c.set_max_speed(200); // setting the max speed of the car
  c.set_price(100000); // setting the price of the car
  c.set_name("BMW"); // setting the name of the car
  c.set_color("Black"); // setting the color of the car
  c.set_model("2020"); // setting the model of the car
  c.print(); // printing the details of the car
  
  return 0;
}
