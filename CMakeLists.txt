cmake_minimum_required(VERSION 3.20)
project(cooking)

set(CMAKE_CXX_STANDARD 17)

# 1. Path to your curl folder
set(CURL_DIR "C:/Users/fabia/Downloads/curl-8.18.0_4-win64-mingw/curl-8.18.0_4-win64-mingw")

# 2. Headers
include_directories("${CURL_DIR}/include")

# 3. DO NOT use add_definitions(-DCURL_STATICLIB) anymore.
# We want to use the DLL version now.

add_executable(CryptoTracker main.cpp)

# 4. Link directly to the DLL import library
# This is usually much smaller and 'points' to the .dll file
target_link_libraries(CryptoTracker
        "${CURL_DIR}/lib/libcurl.dll.a"
)