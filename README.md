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
