

#include <iostream>
using namespace std;
void fill_arr(int arr[], int X) //функция заполнения массива
{
    for (int i = 0; i < X; i++)
    {
        arr[i] = rand() % 10;
        cout << " " << arr[i];
    }
    cout << endl << endl;
}

void sort_arr(int arr[], int X) // функция сортировки массива
{
    for (int i = 0; i < X - 1; i++)
        for (int j = i + 1; j < X; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            
        }
    /*for (int i = 0; i < X; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;*/
}

int main()
{
    setlocale(0, "rus");
    srand(time(0));
    int M,
        N,
        count = 0;
        
    bool Yes_ = 0;

    cout << " How many elements will be in the first array? ";
    cin >> M;
    cout << "\n";

    cout << " How many elements will be in the second array? ";
    cin >> N;
    cout << "\n";

    int* A = new int[M];
    int* B = new int[N];

    fill_arr(A, M); // заполняем массивы А и В
    fill_arr(B, N);

    sort_arr(A, M); //сортируем массив А, чтобы потом получить правильное число элементов в новом массиве

    for (int i = 0; i < M; i++) // находим величину нового массива
    {
        if (A[i] != A[i + 1]) //исключаем повторение значений массива А
        {
            for (int j = 0; j < N; j++)
            {
                if (A[i] != B[j]) //исключаем все одинаковые значения, которые есть и в А, и в В
                {
                    Yes_ = 1;
                }
                else
                {
                    Yes_ = 0;
                    break;
                }
            }
            if (Yes_)
            {
                count++;  // считаем, сколько элементов будет в новом массиве
                //cout << " " << A[i];
            }
        }
    }
    //cout << endl;
    //cout << " " << count << endl;

    int* C = new int[count];

    count = 0;
    for (int i = 0; i < M; i++) // заполняем массив С значениями из А без повторениий и теми значениями, которых нет в В
    {
        if (A[i] != A[i + 1]) //исключаем повторение значений массива А
        {
            for (int j = 0; j < N; j++)
            {
                if (A[i] != B[j]) //исключаем все одинаковые значения, которые есть и в А, и в В
                {
                    Yes_ = 1;
                }
                else
                {
                    Yes_ = 0;
                    break;
                }
            }
            if (Yes_)
            {
                C[count] = A[i]; //присваиваем элеменатам нового массива значения массива А, которых нет в массиве В
                //cout << " " << C[count];
                count++;
               
            }
        }
    }
    //выводим новый массив
    cout << endl;
    cout << " Elements of new array " << "\n\n";
    for (int i = 0; i < count; i++)
    {
        cout << " " << C[i];
    }
    
    cout << "\n\n\n";
   
    delete[] A;
    delete[] B;
    delete[] C;

  } 

    


    





