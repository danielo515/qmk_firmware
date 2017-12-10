#!/usr/bin/env bash
docker run --rm -v $(pwd):/qmk -e subproject="" danielomp_builder:latest