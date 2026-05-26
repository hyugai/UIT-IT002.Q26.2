file(GLOB SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
add_library(bt2Lib)
target_sources(bt2Lib PRIVATE ${SRC_FILES})

target_link_libraries(bt2Lib PUBLIC bt2Headers)
