cmake_minimum_required(VERSION 2.8)

project (Dining_Philosophers)

SET(CMAKE_SYSTEM_NAME Linux)  

include_directories( app/include/ )

file(GLOB headers "app/include/*.h" )
file(GLOB sources "app/src/*.c" )

add_executable(dining_philosophers ${sources} ${headers})

target_link_libraries( dining_philosophers pthread )
