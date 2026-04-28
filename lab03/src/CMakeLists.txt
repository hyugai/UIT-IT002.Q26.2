# ===== Task 1 =====
add_executable(BT1)
target_sources(BT1 PRIVATE BT1.cpp)
target_link_libraries(BT1 PRIVATE cTamGiac cDiem cDuongThang)

# ===== Task 2 =====
add_executable(BT2)
target_sources(BT2 PRIVATE BT2.cpp)
target_link_libraries(BT2 PRIVATE cDaGiac cDiem cDuongThang)

# ===== Task 4 =====
add_executable(BT4)
target_sources(BT4 PRIVATE BT4.cpp)
target_link_libraries(BT4 PRIVATE cArray)

# ===== Task 5 =====
add_executable(BT5)
target_sources(BT5 PRIVATE BT5.cpp)
target_link_libraries(BT5 PRIVATE cDaThuc cSoHang)

# ===== Task 8 =====
add_executable(BT8)
target_sources(BT8 PRIVATE BT8.cpp)
target_link_libraries(BT8 PRIVATE cNgayThangNam cNhanVienSX cListNhanVienSX)
