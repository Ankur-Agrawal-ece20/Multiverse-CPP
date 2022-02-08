#include<bits/stdc++.h>
using namespace std;

int main()
{
    // stack declaration with datatype int
    stack<int> stk;
    if(stk.empty()) cout << "stack is empty\n";
    else cout << "stack is not empty\n";
    stk.push(5);
    stk.push(8); // 8 pushed on top of 5
    cout << "stack size = " << stk.size() << '\n'; // size of stack

    while (!stk.empty()) {
      cout << stk.top() << ' ';
      stk.pop();
    }
    cout << '\n';





    // queue declaration with datatype int
    queue<int> q;
    if(q.empty()) cout << "queue is empty\n";
    else cout << "queue is not empty\n";
    q.push(5);
    q.push(8); // 8 pushed behind 5 in the queue
    q.push(3);
    cout << "queue size = " << q.size() << '\n'; // size of queue
    cout << "q.front() = " << q.front() << '\n';
    cout << "q.back() = " << q.back() << '\n';

    while (!q.empty()) {
      cout << q.front() << ' ';
      q.pop();
    }
    cout << '\n';






    set<int, greater<int>> st;
    st.insert(4);
    st.insert(8);
    st.insert(3);
    st.insert(10);
    st.insert(12);
    st.insert(1);

    set<int>::iterator itr; // iterator for iterating through set<int>
    for (itr = st.begin(); itr != st.end(); itr++) {
      cout << *itr << ' ';
    }
    cout << '\n';
    st.erase(st.find(10));
    // auto keyword
    // “auto” keyword is used to deduce datatype automatically
    for(auto it = st.begin(); it != st.end(); it++){
      cout << *it << ' ';
    }
    cout << '\n';
    // This works for all three: set, map and vector

    auto it1 = st.lower_bound(3); // it will point to the 1st element which is >=3
    auto it2 = st.upper_bound(3); // it will point to the 1st element which is >3
    if (it1 != st.end())
        cout << "The lower bound of 3 is " << *it1 << '\n';
    else
        cout << "Element is larger than the greatest element in the set\n";
    if (it2 != st.end())
        cout << "The upper bound of 3 is " << *it2 << '\n';
    else
        cout << "Element is larger than the greatest element in the set\n";

    st.clear();
    cout << "set size = " << st.size() << '\n'; // size of set









    map<int, int> mp1;
    mp1[2] = 5;
    mp1[7] = 1;
    mp1[3]++;
    mp1[3]++;
    cout << "mp1[3] = " << mp1[3] << '\n';
    cout << "mp1[2] = " << mp1[2] << '\n';

    map<string, int> mp2;
    mp2["cheese"] = 1;
    mp2["salsa"] = 2;
    cout << "mp2[\"salsa\"] = " << mp2["salsa"] << '\n';
    for(auto it : mp1){
      cout << it.first << ' ' << it.second << endl;
    }






    return 0;
}