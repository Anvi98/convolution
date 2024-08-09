/**
 * @file conv.cpp
 *@author Anvi Alex Eponon
 *@version v0.01
 * @brief Main program for applying 2D convolution.
 * 
 * This file contains the main function which applies a convolution operation
 * on a matrix using a specified kernel. The results are then printed to the console.
 * It is restricted now to use only integers matrices and it applies very basic convolution operation on a 2D matrix.
 */

#include <iostream>
#include "conv.hpp"
#include "toy_matrices.hpp"

int main(void){
  
  // Get sizes
  const auto [numRow_m, numCol_m, numRow_kernel, numCol_kernel] = get_matrix_sizes(matrix_1, kernel);

  //check matrix and kernel dimensions
  bool is_same_size = true;
  if(numCol_kernel*numRow_kernel > numCol_m*numRow_m){
    throw std::invalid_argument("Kernel dimensions goes beyond Matrix dimensions.");
    is_same_size = false;
    return -1;
  }
  
  //Apply convolution
  auto conv_result_matrix = conv2D(matrix_1, kernel);
  
  // Display results matrix after Convolution
  std::cout<<"-----------Res conv --------------\n";
  for (size_t i = 0; i < conv_result_matrix.size(); ++i) {
    for (size_t j = 0; j < conv_result_matrix[0].size(); ++j) {
      std::cout<<conv_result_matrix[i][j]<<" ";
    }
    std::cout<<'\n';
  }

  return 0;
}
