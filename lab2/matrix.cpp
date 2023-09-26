#include "matrix.h"

Matrix::Matrix(){
    this->order = DEFAULT_ORDER;
}

std::vector<std::vector<complex>>& Matrix::get_matrix(){
    return matrix_array;
}

void Matrix::user_matrix() {
    std::cout << "Enter elements of matrix. (First number for real, second - for imaginary)" << "\n";
    std::cout << "First number for row, second for column" << '\n';
    complex element;
    for(int i = 0; i < order; i++) {
        matrix_array.push_back(std::vector<complex>());
        for (int j = 0; j < order; ++j) {
            std::cout << "Element " << i + 1 << j + 1 << " = ";
            std::cin >> element;
            while (std::cin.fail() || element.get_real() == 0 || element.get_imaginary() == 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Incorrect input. Try again" << '\n';
                std::cin >> element;
            }
            matrix_array.back().push_back(element);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix){
    for(int i = 0; i < matrix.order; i++){
        for(int j = 0; j < matrix.order; j++){
            out << matrix.matrix_array[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}

void Matrix::default_matrix() {
    for(int i = 0; i < order; ++i){
        matrix_array.push_back(std::vector<complex>());
        for(int j = 0; j < order; ++j){
            complex number;
            number.set_imaginary(rand()%10+1);
            number.set_real(rand()%10+1);
            matrix_array.back().push_back(number);
        }
    }
}

bool Matrix::full_of_zeroes(std::vector<std::vector<complex>> &matrix){

    int count = 0;
    for(int i = 0; i < order; i++){
        for(int j = 0; j < order; j++){
            if(matrix[i][j].get_real() == 0 && matrix[i][j].get_imaginary() == 0) count++;
        }
    }
    if(count == pow(order, 2)) return true;
    return false;

}

complex Matrix::determinant(){

    if(matrix_array.empty()) return TComplex(0, 0);

    det = matrix_array[0][0]*matrix_array[1][1]*matrix_array[2][2]+
          matrix_array[0][1]*matrix_array[1][2]*matrix_array[2][0]+
          matrix_array[0][2]*matrix_array[1][0]*matrix_array[2][1]-
          matrix_array[0][2]*matrix_array[1][1]*matrix_array[2][0]-
          matrix_array[0][0]*matrix_array[1][2]*matrix_array[2][1]-
          matrix_array[0][1]*matrix_array[1][0]*matrix_array[2][2];

    return det;

}

std::vector<std::vector<complex>>& Matrix::transpose(){

    if(!matrix_array.empty()){
        complex **temp = new complex *[order];
        for(int i = 0; i < order; i++) temp[i] = new complex[order];
        for(int j = 0; j < order; j++){
            for(int k = 0; k < order; k++) temp[j][k] = matrix_array[j][k];
        }

        for(int j = 0; j < order; j++){
            for(int k = 0; k < order; k++) matrix_array[j][k] = temp[k][j];
        }

        for(int i = 0; i < order; i++) delete []temp[i];
        return matrix_array;
    }
    else std::cout << "Matrix is empty. Transposition is impossible" << '\n' << "\n";
    return matrix_array;

}

int Matrix::rank(std::vector<std::vector<complex>> &matrix){

    if(matrix_array.empty()) return 0;

    int rank_value = 0;

    complex m1 = matrix_array[0][1]*matrix_array[1][2] - matrix[0][2]*matrix[1][1];
    complex m2 = matrix_array[0][0]*matrix_array[1][2] - matrix[0][2]*matrix[1][0];
    complex m3 = matrix_array[0][0]*matrix_array[1][1] - matrix[0][1]*matrix[1][0];
    complex m4 = matrix_array[1][1]*matrix_array[2][2] - matrix[1][2]*matrix[2][1];
    complex m5 = matrix_array[0][0]*matrix_array[2][2] - matrix[0][2]*matrix[2][0];
    complex m6 = matrix_array[0][0]*matrix_array[2][1] - matrix[0][1]*matrix[2][0];
    complex m7 = matrix_array[1][1]*matrix_array[2][2] - matrix[1][2]*matrix[2][1];
    complex m8 = matrix_array[1][0]*matrix_array[2][2] - matrix[1][2]*matrix[2][0];
    complex m9 = matrix_array[1][0]*matrix_array[2][1] - matrix[1][1]*matrix[2][0];

    bool some_zero_minors = (m1.get_real() != 0 && m1.get_imaginary() != 0) ||
            (m2.get_real() != 0 && m2.get_imaginary() != 0) ||
            (m3.get_real() != 0 && m3.get_imaginary() != 0) ||
            (m4.get_real() != 0 && m4.get_imaginary() != 0) ||
            (m5.get_real() != 0 && m5.get_imaginary() != 0) ||
            (m6.get_real() != 0 && m6.get_imaginary() != 0) ||
            (m7.get_real() != 0 && m7.get_imaginary() != 0) ||
            (m8.get_real() != 0 && m8.get_imaginary() != 0) ||
            (m9.get_real() != 0 && m9.get_imaginary() != 0);

    bool all_zero_minors = (m1.get_real() == 0 && m1.get_imaginary() == 0) &&
            (m2.get_real() == 0 && m2.get_imaginary() == 0) &&
            (m3.get_real() == 0 && m3.get_imaginary() == 0) &&
            (m4.get_real() == 0 && m4.get_imaginary() == 0) &&
            (m5.get_real() == 0 && m5.get_imaginary() == 0) &&
            (m6.get_real() == 0 && m6.get_imaginary() == 0) &&
            (m7.get_real() == 0 && m7.get_imaginary() == 0) &&
            (m8.get_real() == 0 && m8.get_imaginary() == 0) &&
            (m9.get_real() == 0 && m9.get_imaginary() == 0);

    if(full_of_zeroes(matrix)) rank_value = 0;

    if(all_zero_minors && !full_of_zeroes(matrix)) rank_value = 1;

    if(determinant().get_real() == 0 && determinant().get_imaginary() == 0 && some_zero_minors) rank_value = 2;

    if(determinant().get_real() != 0 || determinant().get_imaginary() != 0 && some_zero_minors) rank_value = 3;

    return rank_value;

}
