#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution
{
private:
    int n;                                    // n is size that user inputs
    vector<unsigned int> v, ans1, ans2, ans3; // v is the vector that user inputs
    void solve_task1()
    {
        // solve task1 and save the answer in ans1
        set<int>unique;
        for (int i = 0; i < n; i++)
        {
            unique.insert(v[i]);
        }
        set<int>::iterator sort;
        for (sort = s.begin(); sort != s.end(); sort++)
        {
            ans1.pb(*sort);
        }
    }
    bool sortbyfirst(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second > b.second)
            return false;
        else if (a.second == b.second)
        {
            if (a.first > b.first)
                return true;
            else
                return false;
        }
        else
            return true
    }

    void solve_task2()
    {
        // solve task2 and save the answer in ans2
        vector<pair<int, int>> req;
        for (int i = 0; i < n - 1; i = i + 2)
        {
            int one = v[i];
            int two = v[i + 1];
            req.pb({one, two});

            sort(req.begin(), req.end(), sortbyfirst);
            for (int i = 0; i < req.size(); i++)
            {
                ans2.pb(req[i].first);
            }
        }
    }
        void solve_task3()
        {
            // solve task3 and save the answer in ans3
            vector<pair<int, int>> req;
            for (int i = 0; i < n - 1; i = i + 2)
            {
                int one = v[i];
                int two = v[i + 1];
                req.pb({one, two});
            }
            queue<int> que;
            for (int i = 0; i < req.size(); i++)
            {
                if (req[i].first % 2 != 0)
                {
                    que.push(req[i].second);
                }
                else
                {
                    que.push(req[i].second);
                    que.pop();
                }
            }

            while (!que.empty())
            {
                int one = que.front();
                ans3.pb(one);
                que.pop();
            }
        }

    public:
        // create a constructor to take input
         solution(int size, vector<unsigned int> a)
        {
            n = size;
            v = a;
            solve_task1();
            solve_task2();
            solve_task3();
        }

        string FINDMATCH(string path)
        {
            // complete this function to read file, compare with ans1, ans2, ans3
            // and return the answer
            ifstream binaryfile;
            binaryfile.open(path, ios::binary);

            if (!binaryfile.is_open())
            {
                cout << "The file can't be opened.\n";
                return "ERROR";
            }
            binaryfile.seekg(0, ios::end);
            int length = binaryfile.tellg();
            binaryfile.seekg(0, ios::beg);

            vector<unsigned int> answer;

            while (binaryfile.tellg() != length)
            {
                int x;
                binaryfile.read((char *)&x, sizeof(int));
                answer.pb(x);
            }

            if (ans1 == answer)
            {
                return "TASK1";
            }
            else if (ans2 == answer)
            {
                return "TASK2";
            }
            else if (ans3 == answer)
            {
                return "TASK3";
            }
            else
            {
                return "NOTFOUND";
            }
        }
};

// int main()
// {
//     vector<unsigned int> a{5, 7, 6, 5, 2, 1, 4, 0, 1, 3};
//     string paths[] = {
//         "missing_files/missing1.bin",
//         "missing_files/missing2.bin",
//         "missing_files/missing3.bin",
//         "missing_files/missing4.bin",
//     };
//     // Intialize your solution object here
//     solution ob(a.size(),a);
//     // Make a for loop to go through paths array and call FINDMATCH function
//       for(string path : paths){
//         cout<<ob.FINDMATCH(path)<<endl;
//     }

//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code
#include "../../include/test2_cases.h"