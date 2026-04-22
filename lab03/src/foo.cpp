#include <cstdio>
#include <iostream>

using namespace std;

void output(int a, int b) { printf("(%d;%d)", a, b); }
int sum(int a, int b) { return a + b; }

template <typename F, typename A, typename R>
void genComb(const int &size, F func, A arr, R res, int i = 0) {
    if (i == size - 1) {
        return;
    }

    for (int k{i + 1}; k < size; k++) {
        cout << func(arr[i], arr[k]) << ' ';
        // output(arr[i], arr[k]);
    }
    genComb(size, func, arr, res, ++i);
}

int main() {
    // genComb(5);
    // cout << endl;
    int arr[]{4, 2, 3, 6};
    int res[10]{};

    genComb(4, sum, arr, res);
    cout << endl;

    return 0;
}
