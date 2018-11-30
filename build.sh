#!/usr/bin/env bash
set -e

rm -rf build

cd ElectronTouchID
make clean
make
cd ..
./node_modules/.bin/node-gyp rebuild
