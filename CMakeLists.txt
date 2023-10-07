cmake_minimum_required(VERSION 3.12)
project(VirtualFileSystem)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "inc/*.h")

add_executable(vfs ${SOURCES} ${HEADERS})
target_include_directories(vfs PRIVATE inc)