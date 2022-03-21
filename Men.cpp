//Описать структуру Man (Фамилия, Имя, Возраст, Дата рождения). Создать массив, предусмотреть: 
//■ Вывод информации с сортировкой по фамилии или имени;
//■ Вывод списка именинников месяца с указанием даты рождения;
//■ Изменение размеров массива при добавлении и удалении записей;
//■ Поиск по фамилии и имени;
//■ Редактирование записи.

#include <iostream>
#include <string>
using namespace std;

struct Man
{
    struct Data_of_birth 
    {
        int month;
        int day;
        int year;
    };

    struct Full_Name
    {
        string Second_Name;
        string First_Name;
    };
    
    Full_Name Name;
    int Age;
    Data_of_birth Birthday;

    void display_Man() //вывод имени, фамилии, возраста, дня, месяца, года рождения
    {
        cout << " " << Name.First_Name;
        cout << " " << Name.Second_Name;
        cout << "\t " << Age;
        cout << "\t" << Birthday.day;
        cout << "." << Birthday.month;
        cout << "." << Birthday.year << endl;
        cout << "\n";
    }
 };

void sort_first_name(Man b[], int size) //сортировка списка по имени 
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (b[i].Name.First_Name[0] > b[j].Name.First_Name[0])
                swap(b[i], b[j]);
        }
    }
}

void sort_last_name(Man b[], int size) //сортировка списка по фамилии
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (b[i].Name.Second_Name[0] > b[j].Name.Second_Name[0])
                swap(b[i], b[j]);
        }
    }
}

void birthday_man(Man b[], int size, int month) //именинник месяца - вывода списка
{
    bool result = 1;
    for (int i = 0; i < size; i++)
    {
        if (month == b[i].Birthday.month)
        {
            result = 0;
            cout << " " << b[i].Birthday.day << "." << b[i].Birthday.month << "." << b[i].Birthday.year
                << "\t" << b[i].Name.First_Name << " " << b[i].Name.Second_Name;
        }
    }   
    cout << "\n";
    if (result) cout << " No one ";
    cout << "\n";
}


void add_new_name(Man *&new_list, int& size) //добавление человека в список
{
    Man* new_arr = new Man[size];
    for (int i = 0; i < size-1 ; i++)
    {
        new_arr[i] = new_list[i];
    }

    cout << " The first name of new man "; cin >> new_arr[size-1].Name.First_Name;
    cout << " The second name of new man "; cin >> new_arr[size-1].Name.Second_Name;
    cout << " The age of new man "; cin >> new_arr[size-1].Age;
    cout << " The birth day of new man "; cin >> new_arr[size - 1].Birthday.day;
    cout << " The birth month of new man "; cin >> new_arr[size-1].Birthday.month;
    cout << " The birth year of new man "; cin >> new_arr[size-1].Birthday.year;
    cout << "\n";
    delete[] new_list;
    new_list = new_arr;

}

void remove_item(Man *&new_list, int& size) //удаление человека из списка
{
    cout << " Which line do you want to delete? ";
    int line;
    cin >> line;
    line--;
    Man* new_arr = new Man[size];
    for (int i = 0; i < size; i++)
    {
        if (i != line) new_arr[i] = new_list[i];
        else new_arr[i] = new_list[size];
    }
    cout << "\n";
    delete[] new_list;
    new_list = new_arr;

}

void find_by_name(Man b[], int size, string name) //поиск человека по имени 
{
    bool result = 1;
    for (int i = 0; i < size; i++)
    {
        if (name == b[i].Name.First_Name)
        {
            result = 0;
            cout << " " << b[i].Name.First_Name;
            cout << " " << b[i].Name.Second_Name;
            cout << "\t " << b[i].Age;
            cout << "\t" << b[i].Birthday.day;
            cout << "." << b[i].Birthday.month;
            cout << "." << b[i].Birthday.year << endl;
        } 
    }
    if (result) cout << " Sorry, there is not this name on the list ";
    cout << "\n\n";
}

