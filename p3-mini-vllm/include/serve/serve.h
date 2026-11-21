#pragma once
// Mini vLLM: serving engine with KV cache, paged blocks and continuous batching.

#include <string_view>

namespace serve {

std::string_view project_name();

}  // namespace serve
