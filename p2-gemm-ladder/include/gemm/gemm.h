#pragma once
// GEMM Ladder: matmul kernels from naive to tensor cores, each explained with profiler evidence.

#include <string_view>

namespace gemm {

std::string_view project_name();

}  // namespace gemm
