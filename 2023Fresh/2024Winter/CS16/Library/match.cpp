#include "xps.h"

using namespace std;

void print_input_error() {
	const char* cstr = "USAGE: match [pattern]";
	xps_writeline(xps_from_cstr(cstr));
}

bool detect_input_error(int argc) {
	if (argc != 2) {
		return true;
	}
	return false;
}

int main(int argc, char** argv) {
	if (detect_input_error(argc)) {
		print_input_error();
		return 1;
	}	
	const char* strmatch = "Match!";
	const char* no_match = "No match.";
	char* xps_match = xps_from_cstr(strmatch); 
	char* xps_no_match = xps_from_cstr(no_match);
	char* star = new char[2];
	star[0] = 1;
	star[1] = '*';
	char* pattern = xps_from_cstr(argv[1]);
	char* match = xps_readline();
	while (match != nullptr) {
		size_t pat_occ = xps_find(pattern, star);
		if (pat_occ == XPS_NPOS) {
			//no * in the pattern
			size_t match_occ = xps_find(match, pattern);
			if (match_occ == XPS_NPOS) {
				xps_writeline(xps_no_match);
			} else {
				xps_writeline(xps_match);
			}
		} else {
			//* in pattern 	
			bool bmatch = true;
			size_t pat_front = 0;
			size_t match_front = 0;
			while (pat_occ != XPS_NPOS) {
				char* subpat = xps_slice(pattern, pat_front, pat_occ);
				size_t subpat_len = xps_length(subpat);
				pat_front = pat_occ+1;
				//test if subpat is in
				size_t match_occ = xps_find(match, subpat, match_front);
				if (match_occ == XPS_NPOS) {
					bmatch=false;
					xps_free(subpat);
					break;
				} else {
					match_front = match_occ+subpat_len;
				}
				pat_occ = xps_find(pattern, star, pat_front);
				xps_free(subpat);
			}
			if (bmatch) {
				char* subpat = xps_slice(pattern, pat_front);
				size_t match_occ = xps_find(match, subpat, match_front);
				if (match_occ == XPS_NPOS) {
					xps_writeline(xps_no_match);
				} else {	
					xps_writeline(xps_match);
				}
				xps_free(subpat);
			} else {
				xps_writeline(xps_no_match);
			}
		}
		xps_free(match);
		match = xps_readline();
	}
	xps_free(star);
	xps_free(pattern);
	xps_free(xps_match);
	xps_free(xps_no_match);
}
