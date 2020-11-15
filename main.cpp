#include <iostream>
using namespace std;

struct PRICE {
    char name[100];
    char shop[100];
    double price;

    void Show() {
        cout << name << " " << shop << " " << price << endl;
    }

    void getEl() {

        cout << "Enter name of item:\n";
        gets_s(name);
        cout << "Enter name of shop:\n";
        gets_s(shop);
        cout << "Enter price of item:\n";
        cin >> price;
        cin.ignore(1, '\n');
    }

};
template< class T >
void Sort(T* arr, int size);

int main() {
    const int size = 8;
    PRICE arr[size];
    char temp[100];
    bool f = false;
    for (int i = 0;i < size;i++)
        arr[i].getEl();
    Sort(arr, size);
    cout << "You've enter array:\n";
    for (int i = 0;i < size;i++)
        arr[i].Show();
    cout << "Enter item name to find:\n";
    gets_s(temp);
    for (int i = 0;i < size;i++) {
        if (!stricmp(temp, arr[i].name)) {
            arr[i].Show();
            f = true;
        }
    }
    if (!f)
        cout << "There's no item with such name\n";
    system("PAUSE");
    return 0;
}

template< class T >
void Sort(T* arr, int size)
{
    T tmp;

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (stricmp(arr[j + 1].name, arr[j].name) < 0)
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
