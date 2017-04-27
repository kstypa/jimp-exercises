
project(ballexception)

set(HEDEAR_FILES BallException.h)
set(SOURCE_FILES BallException.cpp)

add_library(libballexception STATIC ${SOURCE_FILES})
target_include_directories(libballexception PUBLIC .)

add_executable(ballexception ${SOURCE_FILES} main.cpp)

target_link_libraries(ballexception libballexception)

