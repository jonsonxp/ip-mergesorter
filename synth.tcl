############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project ip-mergesorter
set_top ip_mergesorter
add_files ./src/main.cpp
add_files ./src/main.hpp
add_files -tb ./src/test.cpp
open_solution "solution1"
set_part {xc7vx485tffg1761-2}
create_clock -period 5 -name default
set_clock_uncertainty 5%
csynth_design
#export_design -format syn_dcp
quit
