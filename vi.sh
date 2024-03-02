#!/bin/bash

SEARCH_PATH=""

if [ -n "$1" ]
then
  SEARCH_PATH="*${1}*"
else
  SEARCH_PATH="*"
fi

search_command() {
  find * \
    -path "*/node_modules" -prune -o \
    -path "*/.git" -prune -o \
    -path "$SEARCH_PATH" -type f
}
fzf_command() {
  fzf +m --cycle --reverse \
    --bind=tab:down,btab:up \
    --preview 'bat --style=numbers --color=always --line-range :500 {}'
}

# Store search results directly to avoid unnecessary executions
RES=$(search_command)

# Count lines efficiently
FC=$(wc -l <<< "$RES")

if [[ $FC -eq 0 || -z $RES ]]
then
  FC=0
  echo "There is no matching file"
elif [ $FC -ne 1 ]
then
  RES=$(echo "$RES" | fzf_command)  # Use fzf for multiple matches
fi

if [ -n "$RES" ]
then
  nvim "$RES"
fi
