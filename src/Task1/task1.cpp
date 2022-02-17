#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<string> arr){
    int answer=0;
    // Start your code here
    stringstream ss;
    map<string, int> mp1;
    for(int i=0;i < n;i++)
    {   
        stringstream ss;
        ss<<arr[i];
        string s2;
        ss>>s2;

        if (s2.compare("li")==0){
            ss>>s2;
             if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }
            int x;
            ss>>x;
            mp1[s2]=x;
            }
        else if (s2.compare("add")==0)
        {   string s3,s4;
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }
            ss>>s3;
            if(s3.find(',')!=string::npos) {
                s3.erase(s3.find(','),1);
            }
            ss>>s4;
            if(s4.find(',')!=string::npos) {
                s4.erase(s4.find(','),1);
            }
            mp1[s2]=mp1[s3]+mp1[s4];
        }
        else if (s2.compare("sub")==0){
            string s3,s4;
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }
            ss>>s3;
            if(s3.find(',')!=string::npos) {
                s3.erase(s3.find(','),1);
            }
            ss>>s4;
            if(s4.find(',')!=string::npos) {
                s4.erase(s4.find(','),1);
            }
            mp1[s2]=mp1[s3]-mp1[s4];
        }
        else if (s2.compare("mul")==0){
            string s3,s4;
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }

            ss>>s3;
            if(s3.find(',')!=string::npos) {
                s3.erase(s3.find(','),1);
            }

            ss>>s4;
            if(s4.find(',')!=string::npos) {
                s4.erase(s4.find(','),1);
            }

            mp1[s2]=mp1[s3]*mp1[s4];
        }


        else if (s2.compare("and")==0){
            string s3,s4;
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }

            ss>>s3;
            if(s3.find(',')!=string::npos) {
                s3.erase(s3.find(','),1);
            }

            ss>>s4;
            if(s4.find(',')!=string::npos) {
                s4.erase(s4.find(','),1);
            }

            mp1[s2]=mp1[s3]&mp1[s4];
        }
        else if (s2.compare("or")==0){
            string s3,s4;
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }

            ss>>s3;
            if(s3.find(',')!=string::npos) {
                s3.erase(s3.find(','),1);
            }

            ss>>s4;
            if(s4.find(',')!=string::npos) {
                s4.erase(s4.find(','),1);
            }

            mp1[s2]=mp1[s3]|mp1[s4];
        }
        else if (s2.compare("andi")==0){
            string s3,s4;
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }

            ss>>s3;
            if(s3.find(',')!=string::npos) {
                s3.erase(s3.find(','),1);
            }
            int x;
            ss>>x;
            mp1[s2]=mp1[s3]&x;
        }
        else if (s2.compare("ori")==0){
            string s3,s4;
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }

            ss>>s3;
            if(s3.find(',')!=string::npos) {
                s3.erase(s3.find(','),1);
            }
            int x;
            ss>>x;
            mp1[s2]=mp1[s3]|x;
        }
        else if (s2.compare("addi")==0)
        {   string s3,s4;
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }
            ss>>s3;
            if(s3.find(',')!=string::npos) {
                s3.erase(s3.find(','),1);
            }
            int x;
            ss>>x;
            mp1[s2]=mp1[s3]+x;
        }
        else if (s2.compare("sw")==0){
            ss>>s2;
            if(s2.find(',')!=string::npos) {
                s2.erase(s2.find(','),1);
            }
            answer=mp1[s2];
        }
        }
    // End your code here
    return answer;
}
// int main(){
//     int n;
//     cout<<"Enter the value of n";
//     cin>>n;
//     cin.ignore();
//     vector<string> arr(n);
//     for(int i=0;i<n;i++){
//         getline(cin,arr[i]);
//         cout<<arr[i]<<endl;
//     }
//     // return 0;
// }
// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"