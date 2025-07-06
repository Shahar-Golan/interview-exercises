#include "processor.h"
#include <limits>

namespace example {

Processor::Processor(const Config& cfg)
    : config_(cfg) {}

ErrorCode Processor::operator()(int32_t input, int32_t& output) const {
    if (input < config_.minValue || input > config_.maxValue) {
        return ErrorCode::InvalidInput;
    }
    // Simple operation: multiply by 2
    int64_t result = static_cast<int64_t>(input) * 2;
    if (result > std::numeric_limits<int32_t>::max() ||
        result < std::numeric_limits<int32_t>::min()) {
        return ErrorCode::CalculationError;
    }
    output = static_cast<int32_t>(result);
    return ErrorCode::Success;
}

} // namespace example