void find_by_last_name(Man b[], int size, string name) //поиск человека по фамилии
{
    bool result = 1;
    for (int i = 0; i < size; i++)
    {
        if (name == b[i].Name.Second_Name)
        {
            result = 0;
            cout << " " << b[i].Name.First_Name;
            cout << " " << b[i].Name.Second_Name;
            cout << "\t " << b[i].Age;
            cout << "\t" << b[i].Birthday.day;
            cout << "." << b[i].Birthday.month;
            cout << "." << b[i].Birthday.year << endl;
        }
    }
    if (result) cout << " Sorry, there is not this last name on the list ";
    cout << "\n\n";
}

void reduct_item(Man b[], int item) //редактирование данных
{
    
    cout << " The name of new man "; cin >> b[item].Name.First_Name;
    cout << " The last name of new man "; cin >> b[item].Name.Second_Name;
    cout << " The age of new man "; cin >> b[item].Age;
    cout << " The birth month of new man "; cin >> b[item].Birthday.month;
    cout << " The birth day of new man "; cin >> b[item].Birthday.day;
    cout << " The birth year of new man "; cin >> b[item].Birthday.year;
    cout << "\n\n";
}

int main()
{
    int const size = 3;
    int i = 0, month, choice, new_size;
    string name;
    Man first_list[size] = {{{"Wesley", "John"}, 32, {8, 15, 1990}},
                      {{"Scott", "William"}, 22, {8, 5, 2000}},
                      {{"Lewis", "Adam"}, 17, {8, 25, 2005}}};
    
    new_size = size;
    Man* new_list = new Man[new_size];
    for (int i = 0; i < size; i++)
    {
        new_list[i] = first_list[i];
    }
    cout << "\n\n";
    for (int i = 0; i < size; i++)
    {
        new_list[i].display_Man();
    }
    cout << "\n\n";
    do
    {
        cout << " Select a menu item " << endl;
        cout << " 1 - List output " << endl;
        cout << " 2 - Sorting by name " << endl;
        cout << " 3 - Sorting by last name " << endl;
        cout << " 4 - List of birthday people " << endl;
        cout << " 5 - Add a person to the list " << endl;
        cout << " 6 - Remove a person from the list " << endl;
        cout << " 7 - Find a person by name " << endl;
        cout << " 8 - Find a person by last name " << endl;
        cout << " 9 - Edit Data " << endl;
        cout << " 0 - Exit " << endl;
        cout << " ";
        cin >> choice;
    
        switch (choice)
        {
        case 1: // List output

            for (int i = 0; i < new_size; i++)
            {
                new_list[i].display_Man();
            }
            cout << "\n";
            break;

        case 2: // sorting by name
            sort_first_name(new_list, new_size);
            for (int i = 0; i < new_size; i++)
            {
                new_list[i].display_Man();
            }
            cout << "\n";
            break;

        case 3: // sorting by last_name
            sort_last_name(new_list, new_size);
            for (int i = 0; i < new_size; i++)
            {
                new_list[i].display_Man();
            }
            cout << "\n";
            break;

        case 4: //List of birthday people

            cout << " What montn of man birthday do want? ";
            cin >> month;
            birthday_man(new_list, new_size, month);
            cout << "\n";
            break;

        case 5: //Add a person to the list
           
            new_size++;
            add_new_name(new_list, new_size);
            break;

        case 6: //remove a person
            new_size--;
            remove_item(new_list, new_size);
            break;

        case 7: // find by name
            cout << " Whose data are you looking for by name? "; 
            cin >> name;
            cout << "\n";
            find_by_name(new_list, new_size, name);
            break;

        case 8: // find by last name
            cout << " Whose data are you looking for by last name? ";
            cin >> name;
            cout << "\n";
            find_by_last_name(new_list, new_size, name);
            break;

        case 9: // reducting 
            cout << " Which item do you want to reduct? ";
            int item;
            //string anything;
            cin >> item;
            item--;
            reduct_item(new_list, item);
            break;

        case 0:

        default:
            break;
        }

    } while (choice != 0);
    
    cout << "\n\n\n";
    delete[] new_list;
    
}

