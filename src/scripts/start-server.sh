#!/bin/bash

IPADDR=127.0.0.1
PORT=9001
FILENAME=file.bin
SIZES=( 10 100 1000 10000 100000 )

TCPSERVER=../tcp/tcp-server
UDPSERVER=../udp/udp-server
STCPSERVER=../sctp/sctp-server
QUICSERVER=../quic/quic-server
CCNSERVER=../ccn/ccn-server

SERVERLIST=( $TCPSERVER )

N=10

export TIMEFORMAT='%3R'

echo "Starting the server test..."

for SERVER in "${SERVERLIST[@]}"
do
    echo "$SERVER"
    for s in "${SIZES[@]}"
    do
        for i in `seq 1 $N`
        do
            OUTFILE=$SERVER_$i.out
            ./create-file.sh $FILENAME $s
            $SERVER $PORT $FILENAME > $OUTFILE
        done
    done
done
