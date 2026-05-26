file(GLOB SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
add_library(bt4Lib)
target_sources(bt4Lib PRIVATE ${SRC_FILES})

target_link_libraries(bt4Lib PUBLIC bt4Headers)
