cmake_minimum_required(VERSION 3.20)
project(cooking)

set(CMAKE_CXX_STANDARD 17)

# curl folder
set(CURL_DIR "C:/Users/fabia/Downloads/curl-8.18.0_4-win64-mingw/curl-8.18.0_4-win64-mingw")

# 2. Headers
include_directories("${CURL_DIR}/include")


add_executable(CryptoTracker main.cpp)


target_link_libraries(CryptoTracker
        "${CURL_DIR}/lib/libcurl.dll.a"
)