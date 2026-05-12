# ===== Task 1 ===== 
add_library(cSoPhuc)
target_sources(cSoPhuc
    PRIVATE
        ../src/cSoPhuc.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cSoPhuc.h
)

# ===== Task 2 ===== 
add_library(cPhanSo)
target_sources(cPhanSo
    PRIVATE
        ../src/cPhanSo.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cPhanSo.h
)

# ===== Task 3 ===== 
add_library(cTime)
target_sources(cTime
    PRIVATE
        ../src/cTime.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cTime.h
)

# ===== Task 4 ===== 
add_library(cDate)
target_sources(cDate
    PRIVATE
        ../src/cDate.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cDate.h
)

# ===== Task 5 ===== 
add_library(cDaThuc)
target_sources(cDaThuc
    PRIVATE
        ../src/cDaThuc.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            cDaThuc.h
)

# ===== Task 6 ===== 
add_library(CVector)
target_sources(CVector
    PRIVATE
        ../src/CVector.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            CVector.h
)

# ===== Task 7 ===== 
add_library(CMatrix)
target_sources(CMatrix
    PRIVATE
        ../src/CMatrix.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            CMatrix.h
)
