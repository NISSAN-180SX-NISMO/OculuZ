#include <torch/torch.h>
#include <iostream>

int main() {
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << std::endl;
    std::cout << "CUDA is available: "
              << (torch::cuda::is_available() ? "Yes" : "No")
              << std::endl;
    return 0;
}
