#include "main.hpp"
using namespace hls;

void merge1(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge2(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge3(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge4(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge5(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge6(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge7(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge8(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge9(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge10(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge11(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge12(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge13(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge14(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge15(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge16(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge17(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge18(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge19(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge20(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge21(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge22(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge23(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge24(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge25(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge26(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge27(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge28(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge29(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge30(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge31(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge32(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge33(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge34(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge35(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge36(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge37(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge38(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge39(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge40(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge41(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge42(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge43(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge44(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge45(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge46(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge47(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge48(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge49(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge50(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge51(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge52(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge53(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge54(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge55(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge56(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge57(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge58(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge59(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge60(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge61(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge62(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void merge63(stream<MYINT> &channel0,
		stream<MYINT> &channel1,
		stream<MYINT> &out,
		int sortLength
		){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	static MYINT value0;
	static MYINT value1;
	static MYINT cnt0;
	static MYINT cnt1;
	static enum sortState { SORT_INIT=0, SORT_READ_CH0, SORT_READ_CH1, SORT_COMPARE, FLUSH_READ_CH0, FLUSH_READ_CH1, FLUSH_CH1, FLUSH_CH0} mState;

	switch (mState){
		case SORT_INIT:{
			if(!channel0.empty() && !channel1.empty()){
				channel0.read(value0);
				channel1.read(value1);
				cnt0=1;
				cnt1=1;
				mState = SORT_COMPARE;
			}
			break;
		}
		case SORT_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = SORT_COMPARE;
				cnt0++;
			}
			break;
		}
		case SORT_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = SORT_COMPARE;
				cnt1++;
			}
			break;
		}
		case SORT_COMPARE:{
			if(value0 < value1){
				if(out.write_nb(value0)){
					if(cnt0<sortLength){
						mState = SORT_READ_CH0;
					}else{
						mState = FLUSH_CH1;
					}
				}
			}else{
				if(out.write_nb(value1)){
					if(cnt1<sortLength){
						mState = SORT_READ_CH1;
					}else{
						mState = FLUSH_CH0;
					}
				}
			}
			break;
		}
		case FLUSH_READ_CH0:{
			if(channel0.read_nb(value0)){
				mState = FLUSH_CH0;
			}
			break;
		}
		case FLUSH_READ_CH1:{
			if(channel1.read_nb(value1)){
				mState = FLUSH_CH1;
			}
			break;
		}
		case FLUSH_CH0:{
			if(out.write_nb(value0)){
				if(cnt0 < sortLength){
					mState = FLUSH_READ_CH0;
				}
				else{
					mState = SORT_INIT;
				}
				cnt0++;
			}
			break;
		}
		case FLUSH_CH1:{
			if(out.write_nb(value1)){
				if(cnt1 < sortLength){
					mState = FLUSH_READ_CH1;
				}
				else{
					mState = SORT_INIT;
				}
				cnt1++;
			}
			break;
		}
	}
}
void ip_mergesorter(
		stream<MYINT> &in,
		stream<MYINT> &out
	){
	#pragma HLS PIPELINE II=0 enable_flush
	#pragma HLS LATENCY max=0
	#pragma HLS INTERFACE ap_fifo depth=100 port=in
	#pragma HLS INTERFACE ap_fifo depth=100 port=out
	#pragma AP interface ap_ctrl_none port=return
	static MYINT sortLength;
	static MYINT value;
	static enum readState{READ_INIT=0, READ_INIT2, READ_CHANNEL0, WRITE_CHANNEL0, READ_CHANNEL1, WRITE_CHANNEL1, READ_CHANNEL2, WRITE_CHANNEL2, READ_CHANNEL3, WRITE_CHANNEL3, READ_CHANNEL4, WRITE_CHANNEL4, READ_CHANNEL5, WRITE_CHANNEL5, READ_CHANNEL6, WRITE_CHANNEL6, READ_CHANNEL7, WRITE_CHANNEL7, READ_CHANNEL8, WRITE_CHANNEL8, READ_CHANNEL9, WRITE_CHANNEL9, READ_CHANNEL10, WRITE_CHANNEL10, READ_CHANNEL11, WRITE_CHANNEL11, READ_CHANNEL12, WRITE_CHANNEL12, READ_CHANNEL13, WRITE_CHANNEL13, READ_CHANNEL14, WRITE_CHANNEL14, READ_CHANNEL15, WRITE_CHANNEL15, READ_CHANNEL16, WRITE_CHANNEL16, READ_CHANNEL17, WRITE_CHANNEL17, READ_CHANNEL18, WRITE_CHANNEL18, READ_CHANNEL19, WRITE_CHANNEL19, READ_CHANNEL20, WRITE_CHANNEL20, READ_CHANNEL21, WRITE_CHANNEL21, READ_CHANNEL22, WRITE_CHANNEL22, READ_CHANNEL23, WRITE_CHANNEL23, READ_CHANNEL24, WRITE_CHANNEL24, READ_CHANNEL25, WRITE_CHANNEL25, READ_CHANNEL26, WRITE_CHANNEL26, READ_CHANNEL27, WRITE_CHANNEL27, READ_CHANNEL28, WRITE_CHANNEL28, READ_CHANNEL29, WRITE_CHANNEL29, READ_CHANNEL30, WRITE_CHANNEL30, READ_CHANNEL31, WRITE_CHANNEL31, READ_CHANNEL32, WRITE_CHANNEL32, READ_CHANNEL33, WRITE_CHANNEL33, READ_CHANNEL34, WRITE_CHANNEL34, READ_CHANNEL35, WRITE_CHANNEL35, READ_CHANNEL36, WRITE_CHANNEL36, READ_CHANNEL37, WRITE_CHANNEL37, READ_CHANNEL38, WRITE_CHANNEL38, READ_CHANNEL39, WRITE_CHANNEL39, READ_CHANNEL40, WRITE_CHANNEL40, READ_CHANNEL41, WRITE_CHANNEL41, READ_CHANNEL42, WRITE_CHANNEL42, READ_CHANNEL43, WRITE_CHANNEL43, READ_CHANNEL44, WRITE_CHANNEL44, READ_CHANNEL45, WRITE_CHANNEL45, READ_CHANNEL46, WRITE_CHANNEL46, READ_CHANNEL47, WRITE_CHANNEL47, READ_CHANNEL48, WRITE_CHANNEL48, READ_CHANNEL49, WRITE_CHANNEL49, READ_CHANNEL50, WRITE_CHANNEL50, READ_CHANNEL51, WRITE_CHANNEL51, READ_CHANNEL52, WRITE_CHANNEL52, READ_CHANNEL53, WRITE_CHANNEL53, READ_CHANNEL54, WRITE_CHANNEL54, READ_CHANNEL55, WRITE_CHANNEL55, READ_CHANNEL56, WRITE_CHANNEL56, READ_CHANNEL57, WRITE_CHANNEL57, READ_CHANNEL58, WRITE_CHANNEL58, READ_CHANNEL59, WRITE_CHANNEL59, READ_CHANNEL60, WRITE_CHANNEL60, READ_CHANNEL61, WRITE_CHANNEL61, READ_CHANNEL62, WRITE_CHANNEL62, READ_CHANNEL63, WRITE_CHANNEL63} inState;
	static stream<MYINT> channel0;
	static stream<MYINT> channel1;
	static stream<MYINT> channel2;
	static stream<MYINT> channel3;
	static stream<MYINT> channel4;
	static stream<MYINT> channel5;
	static stream<MYINT> channel6;
	static stream<MYINT> channel7;
	static stream<MYINT> channel8;
	static stream<MYINT> channel9;
	static stream<MYINT> channel10;
	static stream<MYINT> channel11;
	static stream<MYINT> channel12;
	static stream<MYINT> channel13;
	static stream<MYINT> channel14;
	static stream<MYINT> channel15;
	static stream<MYINT> channel16;
	static stream<MYINT> channel17;
	static stream<MYINT> channel18;
	static stream<MYINT> channel19;
	static stream<MYINT> channel20;
	static stream<MYINT> channel21;
	static stream<MYINT> channel22;
	static stream<MYINT> channel23;
	static stream<MYINT> channel24;
	static stream<MYINT> channel25;
	static stream<MYINT> channel26;
	static stream<MYINT> channel27;
	static stream<MYINT> channel28;
	static stream<MYINT> channel29;
	static stream<MYINT> channel30;
	static stream<MYINT> channel31;
	static stream<MYINT> channel32;
	static stream<MYINT> channel33;
	static stream<MYINT> channel34;
	static stream<MYINT> channel35;
	static stream<MYINT> channel36;
	static stream<MYINT> channel37;
	static stream<MYINT> channel38;
	static stream<MYINT> channel39;
	static stream<MYINT> channel40;
	static stream<MYINT> channel41;
	static stream<MYINT> channel42;
	static stream<MYINT> channel43;
	static stream<MYINT> channel44;
	static stream<MYINT> channel45;
	static stream<MYINT> channel46;
	static stream<MYINT> channel47;
	static stream<MYINT> channel48;
	static stream<MYINT> channel49;
	static stream<MYINT> channel50;
	static stream<MYINT> channel51;
	static stream<MYINT> channel52;
	static stream<MYINT> channel53;
	static stream<MYINT> channel54;
	static stream<MYINT> channel55;
	static stream<MYINT> channel56;
	static stream<MYINT> channel57;
	static stream<MYINT> channel58;
	static stream<MYINT> channel59;
	static stream<MYINT> channel60;
	static stream<MYINT> channel61;
	static stream<MYINT> channel62;
	static stream<MYINT> channel63;
	static stream<MYINT> channel64;
	static stream<MYINT> channel65;
	static stream<MYINT> channel66;
	static stream<MYINT> channel67;
	static stream<MYINT> channel68;
	static stream<MYINT> channel69;
	static stream<MYINT> channel70;
	static stream<MYINT> channel71;
	static stream<MYINT> channel72;
	static stream<MYINT> channel73;
	static stream<MYINT> channel74;
	static stream<MYINT> channel75;
	static stream<MYINT> channel76;
	static stream<MYINT> channel77;
	static stream<MYINT> channel78;
	static stream<MYINT> channel79;
	static stream<MYINT> channel80;
	static stream<MYINT> channel81;
	static stream<MYINT> channel82;
	static stream<MYINT> channel83;
	static stream<MYINT> channel84;
	static stream<MYINT> channel85;
	static stream<MYINT> channel86;
	static stream<MYINT> channel87;
	static stream<MYINT> channel88;
	static stream<MYINT> channel89;
	static stream<MYINT> channel90;
	static stream<MYINT> channel91;
	static stream<MYINT> channel92;
	static stream<MYINT> channel93;
	static stream<MYINT> channel94;
	static stream<MYINT> channel95;
	static stream<MYINT> channel96;
	static stream<MYINT> channel97;
	static stream<MYINT> channel98;
	static stream<MYINT> channel99;
	static stream<MYINT> channel100;
	static stream<MYINT> channel101;
	static stream<MYINT> channel102;
	static stream<MYINT> channel103;
	static stream<MYINT> channel104;
	static stream<MYINT> channel105;
	static stream<MYINT> channel106;
	static stream<MYINT> channel107;
	static stream<MYINT> channel108;
	static stream<MYINT> channel109;
	static stream<MYINT> channel110;
	static stream<MYINT> channel111;
	static stream<MYINT> channel112;
	static stream<MYINT> channel113;
	static stream<MYINT> channel114;
	static stream<MYINT> channel115;
	static stream<MYINT> channel116;
	static stream<MYINT> channel117;
	static stream<MYINT> channel118;
	static stream<MYINT> channel119;
	static stream<MYINT> channel120;
	static stream<MYINT> channel121;
	static stream<MYINT> channel122;
	static stream<MYINT> channel123;
	static stream<MYINT> channel124;
	static stream<MYINT> channel125;
	#pragma HLS STREAM variable=channel0 depth=1000
	#pragma HLS STREAM variable=channel1 depth=1000
	#pragma HLS STREAM variable=channel2 depth=1000
	#pragma HLS STREAM variable=channel3 depth=1000
	#pragma HLS STREAM variable=channel4 depth=1000
	#pragma HLS STREAM variable=channel5 depth=1000
	#pragma HLS STREAM variable=channel6 depth=1000
	#pragma HLS STREAM variable=channel7 depth=1000
	#pragma HLS STREAM variable=channel8 depth=1000
	#pragma HLS STREAM variable=channel9 depth=1000
	#pragma HLS STREAM variable=channel10 depth=1000
	#pragma HLS STREAM variable=channel11 depth=1000
	#pragma HLS STREAM variable=channel12 depth=1000
	#pragma HLS STREAM variable=channel13 depth=1000
	#pragma HLS STREAM variable=channel14 depth=1000
	#pragma HLS STREAM variable=channel15 depth=1000
	#pragma HLS STREAM variable=channel16 depth=1000
	#pragma HLS STREAM variable=channel17 depth=1000
	#pragma HLS STREAM variable=channel18 depth=1000
	#pragma HLS STREAM variable=channel19 depth=1000
	#pragma HLS STREAM variable=channel20 depth=1000
	#pragma HLS STREAM variable=channel21 depth=1000
	#pragma HLS STREAM variable=channel22 depth=1000
	#pragma HLS STREAM variable=channel23 depth=1000
	#pragma HLS STREAM variable=channel24 depth=1000
	#pragma HLS STREAM variable=channel25 depth=1000
	#pragma HLS STREAM variable=channel26 depth=1000
	#pragma HLS STREAM variable=channel27 depth=1000
	#pragma HLS STREAM variable=channel28 depth=1000
	#pragma HLS STREAM variable=channel29 depth=1000
	#pragma HLS STREAM variable=channel30 depth=1000
	#pragma HLS STREAM variable=channel31 depth=1000
	#pragma HLS STREAM variable=channel32 depth=1000
	#pragma HLS STREAM variable=channel33 depth=1000
	#pragma HLS STREAM variable=channel34 depth=1000
	#pragma HLS STREAM variable=channel35 depth=1000
	#pragma HLS STREAM variable=channel36 depth=1000
	#pragma HLS STREAM variable=channel37 depth=1000
	#pragma HLS STREAM variable=channel38 depth=1000
	#pragma HLS STREAM variable=channel39 depth=1000
	#pragma HLS STREAM variable=channel40 depth=1000
	#pragma HLS STREAM variable=channel41 depth=1000
	#pragma HLS STREAM variable=channel42 depth=1000
	#pragma HLS STREAM variable=channel43 depth=1000
	#pragma HLS STREAM variable=channel44 depth=1000
	#pragma HLS STREAM variable=channel45 depth=1000
	#pragma HLS STREAM variable=channel46 depth=1000
	#pragma HLS STREAM variable=channel47 depth=1000
	#pragma HLS STREAM variable=channel48 depth=1000
	#pragma HLS STREAM variable=channel49 depth=1000
	#pragma HLS STREAM variable=channel50 depth=1000
	#pragma HLS STREAM variable=channel51 depth=1000
	#pragma HLS STREAM variable=channel52 depth=1000
	#pragma HLS STREAM variable=channel53 depth=1000
	#pragma HLS STREAM variable=channel54 depth=1000
	#pragma HLS STREAM variable=channel55 depth=1000
	#pragma HLS STREAM variable=channel56 depth=1000
	#pragma HLS STREAM variable=channel57 depth=1000
	#pragma HLS STREAM variable=channel58 depth=1000
	#pragma HLS STREAM variable=channel59 depth=1000
	#pragma HLS STREAM variable=channel60 depth=1000
	#pragma HLS STREAM variable=channel61 depth=1000
	#pragma HLS STREAM variable=channel62 depth=1000
	#pragma HLS STREAM variable=channel63 depth=1000
	#pragma HLS STREAM variable=channel64 depth=10
	#pragma HLS STREAM variable=channel65 depth=10
	#pragma HLS STREAM variable=channel66 depth=10
	#pragma HLS STREAM variable=channel67 depth=10
	#pragma HLS STREAM variable=channel68 depth=10
	#pragma HLS STREAM variable=channel69 depth=10
	#pragma HLS STREAM variable=channel70 depth=10
	#pragma HLS STREAM variable=channel71 depth=10
	#pragma HLS STREAM variable=channel72 depth=10
	#pragma HLS STREAM variable=channel73 depth=10
	#pragma HLS STREAM variable=channel74 depth=10
	#pragma HLS STREAM variable=channel75 depth=10
	#pragma HLS STREAM variable=channel76 depth=10
	#pragma HLS STREAM variable=channel77 depth=10
	#pragma HLS STREAM variable=channel78 depth=10
	#pragma HLS STREAM variable=channel79 depth=10
	#pragma HLS STREAM variable=channel80 depth=10
	#pragma HLS STREAM variable=channel81 depth=10
	#pragma HLS STREAM variable=channel82 depth=10
	#pragma HLS STREAM variable=channel83 depth=10
	#pragma HLS STREAM variable=channel84 depth=10
	#pragma HLS STREAM variable=channel85 depth=10
	#pragma HLS STREAM variable=channel86 depth=10
	#pragma HLS STREAM variable=channel87 depth=10
	#pragma HLS STREAM variable=channel88 depth=10
	#pragma HLS STREAM variable=channel89 depth=10
	#pragma HLS STREAM variable=channel90 depth=10
	#pragma HLS STREAM variable=channel91 depth=10
	#pragma HLS STREAM variable=channel92 depth=10
	#pragma HLS STREAM variable=channel93 depth=10
	#pragma HLS STREAM variable=channel94 depth=10
	#pragma HLS STREAM variable=channel95 depth=10
	#pragma HLS STREAM variable=channel96 depth=10
	#pragma HLS STREAM variable=channel97 depth=10
	#pragma HLS STREAM variable=channel98 depth=10
	#pragma HLS STREAM variable=channel99 depth=10
	#pragma HLS STREAM variable=channel100 depth=10
	#pragma HLS STREAM variable=channel101 depth=10
	#pragma HLS STREAM variable=channel102 depth=10
	#pragma HLS STREAM variable=channel103 depth=10
	#pragma HLS STREAM variable=channel104 depth=10
	#pragma HLS STREAM variable=channel105 depth=10
	#pragma HLS STREAM variable=channel106 depth=10
	#pragma HLS STREAM variable=channel107 depth=10
	#pragma HLS STREAM variable=channel108 depth=10
	#pragma HLS STREAM variable=channel109 depth=10
	#pragma HLS STREAM variable=channel110 depth=10
	#pragma HLS STREAM variable=channel111 depth=10
	#pragma HLS STREAM variable=channel112 depth=10
	#pragma HLS STREAM variable=channel113 depth=10
	#pragma HLS STREAM variable=channel114 depth=10
	#pragma HLS STREAM variable=channel115 depth=10
	#pragma HLS STREAM variable=channel116 depth=10
	#pragma HLS STREAM variable=channel117 depth=10
	#pragma HLS STREAM variable=channel118 depth=10
	#pragma HLS STREAM variable=channel119 depth=10
	#pragma HLS STREAM variable=channel120 depth=10
	#pragma HLS STREAM variable=channel121 depth=10
	#pragma HLS STREAM variable=channel122 depth=10
	#pragma HLS STREAM variable=channel123 depth=10
	#pragma HLS STREAM variable=channel124 depth=10
	#pragma HLS STREAM variable=channel125 depth=10

	switch(inState) {
	case READ_INIT : {
		if(in.read_nb(value)){
			inState = READ_INIT2;
		}
		break;
	}
	case READ_INIT2: {
		if(value > 0){
				sortLength = value;
				inState = READ_CHANNEL0;
		}else{
			inState = READ_INIT;
		}
		break;
	}
	case READ_CHANNEL0 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL0;
		}
		break;
	}
	case WRITE_CHANNEL0 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel0.write_nb(value)){
				inState = READ_CHANNEL1;
			}
		}
		break;
	}
	case READ_CHANNEL1 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL1;
		}
		break;
	}
	case WRITE_CHANNEL1 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel1.write_nb(value)){
				inState = READ_CHANNEL2;
			}
		}
		break;
	}
	case READ_CHANNEL2 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL2;
		}
		break;
	}
	case WRITE_CHANNEL2 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel2.write_nb(value)){
				inState = READ_CHANNEL3;
			}
		}
		break;
	}
	case READ_CHANNEL3 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL3;
		}
		break;
	}
	case WRITE_CHANNEL3 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel3.write_nb(value)){
				inState = READ_CHANNEL4;
			}
		}
		break;
	}
	case READ_CHANNEL4 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL4;
		}
		break;
	}
	case WRITE_CHANNEL4 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel4.write_nb(value)){
				inState = READ_CHANNEL5;
			}
		}
		break;
	}
	case READ_CHANNEL5 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL5;
		}
		break;
	}
	case WRITE_CHANNEL5 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel5.write_nb(value)){
				inState = READ_CHANNEL6;
			}
		}
		break;
	}
	case READ_CHANNEL6 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL6;
		}
		break;
	}
	case WRITE_CHANNEL6 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel6.write_nb(value)){
				inState = READ_CHANNEL7;
			}
		}
		break;
	}
	case READ_CHANNEL7 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL7;
		}
		break;
	}
	case WRITE_CHANNEL7 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel7.write_nb(value)){
				inState = READ_CHANNEL8;
			}
		}
		break;
	}
	case READ_CHANNEL8 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL8;
		}
		break;
	}
	case WRITE_CHANNEL8 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel8.write_nb(value)){
				inState = READ_CHANNEL9;
			}
		}
		break;
	}
	case READ_CHANNEL9 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL9;
		}
		break;
	}
	case WRITE_CHANNEL9 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel9.write_nb(value)){
				inState = READ_CHANNEL10;
			}
		}
		break;
	}
	case READ_CHANNEL10 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL10;
		}
		break;
	}
	case WRITE_CHANNEL10 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel10.write_nb(value)){
				inState = READ_CHANNEL11;
			}
		}
		break;
	}
	case READ_CHANNEL11 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL11;
		}
		break;
	}
	case WRITE_CHANNEL11 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel11.write_nb(value)){
				inState = READ_CHANNEL12;
			}
		}
		break;
	}
	case READ_CHANNEL12 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL12;
		}
		break;
	}
	case WRITE_CHANNEL12 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel12.write_nb(value)){
				inState = READ_CHANNEL13;
			}
		}
		break;
	}
	case READ_CHANNEL13 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL13;
		}
		break;
	}
	case WRITE_CHANNEL13 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel13.write_nb(value)){
				inState = READ_CHANNEL14;
			}
		}
		break;
	}
	case READ_CHANNEL14 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL14;
		}
		break;
	}
	case WRITE_CHANNEL14 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel14.write_nb(value)){
				inState = READ_CHANNEL15;
			}
		}
		break;
	}
	case READ_CHANNEL15 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL15;
		}
		break;
	}
	case WRITE_CHANNEL15 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel15.write_nb(value)){
				inState = READ_CHANNEL16;
			}
		}
		break;
	}
	case READ_CHANNEL16 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL16;
		}
		break;
	}
	case WRITE_CHANNEL16 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel16.write_nb(value)){
				inState = READ_CHANNEL17;
			}
		}
		break;
	}
	case READ_CHANNEL17 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL17;
		}
		break;
	}
	case WRITE_CHANNEL17 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel17.write_nb(value)){
				inState = READ_CHANNEL18;
			}
		}
		break;
	}
	case READ_CHANNEL18 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL18;
		}
		break;
	}
	case WRITE_CHANNEL18 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel18.write_nb(value)){
				inState = READ_CHANNEL19;
			}
		}
		break;
	}
	case READ_CHANNEL19 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL19;
		}
		break;
	}
	case WRITE_CHANNEL19 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel19.write_nb(value)){
				inState = READ_CHANNEL20;
			}
		}
		break;
	}
	case READ_CHANNEL20 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL20;
		}
		break;
	}
	case WRITE_CHANNEL20 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel20.write_nb(value)){
				inState = READ_CHANNEL21;
			}
		}
		break;
	}
	case READ_CHANNEL21 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL21;
		}
		break;
	}
	case WRITE_CHANNEL21 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel21.write_nb(value)){
				inState = READ_CHANNEL22;
			}
		}
		break;
	}
	case READ_CHANNEL22 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL22;
		}
		break;
	}
	case WRITE_CHANNEL22 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel22.write_nb(value)){
				inState = READ_CHANNEL23;
			}
		}
		break;
	}
	case READ_CHANNEL23 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL23;
		}
		break;
	}
	case WRITE_CHANNEL23 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel23.write_nb(value)){
				inState = READ_CHANNEL24;
			}
		}
		break;
	}
	case READ_CHANNEL24 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL24;
		}
		break;
	}
	case WRITE_CHANNEL24 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel24.write_nb(value)){
				inState = READ_CHANNEL25;
			}
		}
		break;
	}
	case READ_CHANNEL25 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL25;
		}
		break;
	}
	case WRITE_CHANNEL25 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel25.write_nb(value)){
				inState = READ_CHANNEL26;
			}
		}
		break;
	}
	case READ_CHANNEL26 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL26;
		}
		break;
	}
	case WRITE_CHANNEL26 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel26.write_nb(value)){
				inState = READ_CHANNEL27;
			}
		}
		break;
	}
	case READ_CHANNEL27 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL27;
		}
		break;
	}
	case WRITE_CHANNEL27 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel27.write_nb(value)){
				inState = READ_CHANNEL28;
			}
		}
		break;
	}
	case READ_CHANNEL28 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL28;
		}
		break;
	}
	case WRITE_CHANNEL28 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel28.write_nb(value)){
				inState = READ_CHANNEL29;
			}
		}
		break;
	}
	case READ_CHANNEL29 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL29;
		}
		break;
	}
	case WRITE_CHANNEL29 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel29.write_nb(value)){
				inState = READ_CHANNEL30;
			}
		}
		break;
	}
	case READ_CHANNEL30 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL30;
		}
		break;
	}
	case WRITE_CHANNEL30 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel30.write_nb(value)){
				inState = READ_CHANNEL31;
			}
		}
		break;
	}
	case READ_CHANNEL31 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL31;
		}
		break;
	}
	case WRITE_CHANNEL31 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel31.write_nb(value)){
				inState = READ_CHANNEL32;
			}
		}
		break;
	}
	case READ_CHANNEL32 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL32;
		}
		break;
	}
	case WRITE_CHANNEL32 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel32.write_nb(value)){
				inState = READ_CHANNEL33;
			}
		}
		break;
	}
	case READ_CHANNEL33 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL33;
		}
		break;
	}
	case WRITE_CHANNEL33 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel33.write_nb(value)){
				inState = READ_CHANNEL34;
			}
		}
		break;
	}
	case READ_CHANNEL34 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL34;
		}
		break;
	}
	case WRITE_CHANNEL34 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel34.write_nb(value)){
				inState = READ_CHANNEL35;
			}
		}
		break;
	}
	case READ_CHANNEL35 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL35;
		}
		break;
	}
	case WRITE_CHANNEL35 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel35.write_nb(value)){
				inState = READ_CHANNEL36;
			}
		}
		break;
	}
	case READ_CHANNEL36 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL36;
		}
		break;
	}
	case WRITE_CHANNEL36 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel36.write_nb(value)){
				inState = READ_CHANNEL37;
			}
		}
		break;
	}
	case READ_CHANNEL37 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL37;
		}
		break;
	}
	case WRITE_CHANNEL37 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel37.write_nb(value)){
				inState = READ_CHANNEL38;
			}
		}
		break;
	}
	case READ_CHANNEL38 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL38;
		}
		break;
	}
	case WRITE_CHANNEL38 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel38.write_nb(value)){
				inState = READ_CHANNEL39;
			}
		}
		break;
	}
	case READ_CHANNEL39 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL39;
		}
		break;
	}
	case WRITE_CHANNEL39 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel39.write_nb(value)){
				inState = READ_CHANNEL40;
			}
		}
		break;
	}
	case READ_CHANNEL40 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL40;
		}
		break;
	}
	case WRITE_CHANNEL40 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel40.write_nb(value)){
				inState = READ_CHANNEL41;
			}
		}
		break;
	}
	case READ_CHANNEL41 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL41;
		}
		break;
	}
	case WRITE_CHANNEL41 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel41.write_nb(value)){
				inState = READ_CHANNEL42;
			}
		}
		break;
	}
	case READ_CHANNEL42 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL42;
		}
		break;
	}
	case WRITE_CHANNEL42 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel42.write_nb(value)){
				inState = READ_CHANNEL43;
			}
		}
		break;
	}
	case READ_CHANNEL43 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL43;
		}
		break;
	}
	case WRITE_CHANNEL43 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel43.write_nb(value)){
				inState = READ_CHANNEL44;
			}
		}
		break;
	}
	case READ_CHANNEL44 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL44;
		}
		break;
	}
	case WRITE_CHANNEL44 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel44.write_nb(value)){
				inState = READ_CHANNEL45;
			}
		}
		break;
	}
	case READ_CHANNEL45 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL45;
		}
		break;
	}
	case WRITE_CHANNEL45 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel45.write_nb(value)){
				inState = READ_CHANNEL46;
			}
		}
		break;
	}
	case READ_CHANNEL46 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL46;
		}
		break;
	}
	case WRITE_CHANNEL46 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel46.write_nb(value)){
				inState = READ_CHANNEL47;
			}
		}
		break;
	}
	case READ_CHANNEL47 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL47;
		}
		break;
	}
	case WRITE_CHANNEL47 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel47.write_nb(value)){
				inState = READ_CHANNEL48;
			}
		}
		break;
	}
	case READ_CHANNEL48 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL48;
		}
		break;
	}
	case WRITE_CHANNEL48 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel48.write_nb(value)){
				inState = READ_CHANNEL49;
			}
		}
		break;
	}
	case READ_CHANNEL49 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL49;
		}
		break;
	}
	case WRITE_CHANNEL49 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel49.write_nb(value)){
				inState = READ_CHANNEL50;
			}
		}
		break;
	}
	case READ_CHANNEL50 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL50;
		}
		break;
	}
	case WRITE_CHANNEL50 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel50.write_nb(value)){
				inState = READ_CHANNEL51;
			}
		}
		break;
	}
	case READ_CHANNEL51 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL51;
		}
		break;
	}
	case WRITE_CHANNEL51 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel51.write_nb(value)){
				inState = READ_CHANNEL52;
			}
		}
		break;
	}
	case READ_CHANNEL52 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL52;
		}
		break;
	}
	case WRITE_CHANNEL52 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel52.write_nb(value)){
				inState = READ_CHANNEL53;
			}
		}
		break;
	}
	case READ_CHANNEL53 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL53;
		}
		break;
	}
	case WRITE_CHANNEL53 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel53.write_nb(value)){
				inState = READ_CHANNEL54;
			}
		}
		break;
	}
	case READ_CHANNEL54 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL54;
		}
		break;
	}
	case WRITE_CHANNEL54 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel54.write_nb(value)){
				inState = READ_CHANNEL55;
			}
		}
		break;
	}
	case READ_CHANNEL55 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL55;
		}
		break;
	}
	case WRITE_CHANNEL55 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel55.write_nb(value)){
				inState = READ_CHANNEL56;
			}
		}
		break;
	}
	case READ_CHANNEL56 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL56;
		}
		break;
	}
	case WRITE_CHANNEL56 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel56.write_nb(value)){
				inState = READ_CHANNEL57;
			}
		}
		break;
	}
	case READ_CHANNEL57 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL57;
		}
		break;
	}
	case WRITE_CHANNEL57 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel57.write_nb(value)){
				inState = READ_CHANNEL58;
			}
		}
		break;
	}
	case READ_CHANNEL58 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL58;
		}
		break;
	}
	case WRITE_CHANNEL58 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel58.write_nb(value)){
				inState = READ_CHANNEL59;
			}
		}
		break;
	}
	case READ_CHANNEL59 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL59;
		}
		break;
	}
	case WRITE_CHANNEL59 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel59.write_nb(value)){
				inState = READ_CHANNEL60;
			}
		}
		break;
	}
	case READ_CHANNEL60 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL60;
		}
		break;
	}
	case WRITE_CHANNEL60 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel60.write_nb(value)){
				inState = READ_CHANNEL61;
			}
		}
		break;
	}
	case READ_CHANNEL61 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL61;
		}
		break;
	}
	case WRITE_CHANNEL61 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel61.write_nb(value)){
				inState = READ_CHANNEL62;
			}
		}
		break;
	}
	case READ_CHANNEL62 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL62;
		}
		break;
	}
	case WRITE_CHANNEL62 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel62.write_nb(value)){
				inState = READ_CHANNEL63;
			}
		}
		break;
	}
	case READ_CHANNEL63 : {
		if(in.read_nb(value)){
			inState = WRITE_CHANNEL63;
		}
		break;
	}
	case WRITE_CHANNEL63 : {
		if(value == 0xFFFFFFFF){
			inState = READ_INIT;
		}else{
			if(channel63.write_nb(value)){
				inState = READ_CHANNEL0;
			}
		}
		break;
	}
}

	merge1(channel0, channel1, channel64, sortLength);
	merge2(channel2, channel3, channel65, sortLength);
	merge3(channel4, channel5, channel66, sortLength);
	merge4(channel6, channel7, channel67, sortLength);
	merge5(channel8, channel9, channel68, sortLength);
	merge6(channel10, channel11, channel69, sortLength);
	merge7(channel12, channel13, channel70, sortLength);
	merge8(channel14, channel15, channel71, sortLength);
	merge9(channel16, channel17, channel72, sortLength);
	merge10(channel18, channel19, channel73, sortLength);
	merge11(channel20, channel21, channel74, sortLength);
	merge12(channel22, channel23, channel75, sortLength);
	merge13(channel24, channel25, channel76, sortLength);
	merge14(channel26, channel27, channel77, sortLength);
	merge15(channel28, channel29, channel78, sortLength);
	merge16(channel30, channel31, channel79, sortLength);
	merge17(channel32, channel33, channel80, sortLength);
	merge18(channel34, channel35, channel81, sortLength);
	merge19(channel36, channel37, channel82, sortLength);
	merge20(channel38, channel39, channel83, sortLength);
	merge21(channel40, channel41, channel84, sortLength);
	merge22(channel42, channel43, channel85, sortLength);
	merge23(channel44, channel45, channel86, sortLength);
	merge24(channel46, channel47, channel87, sortLength);
	merge25(channel48, channel49, channel88, sortLength);
	merge26(channel50, channel51, channel89, sortLength);
	merge27(channel52, channel53, channel90, sortLength);
	merge28(channel54, channel55, channel91, sortLength);
	merge29(channel56, channel57, channel92, sortLength);
	merge30(channel58, channel59, channel93, sortLength);
	merge31(channel60, channel61, channel94, sortLength);
	merge32(channel62, channel63, channel95, sortLength);
	merge33(channel64, channel65, channel96, sortLength * 2);
	merge34(channel66, channel67, channel97, sortLength * 2);
	merge35(channel68, channel69, channel98, sortLength * 2);
	merge36(channel70, channel71, channel99, sortLength * 2);
	merge37(channel72, channel73, channel100, sortLength * 2);
	merge38(channel74, channel75, channel101, sortLength * 2);
	merge39(channel76, channel77, channel102, sortLength * 2);
	merge40(channel78, channel79, channel103, sortLength * 2);
	merge41(channel80, channel81, channel104, sortLength * 2);
	merge42(channel82, channel83, channel105, sortLength * 2);
	merge43(channel84, channel85, channel106, sortLength * 2);
	merge44(channel86, channel87, channel107, sortLength * 2);
	merge45(channel88, channel89, channel108, sortLength * 2);
	merge46(channel90, channel91, channel109, sortLength * 2);
	merge47(channel92, channel93, channel110, sortLength * 2);
	merge48(channel94, channel95, channel111, sortLength * 2);
	merge49(channel96, channel97, channel112, sortLength * 4);
	merge50(channel98, channel99, channel113, sortLength * 4);
	merge51(channel100, channel101, channel114, sortLength * 4);
	merge52(channel102, channel103, channel115, sortLength * 4);
	merge53(channel104, channel105, channel116, sortLength * 4);
	merge54(channel106, channel107, channel117, sortLength * 4);
	merge55(channel108, channel109, channel118, sortLength * 4);
	merge56(channel110, channel111, channel119, sortLength * 4);
	merge57(channel112, channel113, channel120, sortLength * 8);
	merge58(channel114, channel115, channel121, sortLength * 8);
	merge59(channel116, channel117, channel122, sortLength * 8);
	merge60(channel118, channel119, channel123, sortLength * 8);
	merge61(channel120, channel121, channel124, sortLength * 16);
	merge62(channel122, channel123, channel125, sortLength * 16);
	merge63(channel124, channel125, out, sortLength * 32);
}
