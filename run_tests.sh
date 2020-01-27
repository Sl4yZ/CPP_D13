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

echo "--- Testing ex02 ---"
cp ../ex02/* ex02_tests
cp media/woody.txt ex02_tests
cp media/buzz.txt ex02_tests
cd ex02_tests
g++ -std=c++14 -Wall -Wextra -fprofile-arcs -ftest-coverage --coverage -lcriterion *.cpp -o ex02
if [ $? -ne 0 ]; then
    ((err++))
fi
./ex02 --ascii
if [ $? -ne 0 ]; then
    ((err++))
fi
cd ..
echo "--- End testing ex02 ---"

echo "--- Testing ex03 ---"
cp ../ex03/* ex03_tests
cp media/woody.txt ex03_tests
cp media/buzz.txt ex03_tests
cd ex03_tests
g++ -std=c++14 -Wall -Wextra -fprofile-arcs -ftest-coverage --coverage -lcriterion *.cpp -o ex03
if [ $? -ne 0 ]; then
    ((err++))
fi
./ex03 --ascii
if [ $? -ne 0 ]; then
    ((err++))
fi
cd ..
echo "--- End testing ex03 ---"

echo "--- Testing ex04 ---"
cp ../ex04/* ex04_tests
cp media/woody.txt ex04_tests
cp media/buzz.txt ex04_tests
cd ex04_tests
g++ -std=c++14 -Wall -Wextra -fprofile-arcs -ftest-coverage --coverage -lcriterion *.cpp -o ex04
if [ $? -ne 0 ]; then
    ((err++))
fi
./ex04 --ascii
if [ $? -ne 0 ]; then
    ((err++))
fi
cd ..
echo "--- End testing ex04 ---"

echo "--- Testing ex05 ---"
cp ../ex05/* ex05_tests
cp media/woody.txt ex05_tests
cp media/buzz.txt ex05_tests
cd ex05_tests
g++ -std=c++14 -Wall -Wextra -fprofile-arcs -ftest-coverage --coverage -lcriterion *.cpp -o ex05
if [ $? -ne 0 ]; then
    ((err++))
fi
./ex04 --ascii
if [ $? -ne 0 ]; then
    ((err++))
fi
cd ..
echo "--- End testing ex05 ---"

if [ $err -ne 0 ]; then
    exit 1
fi
