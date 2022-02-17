#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int n;                                    
    vector<unsigned int> v, ans1, ans2, ans3;
    void solve_task1()
    {
        set<unsigned int> set1;
        for (int i = 0; i < n; i++)
            set1.insert(v[i]);
        for (int i : set1)
            ans1.push_back(i);
    }
    bool compare_pairs(pair<unsigned int, unsigned int> pair1, pair<unsigned int, unsigned int> pair2)
    {

        if (pair1.second > pair2.second)
            return false;
        else if (pair1.second == pair2.second)
        {
            if (pair1.first > pair2.first)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    vector<pair<unsigned int,unsigned int>> sorttask2(vector<pair<unsigned int,unsigned int>> v, int n)
    {
        pair<unsigned int,unsigned int> var;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (compare_pairs(v[i], v[j]))
                {
                    var = v[i];
                    v[i] = v[j];
                    v[j] = var;
                }
            }
        }
        return v;
    }

    void solve_task2()
    {
        vector<pair<unsigned int, unsigned int>> pair3;
        for (int i = 1; i <= n / 2; i++)
        {
            pair<unsigned int, unsigned int> pair4;
            pair4.first = v[2 * i - 2];
            pair4.second = v[2 * i - 1];
            pair3.push_back(pair4);
        }
        pair3 = sorttask2(pair3, n / 2);

        for (int i = 0; i < n / 2; i++)
            ans2.push_back(pair3[i].first);
    }
    void solve_task3()
    {
        vector<pair<unsigned int, unsigned int>> pair5;
        for (int i = 1; i <= n / 2; i++)
        {
            pair<unsigned int, unsigned int> p;
            p.first = v[2 * i - 2];
            p.second = v[2 * i - 1];
            pair5.push_back(p);
        }

        queue<unsigned int> q;
        for (pair<unsigned int, unsigned int> p : pair5)
        {
            if (p.first % 2 == 1)
                q.push(p.second);
            else
            {
                q.push(p.second);
                q.pop();
            }
        }

        int element;
        while (!q.empty())
        {
            element = q.front();
            ans3.push_back(element);
            q.pop();
        }
    }

public:
    Solution(int size, vector<unsigned int> arr)
    {
        n = size;
        v = arr;
        solve_task1();
        solve_task2();
        solve_task3();
    }
    string FINDMATCH(string path)
    {
        ifstream file;
        file.open(path, ios::binary);

        if (!file.is_open()){
            cout<<"The file can't be opened.\n";
            return "ERROR";
        }

        file.seekg(0, ios::end);
        int file_size = file.tellg();
        file.seekg(0, ios::beg);

        unsigned int read_data;
        int size_int = sizeof(int);
        vector<unsigned int> answer;

        while(file.tellg() != file_size){
            file.read((char *) &read_data, size_int);
            answer.push_back(read_data);
        }
        if (ans1==answer) return "TASK1";
        else if (ans2==answer) return "TASK2";
        else if (ans3==answer) return "TASK3";
        else return "NOTFOUND";

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
//     return 0;
// }
// ==> NOTE: Comment main function and uncomment below line to verify your code
#include "../../include/test2_cases.h"