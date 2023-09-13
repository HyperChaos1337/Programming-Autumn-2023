#include "application.h"

char Application::cmd(){
    switch(getch()){
        case 49:
            return '1';
        case 50:
            return '2';
        case 51:
            return '3';
        case 52:
            return '4';
        case 53:
            return '5';
        case 54:
            return '6';
        case 13:
            return 'E';
        case 72:
            return 'U';
        case 80:
            return 'D';
        default:;
    }
    return 0;
}


void Application::menu(){

    std::string det = "Matrix determinant: ";
    std::string rank = "Rank value: ";
    bool power_on = true;
    bool enter = false;
    int option = 0;
    char command;
    while(power_on){
        std::cout << "Matrix: " << '\n' << '\n';
        matrix.print();
        std::cout << '\n' << det << '\n';
        std::cout << rank << '\n' << '\n';
        switch (option) {
            case 0:
                std::cout << "Select option:" << '\n';
                std::cout << "1.Create default matrix <==" << '\n';
                std::cout << "2.Enter matrix from keyboard" << '\n';
                std::cout << "3.Find determinant" << '\n';
                std::cout << "4.Transpose matrix" << '\n';
                std::cout << "5.Find rank" << '\n';
                std::cout << "6.Exit" << '\n';
                break;
            case 1:
                std::cout << "Select option:" << '\n';
                std::cout << "1.Create default matrix" << '\n';
                std::cout << "2.Enter matrix from keyboard <==" << '\n';
                std::cout << "3.Find determinant" << '\n';
                std::cout << "4.Transpose matrix" << '\n';
                std::cout << "5.Find rank" << '\n';
                std::cout << "6.Exit" << '\n';
                break;
            case 2:
                std::cout << "Select option:" << '\n';
                std::cout << "1.Create default matrix" << '\n';
                std::cout << "2.Enter matrix from keyboard" << '\n';
                std::cout << "3.Find determinant <==" << '\n';
                std::cout << "4.Transpose matrix" << '\n';
                std::cout << "5.Find rank" << '\n';
                std::cout << "6.Exit" << '\n';
                break;
            case 3:
                std::cout << "Select option:" << '\n';
                std::cout << "1.Create default matrix" << '\n';
                std::cout << "2.Enter matrix from keyboard" << '\n';
                std::cout << "3.Find determinant" << '\n';
                std::cout << "4.Transpose matrix <==" << '\n';
                std::cout << "5.Find rank" << '\n';
                std::cout << "6.Exit" << '\n';
                break;
            case 4:
                std::cout << "Select option:" << '\n';
                std::cout << "1.Create default matrix" << '\n';
                std::cout << "2.Enter matrix from keyboard" << '\n';
                std::cout << "3.Find determinant" << '\n';
                std::cout << "4.Transpose matrix" << '\n';
                std::cout << "5.Find rank <==" << '\n';
                std::cout << "6.Exit" << '\n';
                break;
            case 5:
                std::cout << "Select option:" << '\n';
                std::cout << "1.Create default matrix" << '\n';
                std::cout << "2.Enter matrix from keyboard" << '\n';
                std::cout << "3.Find determinant" << '\n';
                std::cout << "4.Transpose matrix" << '\n';
                std::cout << "5.Find rank" << '\n';
                std::cout << "6.Exit <==" << '\n';
                break;
        }
        command = cmd();
        switch(command){
            case '1':
                system("cls");
                option = 0;
                break;
            case '2':
                system("cls");
                option = 1;
                break;
            case '3':
                system("cls");
                option = 2;
                break;
            case '4':
                system("cls");
                option = 3;
                break;
            case '5':
                system("cls");
                option = 4;
                break;
            case '6':
                system("cls");
                option = 5;
                break;
            case 'D':
                system("cls");
                option++;
                break;
            case 'U':
                system("cls");
                option--;
                break;
            case 'E':
                system("cls");
                enter = true;
                break;
            default:
                system("cls");
                break;
        }
        if(option > 5) option = 0;
        if(option < 0) option = 5;
        if(option == 0 && enter){
            system("cls");
            matrix.get_matrix().clear();
            matrix.set_determinant(0);
            matrix.default_matrix();
            det.erase(20, 20);
            rank.erase(12, 20);
            enter = false;
        }
        if(option == 1 && enter){
            matrix.get_matrix().clear();
            matrix.set_determinant(0);
            matrix.user_matrix();
            det.erase(20, 20);
            rank.erase(12, 20);
            system("cls");
            enter = false;
        }
        if(option == 2 && enter){
            system("cls");
            enter = false;
            det.erase(20, 10);
            det += std::to_string(matrix.determinant());
        }
        if(option == 3 && enter){
            system("cls");
            enter = false;
            matrix.transpose();
        }
        if(option == 4 && enter){
            system("cls");
            enter = false;
            rank.erase(12, 10);
            rank += std::to_string(matrix.rank(matrix.get_matrix()));
        }
        if(option == 5 && enter){
            enter = false;
            power_on = false;
        }
    }
}