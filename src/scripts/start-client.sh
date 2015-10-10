#!/bin/bash

IPADDR=1.2.3.4
PORT=9596

FILENAME=file.bin

TCPCLIENT=../tcp/tcp-client
UDPCLIENT=../udp/udp-client
STCPCLIENT=../sctp/sctp-client
QUICCLIENT=../quic/quic-client
CCNCLIENT=../ccn/ccn-client

CLIENTLIST=( $TCPCLIENT $UDPCLIENT $STCPCLIENT $QUICCLIENT $CCNCLIENT )

N=10

export TIMEFORMAT='%3R'

for CLIENT in "${CLIENTLIST[@]}"
do
    for i in `seq 1 $N`
    do
        OUTFILE=$CLIENT_$i.out
        time ( $CLIENT $IPADDR $PORT $FILENAME ) > $OUTFILE
    done
done
