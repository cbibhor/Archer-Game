#include "stdafx.h"
#include "BoxCollision.h"

BoxCollision::BoxCollision(float Left, float Right, float Top, float Bottom){

	top = Top;
	bottom = Bottom;
	right = Right;
	left = Left;
}

void BoxCollision::updateTop(float Top){
	top = Top;
}

void BoxCollision::updateBottom(float Bottom){
	bottom = Bottom;
}

void BoxCollision::updateRight(float Right){
	right = Right;
}

void BoxCollision::updateLeft(float Left){
	left = Left;
}

bool BoxCollision::isCollision(float pointX, float pointY){
	if(pointX > left && pointX < right){
		if(pointY > top && pointY < bottom)
			return true;
	}
	return false;
}