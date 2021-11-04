#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void create(int* a, const int size, const int Low, const int High);
int sum(int* a, const int n, int& k);


int main() {
    const int n = 20;
    const int low = -20;
    const int hight = 34;

    int s;
    int k = 0;
    int p[n];

    srand((unsigned)time(NULL));

    create(p, n, low, hight);

    cout <<
        " r: ";
    for (int i = 0; i < n; i++) {
        cout << " " << setw(3) << p[i];
    }
    cout << "\n";

    s = sum(p, n, k);

    cout <<
        " r: ";
    for (int i = 0; i < n; i++) {
        cout << " " << setw(3) << p[i];
    }
    cout << "\n";

    cout << "sum =" << setw(4) << s << endl;
    cout << " k = " << setw(2) << k << endl;

}

void create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}


int sum(int* a, const int n, int& k) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] < 0) {
            s += a[i];
            k++;
            a[i] = 0;
        }
    }
    return s;
}
