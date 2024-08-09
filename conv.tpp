#include "conv.hpp"

/**
 * @brief Retrieves the dimensions of the input matrix and kernel.
 * 
 * @tparam M Number of rows in the input matrix.
 * @tparam N Number of columns in the input matrix.
 * @tparam K Number of rows in the kernel.
 * @tparam L Number of columns in the kernel.
 * @param matrix The input matrix.
 * @param kernel The kernel to apply on the matrix.
 * @return std::tuple<int, int, int, int> A tuple containing the number of rows and columns of the matrix, 
 * and the number of rows and columns of the kernel.
 */
template <size_t M, size_t N, size_t K, size_t L>
std::tuple<int, int, int, int>  get_matrix_sizes(const std::array<std::array<int, N>, M>& matrix, const std::array<std::array<int, L>, K>& kernel){
    
    const int numRow_matrix = M; 
    const int numCol_matrix = N; 

    const int numRow_kernel = K; 
    const int numCol_kernel = L; 

    return  std::make_tuple(numRow_matrix, numCol_matrix, numRow_kernel, numCol_kernel); 
  }

/**
 * @brief Performs element-wise multiplication between a matrix and a kernel.
 * 
 * @tparam M Number of rows in the kernel.
 * @tparam N Number of columns in the kernel.
 * @param matrix The matrix to be multiplied.
 * @param kernel The kernel to apply on the matrix.
 * @return std::tuple<int, std::vector<std::vector<int>>> A tuple containing the sum of all elements 
 * and the resulting matrix after element-wise multiplication.
 */
template <size_t M, size_t N>
std::tuple<int, std::vector<std::vector<int>>>
element_wise_matmul(
    const std::vector<std::vector<int>>& matrix, 
    const std::array<std::array<int, M>, N> & kernel
    ){

    size_t numCol_matrix = matrix.size(); 
    size_t numRow_matrix = matrix[0].size(); 
    size_t numCol_kernel = M; 
    size_t numRow_kernel = N;

    std::vector<std::vector<int>> res_matrix(numCol_kernel, std::vector<int>(numRow_kernel, 0));
    int sum_elements = 0;
 
  for(size_t i = 0; i < numRow_kernel; i ++){
      for(size_t j = 0; j < numCol_kernel; j ++){
        res_matrix[i][j] = kernel[i][j] * matrix[i][j];
        sum_elements += res_matrix[i][j];
      }
    }

    for(size_t i=0; i < numRow_kernel; i++){
      for(size_t j = 0; j < numCol_kernel; j++){
      }
    }
 
  return std::make_tuple(sum_elements, res_matrix); 
}

/**
 * @brief Applies a 2D convolution operation on an input matrix using a given kernel.
 * 
 * @tparam M Number of columns in the input matrix.
 * @tparam N Number of rows in the input matrix.
 * @tparam O Number of columns in the kernel.
 * @tparam P Number of rows in the kernel.
 * @param matrix The input matrix to apply the convolution to.
 * @param kernel The kernel used for the convolution.
 * @return std::vector<std::vector<int>> The result of the convolution operation.
 * @throws std::invalid_argument If the kernel dimensions exceed the matrix dimensions.
 */
template <size_t M, size_t N, size_t O, size_t P> 
std::vector<std::vector<int>> conv2D(std::array<std::array<int, M>, N>& matrix, std::array<std::array<int, O>, P>& kernel){
  // find the max_moves for rows and columns
  int numCol_m = M;
  int numRow_m = N;
  int numCol_kernel = O;
  int numRow_kernel = P;
  int stride = 1;

  int max_move_right = ((numCol_m - numCol_kernel)/stride) +1 ; 
  int max_move_down = ((numRow_m - numRow_kernel)/stride) + 1;
  int start_idx_col = 0, start_idx_row = 0 ;


  std::vector<std::vector<int>> conv_result_matrix(max_move_down, std::vector<int>(max_move_right, 0));

  for(int i=0; i< max_move_right * max_move_down; i ++){
    std::vector<std::vector<int>> tmp_sub_matrix(numRow_kernel, std::vector<int>(numCol_kernel));
    for(size_t j = 0 + start_idx_row ; j <numCol_kernel + start_idx_row; j ++){
      for(size_t k = 0 + start_idx_col ; k<numRow_kernel + start_idx_col; k++){
        tmp_sub_matrix[j - start_idx_row][k - start_idx_col] = matrix[j][k];
      }
    }
    // Perform element wise ops 
    auto [sum_res, sub_res_m] = element_wise_matmul(tmp_sub_matrix, kernel);
    conv_result_matrix[start_idx_row][start_idx_col] = sum_res;

    if(start_idx_col == max_move_right - 1){
      start_idx_col = 0;
      start_idx_row ++;
    }

    else {
      start_idx_col ++;
    }
  
  }
  return conv_result_matrix;
}
