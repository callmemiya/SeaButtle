// Copyright 2018 Your Name <your_email>
#include <gtest/gtest.h>
#include "SeaButtle.h"
#include <vector>

TEST(SeaButtle, Poisk){
    int i = poiskAdresa(0, 0, 4, 1, 1);
    EXPECT_EQ(i, 1);
}
