#!/bin/bash
mkdir out out/build
cd out/build
cmake ../../
make
make install