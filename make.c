#!/bin/bash
if [ ! -f include/catch.hpp ]; then
  mkdir -p include
  curl https://raw.githubusercontent.com/CatchOrg/Catch2/master/single_include/catch.hpp -o include/catch.hpp
fi
clang -I include *.cpp -o vector
