#ifndef OOP_LAB1_APPLICATION_H
#define OOP_LAB1_APPLICATION_H

#include "matrix.h"
#include <conio.h>

#define ONE 49
#define TWO 50
#define THREE 51
#define FOUR 52
#define FIVE 53
#define SIX 54
#define ENTER 13
#define ARROW_UP 72
#define ARROW_DOWN 80

class Application{
public:
    Matrix matrix;
    char cmd();
    void menu();
};

#endif