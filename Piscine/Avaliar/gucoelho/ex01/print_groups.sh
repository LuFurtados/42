#!/bin/sh
echo -n $( id --groups --name "$FT_USER" ) | sed "s/ /,/g"
