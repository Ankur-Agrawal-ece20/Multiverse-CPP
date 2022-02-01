<h2 align="center"> Welcome to </h2>
<p align="center">
<img alt="MULTIVERSE OF LANGUAGES" width="700px" src="images/text.png" />
</p>
<br>

# Introduction

In this task you will be working on a `C++ File` and coding it according to given task. The main motive of this task is to make you familiar with:

- Git and GitHub
- C++
- Standard Template Library (STL)

## Setting up the project

Follow the following steps to setup this project.

### Fork this repository
First of all, click on the top-right corner of this repository to fork it.

### Create a local clone of your fork
Then, clone your forked repository using this command:
```
git clone https://github.com/YOUR-USERNAME/Multiverse-CPP.git
```

Change your current directory to the repo's root.
```
cd Multiverse-CPP
```

### Thats it!

Go through the tasks in src folder and

<p align="center">
<img alt="Enjoy coding" width="500px" src="images/meme1.jpg" />
</p>

Then you can finally test your submission using this command.
```
make
```

## Submission
* Follow the instructions to setup this project.
* Complete the task by making the required changes in the files.
* When done, commit your work locally and push it to your origin (forked repository).
* Make a pull request to our repository, stating the tasks which you have completed.
* Let us review your pull request.

<hr>
<br/>

## Want to know about doctest? See this example

Suppose we have a ```factorial()``` function that we want to test:

```c++
int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }
```

A complete compiling example with a self-registering test looks like this:

```c++
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test/doctest.h"

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") {
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}
```

This will compile to a complete executable which responds to command line arguments. If you just run it with no arguments it will execute all test cases (in this case - just one), report any failures, report a summary of how many tests passed and failed and returns 0 on success and 1 if anything failed (useful if you just want a yes/no answer to: "did it work").

If you run this as written it will pass. Everything is good. Right? Well there is still a bug here. We missed to check if ```factorial(0) == 1``` so lets add that check as well:

```c++
TEST_CASE("testing the factorial function") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}
```

Now we get a failure - something like:

```
test.cpp(7) FAILED!
  CHECK( factorial(0) == 1 )
with expansion:
  CHECK( 0 == 1 )
```
