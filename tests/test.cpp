#include <gtest/gtest.h>
#include <SeaButtle.hpp>
#include <vector>

TEST(SeaButtle, Poisk){
    std::vector<vector<int>> m = {{0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    Pole PoleIgroka(m);
    int i = poiskAdresa(0, 0, 4, 1, 1);
    EXCEPT_EQ(i, 1);
}
