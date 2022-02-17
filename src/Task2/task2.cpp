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
	    bool compare_pairs(pair<unsigned int, unsigned int> pairs1, pair<unsigned int, unsigned int> pairs2)
	    {
	

	        if (pairs1.second > pairs2.second)
	            return false;
	        else if (pairs1.second == pairs2.second)
	        {
	            if (pairs1.first > pairs2.first)
	                return true;
	            else
	                return false;
	        }
	        else
	            return true;
	    }
	    vector<pair<unsigned int,unsigned int>> sorttask2(vector<pair<unsigned int,unsigned int>> v, int n)
	    {
	        pair<unsigned int,unsigned int> vtemp;
	        for (int i = 0; i < n; i++)
	        {
	            for (int j = i + 1; j < n; j++)
	            {
	                if (compare_pairs(v[i], v[j]))
	                {
	                    vtemp = v[i];
	                    v[i] = v[j];
	                    v[j] = vtemp;
	                }
	            }
	        }
	        return v;
	    }
	

	    void solve_task2()
	    {
	        vector<pair<unsigned int, unsigned int>> pairs3;
	        for (int i = 1; i <= n / 2; i++)
	        {
	            pair<unsigned int, unsigned int> pairs4;
	            pairs4.first = v[2 * i - 2];
	            pairs4.second = v[2 * i - 1];
	            pairs3.push_back(pairs4);
	        }e
	        pairs3 = sorttask2(pairs3, n / 2);
	

	        for (int i = 0; i < n / 2; i++)
	            ans2.push_back(pairs3[i].first);
	    }
	    void solve_task3()
	    {
	        vector<pair<unsigned int, unsigned int>> pairs5;
	        for (int i = 1; i <= n / 2; i++)
	        {
	            pair<unsigned int, unsigned int> p;
	            p.first = v[2 * i - 2];
	            p.second = v[2 * i - 1];
	            pairs5.push_back(p);
	        }
	

	        queue<unsigned int> q;
	        for (pair<unsigned int, unsigned int> p : pairs5)
	        {
	            if (p.first % 2 == 1)
	                q.push(p.second);
	            else
	            {
	                q.push(p.second);
	                q.pop();
	            }
	        }
	

	        int elmnt;
	        while (!q.empty())
	        {
	            elmnt = q.front();
	            ans3.push_back(elmnt);
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
