#pragma once
#include <istream>
#include <string>

using namespace std;

class SoDienThoai {
    string mS;

    bool isValid() const {
        if (mS.length() != 10)
            return false;

        for (char const &c : mS) {
            if (c < '0' || c > '9')
                return false;
        }

        return true;
    }

  public:
    friend istream &operator>>(istream &, SoDienThoai &);
    string getS() const;
};
