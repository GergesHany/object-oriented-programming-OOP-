#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;

#define EPS 1e-18
#define sz(s) int(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define TC int t; cin >> t; while(t--)
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define updmin(a, b) a = min((ll)a, (ll)b)
#define updmax(a, b) a = max((ll)a, (ll)b)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define cin_2d(vec, n, m) for(int i=0;i<n;i++) for(int j=0;j<m&&cin>>vec[i][j];j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
const ll N = 2 * 1e5 + 5;
const ll mod = 1000000007;
const ll INF = 1LL << 60;

void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x; return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; return out;
}

/*
 * don't be lazy in thinking
 * Think twice, code once
 * Think of different approaches to tackle a problem: write them down
 * Think of different views of the problem. don't look from only one side
*/

class car{
  // private members are not accessible from outside the class
  private:
   int max_speed, price;
   string name, color, model;

  // public members are accessible from outside the class
  public:
   // default constructor
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

void Accepted(){

  car c;
  c.set_max_speed(200);
  c.set_price(100000);
  c.set_name("BMW");
  c.set_color("Black");
  c.set_model("2020");
  c.print();

}

// Characteristics of an Object Oriented Programming language




int main()
{

  Gerges_Hany();
  int testcaces = 1, T = 1;
  // cin >> testcaces;
  while (testcaces--){  
    // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time;
  return 0;
}