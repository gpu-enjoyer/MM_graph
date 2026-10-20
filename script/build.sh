#!/bin/bash
set -euo pipefail

rm -rf build
mkdir build

clear

g++ -g -O0 src/main.cpp src/graph.cpp -o build/bin
