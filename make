#!/bin/bash

for i in "$@"
do
case $i in
        -driver)
        DRIVER=1
        shift
        ;;
        *)
        ;;
esac
done

#compile and install the ip driver
if [ "$DRIVER" ]; then
	if [ -z "$JAVA_HOME" ]; then
        	echo "Please setup the JAVA_HOME environment parameter. For example,"
        	echo "export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64/"
        	exit
	fi

        cd driver/rt_mergetree/java/util
        sh make.sh
        cd ../../../..
        mkdir ~/.hcode/ip-drivers
        mkdir ~/.hcode/ip-drivers/ip-mergesorter
        cp -r driver/rt_mergetree ~/.hcode/ip-drivers/ip-mergesorter
        exit
fi

#cleaning
rm -rf ip-mergesorter
rm -rf output

#execute the vivado_hls synthesis
vivado_hls -f synth.tcl

#copy the dcp and verilog to output folder
mkdir output
mkdir output/dcp
mkdir output/verilog
cp ip-mergesorter/solution1/impl/ip/ip_mergesorter.dcp ./output/dcp
cp ip-mergesorter/solution1/syn/verilog/* ./output/verilog/
