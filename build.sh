#!/bin/bash
BUILD_DIR=build
if [ ! -d ${BUILD_DIR} ]; then
  mkdir ${BUILD_DIR}
fi
pushd ${BUILD_DIR}
  cmake ..
  make -j8
popd
