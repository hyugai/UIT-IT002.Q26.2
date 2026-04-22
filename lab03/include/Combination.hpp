struct Combination {
    Combination();
    Combination(int const &, int const &);
    Combination(Combination const &);

    int getN();
    int getR();
    void setN(int const &);
    void setR(int const &);

    void getPairs(int[][2]);
    int countPairs();

  private:
    int n, r;
};
