#!/bin/sh

git log --pretty=oneline | awk '{print $1}' | head -n 5
