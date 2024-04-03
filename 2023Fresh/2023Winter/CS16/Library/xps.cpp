#include "xps.h"

using namespace std;

int    xps_compare(const char* lhs, const char* rhs) {
	int llen = xps_length(lhs);
	int rlen = xps_length(rhs);
	int min = rlen;
	if (llen < rlen) min = llen;
	for (int i = 0; i < min; i++) {
		char l = xps_getchar(lhs, i);
		char r = xps_getchar(rhs, i);
		if (l-r == 0) {
			continue;
		} else if (l-r > 0) {
			return 1;
		} else {
			return -1;
		}		
	}
	if (llen > rlen) {
		return 1; 
	} else if (llen < rlen) {
		return -1;
	} else {
		return 0;
	}
}

char*  xps_concat(const char* lhs, const char* rhs) {
	int llen = xps_length(lhs);
	int rlen = xps_length(rhs);
	int tot = llen+rlen;
	int xpslen = tot + tot/15 + 1; 
	char* newstr = new char[xpslen];
	int k = 0;
	int fs = tot/15;
	int rem = tot-fs*15;
	for (int i = 0; i < fs; i++, k+= 16) {
		newstr[k] = 15;
	}
	newstr[k] = rem;
	k = 0;
	for (int i = 0; i < llen; i++, k++) {
		if (k % 16 == 0) k++;
		newstr[k] = xps_getchar(lhs, i);
	}
	for (int i = 0; i < rlen; i++, k++) {
		if (k % 16 == 0) k++;
		newstr[k] = xps_getchar(rhs, i);
	}
	return newstr;
}

size_t xps_find(const char* str, const char* pattern) {
	int len = xps_length(str);
	int plen = xps_length(pattern);
	for (int i = 0; i <= len-plen; i++) {
		bool match = true;
		for (int j = 0; j < plen; j++) {
			if (xps_getchar(str, j+i) != xps_getchar(pattern, j)) {
				match = false;
			}
		}
		if (match) {
			return i;
		}
	}
	return XPS_NPOS;
}

size_t xps_find(const char* str, const char* pattern, size_t start) {
	int len = xps_length(str);
	int plen = xps_length(pattern);
	for (int i = start; i <= len-plen; i++) {
		bool match = true;
		for (int j = 0; j < plen; j++) {
			if (xps_getchar(str, j+i) != xps_getchar(pattern, j)) {
				match = false;
			}
		}
		if (match) {
			return i;
		}
	}
	return XPS_NPOS;
}

void   xps_free(char* str) {
	delete[] str;
}

int cstr_length(const char* cstr) {
	int len = 0;
	while (*cstr != '\0') {
		cstr++;
		len++;
	}
	return len;
}

char*  xps_from_cstr(const char* cstr) {
	int len = cstr_length(cstr);
	int xpslen = len + len/15 + 1;
	char* newstr = new char[xpslen];
	int fs = len/15;
	int rem = len-fs*15;
	int k = 0;	
	for (int i = 0; i < fs; i++, k+=16) {
		newstr[k] = 15;
	}
	newstr[k] = rem;
	int cnt = 0;
	for (int i = 0; i < xpslen; i++) {
		if (i % 16 == 0) i++;
		if (cnt == len) break;
		
		//cout << "newstr[i]: " << *cstr << endl;
		
		newstr[i] = *cstr;
		cstr++;
		cnt++;
	}
	return newstr;
}

char   xps_getchar(const char* str, size_t index) {
	int cnt = 0;
	str++;
	while (index--) {
		str++;
		cnt++;
		if (cnt == 15) {
			cnt = 0;
		  	str++;	
		}
	}	
	return *str;
}

size_t xps_length(const char* str) {
	size_t len = 0;
	while (true) {
		int next = *str;
		if (*str < 15) { 
			len += next;
			break;
		} else {
			len += 15;
			str+=16;
		}
	}	
	return len;
}

void   xps_setchar(char* str, size_t index, char c) {
	int cnt = 0;
	str++;
	while (index--) {
		str++;
		cnt++;
		if (cnt == 15) {
			cnt = 0;
		  	str++;	
		}
	}	
	*str = c; 
}

char* xps_slice(const char* str, size_t start) {
	int len = xps_length(str);
	if (start >= (size_t)len) {
		char* empty = new char[1];
		empty[0] = '\0';
		return empty;
	}
	int newlen = len - start;
	int xpsnewlen = newlen/15 + newlen + 1;

	char* newstr = new char[xpsnewlen];
	//first put down the 15's	
	int fs = newlen/15;
	int rem = newlen-fs*15;
	int k = 0;	
	for (int i = 0; i < fs; i++, k+=16) {
		newstr[k] = 15;
	}
	newstr[k] = rem;

	k = start;
	for (int i = 0; i < xpsnewlen; i++) {
		if (i % 16 == 0) {
			continue;
		}
		newstr[i] = xps_getchar(str, k);
		k++;
	}
	return newstr;
}

char*  xps_slice(const char* str, size_t start, size_t stop) {
	int len = xps_length(str);
	if (start >= (size_t)len || stop <= start) {
		char* empty = new char[1];
		empty[0] = '\0';
		return empty;
	}
	if (stop > (size_t)len) {
		return xps_slice(str, start);
	}
	int newlen = stop - start;
	int xpsnewlen = newlen/15 + newlen + 1;
	char* newstr = new char[xpsnewlen];
	//first put down the 15's	
	int fs = newlen/15;
	int rem = newlen-fs*15;
	int k = 0;	
	for (int i = 0; i < fs; i++, k+=16) {
		newstr[k] = 15;
	}
	newstr[k] = rem;

	k = start;
	for (int i = 0; i < xpsnewlen; i++) {
		if (i % 16 == 0) {
			continue;
		}
		newstr[i] = xps_getchar(str, k);
		k++;
	}
	return newstr;
}
