#!/bin/bash

set -e

DB_NAME=db.dat
PROGRAM_NAME=ex17

echo "DEBUG: clean and recompile program"
make clean
make $PROGRAM_NAME

echo "DEBUG: Remove any existing database"
rm $DB_NAME

echo "DEBUG: Create database"
./$PROGRAM_NAME $DB_NAME c

echo "DEBUG: Create fake data in db"
./$PROGRAM_NAME $DB_NAME s 0 andrei andrei.glingeanu@gmail.com
./$PROGRAM_NAME $DB_NAME s 1 zed zed@gmail.com
./$PROGRAM_NAME $DB_NAME s 2 vanea vanea@gmail.com

echo "DEBUG: List database addresses"
./$PROGRAM_NAME $DB_NAME l

echo "DEBUG: Destroy last address in db"
./$PROGRAM_NAME $DB_NAME d 2

echo "DEBUG: List database addresses"
./$PROGRAM_NAME $DB_NAME l

echo "DEBUG: Find address from db"
./$PROGRAM_NAME $DB_NAME f andrei

echo "DEBUG: Create more data, bigger ID"
./$PROGRAM_NAME $DB_NAME s 99 vasilisa vasilisa@gmail.com

echo "DEBUG: List database addresses"
./$PROGRAM_NAME $DB_NAME l

echo "DEBUG: Get address using id"
./$PROGRAM_NAME $DB_NAME g 99
