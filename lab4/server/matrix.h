#ifndef OOP_LAB1_MATRIX_H
#define OOP_LAB1_MATRIX_H

#include <vector>
#include <cmath>

#include "number.h"

#define DEFAULT_ORDER 3

class Matrix{
private:

    int order;
    rational det;
    std::vector<std::vector<rational>> matrix_array;

public:

    Matrix();
    Matrix(int order);

    void clear_matrix();
    void random_matrix();

    int get_order();
    void set_determinant(rational det);

    bool full_of_zeroes(std::vector<std::vector<rational>>& matrix);
    std::vector<std::vector<rational>>& get_matrix();

    QString mat_to_str();
    QString det_to_str();

    rational determinant();
    void transpose();
    int rank();

};

#endif
