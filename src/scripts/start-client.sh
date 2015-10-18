#!/bin/bash

IPADDR=127.0.0.1
PORT=9001

FILENAME=file.bin

TCPCLIENT=../tcp/tcp-client
UDPCLIENT=../udp/udp-client
STCPCLIENT=../sctp/sctp-client
QUICCLIENT=../quic/quic-client
CCNCLIENT=../ccn/ccn-client

CLIENTLIST=( $TCPCLIENT )

N=10

export TIMEFORMAT='%3R'

for CLIENT in "${CLIENTLIST[@]}"
do
    for i in `seq 1 $N`
    do
        OUTFILE=$CLIENT_$i.out
        $CLIENT $IPADDR $PORT $FILENAME > $OUTFILE
    done
done
