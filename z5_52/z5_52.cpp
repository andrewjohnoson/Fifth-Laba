#include <iostream>

int main()
{
    int a[8][8], b[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            a[i][j] = 8 - (i - j) + j;
        }
    }

    std::cout << "Матрица А: \n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            b[i][j] = a[j][i];
        }
    }

    std::cout << "\nТранспонированная матрица А: \n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nЭлементы главной диагонали: \n";
    for (int i = 0; i < 8; i++) {
        std::cout << a[i][i] << " ";
    }
    return 0;
}