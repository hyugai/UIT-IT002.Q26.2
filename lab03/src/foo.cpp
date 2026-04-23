#include <cstdio>
#include <iostream>

using namespace std;

template <typename Func, typename ArrIn, typename ArrOut>
void foo(Func fn, ArrIn &pElements, ArrOut &pRes, int const &size,
         int iResIdx = 0, int i = 0) {
    if (i == size - 1)
        return;

    for (int k{i + 1}; k < size; k++) {
        cout << pElements[i] << ' ' << pElements[k] << endl;
        pRes[iResIdx++] = fn(pElements[i], pElements[k]);
    }

    foo(fn, pElements, pRes, size, ++iResIdx, ++i);
}

int main() {
    int input[]{4, 2, 3, 6};
    int res[10]{};
    foo([&](auto x, auto y) { return x + y; }, input, res, 4);

    return 0;
}
