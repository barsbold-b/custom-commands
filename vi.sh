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

RES=""
FC=$(search_command | wc -l)

if [[ $FC -eq 0 ]]; then
  echo "there is no matching file"
elif [[ $FC -eq 1 ]]; then
  RES=$(search_command)
else
  RES=$(search_command | fzf_command)
fi

if [ -n "$RES" ]
then
  nvim $RES
fi
