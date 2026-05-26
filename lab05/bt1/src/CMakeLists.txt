file(GLOB SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
add_library(bt1Lib)
target_sources(bt1Lib PRIVATE ${SRC_FILES})

target_link_libraries(bt1Lib PUBLIC bt1Headers)
