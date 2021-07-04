//
// Created by saymon on 27/05/19.
//

#include <gtest/gtest.h>
#include <Backtraking/Backtraking.h>

class  BacktrackingTest: public ::testing::Test{
protected:

    void SetUp() override {
        backtrack  = new Backtracking();
    }
    void TearDown() override {}

    Backtracking *backtrack;

};

