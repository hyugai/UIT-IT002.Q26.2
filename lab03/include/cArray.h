class cArray {
    int *mpPhanTu{nullptr}, mN, mMin, mMax;

  public:
    cArray();
    cArray(int, int, int);
    ~cArray();

    void generateMangNgauNhienNPhanTu();
    void nhap();
    void xuat() const;
    void countPhanTuX() const;
    bool isTangDan() const;
    int findPhanTuLeNhoNhat() const;
    int findSoNguyenToLonNhat() const;
    void bubbleSort();
};

bool isPrime(int const &);
