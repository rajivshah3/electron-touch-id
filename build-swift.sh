#!/usr/bin/env bash
set -e

cd ElectronTouchID
rm -rf .build
swift build -c release
cd ..
