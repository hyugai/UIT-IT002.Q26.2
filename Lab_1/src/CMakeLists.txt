add_executable(BT1)
add_executable(BT2)
add_executable(BT3)
#add_executable(BT4)
#add_executable(BT5)

target_sources(BT1 PRIVATE BT1.cpp)
target_link_libraries(BT1 PRIVATE Fraction)

target_sources(BT2 PRIVATE BT2.cpp)
target_link_libraries(BT2 PRIVATE Fraction)

target_sources(BT3 PRIVATE BT3.cpp)
target_link_libraries(BT3 PRIVATE Fraction)
