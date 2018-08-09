#!/bin/bash
if [ -e "/work/sdk/" ]; then
    cd /work/sdk
else
    mkdir /work/sdk -p
    cd /work/sdk
if
git clone --depth=1 git@scm-gitlab:sdk/sv-ab02a-system-sdk.git
cd $WORKSPACE/sdk
. env_setup.sh
make&&make upgen
