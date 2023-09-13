#ifndef OOP_LAB1_MATRIX_H
#define OOP_LAB1_MATRIX_H

#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "number.h"

#define DEFAULT_ORDER 3

class Matrix{
private:
    int order;
    number det;
    std::vector<std::vector<number>> matrix_array;
public:
    Matrix();

    //Матрица по умолчанию
    void default_matrix();
    //Матрица, заданная пользователем
    void user_matrix();
    //Проверяет, является ли матрица нулевой
    bool full_of_zeroes(std::vector<std::vector<number>>& matrix);
    //Получение доступа к матрице вне методов класса
    std::vector<std::vector<number>>& get_matrix();
    //Вывод матрицы
    void print();
    //Определитель матрицы
    number determinant();
    void set_determinant(number det);
    //Транспонирование матрицы
    std::vector<std::vector<number>>& transpose();
    //Поиск ранга матрицы
    int rank(std::vector<std::vector<number>>& matrix);
};

#endif