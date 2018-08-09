#!/bin/bash

if [ -f "/bin/bash" ]; then
    echo "found abc"
else
    echo "cannot found abc"
    `touch abc`
fi

