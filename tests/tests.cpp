#include "vector"
#include "bin/main.cpp"
#include "../../untitled8/algs.h"

#include <gtest/gtest.h>




// Тесты для алгоритма all_of


TEST(AllOfTest, AllOfReturnsTrue) {
std::vector<int> v = {2, 4, 6, 8};
bool result = algos::all_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
EXPECT_TRUE(result);
}

TEST(AllOfTest, AllOfReturnsFalse) {
std::vector<int> v = {2, 4, 5, 8};
bool result = algos::all_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
EXPECT_FALSE(result);
}

// Тесты для алгоритма any_of
TEST(AnyOfTest, AnyOfReturnsTrue) {
std::vector<int> v = {1, 3, 5, 8};
bool result = algos::any_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
EXPECT_TRUE(result);
}

TEST(AnyOfTest, AnyOfReturnsFalse) {
std::vector<int> v = {1, 3, 5, 7};
bool result = algos::any_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
EXPECT_FALSE(result);
}

// Тесты для алгоритма is_partitioned
TEST(IsPartitionedTest, IsPartitionedReturnsTrue) {
std::vector<int> v = {1, 2, 3, 4, 5};
bool result = algos::is_partitioned(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
EXPECT_TRUE(result);
}

TEST(IsPartitionedTest, IsPartitionedReturnsFalse) {
std::vector<int> v = {1, 2, 3, 4, 5};
bool result = is_partitioned(v.begin(), v.end(), [](int i){ return i % 3 == 0; });
EXPECT_FALSE(result);
}

TEST(FindNotTest, FindNotReturnsCorrectValue) {
std::vector<int> v = {1, 2, 3, 4, 5};
auto result = algos::find_not(v.begin(), v.end(), 3);
EXPECT_EQ(*result, 1);
}

// Тесты для алгоритма find_backward
TEST(FindBackwardTest, FindBackwardReturnsCorrectValue) {
std::vector<int> v = {1, 2, 3, 4, 3};
auto result = algos::find_backward(v.begin(), v.end(), 3);
EXPECT_EQ(*result, 3);
}
