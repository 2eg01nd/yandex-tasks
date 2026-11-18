#include "two_sum.h"
#include <gtest/gtest.h>

TEST(TwoSumTest, BasicCase)
{
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto res = sol.twoSum(nums, target);
    ASSERT_EQ(res.size(), 2u);
    EXPECT_TRUE((res[0] == 0 && res[1] == 1) || (res[0] == 1 && res[1] == 0));
}

TEST(TwoSumTest, DuplicateValuesDifferentIndices)
{
    Solution sol;
    std::vector<int> nums = {3, 3};
    int target = 6;

    auto res = sol.twoSum(nums, target);
    ASSERT_EQ(res.size(), 2u);
    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], 1);
}

TEST(TwoSumTest, LargeInputPerformanceCheck)
{
    Solution sol;
    // Создаем большой массив для проверки O(N) сложности
    // В реальном тесте можно использовать генератор случайных чисел
    std::vector<int> nums(100000, 1);
    nums[99999] = 2; // Последний элемент изменен
    int target = 3;

    auto start = std::chrono::high_resolution_clock::now();
    auto res = sol.twoSum(nums, target);
    auto end = std::chrono::high_resolution_clock::now();

    ASSERT_EQ(res.size(), 2u);
    EXPECT_EQ(res[0], 99998);
    EXPECT_EQ(res[1], 99999);

    // Время выполнения должно быть миллисекунды, а не секунды
    double duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    EXPECT_LT(duration_ms, 100.0);
}

TEST(TwoSumTest, NoSolutionEdgeCase)
{
    Solution sol;
    std::vector<int> nums = {1, 2, 3};
    int target = 100;

    auto res = sol.twoSum(nums, target);
    // По условию задачи решение гарантировано, но хороший код должен обрабатывать отсутствие
    // Если по условию LeetCode/Yandex решение всегда есть, этот тест можно адаптировать под assert или исключение
    EXPECT_TRUE(res.empty());
}
