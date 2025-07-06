#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>

namespace example {

// Error codes returned by Processor
enum class ErrorCode {
    Success = 0,
    InvalidInput,
    CalculationError
};

// Configuration for Processor
struct Config {
    int32_t minValue;
    int32_t maxValue;
};

// Functor: checks bounds and multiplies input by 2
class Processor {
public:
    explicit Processor(const Config& cfg);
    ErrorCode operator()(int32_t input, int32_t& output) const;

private:
    Config config_;
};

} // namespace example
#endif // PROCESSOR_H
