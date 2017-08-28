#include "stdafx.h"
#include "Sound.h"

SoundClass::SoundClass(){
	buffer.loadFromFile("Sounds/cheering.wav");
	sound.setBuffer(buffer);

	music.openFromFile("Sounds/Tsuna Awakens.wav");
	music.play();
	music.setLoop(true);
}

void SoundClass::playCheering(){
	sound.play();
}