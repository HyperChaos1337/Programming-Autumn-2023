#ifndef OOP_LAB1_MATRIX_H
#define OOP_LAB1_MATRIX_H

#include <vector>
#include <cmath>

#include "number.h"

#define DEFAULT_ORDER 3

class Matrix{
private:
    int order;
    complex det;
    std::vector<std::vector<complex>> matrix_array;
public:
    Matrix();

    //Матрица по умолчанию
    void default_matrix();
    //Матрица, заданная пользователем
    void user_matrix();
    //Проверяет, является ли матрица нулевой
    bool full_of_zeroes(std::vector<std::vector<complex>>& matrix);
    //Получение доступа к матрице вне методов класса
    std::vector<std::vector<complex>>& get_matrix();
    //Вывод матрицы
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
    //Определитель матрицы
    complex determinant();
    //Транспонирование матрицы
    std::vector<std::vector<complex>>& transpose();
    //Поиск ранга матрицы
    int rank(std::vector<std::vector<complex>>& matrix);
};

#endif