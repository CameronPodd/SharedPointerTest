# Set some variables
set(BINARY ${CMAKE_PROJECT_NAME})

# Create the executbale from the main method
add_executable(${BINARY} main.cpp MergeSort.h)
