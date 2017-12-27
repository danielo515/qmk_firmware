#!/usr/bin/env bash
docker run --rm -v $(pwd):/qmk -e subproject="" -e keyboard=danielomp danielomp_builder:latest
