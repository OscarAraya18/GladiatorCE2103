//
// Created by saymon on 28/05/19.
//


#include <gtest/gtest.h>
#include <logica/Algoritmo.h>

class  GeneticoTest: public ::testing::Test{
protected:

    void SetUp() override {
        algoritmo  = new Algoritmo;
    }
    void TearDown() override {}

    Algoritmo *algoritmo;

};

