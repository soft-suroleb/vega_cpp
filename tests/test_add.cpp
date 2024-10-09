#include <gtest/gtest.h>
#include "addition.hpp"

TEST(Addition, Simple) {
    EXPECT_EQ(add(10, 5), 15);
    EXPECT_EQ(add(-4, 10), add(10, -4));
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-10, -20), -30);
    EXPECT_EQ(add(-10, 20), 10);
    EXPECT_EQ(add(10, -20), -10);
}
