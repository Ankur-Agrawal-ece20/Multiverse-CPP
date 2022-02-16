// Tutorial File for learning stringstream
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include<string>
using namespace std;
 
 
// Driver code
int main()
{
    string str = "C++ is a general-purpose programming language created by Bjarne Stroustrup";

    // stringstream ss;
    // ss << str;
    // // string s2= ss.str();


    // string s2;
    // ss >> s2;

    // cout<<s2<<endl;



    // string str2 ="10 02 2022";
    // stringstream ss1;
    // ss1 << str2;
    // ss1 >> str2;

    // cout<<str2<<endl;
    // ss1 >> str2;
    // cout<<str2<<endl;

    




    // Application -1: count words in a string.
    // Idea is to break input into word using string stream
   
    // Used for breaking words
    // stringstream ss(str);
   
    // // // To store individual words
    // string word;

    // int count = 0; // stores count of words
    // while (ss >> word)
    //     count++;

    // cout << " Number of words are: " << count;






    // Application-2 : Divide words in string 
  //   string tmp; // A string to store the word on each iteration.
  //   stringstream str_strm(str);
  //  while (str_strm >> tmp) {
  //     // Provide proper checks here for tmp like if empty
  //     // Also strip down symbols like !, ., ?, etc.
  //     // Finally push it.
  //     cout<<tmp<<endl;  
  //  }




    // Application -3: Remove space from string

    // stringstream ss2;
    // string temp;
 
    // // Storing the whole string
    // // into string stream
    // ss2 << str;
 
    // // Making the string empty
    // str = "";
 
    // // Running loop till end of stream
    // while (ss2 >> temp) { 
    //     // Concatenating in the string to be
    //     // returned
    //     str = str + temp;
    // }
    // cout<< "Modified String is " << str<<endl;





    // Application -4: Conversion of string to num and vice versa 

    string s = "1927354";
 
    // object from the class stringstream
    stringstream string_to_num(s);
 
    // The object has the value 1927354 and stream
    // it to the integer x
    int x = 0;
    string_to_num >> x;
 
    // Now the variable x holds the value 12345
    cout << "Value of x : " << x;








    // Application -5 : Print frequency of words 
    // Each word it mapped to it's frequency
    // map<string, int>FW;
   
    // // Used for breaking words
    // stringstream ss1(str);
   
    // // To store individual words
    // string Word;
 
    // while (ss1 >> Word)
    //     FW[Word]++;
 
    // map<string, int>::iterator m;
    // for (m = FW.begin(); m != FW.end(); m++)
    //     cout << m->first << "-> "
    //          << m->second << "\n";


    return 0;
}