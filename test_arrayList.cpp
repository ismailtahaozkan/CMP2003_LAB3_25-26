#define CATCH_CONFIG_MAIN
#define CATCH_TESTING
#include "catch_amalgamated.hpp"
#include <iostream>
using namespace std;

extern int student_main();
#include "MainProgram.cpp"

/************************************************************
 CMP2003 – Data Structures Lab
 Autograder Test File for arrayListType
 ------------------------------------------------------------
 Each section tests one requirement separately:
   [removeAt]   → Task 2
   [removeAll]  → Task 3
   [min]        → Task 4
   [max]        → Task 5
************************************************************/

TEST_CASE("Task 2 - removeAt uses swap or removes correctly", "[removeAt]") {
    arrayListType<int> list(10);
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    REQUIRE(list.listSize() == 4);
    list.removeAt(1); // remove index 1 (20)
    REQUIRE(list.listSize() == 3);

    // check that 20 no longer exists
    int val;
    bool found = false;
    for (int i = 0; i < list.listSize(); i++) {
        list.retrieveAt(i, val);
        if (val == 20) found = true;
    }
    REQUIRE_FALSE(found);
}

TEST_CASE("Task 3 - removeAll removes all occurrences of an element", "[removeAll]") {
    arrayListType<int> list(15);
    list.insertEnd(5);
    list.insertEnd(7);
    list.insertEnd(3);
    list.insertEnd(7);
    list.insertEnd(9);
    list.insertEnd(7);

    REQUIRE(list.listSize() == 6);
    list.removeAll(7);
    REQUIRE(list.listSize() == 3);

    // ensure no 7s remain
    int val;
    for (int i = 0; i < list.listSize(); i++) {
        list.retrieveAt(i, val);
        REQUIRE(val != 7);
    }
}

TEST_CASE("Task 4 - min returns smallest element", "[min]") {
    arrayListType<int> list(10);
    list.insertEnd(15);
    list.insertEnd(8);
    list.insertEnd(22);
    list.insertEnd(5);
    list.insertEnd(9);
    REQUIRE(list.min() == 5);
}

TEST_CASE("Task 5 - max returns largest element", "[max]") {
    arrayListType<int> list(10);
    list.insertEnd(15);
    list.insertEnd(8);
    list.insertEnd(22);
    list.insertEnd(5);
    list.insertEnd(9);
    REQUIRE(list.max() == 22);
}
