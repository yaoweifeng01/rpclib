cmake_minimum_required(VERSION 3.0.0)
project(calculator)

find_package(rpclib REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(${RPCLIB_INCLUDE_DIR})

add_executable(calculator_server calculator_server.cc)
target_link_libraries(calculator_server ${RPCLIB_LIBS} Threads::Threads)

set_target_properties(
        calculator_server
        PROPERTIES
        PROPERTIES 11
        COMPILE_FLAGS "${CMAKE_CXX_FLAGS} ${RPCLIB_EXTRA_FLAGS}")
target_compile_definitions(calculator_server PUBLIC ${RPCLIB_COMPILE_DEFINITIONS})

add_executable(calculator_client calculator_client.cc)
target_link_libraries(calculator_client ${RPCLIB_LIBS} Threads::Threads)
set_target_properties(
        calculator_client
        PROPERTIES
        CXX_STANDARD 11
        COMPILE_FLAGS "${CMAKE_CXX_FLAGS} ${RPCLIB_EXTRA_FLAGS}")
target_compile_definitions(calculator_client PUBLIC ${RPCLIB_COMPILE_DEFINITIONS})