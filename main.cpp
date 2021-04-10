#include <cmath>
#include <iostream>
#include <vector>

template <typename T> class Solution {
public:
  Solution();
  size_t GetRank() { return dimension; };
  inline void PrintMatrix();
  inline size_t GetMaxRank();
private:
  struct Node {
    bool type;
    char value;
  };
  size_t max_of_type0 = 0;//максимальное кол-во 1 ого типа
  size_t max_of_type1 = 0;//максимальное кол-во 2 ого типа
  std::vector<std::vector<Node>> matrix;
  size_t dimension;

  inline void InputMatrix();
};

template <typename T> void Solution<T>::InputMatrix() {
  std::vector<T> matrix_imposter;
  char c;
  while ((c = getchar()) != EOF) {
    if (c == '{' || c == ' ') {
      continue;
    }
    if (c == '}') {
      break;
    }
    matrix_imposter.emplace_back(c);
  }
  dimension = sqrt(matrix_imposter.size());
  matrix.resize(dimension);
  for (size_t i = 0; i < dimension; ++i) {
    matrix[i].resize(dimension);
  }

  for (size_t i = 0; i < dimension; ++i) {
    for (size_t j = 0; j < dimension; ++j) {
      bool type = ((i+j)%2 == 1);
      matrix_imposter[i * dimension + j] == '1' ? ++max_of_type1 : ++max_of_type0;
      matrix[i][j] = Node{type, matrix_imposter[i * dimension + j]};
    }
  }
}

template <typename T> Solution<T>::Solution() {
  InputMatrix();
}

template <typename T> void Solution<T>::PrintMatrix() {
//  std::cout << dimension << std::endl;
  for (size_t i = 0; i < dimension; ++i) {
    for (size_t j = 0; j < dimension; ++j) {

      std::cout << matrix[i][j].value << " ";
    }
    std::cout << std::endl;
  }
}

template <typename T>
size_t Solution<T>::GetMaxRank() {
    if (max_of_type0 < dimension){
      return 0;
    }
    std::cout << "Not implemented";
    exit(0);
}

int main() {
  Solution<char> a;
  a.PrintMatrix();
  std::cout << "Максимальный определитель: " << a.GetMaxRank();
  return 0;
}
