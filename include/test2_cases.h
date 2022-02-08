#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Working on test1") {
	vector<unsigned int> testcase{1,2,3,4,5,6};
    Solution solve(testcase.size(),testcase);
	CHECK(solve.FINDMATCH("include/testfiles/testcase1.bin") == "TASK1");
	CHECK(solve.FINDMATCH("include/testfiles/testcase2.bin") == "NOTFOUND");
}