#!/bin/bash

cd ..
mkdir dacha_build
cd dacha_build
cmake .
make
./dacha