#include <torch/torch.h>
#include <iostream>

using namespace torch;  // libtorch命名空间
using namespace std;

int main() {
  cout << torch::cuda::is_available() << endl;
  cout << torch::cuda::cudnn_is_available() << endl;
  cout << torch::cuda::device_count() << endl;
  std::cout << "CUDA DEVICE COUNT: " << torch::cuda::device_count() << std::endl;
  
  torch::Tensor tensor = torch::rand({2, 3});
  std::cout << tensor << std::endl;
}
