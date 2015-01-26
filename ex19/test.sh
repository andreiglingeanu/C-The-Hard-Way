#!/bin/sh

set -e

test () {
    echo "___START TEST: $2"
    echo
    echo "$1" | ./ex19
    echo
    echo "___END TEST"
}

test "n\na" "Go to north and attack"
test "n\nl" "Go to north and list"
