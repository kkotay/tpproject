#!/bin/bash

runned=false
if [ "$1" == "runned" ]; then
  runned=true
  mkdir dacha_build
  cd dacha_build
  cmake ..
  make
fi

if [ $runned == false ]; then\
  cd dacha_build
  ./dacha
fi