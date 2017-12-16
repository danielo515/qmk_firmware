#!/usr/bin/env bash
KEYBOARD=${1-:danielomp}
KEYMAP=${2-:default}
docker run --rm -v $(pwd):/qmk -e keyboard=$KEYBOARD -e subproject=" " -e keymap="$KEYMAP" danielomp_builder:latest
