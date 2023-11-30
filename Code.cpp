#include <fstream>
#include <string>
#include <iostream>

// picture 2

using namespace std;

float line(int x)
{
    float y = 0;
    if (x >= -10 && x < -8)
    {
        y = -3;
    }
    if (x >= -8 && x < -3)
    {
        y = (x + 3) * (0.6);
    }
    if (x >= -3 && x < 3)
    {
        y = sqrt(9 - x * x);
    }
    if (x >= 3 && x <= 5)
    {
        y = x - 3;
    }
    if (x > 5 && x <= 8)
    {
        y = 3;
    }
    return y;
}

float main()
{
    // создаем массив на 19 строк, в каждой строке которого 30 знаков
    const int len = 30, strings = 19; 
    const char ch = '\n';
    char mass[len][strings];
    int x = 0;

    ofstream fout("lab1.txt"); // создание текстового файла

    for (int x = -10; x <= 8; x++) // цикл записи значений "x" и "y" в текстовый файл
    {
        fout << "x = " << x << "   y = " << line(x) << endl; // запись значений в файл
    }
    fout.close(); // закрываем файл


    ifstream fs("lab1.txt", ios::in | ios::binary); // открываем текстовый файл

    if (!fs)
        return 1; // Если ошибка открытия файла, то завершаем программу

    for (int r = 0; r <= 19; r++)
    {
        fs.getline(mass[r], len - 1, ch); // Считываем строки в массив
        cout << mass[r] << endl;          // Выводи строку из массива
    }
    fs.close(); // Закрываем файл
    return 0;
}
