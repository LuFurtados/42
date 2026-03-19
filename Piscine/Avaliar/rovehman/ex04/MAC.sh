#!/bin/bash
ifconfig | grep Ethernet | awk '{print$2}'
