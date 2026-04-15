add_library(Fraction)
add_library(Date)
add_library(Student)

target_sources(Fraction
    PRIVATE
        ../src/fraction.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            fraction.hpp
)
target_sources(Date
    PRIVATE
        ../src/date.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            date.hpp
)
target_sources(Student
    PRIVATE
        ../src/student.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            student.hpp
)
