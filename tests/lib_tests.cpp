#include <lib.h>
#include <gtest/gtest.h>

TEST(LibTests, TestIntegerOne_One) {
    const auto expected = 1;
    const auto actual = lib::multiply(1, 1);
    ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}