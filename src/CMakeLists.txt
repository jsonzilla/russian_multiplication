cmake_minimum_required(VERSION 2.8)

project(RussianMultiplication)
include(gtest.cmake)

# set(COVERAGE OFF CACHE BOOL "Coverage")

#file(GLOB sources "example.cpp")
#file(GLOB headers "example.h")
add_executable(RussianMultiplication 
    main.cpp 
	rmult.h
    ${headers}
    ${sources}
    ) 

file(GLOB sourcesTests "unit_fixture.cpp")
file(GLOB headersTests "unit_fixture.h")
add_executable(tests 
    "unit_tests.cpp"
	rmult.h
    ${headers}
    ${sources} 
    ${headersTests} 
    ${sourcesTests} 
    )

#target_include_directories(RussianMultiplication)   

#target_include_directories(tests)   

find_package (Threads)
target_link_libraries(tests gtest ${CMAKE_THREAD_LIBS_INIT})    

if (MSVC)
    target_compile_options(tests PRIVATE /std:c++14)

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od")

    # VS 2017 removed tr1
    add_definitions(-DGTEST_HAS_TR1_TUPLE=0)
else()
    target_compile_options(RussianMultiplication PRIVATE -std=c++11 -g -fpermissive)
    target_compile_options(tests PRIVATE -std=c++11 -g -fpermissive)
    # if (COVERAGE)
    #     target_compile_options(tests PRIVATE --coverage)
    #     target_link_libraries(tests PRIVATE --coverage)
    # endif()
endif()




