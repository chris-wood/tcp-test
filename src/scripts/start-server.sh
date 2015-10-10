#!/bin/bash

IPADDR=1.2.3.4
PORT=9596
FILENAME=file.bin
SIZES=( 10 100 1000 10000 100000 )

TCPSERVER=../tcp/tcp-server
UDPSERVER=../udp/udp-server
STCPSERVER=../sctp/sctp-server
QUICSERVER=../quic/quic-server
CCNSERVER=../ccn/ccn-server

SERVERLIST=( $TCPCLIENT $UDPCLIENT $STCPCLIENT $QUICCLIENT $CCNCLIENT )

N=10

export TIMEFORMAT='%3R'

for SERVER in "${SERVERLIST[@]}"
do
    for s in "${SIZES[@]}"
    do
        for i in `seq 1 $N`
        do
            OUTFILE=$SERVER_$i.out
            ./create-file.sh $FILENAME $s
            time ( $SERVER $IPADDR $PORT $FILENAME ) > $OUTFILE
        done
    done
done
