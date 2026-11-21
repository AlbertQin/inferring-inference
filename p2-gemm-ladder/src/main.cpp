#include <iostream>

#include "gemm/gemm.h"

int main() {
    std::cout << gemm::project_name() << '\n';
    return 0;
}
