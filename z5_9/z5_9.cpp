#include <iostream>
#include <cctype>
#include <ctime>
#include <cstdlib>

int main()
{
    setlocale(LC_ALL, "rus");

    std::cout << "Введите размер квадратной матрицы (натуральное число):\n";
    int n;
    
    while (!(std::cin >> n) || std::cin.peek() != '\n' || n <= 0) {
        std::cout << "Некорректный ввод данных.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    srand(time(0));
    int a[n][n];
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    } */

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 40 - 10;
        }
    }

    
    std::cout << "Ваш массив: \n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }

   long proizv[n];
   for (int i = 0; i < n; i++) {
       proizv[i] = 1;
       for (int j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                proizv[i] = -1;
                break;
            } else {
                proizv[i] *= a[i][j];
            }
           
        }
    }

    std::cout << "Произведение элементов в строках, где нету отрицательного элемента:\n";
    int negative = 0;
    for (int i = 0; i < n; i++) {
        if (proizv[i] >= 0) {
            std::cout << proizv[i] << " ";
        } else {
            negative++;
        }
    }

    if (negative == n) {
        std::cout << "Во всех строках есть отрицательные числа.\n";
    }
    std::cout << "\n";

    int amax1 = a[0][0], amax2 = a[n - 1][n - 1], dmax = 0;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            sum1 += a[i + j][j];
            sum2 += a[j][j + i];
            
            //std::cout << a[i + j][j] << " " << a[j][j + i] << " ";
        }
        int temp = std::max(sum1, sum2);
        if (temp > dmax) {
            dmax = temp;
        }
        //std::cout << "\n";
    }

    std::cout << "Максимум среди сумм элементов диагоналей параллельных главной: " << dmax;

    return 0;
}