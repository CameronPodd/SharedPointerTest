# Set some variables
set(BINARY ${CMAKE_PROJECT_NAME}_test)
# Add Test sources and their corresponding source libraries
set(SRCS MergeSort-test.cpp helpers.h)

# Create the tests as an executable
add_executable(${BINARY} ${SRCS})

# Create dependency of ${BINARY} on googletest and pistache
add_dependencies(${BINARY} googletest pistache)

target_link_libraries(${BINARY} PUBLIC gtest gtest_main pthread pistache) 

# Name test cases
add_test(NAME ${BINARY} COMMAND ${BINARY})
