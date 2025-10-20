#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

int main()
{
    std::string input;
    int n;
    while (1) {
        bool isDigit = true;
        getline(std::cin, input);
        for (char c : input) {
            if (!std::isdigit(c)) {
                isDigit = false;
                break;
            }
        }

        if (!isDigit) {
            std::cout << "Некорректный ввод.\n";
            continue;
        } else {
            try {
                int n = std::stoi(input);
            } catch (const std::out_of_range&) {
                std::cout << "Число не входит в диапазон.\n";
            }
        }
    }

    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    int proizv[n];
    for (int i = 0; i < n; i++) {
        proizv[i] = 1;
        for (int j = 0; j < n; j++) {
            a[i][j] < 0 ? proizv[i] = -1 : proizv[i] *= a[i][j];
        }
    }

    int amax1 = -999999999, amax2 = -999999999;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            sum1 += a[i + j][j];
            sum2 += a[j][j + i];
            
            std::cout << a[i + j][j] << " " << a[j][j + i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}