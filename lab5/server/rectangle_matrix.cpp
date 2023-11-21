#include "rectangle_matrix.h"

RectangleMatrix::RectangleMatrix(){
    this->rows = this->columns = DEFAULT_ORDER;
}
RectangleMatrix::RectangleMatrix(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
}

void RectangleMatrix::clear_matrix(){
    for(int i = 0; i < rows; ++i){
        matrix_array.push_back(std::vector<rational>());
        for(int j = 0; j < columns; ++j){
            rational number;
            number.set_num(0);
            number.set_den(1);
            matrix_array.back().push_back(number);
        }
    }
}

std::vector<std::vector<rational>>& RectangleMatrix::get_matrix(){
    return matrix_array;
}

void RectangleMatrix::swapRows(int row1, int row2){
    if ((row1 >= rows) || (row2 >= rows) || (row1 == row2)) return;
    rational temp;
    for (int x = 0; x < rows; x++) {
        temp = matrix_array[row1][x];
        matrix_array[row1][x] = matrix_array[row2][x];
        matrix_array[row2][x] = temp;
    }
}

void RectangleMatrix::transpose(){

    rational **temp = new rational *[rows];
    for(int i = 0; i < rows; i++) temp[i] = new rational[columns];
    for(int j = 0; j < rows; j++){
        for(int k = 0; k < columns; k++) temp[j][k] = matrix_array[j][k];
    }

    for(int j = 0; j < rows; j++){
        for(int k = 0; k < columns; k++) matrix_array[j][k] = temp[k][j];
    }

    for(int i = 0; i < rows; i++) delete []temp[i];

}
int RectangleMatrix::rank(){

    if(matrix_array.empty()) return 0;
    std::vector<std::vector<rational>> mat = matrix_array;
    int rank = columns;
    rational zero(0, 0);
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
                rational coefficient = mat[i][row] / mat[row][row];
                for (int j = row; j < rank; j++) {
                    mat[i][j] = (mat[i][j] - mat[row][j]) * coefficient;
                }
            }
        }
    }

    return rank;

}
