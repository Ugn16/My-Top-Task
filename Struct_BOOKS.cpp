

#include <iostream>
using namespace std;

struct Library //создание структуры
{
    char title;
    char author;
    char Publisher;
    char genre;
   
    void display() //печать всех книг
    {
        cout << " The Title of the book " << title << endl;
        cout << " The author of the book " << author << endl;
        cout << " The Publisher of the book " << Publisher << endl;
        cout << " The genre of the book " << genre << endl;
        cout << endl;
    }
};

void reduct(Library a[]) //редактирование
{
    int i;
    cout << " What BOOK do you want to reduct? ";
    cin >> i;
    i--;
    cout << " What is the title of the BOOK? ";
    cin >> a[i].title;
    cout << " What the author of the BOOK? ";
    cin >> a[i].author;
    cout << " What the Publisher of the BOOK? ";
    cin >> a[i].Publisher;
    cout << " What the genre of the BOOK? ";
    cin >> a[i].genre;
    cout << "\n\n";

    cout << " New BOOK " << i + 1 << " data " << endl;
    cout << " The title " << a[i].title << endl;
    cout << " The author " << a[i].author << endl;
    cout << " The publsher " << a[i].Publisher << endl;
    cout << " The genre " << a[i].genre << endl;
    cout << "\n\n";

}

//сортировка по названию

void Sort_title(Library a[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (a[i].title > a[j].title)
            {
                swap(a[i].title, a[j].title);

            }
        }
    }
}

//сортировка по автору
void Sort_author(Library a[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (a[i].author > a[j].author)
            {
                swap(a[i].author, a[j].author);

            }
        }       
    }
}

//сортировка по издательству

void Sort_Publisher(Library a[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (a[i].Publisher > a[j].Publisher)
            {
                swap(a[i].Publisher, a[j].Publisher);

            }
        }
    }
}



int main()
{
    setlocale(0, "rus");
    Library book[4] = {   'f', 'f', 'f', 'f', 'l', 'l', 'l', 'l', 'z', 'z', 'z', 'z', 'a', 'a', 'a', 'a' };
    char find;
    int choice;

    for (int i = 0; i < 4; i++)
    {
        cout << " BOOK " << i + 1 << endl;
        book[i].display();
    }
    
    do
    {
        cout << endl;
        cout << " 1 - Edit BOOK data " << endl;
        cout << " 2 - Print all BOOKs " << endl;
        cout << " 3 - Search for BOOKs by author " << endl;
        cout << " 4 - Search for a BOOK by title " << endl;
        cout << " 5 - Sorting the array by BOOK name " << endl;
        cout << " 6 - Sorting the array by author " << endl;
        cout << " 7 - Sorting the array by Publisher " << endl;
        cout << " 8 - Exit " << endl;
        cout << " ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            reduct(book);
            break;

        case 2:
            for (int i = 0; i < 4; i++)
            {
                book[i].display();
            }
            break;

        case 3:
            cout << " What author? ";
            cin >> find;
            cout << find << endl;
            for (int i = 0; i < 4; i++)
            {
                if (book[i].author == find)
                {
                    cout << book[i].title << " " << book[i].Publisher << " " << book[i].genre << endl;
                }
            }
            break;

        case 4:
            cout << " What title? ";
            cin >> find;
            for (int i = 0; i < 4; i++)
            {
                if (find == book[i].title)
                {
                    cout << book[i].author << " " << book[i].Publisher << " " << book[i].genre << endl;
                }
            }

            break;

        case 5:
            Sort_title(book);
            for (int i = 0; i < 4; i++) book[i].display();
            break;

        case 6:
            Sort_author(book);
            for (int i = 0; i < 4; i++) book[i].display();
            break;

        case 7:
            Sort_Publisher(book);
            for (int i = 0; i < 4; i++) book[i].display();
            break;

        case 8:
            cout << " See you ";
            cout << "\n\n\n";

        default:
            break;
        }
    } while (choice != 8);
    

    return 0;
}