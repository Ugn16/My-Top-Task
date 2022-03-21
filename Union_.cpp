// Создайте объединение, состоящее из целого числа и массива символов. Напишите следующие функции: 
//■ Ввести целое число;
//■ Просмотреть все байты числа;
//■ Просмотреть выбранный байт числа;
//■ Вывод байтов числа в двоичном и шестнадцатеричном виде.
//

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

union Int_Char //функция ввода числа
{
    int number;
    char sign[5] = {'a', 'v', 'f', 'h', 's'};

    void input()
    {
        cout << " Input any number ";
        cin >> number;
    }

    void binary() //функция вывода числа в двоичном формате, все байты
    {
        int b = 31, i = 0;
        int temp[32] = { 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 };
        do
        {
            temp[i] = number % 2;
            number /= 2;
            i++;
        } while (number);

        for (int j = 0; j < i ; j++)
        {

            swap(temp[j], temp[b]);
            b--;
        }

        for (int j = 0; j < 32; j++)
        {
            if (j % 8 == 0) cout << " ";
            cout << temp[j];
        }
            cout << "\n"; 
    }

    void hexadecimal() //функция вывода числа в шестнадцатиричном формате, все байты
    {
        int b = 7, i = 0;
        int tmp;
        char temp[8] = {'0','0', '0','0', '0','0', '0','0' };
        do{
            tmp = number % 16;
            if (tmp == 10) temp[i] = 'A';
            if (tmp == 11) temp[i] = 'B';
            if (tmp == 12) temp[i] = 'C';
            if (tmp == 13) temp[i] = 'D';
            if (tmp == 14) temp[i] = 'E';
            if (tmp == 15) temp[i] = 'F';
            if (tmp >= 0 && tmp <= 9) temp[i] = tmp + '0';
            
            number /= 16;
            i++;
        } while (number);

        for (int j = 0; j < i; j++)
        {
            swap(temp[j], temp[b]);
            b--;
        }

        for (int j = 0; j < 8; j++)
        {
            if (j % 2 == 0) cout << " ";
            cout << temp[j];
        }

        cout << "\n";
    }

    void number_bytes() //данная функция не используется в программе
    {
        cout << " " << sizeof(number) << "bytes " << endl;

        cout << bitset<sizeof(number)*CHAR_BIT>(number) << endl; //вариант вывода числа в двоичном формате, все байты

        printf("%x", number);//вариант вывода числа в 16-м формате, все байты
    }

    void selected_byte_binary() //функция вывода выбранного байта числа в двоичном формате
    {
        int b = 31,
            i = 0,
            byte;
        int temp[32] = { 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 };

        do{
            temp[i] = number % 2;
            number /= 2;
            i++;
        } while (number);

        cout << endl;
        for (int j = 0; j < i; j++)
        {

            swap(temp[j], temp[b]);
            b--;
        }
        cout << " Select byte (from 0 to 3) "; 
        cin >> byte;
        cout << " ";
        for (int j = 0; j < 32; j++)
        {
            if (j / 8 != abs(byte - 3)) continue;
            else cout << temp[j];
        }
        cout << "\n";
    }

    void selected_byte_hexadecimal() //функция вывода выбранного байта числа в шестнадцатиричном формате
    {
        int b = 7, 
            i = 0, 
            byte;
        int tmp;
        char temp[8] = { '0','0',  '0','0',  '0','0',  '0','0' };
        do {
            tmp = number % 16;
            if (tmp == 10) temp[i] = 'A';
            if (tmp == 11) temp[i] = 'B';
            if (tmp == 12) temp[i] = 'C';
            if (tmp == 13) temp[i] = 'D';
            if (tmp == 14) temp[i] = 'E';
            if (tmp == 15) temp[i] = 'F';
            if (tmp >= 0 && tmp <= 9) temp[i] = tmp + '0';

            number /= 16;
            i++;
        } while (number);


        cout << endl;
        for (int j = 0; j < i; j++)
        {

            swap(temp[j], temp[b]);
            b--;
        }

        cout << " Select byte (from 0 to 3) ";
        cin >> byte;
        cout << " ";
        for (int j = 0; j < 32; j++)
        {
            if (j / 2 != abs(byte - 3)) continue;
            else cout << temp[j];
        }
        cout << "\n";
    }
};

int main()
{
    int choice;
    Int_Char My_data;
    
    do {
        cout << "\n",
        cout << " 1 - Enter an integer and view all bytes of this number in binary form " << endl;
        cout << " 2 - Enter an integer and view all bytes of this number in hexadecimal form " << endl;
        cout << " 3 - Enter an integer and View the selected byte of the number in binary form " << endl;
        cout << " 4 - Enter an integer and View the selected byte of the number in hexadecimal form " << endl;
        cout << " 5 - Exit " << endl;
        cout << " ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            My_data.input();
            My_data.binary();
            break;

        case 2:
            My_data.input();
            My_data.hexadecimal();
            break;

        case 3:
            My_data.input();
            My_data.selected_byte_binary();
            break;

        case 4:
            My_data.input();
            My_data.selected_byte_hexadecimal();
            break;

        case 5:

        default:
            break;
        }
        cout << "\n";
    } while (choice != 5);
}

