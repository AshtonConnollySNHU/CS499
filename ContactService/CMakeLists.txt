cmake_minimum_required(VERSION 3.20)
project(ContactServiceCpp LANGUAGES CXX_EXTENSIONS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Library
add_library(contact_lib
    src/Contact.cpp
    src/ContactService.cpp
)
target_include_directories(contact_lib PUBLIC include)

# GoogleTest via FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Tests
add_executable(contact_tests
    tests/test_contact.cpp
    tests/test_contact_service.cpp
)
target_link_libraries(contact_tests PRIVATE contact_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(contact_tests)