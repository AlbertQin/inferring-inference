// Capstone: Local LLM Engine. A 0.5-1B model at 4 bits on the Mac (Metal),
// reusing the graph runner (P1) and the KV cache / block manager (P3).
#include <iostream>

#include "graph/graph.h"
#include "serve/serve.h"

int main() {
    std::cout << "Local LLM Engine, using " << graph::project_name() << " and "
              << serve::project_name() << '\n';
    return 0;
}
