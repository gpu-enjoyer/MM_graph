#!/bin/bash
set -euo pipefail

./script/build.sh

for f in input/*.txt; do
    echo "$f"
    ./build/bin "$f"
    echo -e ""
done

./build/bin graph.txt
