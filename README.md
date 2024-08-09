
# Convolution in C++

This project implements a basic 2D convolution operation using C++. Below is the detailed documentation of the functions and their usage.

## Table of Contents

1. [Introduction](#introduction)
2. [Functions](#functions)
   - [get_matrix_sizes](#get_matrix_sizes)
   - [element_wise_matmul](#element_wise_matmul)
   - [conv2D](#conv2d)
3. [Usage](#usage)
4. [Matrix Definitions](#matrix-definitions)
5. [Compiling the Program](#compiling-the-program)
6. [Example Output](#example-output)
7. [Author](#author)

## Introduction

This project demonstrates how to implement a 2D convolution in C++ using template metaprogramming. The convolution operation is performed on a matrix with a given kernel, producing a result matrix.

## Functions

### `get_matrix_sizes`

```
template <size_t M, size_t N, size_t K, size_t L>
std::tuple<int, int, int, int> get_matrix_sizes(const std::array<std::array<int, N>, M>& matrix, const std::array<std::array<int, L>, K>& kernel);
```

#### Description: 
This function returns the dimensions of the input matrix and the kernel.

#### Parameters:
- matrix: A 2D array representing the input matrix.
- kernel: A 2D array representing the convolution kernel.
- Returns: A tuple containing the number of rows and columns of both the matrix and the kernel.

### element_wise_matmul

```
template <size_t M, size_t N>
std::tuple<int, std::vector<std::vector<int>>> element_wise_matmul(const std::vector<std::vector<int>>& matrix, const std::array<std::array<int, M>, N>& kernel);
```
#### Description: 
Performs element-wise multiplication between a sub-matrix of the main matrix and the kernel.

#### Parameters:

- matrix: A 2D vector representing the sub-matrix extracted from the main matrix.
- kernel: A 2D array representing the convolution kernel.
- Returns: A tuple containing the sum of the element-wise multiplication results and the resulting sub-matrix.

### conv2D

```
template <size_t M, size_t N, size_t O, size_t P>
std::vector<std::vector<int>> conv2D(std::array<std::array<int, M>, N>& matrix, std::array<std::array<int, O>, P>& kernel);

```
#### Description: 

Performs a 2D convolution operation on the input matrix with the given kernel.

#### Parameters:
- matrix: A 2D array representing the input matrix.
- kernel: A 2D array representing the convolution kernel.
- Returns: A 2D vector representing the result of the convolution operation.


## Usage
To use these functions, include the header files where the functions are declared and define your matrices and kernels as shown in the examples.

## Matrix Definitions
The matrices used in this program are defined in matrices.hpp and implemented in matrices.cpp. Here is an example:

```
std::array<std::array<int, 14>, 9> matrice_1 = {{
    {1, 4, 4, 2, 1, 0, 0, 1, 0, 0, 3, 3, 3, 4},
    // ...
}};

```
## Compiling the Program
You can compile the program using g++ as follows:


```
g++ conv.cpp toy_matrices.cpp -o ./conv

```
## Example Output
Here is an example output after running the program:

```
-----------Res conv --------------
17 19 13 17 17 26 25 22 21 20 20 28 
10 11 8 19 25 34 30 31 24 22 15 20 
14 7 16 26 21 26 24 27 25 17 13 23 
21 16 14 20 16 19 21 23 23 22 18 16 
23 28 25 21 21 13 21 20 27 21 22 15 
26 25 19 15 19 17 25 22 27 22 19 20 
24 21 15 15 23 23 27 26 17 19 17 19 

```
## Task to do
- Take into account floating points; 
- Implement convolutions with rotations -180 and 180 degrees;
- Add padding features;
- Convert code using Eigen Library

## Author
Anvi Alex.
