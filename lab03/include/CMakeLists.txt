# ===== Task 1 ===== 
add_library(line)
target_sources(line
    PRIVATE
        ../src/line.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            line.hpp
)

add_library(point)
target_sources(point
    PRIVATE
        ../src/point.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            point.hpp
)

add_library(triangle)
target_sources(triangle
    PRIVATE
        ../src/triangle.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            triangle.hpp
)

# ===== Task 2 ===== 
# ===== Task 3 ===== 
# ===== Task 4 ===== 
# ===== Task 5 ===== 
# ===== Task 6 ===== 
# ===== Task 7 ===== 
# ===== Task 8 ===== 
