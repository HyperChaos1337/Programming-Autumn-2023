#include "matrix.h"

Matrix::Matrix(){
    this->order = DEFAULT_ORDER;
}

std::vector<std::vector<number>>& Matrix::get_matrix(){
    return matrix_array;
}

void Matrix::user_matrix() {
    std::cout << "Enter elements of matrix. It must me higher than -10 and lower than 10" << "\n";
    std::cout << "First number for row, second for column" << '\n';
    number element;
    for(int i = 0; i < order; i++){
        matrix_array.push_back(std::vector<number>());
        for(int j = 0; j < order; ++j){
            std::cout << "Element " << i+1 << j+1 << " = ";std::cin >> element;
            while(std::cin.fail() || element < -10 || element > 10){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Element has to be greater than -10 and lower than 10. Try again" << '\n';
                std::cin >> element;
            }
            matrix_array.back().push_back(element);
        }
    }

}

void Matrix::print(){
    for(auto row: matrix_array){
        for(auto element: row){
            std::cout << std::fixed << std::setprecision(2) << element << " ";
        }
        std::cout << '\n';
    }
}

void Matrix::default_matrix() {
    for(int i = 0; i < order; ++i){
        matrix_array.push_back(std::vector<number>());
        for(int j = 0; j < order; ++j){
            if(i == j) matrix_array.back().push_back(1);
            else matrix_array.back().push_back(0);
        }
    }
}

bool Matrix::full_of_zeroes(std::vector<std::vector<number>> &matrix){

    int count = 0;
    for(int i = 0; i < order; i++){
        for(int j = 0; j < order; j++){
            if(matrix[i][j] == 0) count++;
        }
    }
    if(count == pow(order, 2)) return true;
    return false;
}

number Matrix::determinant(){

    if(matrix_array.empty()){
        std::cout << "Matrix is empty. Determinant will be equated to zero" << '\n';
        return 0;
    }

    det = matrix_array[0][0]*matrix_array[1][1]*matrix_array[2][2]+
          matrix_array[0][1]*matrix_array[1][2]*matrix_array[2][0]+
          matrix_array[0][2]*matrix_array[1][0]*matrix_array[2][1]-
          matrix_array[0][2]*matrix_array[1][1]*matrix_array[2][0]-
          matrix_array[0][0]*matrix_array[1][2]*matrix_array[2][1]-
          matrix_array[0][1]*matrix_array[1][0]*matrix_array[2][2];

    return det;

}

void Matrix::set_determinant(number det){
    this->det = det;
}

std::vector<std::vector<number>>& Matrix::transpose(){

    if(!matrix_array.empty()){
        number **temp = new number*[order];
        for(int i = 0; i < order; i++) temp[i] = new number[order];
        for(int j = 0; j < order; j++){
            for(int k = 0; k < order; k++) temp[j][k] = matrix_array[j][k];
        }

        for(int j = 0; j < order; j++){
            for(int k = 0; k < order; k++) matrix_array[j][k] = temp[k][j];
        }

        for(int i = 0; i < order; i++) delete []temp[i];
        return matrix_array;
    }
    else std::cout << "Matrix is empty. Transposition is impossible" << '\n';
    return matrix_array;
}

int Matrix::rank(std::vector<std::vector<number>> &matrix){

    if(matrix_array.empty()){
        std::cout << "Matrix is empty. Rank will be equated to zero" << '\n';
        return 0;
    }

    int rank_value = 0;

    number m1 = matrix_array[0][1]*matrix_array[1][2] - matrix[0][2]*matrix[1][1];
    number m2 = matrix_array[0][0]*matrix_array[1][2] - matrix[0][2]*matrix[1][0];
    number m3 = matrix_array[0][0]*matrix_array[1][1] - matrix[0][1]*matrix[1][0];
    number m4 = matrix_array[1][1]*matrix_array[2][2] - matrix[1][2]*matrix[2][1];
    number m5 = matrix_array[0][0]*matrix_array[2][2] - matrix[0][2]*matrix[2][0];
    number m6 = matrix_array[0][0]*matrix_array[2][1] - matrix[0][1]*matrix[2][0];
    number m7 = matrix_array[1][1]*matrix_array[2][2] - matrix[1][2]*matrix[2][1];
    number m8 = matrix_array[1][0]*matrix_array[2][2] - matrix[1][2]*matrix[2][0];
    number m9 = matrix_array[1][0]*matrix_array[2][1] - matrix[1][1]*matrix[2][0];

    bool some_zero_minors = m1 != 0 || m2 != 0 || m3 != 0 ||
                           m4 != 0 || m5 != 0 || m6 != 0 ||
                           m7 != 0 || m8 != 0 || m9 != 0;

    bool all_zero_minors = m1 == 0 && m2 == 0 && m3 == 0 &&
                           m4 == 0 && m5 == 0 && m6 == 0 &&
                           m7 == 0 && m8 == 0 && m9 == 0;

    if(full_of_zeroes(matrix)) rank_value = 0;

    if(all_zero_minors && !full_of_zeroes(matrix)) rank_value = 1;

    if(determinant() == 0 && some_zero_minors) rank_value = 2;

    if(determinant() != 0 && some_zero_minors) rank_value = 3;

    return rank_value;
}