cmake_minimum_required(VERSION 3.0.0)
project(echo)

find_package(rpclib REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(${RPCLIB_INCLUDE_DIR})

add_executable(echo_server echo_server.cc)
target_link_libraries(echo_server ${RPCLIB_LIBS} Threads::Threads)
set_target_properties(
        echo_server
        PROPERTIES
        CXX_STANDARD 11
        COMPILE_FLAGS "${CMAKE_CXX_FLAGS} ${RPCLIB_EXTRA_FLAGS}")
target_compile_definitions(echo_server PUBLIC ${RPCLIB_COMPILE_DEFINITIONS})

add_executable(echo_client echo_client.cc)
target_link_libraries(echo_client ${RPCLIB_LIBS} Threads::Threads)
set_target_properties(
        echo_client
        PROPERTIES
        CXX_STANDARD 11
        COMPILE_FLAGS "${CMAKE_CXX_FLAGS} ${RPCLIB_EXTRA_FLAGS}")
target_compile_definitions(echo_client PUBLIC ${RPCLIB_COMPILE_DEFINITIONS})
