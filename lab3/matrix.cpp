#include "matrix.h"

Matrix::Matrix(){
    this->order = DEFAULT_ORDER;
}

void Matrix::clear_matrix(){
    for(int i = 0; i < order; ++i){
        matrix_array.push_back(std::vector<rational>());
        for(int j = 0; j < order; ++j){
            rational number;
            number.set_num(0);
            number.set_den(1);
            matrix_array.back().push_back(number);
        }
    }
}
void Matrix::random_matrix() {
    for(int i = 0; i < order; ++i){
        for(int j = 0; j < order; ++j){
            matrix_array[i][j].set_num(rand()%6+1);
            matrix_array[i][j].set_den(rand()%6+1);
            matrix_array[i][j].simplify();
        }
    }
}


int Matrix::get_order(){
    return order;
}
void Matrix::set_determinant(rational det){
    this->det = det;
}

std::vector<std::vector<rational>>& Matrix::get_matrix(){
    return matrix_array;
}
bool Matrix::full_of_zeroes(std::vector<std::vector<rational>> &matrix){

    int count = 0;
    for(int i = 0; i < order; i++){
        for(int j = 0; j < order; j++){
            if(matrix[i][j].get_num() == 0) count++;
        }
    }
    if(count == pow(order, 2)) return true;
    return false;

}

QString Matrix::mat_to_str(){

    QString str("");
    for(int i = 0; i < order; i++){
        for(int j = 0; j < order; j++){
            str << matrix_array[i][j];
            str = str + "\t" + "\t";
        }
        str = str + "\n" + "\n" + "\n";
    }
    return str;

}
QString Matrix::det_to_str(){
    if(det.get_num() == 0) return "0";
    else if(det.get_num() == det.get_den()) return QString().setNum(det.get_num());
    else return QString().setNum(det.get_num()) + "/" + QString().setNum(det.get_den());
}

rational Matrix::determinant(){

    if(matrix_array.empty()) return TRational(0, 1);
    det = matrix_array[0][0]*matrix_array[1][1]*matrix_array[2][2]+
          matrix_array[0][1]*matrix_array[1][2]*matrix_array[2][0]+
          matrix_array[0][2]*matrix_array[1][0]*matrix_array[2][1]-
          matrix_array[0][2]*matrix_array[1][1]*matrix_array[2][0]-
          matrix_array[0][0]*matrix_array[1][2]*matrix_array[2][1]-
          matrix_array[0][1]*matrix_array[1][0]*matrix_array[2][2];
    det.simplify();
    det.change_sign();
    return det;

}
void Matrix::transpose(){

    if(!matrix_array.empty()){
        rational **temp = new rational *[order];
        for(int i = 0; i < order; i++) temp[i] = new rational[order];
        for(int j = 0; j < order; j++){
            for(int k = 0; k < order; k++) temp[j][k] = matrix_array[j][k];
        }

        for(int j = 0; j < order; j++){
            for(int k = 0; k < order; k++) matrix_array[j][k] = temp[k][j];
        }

        for(int i = 0; i < order; i++) delete []temp[i];
    }
    else std::cout << "Matrix is empty. Transposition is impossible" << '\n' << "\n";

}
int Matrix::rank(){

    if(matrix_array.empty()) return 0;

    int rank_value = 0;

    rational m1 = matrix_array[0][1]*matrix_array[1][2] - matrix_array[0][2]*matrix_array[1][1];
    rational m2 = matrix_array[0][0]*matrix_array[1][2] - matrix_array[0][2]*matrix_array[1][0];
    rational m3 = matrix_array[0][0]*matrix_array[1][1] - matrix_array[0][1]*matrix_array[1][0];
    rational m4 = matrix_array[1][1]*matrix_array[2][2] - matrix_array[1][2]*matrix_array[2][1];
    rational m5 = matrix_array[0][0]*matrix_array[2][2] - matrix_array[0][2]*matrix_array[2][0];
    rational m6 = matrix_array[0][0]*matrix_array[2][1] - matrix_array[0][1]*matrix_array[2][0];
    rational m7 = matrix_array[1][1]*matrix_array[2][2] - matrix_array[1][2]*matrix_array[2][1];
    rational m8 = matrix_array[1][0]*matrix_array[2][2] - matrix_array[1][2]*matrix_array[2][0];
    rational m9 = matrix_array[1][0]*matrix_array[2][1] - matrix_array[1][1]*matrix_array[2][0];

    bool some_zero_minors = m1.get_num() != 0 || m2.get_num() != 0 || m3.get_num() != 0 ||
            m4.get_num() != 0 || m5.get_num() != 0 || m6.get_num() != 0 ||
            m7.get_num() != 0 || m8.get_num() != 0 || m9.get_num() != 0;

    bool all_zero_minors = m1.get_num() == 0 && m2.get_num() == 0 && m3.get_num() == 0 &&
            m4.get_num() == 0 && m5.get_num() == 0 && m6.get_num() == 0 &&
            m7.get_num() == 0 && m8.get_num() == 0 && m9.get_num() == 0;

    if(full_of_zeroes(matrix_array)) rank_value = 0;

    if(all_zero_minors && !full_of_zeroes(matrix_array)) rank_value = 1;

    if(determinant().get_num() == 0 && some_zero_minors) rank_value = 2;

    if(determinant().get_num() != 0 && some_zero_minors) rank_value = 3;

    return rank_value;

}
