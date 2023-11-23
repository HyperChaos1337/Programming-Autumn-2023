#ifndef RECTANGLEMATRIX_H
#define RECTANGLEMATRIX_H

#define DEFAULT_ORDER 3

#include <vector>

template <typename T>

class RectangleMatrix{
protected:
    int rows, columns;
    std::vector<std::vector<T>> matrix_array;
public:
    RectangleMatrix();
    RectangleMatrix(int rows, int columns);
    RectangleMatrix(int rows, int columns, std::vector<std::vector<T>>& matrix);
    std::vector<std::vector<T>>& get_matrix();
    void transpose();
    void swapRows(int row1, int row2);
    int rank();
    int rank(std::vector<std::vector<T>>& matrix);
};

template <typename T>
RectangleMatrix<T>::RectangleMatrix(){
    this->rows = this->columns = DEFAULT_ORDER;
    for(int i = 0; i < rows; ++i){
        matrix_array.push_back(std::vector<T>());
        for(int j = 0; j < columns; ++j){
            T number(0, 1);
            matrix_array.back().push_back(number);
        }
    }
}

template <typename T>
RectangleMatrix<T>::RectangleMatrix(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    for(int i = 0; i < rows; ++i){
        matrix_array.push_back(std::vector<T>());
        for(int j = 0; j < columns; ++j){
            T number(0, 1);
            matrix_array.back().push_back(number);
        }
    }
}

template <typename T>
RectangleMatrix<T>::RectangleMatrix(int rows, int columns, std::vector<std::vector<T>> &matrix){
    this->rows = rows;
    this->columns = columns;
    for(int i = 0; i < rows; ++i){
        matrix.push_back(std::vector<T>());
        for(int j = 0; j < columns; ++j){
            T number = 1.0;
            matrix.back().push_back(number);
        }
    }
    matrix_array = matrix;
}

template <typename T>
std::vector<std::vector<T>>& RectangleMatrix<T>::get_matrix(){
    return matrix_array;
}

template <typename T>
void RectangleMatrix<T>::transpose(){
    T **temp = new T *[rows];
    for(int i = 0; i < rows; i++) temp[i] = new T[columns];
    for(int j = 0; j < rows; j++){
        for(int k = 0; k < columns; k++) temp[j][k] = matrix_array[j][k];
    }

    for(int j = 0; j < rows; j++){
        for(int k = 0; k < columns; k++) matrix_array[j][k] = temp[k][j];
    }

    for(int i = 0; i < rows; i++) delete []temp[i];
}

template <typename T>
void RectangleMatrix<T>::swapRows(int row1, int row2){
    if ((row1 >= rows) || (row2 >= rows) || (row1 == row2)) return;
    T temp;
    for (int x = 0; x < rows; x++) {
        temp = matrix_array[row1][x];
        matrix_array[row1][x] = matrix_array[row2][x];
        matrix_array[row2][x] = temp;
    }
}

template <typename T>
int RectangleMatrix<T>::rank(){
    if(matrix_array.empty()) return 0;
    std::vector<std::vector<T>> mat = matrix_array;
    int rank = columns;
    T zero(0, 0);
    for (int row = 0; row < rank; row++) {
        if (mat[row][row] == zero) {
            bool flag = false;
            for (int i = row + 1; i < rows; i++) {
                if (mat[i][row] != zero) {
                    swapRows(row, i);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                rank--;
                for (int i = row + 1; i < rows; i++) {
                    mat[i][row] = zero;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            if (i != row) {
                T coefficient = mat[i][row] / mat[row][row];
                for (int j = row; j < rank; j++) {
                    mat[i][j] = (mat[i][j] - mat[row][j]) * coefficient;
                }
            }
        }
    }

    return rank;
}

template <typename T>
int RectangleMatrix<T>::rank(std::vector<std::vector<T>> &matrix){
    if(matrix.empty()) return 0;
    matrix = matrix_array;
    int rank = columns;
    T zero = 0;
    for (int row = 0; row < rank; row++) {
        if (matrix[row][row] == zero) {
            bool flag = false;
            for (int i = row + 1; i < rows; i++) {
                if (matrix[i][row] != zero) {
                    swapRows(row, i);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                rank--;
                for (int i = row + 1; i < rows; i++) {
                    matrix[i][row] = zero;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            if (i != row) {
                T coefficient = matrix[i][row] / matrix[row][row];
                for (int j = row; j < rank; j++) {
                    matrix[i][j] = (matrix[i][j] - matrix[row][j]) * coefficient;
                }
            }
        }
    }

    return rank;
}

#endif // RECTANGLEMATRIX_H
