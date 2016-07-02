#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <cstdlib>
#include <hls_stream.h>
#include "ap_int.h"

using namespace hls;

#define MYINT ap_int<32>

void ip_mergesorter(
		stream<MYINT> &inData,
		stream<MYINT> &outData);
