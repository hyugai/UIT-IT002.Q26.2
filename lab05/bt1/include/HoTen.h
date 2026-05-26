#pragma once
#include <cctype>
#include <string>
// #include <iostream>

using namespace std;

class HoTen {
    string mS;

    /* *
     * @brief Kiểm tên nhập vào có hợp lệ
     * @param void
     * @return bool
     * */
    bool isTenHopLe() const {
        // tên bỏ trống
        if (mS.empty())
            return false;

        // cout << 1 << endl;
        //  Khoảng trắng đầu và cuối
        if (mS.front() == ' ' || mS.back() == ' ')
            return false;

        // cout << 2 << endl;
        for (int i{0}; i < mS.length(); ++i) {
            char const &c{mS[i]};

            // Không phải chữ cái hay khoảng trắng
            if (!isalpha(c) && c != ' ')
                return false;

            // cout << 3 << endl;
            //  Giữa các từ có nhiều hơn 1 khoảng trắng
            if (c == ' ' && mS[i + 1] == ' ')
                return false;

            // cout << 4 << endl;
            //  Chữ cái đầu mỗi từ có phải chữ hoa không
            if (i == 0 || mS[i - 1] == ' ') {
                if (!isupper(mS[i]))
                    return false;
            }
        }

        return true;
    }

  public:
    string getS() const;
    friend istream &operator>>(istream &, HoTen &);
};
