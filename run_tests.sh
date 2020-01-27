#!/bin/bash

err=0

echo "--- Testing ex00 ---"
cp ../ex00/* ex00_tests
cd ex00_tests
g++ -std=c++14 -Wall -Wextra -fprofile-arcs -ftest-coverage --coverage -lcriterion *.cpp -o ex00
if [ $? -ne 0 ]; then
    ((err++))
fi
./ex00 --ascii
if [ $? -ne 0 ]; then
    ((err++))
fi
cd ..
echo "--- End testing ex00 ---"

echo "--- Testing ex01 ---"
cp ../ex01/* ex01_tests
cd ex01_tests
g++ -std=c++14 -Wall -Wextra -fprofile-arcs -ftest-coverage --coverage -lcriterion *.cpp -o ex01
if [ $? -ne 0 ]; then
    ((err++))
fi
./ex01 --ascii
if [ $? -ne 0 ]; then
    ((err++))
fi
cd ..
echo "--- End testing ex00 ---"

if [ $err -ne 0 ]; then
    exit 1
fi
