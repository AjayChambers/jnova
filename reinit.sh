#!/bin/bash
set -e

echo "🧹 Cleaning previous build artifacts..."
rm -rf build/ CMakeCache.txt CMakeFiles/

echo "🔍 Verifying compiler availability..."
which gcc && gcc --version
which g++ && g++ --version

echo "🧠 Configuring with Ninja generator..."
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
  -DCMAKE_C_COMPILER=/usr/bin/gcc \
  -DCMAKE_CXX_COMPILER=/usr/bin/g++

echo "✅ Configuration complete. Ready to build:"
echo "  ninja -C build"
