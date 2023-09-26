#include "application.h"

char Application::cmd(){
    switch(getch()){
        case ONE:
            return '1';
        case TWO:
            return '2';
        case THREE:
            return '3';
        case FOUR:
            return '4';
        case FIVE:
            return '5';
        case SIX:
            return '6';
        case ENTER:
            return 'E';
        case ARROW_UP:
            return 'U';
        case ARROW_DOWN:
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
        if(!matrix.get_matrix().empty()) std::cout << matrix;
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
            matrix.default_matrix();
            det.erase(20, 20);
            rank.erase(12, 20);
            enter = false;
        }
        if(option == 1 && enter){
            matrix.get_matrix().clear();
            matrix.user_matrix();
            det.erase(20, 20);
            rank.erase(12, 20);
            system("cls");
            enter = false;
        }
        if(option == 2 && enter){
            system("cls");
            enter = false;
            det.erase(20, 15);
            if(!matrix.get_matrix().empty()) det = det + std::to_string(matrix.determinant().get_real()) +
                    " + " + std::to_string(matrix.determinant().get_imaginary()) + "i ";
            else std::cout << "Matrix is empty. Cannot find determinant" << "\n" << "\n";
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
            if(!matrix.get_matrix().empty()) rank += std::to_string(matrix.rank(matrix.get_matrix()));
            else std::cout << "Matrix is empty. Cannot find rank" << "\n" << "\n";
        }
        if(option == 5 && enter){
            enter = false;
            power_on = false;
        }
    }
}