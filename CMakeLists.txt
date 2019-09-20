cmake_minimum_required(VERSION 2.8)

# use clang++ default
# set(CMAKE_CXX_COMPILER clang++)

project (Cppstdlib CXX)

# # check compile flag
# include(CheckCXXCompilerFlag)
# check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
# check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

# if(COMPILER_SUPPORTS_CXX11)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# elseif(COMPILER_SUPPORTS_CXX0X)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# else()
#         message(ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
# endif()

set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

# get source files
file(GLOB_RECURSE sources RELATIVE ${PROJECT_SOURCE_DIR} "*.cpp")

foreach(src ${sources})
	if (${src} MATCHES "build/.*.cpp")
		list(REMOVE_ITEM sources ${src})
	endif()
endforeach()

# add the binary tree to the search path for include files
include_directories("${PROJECT_SOURCE_DIR}/*")

# set output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# executable linker flags
# not working! fuck!
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread -lrt")

# add the executable
foreach(src ${sources})
	string(REPLACE "/" "_" target_name ${src})
	string(REPLACE ".cpp" ".exe" target_name ${target_name})
	add_executable(${target_name} ${src})

	if (${target_name} MATCHES "concurrency.*")
		target_link_libraries(${target_name} pthread)
	endif()

	if (${target_name} STREQUAL "util_sharedptr3.exe")
		target_link_libraries(${target_name} rt)
	endif()

	if (${target_name} STREQUAL "concurrency_atomics1.exe")
		target_link_libraries(${target_name} atomic)
	endif()

endforeach()
