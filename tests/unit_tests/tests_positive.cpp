#include "positive.h"
#include <gtest/gtest.h>

TEST(Positive_Constructor, correct_args){
    Positive test(0, 24.5, {14.33,37.55}, {25.43,16.11});
    EXPECT_EQ(test.id(),0);
    EXPECT_EQ(test.mass(),24.5);
    EXPECT_FLOAT_EQ(test.position()[0],14.33);
    EXPECT_FLOAT_EQ(test.position()[1],37.55);
    EXPECT_FLOAT_EQ(test.speed()[0],25.43);
    EXPECT_FLOAT_EQ(test.speed()[1],16.11);
}