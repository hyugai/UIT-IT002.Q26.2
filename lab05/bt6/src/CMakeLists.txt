file(GLOB SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
add_library(bt6Lib)
target_sources(bt6Lib PRIVATE ${SRC_FILES})

target_link_libraries(bt6Lib PUBLIC bt6Headers)
