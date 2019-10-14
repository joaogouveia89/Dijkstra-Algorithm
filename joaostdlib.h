#ifndef JOAOSTDLIB_H
#define JOAOSTDLIB_H

int ctoi(char c){
	switch(c){
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
	return -1;
}


int strtoi(char* strNum){
	int n = 0;
	int idx = 0;
	while(strNum[idx] != '\0'){
		n += ctoi(strNum[idx]);
		if(strNum[idx+1] != '\0'){
			n *= 10;
		}
		idx++;
	}
	return n;
}

#endif // JOAOSTDLIB_H