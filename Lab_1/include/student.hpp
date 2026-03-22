#pragma once // avoid multiple callings

#include <istream>
#include <ostream>
#include <string>

using namespace std;

struct MyStudent {
    /* *
     * @brief overload input/output operation (>>, <<)
     *
     * @param out/in
     * @param f
     *
     * @return ostream&/istrem&
     * */
    friend ostream &operator<<(ostream &, const MyStudent &);
    friend istream &operator>>(istream &, MyStudent &);

  private:
    string name;
    double math, literature;
};

/* *
 * @brief validate name
 *
 * @param name
 *
 * name MUST NOT include any number or specical character
 * each character MUST BE one in range 'a-z' OR 'A-Z' OR blank space
 *
 * @return bool true: valid name, false: otherwise
 * */
bool isNameValid(string name);

/* *
 * @brief validate score
 *
 * @param s
 *
 * score MUST be in range 0-10
 *
 * @return bool true: valid score, false: otherwise
 * */
bool isScoreValid(double s);
