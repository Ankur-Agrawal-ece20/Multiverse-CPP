#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
        int n; // n is size that user inputs
        vector<unsigned int> v, ans1, ans2, ans3; // v is the vector that user inputs

        void solve_task1() {
            // solve task1 and save the answer in ans1
            this->ans1 = this->v;
            std::sort(ans1.begin(), ans1.end());
        }

        void solve_task2() {
            // solve task2 and save the answer in ans2
            std::vector<unsigned int> v_temp = v;
            std::vector<std::vector<unsigned int>> container;

            // Group the vector's elements into groups of two
            for (int i{}; i < std::size(v_temp); i += 2) {
                std::vector<unsigned int> temp = {v_temp[i], v_temp[i+1]};
                container.push_back(temp);
            }

            // Store the second elements in an array of their own, sort them, then use a map for referencing group
            std::map<unsigned int, std::vector<unsigned int>&> el_map;
            std::vector<unsigned int> seconds;

            // Mapping the second elements to the ref of their groups
            for (std::vector<unsigned int>& val : container) {
                seconds.push_back(val[1]);
                el_map[val[1]] = val;
            }

            // Sort the seconds and then use the map to access the first members
            std::sort(seconds.begin(), seconds.end(), greater<>());
            for (auto& val : seconds) {
                this->ans2.push_back(el_map[val][0]);
            }
        }
        void solve_task3() {
            // solve task3 and save the answer in ans3

        }
    
    public:
    // create a constructor to take input
        Solution(int n, std::vector<unsigned int> v) {
            this->n = n;
            this->v = v;
        }

    string FINDMATCH(string path) {
        // complete this function to read file, compare with ans1, ans2, ans3
        // and return the answer
        fstream file;

        file.open(path, std::ios::in | std::ios::binary);
    }
};



// int main() {
//     vector<unsigned int> a{5, 7, 6, 5, 2, 1, 4, 0, 1, 3};
//     string paths[] = {
//         "missing_files/missing1.bin",
//         "missing_files/missing2.bin",
//         "missing_files/missing3.bin",
//         "missing_files/missing4.bin",
//     };
//     // Intialize your solution object here

//     // Make a for loop to go through paths array and call FINDMATCH function

//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test2_cases.h"