#pragma once
#include <cctype>
#include <istream>
#include <string>

using namespace std;

class Email {
    string mS;

    bool isValid() const {
        for (char const &c : mS) {
            if (!(isalnum(c) || c == '.' || c == '_' || c == '@'))
                return false;
        }

        return true;
    }

  public:
    friend istream &operator>>(istream &, Email &);
    string getS() const;
};
