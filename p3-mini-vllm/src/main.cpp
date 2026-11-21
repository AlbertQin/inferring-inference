#include <iostream>

#include "serve/serve.h"

int main() {
    std::cout << serve::project_name() << '\n';
    return 0;
}
