cmake_minimum_required(VERSION 3.16)
project(BTreeDatabase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(YAML_CPP_DIR "C:/CPPLibs/yaml-cpp/install")

add_executable(BTreeDatabase "BTreeDatabaseProject/src/main/BTreeDatabaseProject.cpp")

target_include_directories(BTreeDatabase PRIVATE "${YAML_CPP_DIR}/include")

target_link_libraries(BTreeDatabase PRIVATE "${YAML_CPP_DIR}/lib/yaml-cpp.lib")