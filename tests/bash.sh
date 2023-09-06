#!/bin/bash

RED='\033[0;31m'
NC='\033[0m' # No Color
GREEN='\033[0;32m'
BLUE='\033[0;34m'

echo -e "${GREEN}Testing has started!${NC}"
echo
for file in tests/*.in; do
    printf "%s\n" $file
    printf "LFU cache hits: "
    ./lfu < $file
    printf "Perfect cache hits: "
    ./perfect < $file
    printf "\n" 
done