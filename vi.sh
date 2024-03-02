#!/bin/bash

SEARCH_PATH=""

if [ $1 ]
then
  SEARCH_PATH="*${1}*"
else
  SEARCH_PATH="*"
fi

RES=""

if [[ $(find . -path $SEARCH_PATH -type f | wc -l) -gt 1 ]]; then
  RES=$(find . -path $SEARCH_PATH -type f | fzf)
else
  RES=$(find . -path $SEARCH_PATH -type f)
fi

if [ RES ]
then
  nvim $RES
fi
