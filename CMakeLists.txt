cmake_minimum_required(VERSION 3.26)

project(Pong_SFML
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE PONG_SOURCES
        src/*.cpp
)

file(GLOB_RECURSE PONG_HEADERS
        src/*.h
        src/*.hpp
)

include_directories(src)

add_executable(Pong_SFML
        ${PONG_SOURCES}
        ${PONG_HEADERS}
)


#System binaries
set(PROJECT_RUNTIME_DIR
        ${CMAKE_SOURCE_DIR}/ext/bin
)

file(GLOB PROJECT_RUNTIME_DLLS
        "${PROJECT_RUNTIME_DIR}/*.dll"
)

add_custom_command(TARGET Pong_SFML POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_RUNTIME_DLLS}
        $<TARGET_FILE_DIR:Pong_SFML>
)

#SFML
add_library(SFML_SDK INTERFACE)

target_include_directories(SFML_SDK INTERFACE
        ${CMAKE_SOURCE_DIR}/ext/SFML/include
)

file(GLOB SFML_LIBS
        ${CMAKE_SOURCE_DIR}/ext/SFML/lib/*.a
        ${CMAKE_SOURCE_DIR}/ext/SFML/lib/*.lib
)

target_link_libraries(SFML_SDK INTERFACE
        ${SFML_LIBS}
)

target_link_libraries(Pong_SFML PRIVATE SFML_SDK)

file(GLOB SFML_DLLS
        ${CMAKE_SOURCE_DIR}/ext/SFML/bin/*.dll
)

add_custom_command(TARGET Pong_SFML POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SFML_DLLS}
        $<TARGET_FILE_DIR:Pong_SFML>
)

#AtlasSDK
add_library(AtlasSDK INTERFACE)

target_include_directories(AtlasSDK INTERFACE
        ${CMAKE_SOURCE_DIR}/ext/AtlasSDK/include
)

file(GLOB AtlasSDK_LIBS
        ${CMAKE_SOURCE_DIR}/ext/AtlasSDK/lib/*.a
        ${CMAKE_SOURCE_DIR}/ext/AtlasSDK/lib/*.lib
)

target_link_libraries(AtlasSDK INTERFACE
        ${AtlasSDK_LIBS}
)

target_link_libraries(Pong_SFML PRIVATE AtlasSDK)

file(GLOB AtlasSDK_DLLS
        ${CMAKE_SOURCE_DIR}/ext/AtlasSDK/bin/*.dll
)

add_custom_command(TARGET Pong_SFML POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${AtlasSDK_DLLS}
        $<TARGET_FILE_DIR:Pong_SFML>
)

# resources
add_custom_target(copy_res ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        $<TARGET_FILE_DIR:Pong_SFML>/res
)
add_dependencies(Pong_SFML copy_res)