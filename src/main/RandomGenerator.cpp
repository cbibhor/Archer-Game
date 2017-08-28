#include "stdafx.h"
#include "RandomGenerator.h"

randomGenerator::randomGenerator(){
}

int randomGenerator::generateRandom(int maxNum){
	srand((unsigned)time(NULL));
	if(maxNum-1 == RAND_MAX){
		return rand();
	}
	else{
		long end = RAND_MAX / maxNum;
		end*=maxNum;
		int r;
		while((r=rand()) >= end);
		return r%maxNum;
	}
}