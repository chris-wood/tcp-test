#!/bin/bash

IPADDR=127.0.0.1
PORT=8001

FILENAME=file.bin

SIZES=( 10 100 1000 10000 100000 )

TCPCLIENT=../tcp/tcp-client
UDPCLIENT=../udp/udp-client
STCPCLIENT=../sctp/sctp-client
QUICCLIENT=../quic/quic-client
CCNCLIENT=../ccn/ccn-client

# CLIENTLIST=( $TCPCLIENT )
CLIENTLIST=( $UDPCLIENT )

N=10

export TIMEFORMAT='%3R'

for CLIENT in "${CLIENTLIST[@]}"
do
    for s in "${SIZES[@]}"
    do
        for i in `seq 1 $N`
        do
            OUTFILE=run_"$s"_$i.out

            echo $SERVER $s $i $OUTFILE
            echo $CLIENT $IPADDR $PORT $FILENAME

            $CLIENT $IPADDR $PORT $FILENAME > $OUTFILE

            sleep 0.5
        done
    done
done
