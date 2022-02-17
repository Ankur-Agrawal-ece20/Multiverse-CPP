#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<string> arr)
{
    int answer = 0;
    string temp, a, b, c;
    // Started my code here
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] != ',')
            {
                s += arr[i][j];
            }
        }
        arr[i] = s;
    }
    for (int i = 0; i < n; i++)
    {
        string s = arr[i];
        stringstream ss;
        ss << s;
        ss >> s;
        temp = s;
        ss >> s;
        a = s;
        ss >> s;
        b = s;
        ss >> s;
        c = s;

        if (temp == "li")
        {
            stringstream str_to_num(b);
            int add = 0;
            str_to_num >> add;
            mp[a] = add;
        }
        else if (temp == "add")
        {
            mp[a] = mp[b] + mp[c];
        }
        else if (temp == "sub")
        {
            mp[a] = mp[b] - mp[c];
        }
        else if (temp == "addi")
        {
            stringstream str_to_num(c);
            int add = 0;
            str_to_num >> add;
            mp[a] = mp[b] + add;
        }
        else if (temp == "mul")
        {
            mp[a] = mp[b] * mp[c];
        }
        else if (temp == "and")
        {
            mp[a] = mp[b] & mp[c];
        }
        else if (temp == "or")
        {
            mp[a] = mp[b] | mp[c];
        }
        else if (temp == "andi")
        {
            stringstream str_to_num(c);
            int add = 0;
            str_to_num >> add;
            mp[a] = mp[b] & add;
        }
        else if (temp == "ori")
        {
            stringstream str_to_num(c);
            int add = 0;
            str_to_num >> add;
            mp[a] = mp[b] | add;
        }
        else if (temp == "sw")
        {
            mp["answer"] = mp[a];
            answer = mp["answer"];
        }
    }
    return answer;
    }

// int main()
// {
//     int n;
//     cin >> n;
//     cin.ignore();
//     vector<string> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         getline(cin, arr[i]);
//         cout << arr[i] << endl;
//     }
//     cout << solve(n, arr);
//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code
#include "../../include/test1_cases.h"