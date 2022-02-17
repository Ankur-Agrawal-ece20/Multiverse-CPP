#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs
    void solve_task1(){
        // solve task1 and save the answer in ans1

        set<unsigned int> s;
        for (auto value : v) s.insert(value);
        for (auto value : s) ans1.push_back(value);

    }
    void solve_task2(){
        // solve task2 and save the answer in ans2

        vector<pair<unsigned int, unsigned int>> pairs;
        for (int i = 0; i < n; i += 2) pairs.push_back({v[i], v[i+1]});
        sort(pairs.begin(), pairs.end(),
            [](pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b) {
                if (a.second != b.second) return a.second > b.second;
                else return a.first < b.first;
            });
        for (auto p : pairs) {
            ans2.push_back(p.first);
            // ans2.push_back(p.second);
        }

    }
    void solve_task3(){
        // solve task3 and save the answer in ans3

        vector<pair<unsigned int, unsigned int>> pairs;
        for (int i = 0; i < n; i += 2) pairs.push_back({v[i], v[i+1]});
        queue<int> q;
        for (auto p : pairs) {
            q.push(p.second);
            if (p.first % 2 == 0) q.pop();
        }
        while (q.size() != 0) {
            ans3.push_back(q.front());
            q.pop();
        }

    }
    
    public:
    // create a constructor to take input
        Solution(int size, vector<unsigned int> vec) {
            n = size;
            v = vec;
            solve_task1();
            solve_task2();
            solve_task3();
        }

    string FINDMATCH(string path){
        // complete this function to read file, compare with ans1, ans2, ans3
        // and return the answer

        path = "../../"+path;
        ifstream file;
        file.open(path, ios::binary);

        if (!file.is_open()) return "ERROR";

        file.seekg(0, ios::end);
        int file_size = file.tellg();
        file.seekg(0, ios::beg);

        unsigned int read_data;
        vector<unsigned int> answer;

        while (file.tellg() != file_size) {
            file.read((char *) &read_data, sizeof(int));
            answer.push_back(read_data);
        }

        if (answer == ans1) return "TASK1";
        else if (answer == ans2) return "TASK2";
        else if (answer == ans3) return "TASK3";
        else return "NOTFOUND";
    }
};


#include "../../include/test2_cases.h"