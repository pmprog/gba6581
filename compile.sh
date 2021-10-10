#!/bin/bash

if [ -d libseven ]; then
    cd libseven
    git pull
    cd ..
else
    git clone https://github.com/LunarLambda/libseven
fi


if [ -d sid-the-kid ]; then
    cd sid-the-kid
    git pull
    cd ..
else
    git clone https://github.com/mic-/sid-the-kid
fi

if [ -d build ]; then
    rm -rf build/
fi

make -j4

if [ -f build/gbasid.gba ]; then
    mgba-qt build/gbasid.gba
fi
