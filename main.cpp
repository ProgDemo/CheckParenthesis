#include <iostream>
#include "Stack.h"

using namespace std;

#define NORMAL
#ifdef NORMAL

bool checkParenthesis(string line);

int main()
{
    cout << checkParenthesis("()((()()))");
    return 0;
}

bool checkParenthesis(string line) {
    Stack stack;
    bool correct = true;

    int i = 0;
    while(correct && i < line.length()) {
        if (line[i] == '(') {
            stack.push(i);
        } else if (line[i] == ')') {
            if (stack.isEmpty()) {
                correct = false;
            } else {
                stack.pop();
            }
        }
        ++i;
    }

    return correct && stack.isEmpty();
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//Néhány teszteset

TEST_CASE("Empty stack, top method", "Should throw ItemNotFoundException") {

    Stack s;
    CHECK_THROWS(s.top()); //Azt ellenõrzi, hogy a top metódus dob -e kivételt
}

TEST_CASE("Empty stack, pop method", "Should throw ItemNotFoundException") {

    Stack s;
    CHECK_THROWS(s.pop());
}

TEST_CASE("Stack with 1 item, top method", "Should return the top item") {

    Stack s;
    s.push(1);
    CHECK(s.top() == 1);
}

TEST_CASE("Stack with 1 item, pop method", "Should return the top item with empty stack") {

    Stack s;
    s.push(1);
    bool result = s.pop() == 1 && s.isEmpty();
    CHECK(result);
}

TEST_CASE("Stack with more items, pop method", "Should return the top item") {

    Stack s;

    for (int i = 1; i <= 5; ++i) {
        s.push(i);
    }

    CHECK(s.top() == 5);
}

TEST_CASE("Full stack, full method", "Should return true") {

    Stack s;

    for (int i = 1; i <= 100; ++i) {
        s.push(i);
    }

    CHECK(s.isFull());
}

TEST_CASE("Empty stack, empty method", "Should return true") {

    Stack s;

    CHECK(s.isEmpty());
}

TEST_CASE("Full stack, push method", "Should throw StackOverFlowException") {

    Stack s;

    for (int i = 1; i <= 100; ++i) {
        s.push(i);
    }

    CHECK_THROWS(s.push(10));
}

TEST_CASE("Stack with more items, clear method", "isEmpty should return true") {

    Stack s;

    for (int i = 1; i <= 10; ++i) {
        s.push(i);
    }
    s.clear();

    CHECK(s.isEmpty());
}

#endif
