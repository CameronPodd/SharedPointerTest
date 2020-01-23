#!bin/bash

if [ -d "../scripts" ]
then
    cd ..
fi

if [ -d "../tools" ]
then
    cd ..
fi

if [ ! -d "./build" ]
then
    mkdir build
fi
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .


if (($# >= 2))
then
    if (($1 == "-d"))
    then
        lldb ./TESTS/$2_test
    fi
else
    ctest -VV
fi
