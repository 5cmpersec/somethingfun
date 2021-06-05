#!/usr/bin/env bash

find . \
    -iname *.h -o -iname *.hpp -o -iname *.cpp -o -iname *.c -o -iname *.cc -o -iname *.tpp \
    | xargs clang-format -style=file -i -fallback-style=none
