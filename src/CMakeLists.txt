# Set some variables
set(BINARY ${CMAKE_PROJECT_NAME})
# Add some libraries
# set(LIBS Formula)

# Add a library for each class
# add_library(Formula Formula.cpp Formula.h)

# Create the executbale from the main method
add_executable(${BINARY} main.cpp)

target_link_libraries(${BINARY} PUBLIC ${LIBS})
