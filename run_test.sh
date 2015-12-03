#! /usr/bin/env bash

~nimrodav/grep_tests/test_permissions.sh

~nimrodav/socket_ex/verify_readme.sh

cat ~nimrodav/ex1/test1_input | ./ex1 | diff -b ~nimrodav/ex1/test1_output -
