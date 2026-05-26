file(GLOB SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
add_library(bt3Lib)
target_sources(bt3Lib PRIVATE ${SRC_FILES})

target_link_libraries(bt3Lib PUBLIC bt3Headers)
