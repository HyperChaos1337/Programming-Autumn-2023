#include "rectangle_matrix.h"

template <typename T>

class Matrix: public RectangleMatrix<T>{
private:
    int order;
public:

    Matrix();
    Matrix(int order);
    Matrix(int order, std::vector<std::vector<T>>& matrix);
    int get_order();
    T determinant(){
        if(order == 1) return RectangleMatrix<T>::matrix_array[0][0];
        if(order == 2) return RectangleMatrix<T>::matrix_array[0][0]*RectangleMatrix<T>::matrix_array[1][1]
                   - RectangleMatrix<T>::matrix_array[1][0]*RectangleMatrix<T>::matrix_array[0][1];
        if(order == 3)
            return RectangleMatrix<T>::matrix_array[0][0]*RectangleMatrix<T>::matrix_array[1][1]*RectangleMatrix<T>::matrix_array[2][2]+
                   RectangleMatrix<T>::matrix_array[0][1]*RectangleMatrix<T>::matrix_array[1][2]*RectangleMatrix<T>::matrix_array[2][0]+
                   RectangleMatrix<T>::matrix_array[0][2]*RectangleMatrix<T>::matrix_array[1][0]*RectangleMatrix<T>::matrix_array[2][1]-
                   RectangleMatrix<T>::matrix_array[0][2]*RectangleMatrix<T>::matrix_array[1][1]*RectangleMatrix<T>::matrix_array[2][0]-
                   RectangleMatrix<T>::matrix_array[0][0]*RectangleMatrix<T>::matrix_array[1][2]*RectangleMatrix<T>::matrix_array[2][1]-
                   RectangleMatrix<T>::matrix_array[0][1]*RectangleMatrix<T>::matrix_array[1][0]*RectangleMatrix<T>::matrix_array[2][2];
    }
    T determinant(std::vector<std::vector<T>>& matrix){
        if(order == 1) return matrix[0][0];
        if(order == 2) return matrix[0][0]*matrix[1][1]
                   - matrix[1][0]*matrix[0][1];
        if(order == 3)
            return matrix[0][0]*matrix[1][1]*matrix[2][2]+
                   matrix[0][1]*matrix[1][2]*matrix[2][0]+
                   matrix[0][2]*matrix[1][0]*matrix[2][1]-
                   matrix[0][2]*matrix[1][1]*matrix[2][0]-
                   matrix[0][0]*matrix[1][2]*matrix[2][1]-
                   matrix[0][1]*matrix[1][0]*matrix[2][2];
    }
};

template <typename T>
Matrix<T>::Matrix():RectangleMatrix<T>(){
    this->order = DEFAULT_ORDER;
}

template <typename T>
Matrix<T>::Matrix(int order):RectangleMatrix<T>(order, order){
    this->order = order;
}

template<typename T>
Matrix<T>::Matrix(int order, std::vector<std::vector<T>>&matrix):RectangleMatrix<T>(order, order, matrix){
    this->order = order;
    this->matrix_array = matrix;
}

template <typename T>
int Matrix<T>::get_order(){
    return order;
}
