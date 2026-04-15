add_library(NgayThangNam)
add_library(PhanSo)
add_library(SoPhuc)
add_library(GioPhutGiay)


target_sources(NgayThangNam
    PRIVATE
        ../src/NgayThangNam.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            NgayThangNam.hpp
)

target_sources(PhanSo
    PRIVATE
        ../src/PhanSo.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            PhanSo.hpp
)

target_sources(SoPhuc
    PRIVATE
        ../src/SoPhuc.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            SoPhuc.hpp
)

target_sources(GioPhutGiay
    PRIVATE
        ../src/GioPhutGiay.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
           GioPhutGiay.hpp
)
