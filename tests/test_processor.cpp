#include "processor.h"
#include <gtest/gtest.h>

using namespace example;

TEST(ProcessorTest, ValidInput) {
    // specify valid input range
    Config cfg{0, 100};
    // creates a Processor instance with the bounds
    Processor proc(cfg);
    // Stores the output result computed by Processor
    int32_t out = 0;
    // triggers the operator function, insert the excepted value
    EXPECT_EQ(ErrorCode::Success, proc(10, out));
    // Confirm the output result
    EXPECT_EQ(20, out);
}

TEST(ProcessorTest, InputAtMinValue) {
    Config cfg{0, 100};
    Processor proc(cfg);
    int32_t out = 0;
    EXPECT_EQ(ErrorCode::Success, proc(0, out));
    EXPECT_EQ(0, out);
}

TEST(ProcessorTest, InputAtMaxValue) {
    Config cfg{0, 100};
    Processor proc(cfg);
    int32_t out = 0;
    EXPECT_EQ(ErrorCode::Success, proc(100, out));
    EXPECT_EQ(200, out);
}

TEST(ProcessorTest, InputBelowMinValue) {
    Config cfg{0, 100};
    Processor proc(cfg);
    int32_t out = 0;
    EXPECT_EQ(ErrorCode::InvalidInput, proc(-1, out));
}

TEST(ProcessorTest, InputAboveMaxValue) {
    Config cfg{0, 100};
    Processor proc(cfg);
    int32_t out = 0;
    EXPECT_EQ(ErrorCode::InvalidInput, proc(101, out));
}

TEST(ProcessorTest, OverflowCase) {
    Config cfg{0, INT32_MAX};
    Processor proc(cfg);
    int32_t out = 0;
    int32_t input = INT32_MAX / 2 + 1;
    EXPECT_EQ(ErrorCode::CalculationError, proc(input, out));
}


// A code that shows me what happens when the test definitions are wrong
TEST(ProcessorTest, OverflowCase2) {
    Config cfg{0, INT32_MAX};
    Processor proc(cfg);
    int32_t out = 0;
    int32_t input = 1500;
    EXPECT_EQ(ErrorCode::CalculationError, proc(input, out));
}
