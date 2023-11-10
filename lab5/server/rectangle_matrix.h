#ifndef RECTANGLEMATRIX_H
#define RECTANGLEMATRIX_H

#define DEFAULT_ORDER 3

#include <vector>
#include "number.h"

class RectangleMatrix{
protected:
    int rows, columns;
    std::vector<std::vector<rational>> matrix_array;
public:
    RectangleMatrix();
    void clear_matrix();
    std::vector<std::vector<rational>>& get_matrix();
    void transpose();
    void swapRows(int row1, int row2);
    int rank();
};

#endif // RECTANGLEMATRIX_H
