#!/bin/bash
nc --sctp -w 3 $1 1234 < $2

