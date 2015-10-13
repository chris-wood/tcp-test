#!/bin/bash

athena &
athenactl add link tcp://$1:$2/name=test
athenactl add route test lci:/test/
client $3
