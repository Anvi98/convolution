#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP

#include<iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include<array>


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
std::tuple<int, int, int, int>  get_matrix_sizes(const std::array<std::array<int, N>, M>& matrix, const std::array<std::array<int, L>, K>& kernel);

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
    );

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
std::vector<std::vector<int>>
conv2D(
    std::array<std::array<int, M>, N>& matrix, 
    std::array<std::array<int, O>, P>& kernel
    );

#include "conv.tpp"
#endif

