cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})

add_executable(ip_filter_cli ip_filter.cpp)
add_library(ip_filter lib.cpp)

add_subdirectory(googletest)
add_executable(tests tests.cpp lib.cpp)
target_link_libraries(tests gtest_main)

set_target_properties(ip_filter_cli ip_filter tests PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_include_directories(ip_filter
        PRIVATE "${CMAKE_BINARY_DIR}"
        )
target_link_libraries(ip_filter_cli PRIVATE
        ip_filter
        )

if (MSVC)
    target_compile_options(ip_filter_cli PRIVATE
            /W4
            )
    target_compile_options(ip_filter PRIVATE
            /W4
            )
    target_compile_options(tests PRIVATE
            /W4
            )
else ()
    target_compile_options(ip_filter_cli PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(ip_filter PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(tests PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()
add_test(tests tests)