#include <iostream>
#include <iomanip>

using namespace std;

void f1(int* a, const int size, int& s, int& d) {
    s = 0;
    d = 1;

    int low = 10;
    int high = -10;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0)
            s += a[i];

        if (abs(a[i]) > high)
            high = a[i];
        else {
            if (abs(a[i]) < low)
                low = a[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (a[i] >= low && a[i] <= high)
            d *= a[i];
    }
}

void Sort(int* a, const int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        int max = a[i]; 
        int imax = i; 
        for (int j = i + 1; j < size; j++)
            if (max < a[j])
            {
                max = a[j];
                imax = j;
            }
        if (a[i] % 2 > 0) {
            a[imax] = a[i];
            a[i] = max;
        }
    }
}


void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}


void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}



int main()
{
    int n;
    cout << "n = "; cin >> n;

    int* a = new int[n];
    Create(a, n, -10, 10);
    Print(a, n);

    int s = 0;
    int d = 1;

    f1(a, n, s, d);
    cout << "s = " << s << endl;
    cout << "d = " << d << endl;
    Sort(a, n);
    Print(a, n);

    delete[] a; // Очищення виділеної пам'яті
    return 0;
}
