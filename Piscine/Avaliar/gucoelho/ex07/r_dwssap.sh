#!/bin/sh
cat /etc/passwd | grep -E "^[^#].*" | awk 'NR % 2 == 0' | awk 'BEGIN { FS = ":" } ; { print $1 }' | rev | sort -r | sed -n "$FT_LINE1","$FT_LINE2"p | xargs | tr " \n" ",."
