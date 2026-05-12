# ===== Task 1 =====
add_executable(bt1)
target_sources(bt1 PRIVATE bt1.cpp)
target_link_libraries(bt1 PRIVATE cSoPhuc)

# ===== Task 2 =====
add_executable(bt2)
target_sources(bt2 PRIVATE bt2.cpp)
target_link_libraries(bt2 PRIVATE cPhanSo)

# ===== Task 3 =====
add_executable(bt3)
target_sources(bt3 PRIVATE bt3.cpp)
target_link_libraries(bt3 PRIVATE cTime)

# ===== Task 4 =====
add_executable(bt4)
target_sources(bt4 PRIVATE bt4.cpp)
target_link_libraries(bt4 PRIVATE cDate)

# ===== Task 5 =====
add_executable(bt5)
target_sources(bt5 PRIVATE bt5.cpp)
target_link_libraries(bt5 PRIVATE cDaThuc)

# ===== Task 6 =====
add_executable(bt6)
target_sources(bt6 PRIVATE bt6.cpp)
target_link_libraries(bt6 PRIVATE CVector)

# ===== Task 7 =====
add_executable(bt7)
target_sources(bt7 PRIVATE bt7.cpp)
target_link_libraries(bt7 PRIVATE CMatrix CVector)
