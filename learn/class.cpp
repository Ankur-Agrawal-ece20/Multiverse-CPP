#include <bits/stdc++.h>
using namespace std;

class Mall{
  protected:
  int basket_id;
};

class Basket: public Mall
{
  private:
  int n=5;

  public:
  // Basket(){
  //   cout<<"Constructor is called\n";
  // }
  Basket(int x){
    n=x;
  }
  ~Basket(){
    cout<<"Basket with "<<n<<" items is destroyed\n";
  }
  void set_id(int i){
    basket_id=i;
  }
  void print_id(){
    cout<<"Basket_id is "<<basket_id<<"\n";
  }
  void count();
  // void count(){
  //   if(n==0){
  //     cout<<"BASKET IS EMPTY\n";
  //   }
  //   else{
  //     cout<<n<<" items in basket\n";
  //   }
  // }
};

void Basket::count(){
  if(n==0) cout<<"Basket is empty\n";
  else cout<<n<<" items in basket\n";
}

int main() {

    Basket basket1(10);
    basket1.count();
    basket1.set_id(25);
    basket1.print_id();

    for(int i=1;i<=5;i++){
      Basket basket(i);
      basket.count();
    }
    // cout<<basket1.m<<"\n";
    return 0;
}