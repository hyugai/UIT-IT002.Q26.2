# ===== Task 1 =====
add_executable(BT1)
target_sources(BT1 PRIVATE BT1.cpp)
target_link_libraries(BT1 PRIVATE cTamGiac cDiem cDuongThang)

# ===== Task 4 =====
add_executable(BT2)
target_sources(BT2 PRIVATE BT2.cpp)
target_link_libraries(BT2 PRIVATE cArray)

# ===== Task 5 =====
add_executable(BT5)
target_sources(BT5 PRIVATE BT5.cpp)
target_link_libraries(BT5 PRIVATE cDaThuc cSoHang)
