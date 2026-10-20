#!/bin/bash
set -euo pipefail

./script/build.sh
./build/bin graph.txt
