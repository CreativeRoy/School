#include "xps.h"

using namespace std;

void print_input_error() {
	const char* cstr = "USAGE: replace [old] [new]";
	xps_writeline(xps_from_cstr(cstr));
}

bool detect_input_error(int argc) {
	if (argc != 3) {
		return true;
	}
	return false;
}

int main(int argc, char** argv) {
	if (detect_input_error(argc)) {
		print_input_error();
		return 1;
	}
	char* xps = xps_readline();
	char* rep_old = xps_from_cstr(argv[1]);
	char* rep_new = xps_from_cstr(argv[2]);
	int olen = xps_length(rep_old);
	int nlen = xps_length(rep_new);
	while (xps != nullptr) {
		//find occurence 
		int ind = 0;
		size_t occ = xps_find(xps, rep_old, ind);
		while (occ != XPS_NPOS) {
			//substring it out 
			char* front = xps_slice(xps, 0, occ);
			char* back = xps_slice(xps, occ+olen);
			char* concatfront = xps_concat(front,rep_new);
			
			xps_free(xps);	
			xps = xps_concat(concatfront, back);
			
			ind = occ + nlen;
			occ = xps_find(xps, rep_old, ind);
			
			xps_free(front);
			xps_free(back);
			xps_free(concatfront);
		}
		xps_writeline(xps);
		xps_free(xps);
		xps = xps_readline();
	}
	xps_free(rep_old);
	xps_free(rep_new);
	xps_free(xps);
}
