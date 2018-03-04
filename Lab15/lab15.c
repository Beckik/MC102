// Laboratorio 15B - Brincando com cordas
// Vicenzo Cano Cesconetto
// 206456
#include <stdio.h>
#include <string.h>

int removePadrao(char str[], char padrao[], char targetStr[]) {
	int size=0, flag=0;
	size = strlen(str);
	strcpy (targetStr, str);
	for (int i = 0; i < size; ++i) {
		if (targetStr[i] == padrao[0] && targetStr[i+1] == padrao[1]) {
			for (int j = i; j < size; ++j) {
				targetStr[j] = targetStr[j+2];
				if (targetStr[j+2] == '\0') {
					break;
				}
			}
			flag=1;
			--i;
		}
	}
	return flag;
}

int removeBloco(char str[], char c, char targetStr[]) {
	int size = 0, flag = 0;
	size = strlen(str);
	strcpy (targetStr, str);
	if (targetStr[0] == c) {
		for (int k = 1; k < size; ++k) {
			if (targetStr[k] == c) {
				flag = 1;
				for (int t = 0; t < (size-k); ++t) {
					targetStr[t] = targetStr[t+k+1];
					if (targetStr[t+k+1] == '\0') {
						return 1;
					}
				}
			}
		}
		if (flag == 0) {
			targetStr[0] = '\0';
		}
		return 1;
	}
	return 0;
}

int substituiPadrao(char str[], char padrao[], char novoPadrao[], char targetStr[]) {
	int size = 0, flag = 0;
	size = strlen(str);
	strcpy (targetStr, str);
	for (int i = 0; i < size; ++i) {
		if (targetStr[i+2] == '\0') {
			break;
		}
		else if (targetStr[i] == padrao[0] && targetStr[i+1] == padrao[1] && targetStr[i+2] == padrao[2]) {
			targetStr[i] = novoPadrao[0];
			targetStr[i+1] = novoPadrao[1];
			targetStr[i+2] = novoPadrao[2];
			flag = 1;
		}
	}
	return flag;
}