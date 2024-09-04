#!/bin/bash
ip route | grep 'default' | awk '{print $5}'
