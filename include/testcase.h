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
vector<string> testcase5{
	"li $a, 69",
	"addi $b, $a, 420",
	"sub $c, $b, $a",
	"mul $b, $c, $c",
	"sw $b, answer"
};
vector<string> testcase6{
	"li $xy, 21",
	"li $x, 50",
	"add $xy, $xy, $xy",
	"sub $c, $xy, $x",
	"addi $a, $c, 100",
	"mul $c, $a, $xy",
	"and $ddd, $c, $a",
	"or $c, $ddd, $a",
	"andi $d, $x, 15",
	"ori $a, $d, 15",
	"sw $a, answer"
};
vector<string> testcase7{
	"li $t1, 2",
	"andi $t2, $t1, 3",
	"sw $t2, answer"
};
vector<string> testcase8{
	"li $aaa, 3",
	"li $aaa, 5",
	"li $aaa, 7",
	"ori $aaa, $aaa, 16",
	"sw $aaa, answer"
};
vector<string> testcase9{
	"li $a, -84",
	"li $b, -16",
	"add $c, $a, $b",
	"ori $d, $c, 5",
	"sw $d, answer"
};
vector<string> testcase10{
	"li $x, 811",
	"li $y, 97",
	"mul $u3, $x, $y",
	"mul $x, $u3, $y",
	"sub $y, $u3, $y",
	"or $z, $x, $y",
	"sw $z, answer",
};
TEST_CASE("Testing your code") {
	CHECK(solve(testcase1.size(), testcase1) == -10);
	CHECK(solve(testcase2.size(), testcase2) == 1207);
	CHECK(solve(testcase3.size(), testcase3) == 35);
	CHECK(solve(testcase4.size(), testcase4) == 8);
	CHECK(solve(testcase5.size(), testcase5) == 176400);
	CHECK(solve(testcase6.size(), testcase6) == 15);
	CHECK(solve(testcase7.size(), testcase7) == 2);
	CHECK(solve(testcase8.size(), testcase8) == 23);
	CHECK(solve(testcase9.size(), testcase9) == -99);
    CHECK(solve(testcase10.size(),testcase10) == 7700459);
}