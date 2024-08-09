#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<numeric>

template <size_t M, size_t N, size_t K, size_t L>
std::tuple<int, int, int, int>  get_matrix_sizes(int (&matrix)[M][N], int (&kernel)[K][L]);

std::tuple<int, std::vector<std::vector<int>>>
element_wise_matmul(
    const std::vector<std::vector<int>>& matrix, 
    const std::vector<std::vector<int>>& kernel);


int main(void){ 

  int matrice_2[3][3] = {
    {2, 4, 6,},
    {1, 2, 3},
    {0, 9, 5},
  };

  int kernel[3][3] = {
    {1, 1, 0},
    {2, 1, 1},
    {1, 1, 1}
  };
  
  bool is_same_size = true;
  auto [numRow_m, numCol_m, numRow_kernel, numCol_kernel] = get_matrix_sizes(matrice_2, kernel);
  
  if(numCol_kernel != numCol_m || numRow_kernel != numRow_m){
    throw std::invalid_argument("Matrix and kernel dimensions do not match.");
    is_same_size = false;
  }

  if(is_same_size){
    std::vector<std::vector<int>> vec_matrix(numRow_m, std::vector<int>(numCol_m));
    std::vector<std::vector<int>> vec_kernel(numRow_kernel, std::vector<int>(numCol_kernel));

    for (size_t i = 0; i < numCol_m; ++i) {
        for (size_t j = 0; j < numRow_m; ++j) {
            vec_matrix[i][j] = matrice_2[i][j];
        }
    }

    for (size_t i = 0; i < numCol_kernel; ++i) {
        for (size_t j = 0; j < numRow_kernel; ++j) {
            vec_kernel[i][j] = kernel[i][j];
        }
    }

    auto [tmp_sum, tmp_res_matrix] = element_wise_matmul(vec_matrix, vec_kernel);

  }

  else {
    std::cout<<"Size of matrices not the same\n";
  }
    
  //std::cout<<sum_elements<<" \n";
}


template <size_t M, size_t N, size_t K, size_t L>
std::tuple<int, int, int, int>  get_matrix_sizes(int (&matrix)[M][N], int (&kernel)[K][L]){
    
    int numRow_matrix = M; 
    int numCol_matrix = N; 

    int numRow_kernel = K; 
    int numCol_kernel = L; 

    return  std::make_tuple(numRow_matrix, numCol_matrix, numRow_kernel, numCol_kernel); 
  }


std::tuple<int, std::vector<std::vector<int>>>
element_wise_matmul(
    const std::vector<std::vector<int>>& matrix, 
    const std::vector<std::vector<int>>& kernel){

    size_t numCol_matrix = matrix.size(); 
    size_t numRow_matrix = matrix[0].size(); 
    size_t numCol_kernel = kernel.size(); 
    size_t numRow_kernel = kernel[0].size();

    std::vector<std::vector<int>> res_matrix(numCol_kernel, std::vector<int>(numRow_kernel, 0));
    int sum_elements = 0;
 
  for(size_t i = 0; i < numRow_kernel; i ++){
      for(size_t j = 0; j < numCol_kernel; j ++){
        std::cout<<kernel[i][j]<<" "; 
        res_matrix[i][j] = kernel[i][j] * matrix[i][j];
        sum_elements += res_matrix[i][j];
      }
      std::cout<<"\n";
    }

    std::cout<<"\n";
    for(size_t i=0; i < numRow_kernel; i++){
      for(size_t j = 0; j < numCol_kernel; j++){
        std::cout<<res_matrix[i][j]<<" ";
      }
      std::cout<<"\n";
    }
 
  return std::make_tuple(sum_elements, res_matrix); 
}

 
