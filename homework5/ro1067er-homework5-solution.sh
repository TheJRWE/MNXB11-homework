#!/bin/bash

#SBATCH -J first_job
#SBATCH -t 0:30:00
#SBATCH -n 1

hostname
uptime
df -h
entries_etc=$(ls -1 /etc | wc -l)
echo "Entries in /etc: $entries_etc"
entries_usrbin=$(ls -1 /usr/bin | wc -l)
echo "Entries in /usr/bin: $entries_usrbin"

sleep 180

