#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void creat(int* r, const int n, int l, int h);
int sum(int* r, const int n, int i, int s, int& k);

int main() {
	srand((unsigned)time(NULL));

	const int n = 26;
	int r[n];
	int s = 0;
	int k = 0;
	int l = 3;
	int h = 92;

	creat(r, n, l, h);

	for (int i = 0; i < n; i++) {
		cout << setw(3) << r[i] << " ";
	}
	cout << "\n";

	s = sum(r, n, 0, s, k);


	for (int i = 0; i < n; i++) {
		cout << setw(3) << r[i] << " ";
	}
	cout << "\n";
	cout << s << endl << k;
}

void creat(int* r, int n, int l, int h) {
	for (int i = 0; i < n; i++)
		r[i] = l + rand() % (h - l + 1);
}

int sum(int* r, const int n, int i, int s, int& k) {
	if (!(r[i] % 2 != 0) && !(i % 7 == 0) || (i == 0 && !(r[i] % 2 != 0))) {
		s += r[i];
		r[i] = 0;
		k += 1;
	}
	if (i < n - 1) {
		return sum(r, n, i + 1, s, k);
	}
	else {
		return s;
	}
}
