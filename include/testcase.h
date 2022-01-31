#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

vector<string> testcase1{
    "li $t1, 25",	
	"li $t2, 35",
	"add $t3, $t1, $t2",
	"sub $t4, $t1, $t2",
	"sw $t4, answer"
};
vector<string> testcase2{
	"li $a, 71",
	"li $b, 18",
	"mul $c, $a, $b",
	"sub $d, $c, $a",
	"sw $d, answer",
};
vector<string> testcase3{
	"li $a1, 7",
	"li $b2, 5",
	"and $u1, $a1, $b2",
	"or $u2, $a1, $b2",
	"mul $u3, $u1, $u2",
	"sw $u3, answer",
};
vector<string> testcase4{
	"li $x, 236",
	"li $y, 187",
	"mul $u3, $x, $y",
	"mul $x, $u3, $y",
	"sub $y, $u3, $y",
	"andi $z, $x, 200",
	"sw $z, answer",
};
vector<string> testcase5{};
TEST_CASE("Testing your code") {
    CHECK(solve(testcase1.size(),testcase1) == -10);
    CHECK(solve(testcase2.size(),testcase2) == 1207);
    CHECK(solve(testcase3.size(),testcase3) == 35);
    CHECK(solve(testcase4.size(),testcase4) == 8);
    // CHECK(solve(testcase5.size(),testcase5) == );
}