# Set some variables
set(BINARY ${CMAKE_PROJECT_NAME}_test)
# Add Test sources and their corresponding source libraries
# set(SRCS Formula-test.cpp)
# set(LIBS Formula)

# Create the tests as an executable
add_executable(${BINARY} ${SRCS})

# Create dependency of ${BINARY} on googletest
add_dependencies(${BINARY} googletest)

target_link_libraries(${BINARY} PUBLIC gtest gtest_main pthread ${LIBS})

# Name test cases
add_test(NAME ${BINARY} COMMAND ${BINARY})
