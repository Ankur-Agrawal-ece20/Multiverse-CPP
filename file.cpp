#include <bits/stdc++.h>
using namespace std;

int factorial(int number){ 
    return number <= 1 ? number : factorial(number - 1) * number; 
}

#include "unit-test/testcase.h"