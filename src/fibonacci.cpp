#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }
    double fi = ((1 + std::sqrt(5)) / 2);
    double f = round(( pow(fi, n) / std::sqrt(5)));
    return static_cast < uint64_t >(f);
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    for (int i = 2; i<=n; i++){
      fib_prev = fib_prev+fib_curr;
      fib_curr = fib_prev-fib_curr;
    }

    return fib_prev + fib_curr;
  }

  int64_t fib_recursive(int n) {

    if (n == 0){
      return 0;
    }
    if (n==1){
      return 1;
    }
    return (fib_recursive(n-1) + fib_recursive(n-2));
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }
    if (n <= 1) {
      cache[0] = 0;
      cache[1] = 1;
      return cache[n];
    }
    cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);
    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }
    Matrix2x2 matrix = FibMatrix;
    matrix = matrix_power(matrix, n-1);

    return matrix[0][0] + matrix[0][1];
  }

}  // namespace assignment
