add_library(Fraction)

target_sources(Fraction
    PRIVATE
        ../src/fraction.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            fraction.hpp
)
