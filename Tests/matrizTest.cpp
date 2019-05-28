//
// Created by saymon on 28/05/19.
//


#include <gtest/gtest.h>
#include <estructurasLogicas/Matriz.h>


class  matrizTest: public ::testing::Test{
protected:

    void SetUp() override {
        matriz  = new Matriz(10,10);
    }
    void TearDown() override {}

    Matriz *matriz;

};

