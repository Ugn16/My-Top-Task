//структуры, ввод числа int, определение размера структуры, вывод числа в двоичной системе исчисления
#include <iostream>

using namespace std;

struct Int_number
{
    int any_number;
    void input()
    {
        cout << " Any number, please ";
        cin >> any_number;
        cout << " Ok " << endl;
        cout << "\n\n";
    }
    
    void size_of_struct()
    {
        cout << " Size of my struct " << sizeof(Int_number) << endl;
        cout << "\n\n";
    }
    
    void Double_sistem()
    {
        int arr[10] = {0,0,0,0,0,0,0,0,0,0};
        int i = 0;
        
        do
        {
            if ( any_number % 2 == 0)
            {
                arr[i++] = 0;
                any_number = any_number/2;
                //cout << " " << any_number;
            }
            else
            {
                arr[i++] = 1;
                any_number = any_number/2;
                //cout << " " << any_number;
            }
        } while (any_number !=0);
        
        //cout << "\n\n";
        cout << " Your number in binary notation is ";
        
        
        for (i; i >= 0; i--)
        {
            cout << " " << arr[i];
        }
        cout << "\n\n\n\n\n";
    }
    
};

int main(int argc, const char * argv[]) {
    setlocale(0, "rus");
    
    Int_number My_number;
    
    My_number.input();
    My_number.size_of_struct();
    My_number.Double_sistem();

    return 0;
}
