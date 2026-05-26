#pragma once
#include <string>

using namespace std;

class MaDinhDanh {
    string mMa;

  public:
    void setMa(string const &, int const & = 999);
    string getMa() const;
};
