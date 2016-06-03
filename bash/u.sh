#!/bin/bash

# Exit when unbound variable exists
set -u

chroot=$1
ls $chroot
