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
    void set_element(int row, int col, TComplex element);
    //Матрица по умолчанию
    void default_matrix();
    //Матрица, заданная пользователем
    void user_matrix();
    //Проверяет, является ли матрица нулевой
    int get_order();
    bool full_of_zeroes(std::vector<std::vector<rational>>& matrix);
    //Получение доступа к матрице вне методов класса
    std::vector<std::vector<rational>>& get_matrix();
    //Вывод матрицы
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
    friend QString& operator<<(QString& s, Matrix& matrix);
    //Определитель матрицы
    rational determinant();
    //Транспонирование матрицы
    std::vector<std::vector<rational>>& transpose();
    //Поиск ранга матрицы
    int rank(std::vector<std::vector<rational>>& matrix);
};

#endif
