#ifndef CHAR_EXTENSION_H
#define CHAR_EXTENSION_H

char itoc(int n){
	switch(n){
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
	}
}

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
}

float getMatrixValue(char c){
	switch(c){
		case '0':
			return 0.0;
		case '1':
			return 1.0;
		case '2':
			return 2.0;
		case '3':
			return 3.0;
		case '4':
			return 4.0;
		case '5':
			return 5.0;
		case '6':
			return 6.0;
		case '7':
			return 7.0;
		case '8':
			return 8.0;
		case '9':
			return 9.0;
		case 'i':
			return -1.0;
	}
}
#endif // CHAR_EXTENSION_H
