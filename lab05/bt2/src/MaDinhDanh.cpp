#include "../include/MaDinhDanh.h"
#include <iomanip>
#include <random>
#include <sstream>
#include <string>

void MaDinhDanh::setS(string const &header, int const &n) {
    mS += header;

    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> digitDist(0, n);

    stringstream ss;
    ss << setw(3) << setfill('0') << digitDist(gen);

    mS += ss.str();
}

string MaDinhDanh::getS() const { return mS; }
