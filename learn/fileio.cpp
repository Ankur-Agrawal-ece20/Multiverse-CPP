
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
 

// Driver code
int main()
{

// writing content into file 
string input,age;
// int age;

cout << "Writing to the file" << endl;
cout << "Enter your name: ";
cin>>input;

cout << "Enter your age: ";
cin >> age;


ofstream outfile;

outfile.open("input.txt",ios::app);
// write inputted data into the file.
outfile << input << endl;

// again write age data into the file.
outfile << age << endl;
// close the opened file.
outfile.close();



// reading from file 
ifstream infile;
infile.open("input.txt");
cout << "Reading from the file" << endl;
// infile >> input;
// // write the data at the screen.
// cout << input << endl;

// // again read the data from the file and display it.
// infile >> input;
// cout << input << endl;
// // close the opened file.
// infile.close();



// char ch;
// while(!infile.eof()) 
// { 
//   infile >> ch; 
//   cout << ch;   
// }



// infile.close();

string s;
while(infile>>s){
  cout<<s<<endl;
}

infile.close();



// Read and write integers into binary file

ifstream binaryfile;
binaryfile.open("inputbin.bin", ios::in | ios::binary);
binaryfile.seekg(0, ios::end);
int length = binaryfile.tellg();
binaryfile.seekg(0, ios::beg);
while (binaryfile.tellg() != length){
    int x;
    binaryfile.read((char*)&x, sizeof(int));
    cout<<x<<endl;
}
//




// fstream new_file;
// new_file.open("input.txt", ios::trunc | ios::out | ios::in);

  return 0;
}