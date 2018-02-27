#include <stdio.h>
#include <stdlib.h>

char **map;
int empire = 0, rebels = 0;
char v[2];
int row, col;


void destroy (int l, int c, char sym) {

	if (c < 1 || c > col)
		return;


	if (l < 1 || l > row)
		return;

	if (map[l][c] == sym) {
		map[l][c] = '-';
		
		destroy(l-1,c, sym);
		destroy(l-1, c-1, sym);
		destroy(l-1, c+1, sym);
		destroy(l, c-1, sym);
		destroy(l, c+1, sym);
		destroy(l+1, c, sym);
		destroy(l+1, c-1, sym);
		destroy(l+1, c+1, sym);
	}

}

int main() {

	v[0] = '*';
	v[1] = '#';

	scanf("%d", &row);
	scanf("%d", &col);
    scanf("\n");

    map = (char**) malloc((row+2)*sizeof(char*));
    for (int l = 0; l <= row+1; ++l) {
        map[l] = (char*) malloc((col+2)*sizeof(char));
    }

    for (int c = 0; c <= col+1; ++c) {
        map[0][c] = 'f';
        map[row+1][c] = 'f';
    }
    for (int l = 0; l <= row+1; ++l) {
        map[l][0] = 'f';
        map[l][col+1] = 'f';
    }

	for(int i = 1; i <= row; ++i) {
		for(int j = 1; j <= col; ++j) {
			scanf("%c ", &map[i][j]);
		}
	}

	for(int i = 1; i <= row; ++i) {
		for(int j = 1; j <= col; ++j) {
			for (int k = 0; k <= 1; ++k) {
				if (map[i][j] == v[k]) {
					if (map[i][j-1] != v[k]) {
						if (map[i-1][j] != v[k]) {
							if (map[i-1][j-1] != v[k]) {
								if (map[i+1][j] != v[k]) {
									if (map[i][j+1] != v[k]) {
										if (map[i+1][j+1] != v[k]) {
											if (map[i-1][j+1] != v[k]) {
												if (map[i+1][j-1] != v[k]) {
													map[i][j] = '-';
													if (k) {
														++rebels;
													}
													else { 
														++empire;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	for(int i = 1; i <= row; ++i) {
		for(int j = 1; j <= col; ++j) {
			for (int k = 0; k <= 1; ++k) {
				if (map[i][j] == v[k]) {
					destroy(i, j, v[k]);
					if(k)
						++rebels;
					else
						++empire;
				}
			}
		}
	}


	printf("Bases rebeldes: %d\n", rebels);
	printf("Bases do imperio: %d\n", empire);
}