#pragma once
// Graph Runner: loads an .onnx file and runs inference without PyTorch.

#include <string_view>

namespace graph {

std::string_view project_name();

}  // namespace graph
