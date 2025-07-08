# Unit Test Exercise

This repository defines a simple `Processor` functor. Your task is to add GoogleTest-based unit tests.

## Build steps

```bash
git clone git@github.com:weliad/interview-exercises.git
cd interview-exercises
mkdir build && cd build
cmake -DBUILD_TESTS=ON ..
make
ctest
```

## Exercise

- Install or add GoogleTest to this project.
- Integrate GoogleTest into the CMake build.
- Write tests in tests/test_processor.cpp covering:
  - Successful processing of valid inputs
  - Proper error codes on invalid inputs and overflow
- Run ctest and verify all tests pass.

## Bonus question

Identify an additional issue in the Processor class definition, which these unit tests cannot capture.

Answer:
There is no validation of the config range. We can insert there incorrect values like min_val > max_val and the program will crash. 

A proof before I handled it:

TEST(ProcessorTest, InputBelowMinValue) {
  Config cfg{0, -100};
  Processor proc(cfg);
  int32_t out = 0;
  EXPECT_EQ(ErrorCode::InvalidInput, proc(-1, out));
}

Start 4: ProcessorTest.InputBelowMinValue
4/7 Test #4: ProcessorTest.InputBelowMinValue ...   Passed    0.01 sec


