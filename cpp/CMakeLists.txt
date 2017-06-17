cmake_minimum_required(VERSION 3.6)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB EXEC_SOURCES "./*.cpp")

foreach(exec_source ${EXEC_SOURCES})
    message(STATUS ${EXEC_SOURCES})
    string(REGEX MATCH "[0-9]+(-[0-9])?" name ${exec_source})
    message(STATUS ${name})
    if(name)
        add_executable("${name}.out" ${exec_source})
    endif(name)
endforeach(exec_source ${EXEC_SOURCES})