# ===== Task 1 ===== 
add_library(cDiem)
target_sources(cDiem
    PRIVATE
        ../src/cDiem.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cDiem.h
)

add_library(cDuongThang)
target_sources(cDuongThang
    PRIVATE
        ../src/cDuongThang.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cDuongThang.h
)

add_library(cTamGiac)
target_sources(cTamGiac
    PRIVATE
        ../src/cTamGiac.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cTamGiac.h
)

# ===== Task 4 ===== 
add_library(cArray)
target_sources(cArray
    PRIVATE
        ../src/cArray.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cArray.h
)

# ===== Task 5 ===== 
add_library(cSoHang)
target_sources(cSoHang
    PRIVATE
        ../src/cSoHang.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cSoHang.h
)

add_library(cDaThuc)
target_sources(cDaThuc
    PRIVATE
        ../src/cDaThuc.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cDaThuc.h
)

# ===== Task 8 ===== 
add_library(cNgayThangNam)
target_sources(cNgayThangNam
    PRIVATE
        ../src/cNgayThangNam.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cNgayThangNam.h
)
add_library(cNhanVienSX)
target_sources(cNhanVienSX
    PRIVATE
        ../src/cNhanVienSX.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cNhanVienSX.h
)

add_library(cListNhanVienSX)
target_sources(cListNhanVienSX
    PRIVATE
        ../src/cListNhanVienSX.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cListNhanVienSX.h
)
