//
// Created by saymon on 27/05/19.
//


#include <gtest/gtest.h>
#include <logica/AStar.h>

class  aStartTest: public ::testing::Test{
protected:

    void SetUp() override {
        aStar  = new AStar();
    }
    void TearDown() override {}

    AStar *aStar;

};

