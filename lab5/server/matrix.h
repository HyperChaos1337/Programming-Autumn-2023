#include <vector>
#include <cmath>

#include "rectangle_matrix.h"

class Matrix: public RectangleMatrix{
private:
    int order;
public:

    Matrix();
    Matrix(int order);
    int get_order();
    rational determinant();

};
