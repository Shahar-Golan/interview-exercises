#include "processor.h"
#include <limits>
#include <stdexcept>

namespace example {

Processor::Processor(const Config& cfg)
    : config_(cfg) {
        if (cfg.minValue > cfg.maxValue) {
            throw std::invalid_argument("Invalid config: minValue > maxValue");
    }
}

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
