#include "xps.h"

using namespace std;

int main() {
	char* xps = xps_readline();
	while (xps != nullptr) {
		int len = xps_length(xps);
		if (len <= 20) {
			xps_writeline(xps);
		} else {
			char* fill = new char[4];
			fill[0] = 3;
			fill[1] = '.';
			fill[2] = '.';
			fill[3] = '.';
			char* front = xps_slice(xps, 0, 10);
			char* back = xps_slice(xps, len-7);
			xps_write(front);
			xps_write(fill);
			xps_writeline(back);
			
			xps_free(fill);
			xps_free(front);
			xps_free(back);
		}
		xps_free(xps);
		xps = xps_readline();
	}
	xps_free(xps);
}
