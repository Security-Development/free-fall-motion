#include <stdio.h>
#include <windows.h>
#include <math.h>
#define MAP_SIZE 15

int map[MAP_SIZE][MAP_SIZE] = { 0, };

void view_map() {
	system("cls");
	for(int i = MAP_SIZE - 1; i >= 0; i--) {
		for(int j = 0; j < MAP_SIZE - 1; j++) {
			if( map[i][j] == 1 ) {
				printf("■");
			} else {
				printf("□");
			}
		}
		printf("\n"); 
	}
}

int main() {
	float v0,v, a, s;
	v0 = 0; // 초기 속도 
	a = 5; // 가속도
	int down = MAP_SIZE - 1;
	
	for(float t = 1; t < MAP_SIZE; t++) {
		v = v0 + (a * t); // 속도 
		s = (v0 * t) + ( (a * pow(t, 2) / 2 )  ); // 거리 
		map[down][5] = 0;
		map[--down][5] = 1;
		printf("속력 : %f(m/s) | 거리 : %fm\n", 1 - (v / 100 * 2), s);
		view_map();
		Sleep( 1 - (v / 100 * 2));
	}
	
	return 0;
}
