# Set some variables
set(BINARY ${CMAKE_PROJECT_NAME})
# Set the sources
set(SRCS main.cpp MergeSort.h)

# Create the executbale from the main method
add_executable(${BINARY} ${SRCS})

add_dependencies(${BINARY} pistache)

target_link_libraries(${BINARY} PUBLIC pistache) 
