#!/usr/bin/env bash
set -e

rm -rf build

./build-swift.sh
./node_modules/.bin/node-gyp rebuild
