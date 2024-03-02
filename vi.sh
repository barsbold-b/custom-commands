#!/bin/bash

Q="$1"

search() {
  fd $Q -t f -c=never
}
fzf_command() {
  fzf +m --cycle --reverse \
    --bind=tab:down,btab:up \
    --preview 'bat --style=numbers --color=always --line-range :500 {}'
}

RES=$(search)
RC=$(wc -l <<< "$RES")

if [[ "$RC" -eq 0 || -z "$RES" ]]
then
  echo "There is no matching file"
elif [ $RC -ne 1 ]
then
  RES=$(echo "$RES" | fzf_command)
fi

if [ -n "$RES" ]
then
  nvim "$RES"
fi
