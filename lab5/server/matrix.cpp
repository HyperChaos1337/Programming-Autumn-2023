#include "matrix.h"

Matrix::Matrix():RectangleMatrix(){
    this->order = this->columns;
}
Matrix::Matrix(int order):RectangleMatrix(order, order){
    this->order = order;
}

int Matrix::get_order(){
    return order;
}

rational Matrix::determinant(){

    if(order == 1) return matrix_array[0][0];
    if(order == 2) return matrix_array[0][0]*matrix_array[1][1] - matrix_array[1][0]*matrix_array[0][1];
    if(order == 3)
        return matrix_array[0][0]*matrix_array[1][1]*matrix_array[2][2]+
          matrix_array[0][1]*matrix_array[1][2]*matrix_array[2][0]+
          matrix_array[0][2]*matrix_array[1][0]*matrix_array[2][1]-
          matrix_array[0][2]*matrix_array[1][1]*matrix_array[2][0]-
          matrix_array[0][0]*matrix_array[1][2]*matrix_array[2][1]-
          matrix_array[0][1]*matrix_array[1][0]*matrix_array[2][2];

}

