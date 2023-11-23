#include "rectangle_matrix.h"

template <typename T>

class Matrix: public RectangleMatrix<T>{
private:
    int order;
public:

    Matrix();
    Matrix(int order);
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

};

template <typename T>
Matrix<T>::Matrix():RectangleMatrix<T>(){
    this->order = this->columns;
}

template <typename T>
Matrix<T>::Matrix(int order):RectangleMatrix<T>(order, order){
    this->order = order;
}

template <typename T>
int Matrix<T>::get_order(){
    return order;
}
