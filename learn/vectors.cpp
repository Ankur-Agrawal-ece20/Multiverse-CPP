#include <bits/stdc++.h>
using namespace std;

int main() {
  
vector <int> vec; // Intialise vector 
  // vector<int> v(10);
  vec.push_back(8);
  vec.push_back(10);
  vec.push_back(15);
  vec.push_back(9);
  vec.push_back(6);

  if(!vec.empty()){
    cout<<"Size of Vector :" <<vec.size()<<endl;
  }
  else{
    cout<<"Vector vec is empty"<<endl;
  }

//   vec.pop_back();
//  cout<<"Size of Vector v :"<<vec.size()<<endl;
  

  // cout<<"Front element is :"<<vec.front()<<" Back element is :"<<vec.back()<<endl;

//  // traverse a vector 
//  cout<<"Traversing a vector"<<endl;
//  for(int i=0;i<vec.size();i++){
//    cout<<i<<" "<<vec[i]<<endl;
//  }

//  // using iterator 
//  // Declaring iterator to a vector
vector<int>::iterator ptr;

  
// // Displaying vector elements using begin() and end()
cout << "The vector elements are : ";
// for (ptr = vec.begin(); ptr < vec.end(); ptr++)
//     cout << *ptr << " ";


// for(int a: vec){
//   cout<<a<<endl;
// }

// // use auto
// cout << "The vector elements are : ";
// for (auto ptr = vec.begin(); ptr != vec.end(); ptr++)
//     cout << *ptr << " ";

// // advance() in iterators
// vector<int>::iterator p = v.begin();
      
// // Using advance() to increment iterator position
// // points to 4
// advance(p, 5);
  
// // Displaying iterator position
// cout << "The position of iterator after advancing is : ";
// cout << *ptr << " ";


// // sort array using iterators
sort(vec.rbegin(),vec.rend());

cout << "The vector elements are : ";
for (ptr = vec.begin(); ptr < vec.end(); ptr++)
    cout << *ptr << " ";



}