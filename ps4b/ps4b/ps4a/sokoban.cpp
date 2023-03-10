// Copyright 2022 Philopater Askander
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include "sokoban.hpp"
using namespace std;
using namespace sf;

sokoban::sokoban(){ 
	this->initialPositionTexture.loadFromFile("sokoban/player_05.png");
	this->emptySpaceTexture.loadFromFile("sokoban/ground_01.png");
	this->wallTexture.loadFromFile("sokoban/block_06.png");
	this->boxTexture.loadFromFile("sokoban/crate_03.png");
	this->storageLocationTexture.loadFromFile("sokoban/ground_04.png");
	this->characterUpTexture.loadFromFile("sokoban/player_08.png");
	this->characterLeftTexture.loadFromFile("sokoban/player_20.png");
	this->characterRightTexture.loadFromFile("sokoban/player_17.png");
	this->up = false;
	this->down = false;
	this->right = false;
	this->left = false;
	return;
}
void sokoban::tokenize(
		std::string const &str, const char delim, std::vector<int> &out) {
	std::stringstream ss(str);
	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(stoi(s));
	}
}
void sokoban::draw(std::vector<int> array_size, char** map, sf::Sprite image, sf::RenderWindow& window){
	int count = 0; 
	
	for (int i = 0; i < array_size[0]; ++i) {
				for (int j = 0; j < array_size[1]; ++j) {
					if (map[j][i] == '#') {
						this->image.setPosition(i*64, j*64);
						this->image.setTexture(this->wallTexture);
						this->myChar.push_back(count);
						count++;
					}
					else if (map[j][i] == 'O') {
						this->myBox.push_back(count);
						this->image.setPosition(i*64, j*64);
						this->image.setTexture(this->boxTexture);
						count++;
					}
					else if (map[j][i] == '@') {
						count++;
						this->image.setPosition(i*64,j*64);
						this->image.setTexture(this->emptySpaceTexture);
						this->character.setPosition(i*64, j*64);
						this->character.setTexture(
								this->initialPositionTexture);
						this->characterPositionX = i*64;
						this->characterPositionY = j*64;	
					}
					
					else if (map[j][i] == '.') {
						count++;
						this->image.setPosition(i*64, j*64);
						this->image.setTexture(this->emptySpaceTexture);
					}
					else {
						count++;
						this->image.setPosition(i*64, j*64);
						this->image.setTexture
							(this->storageLocationTexture);
					}
					
					window.draw(this->character);
					window.draw(this->image);
			//	draw(count, window);
		//		cout <<count << endl;
				}
	}

 for_each(this->myBox.begin(), this->myBox.end(), [](int i){
             std::cout << i << " " << endl;
	     });
/*
	for(int i = 0; i<this->myBox.size(); i++){
	cout <<this->myBox.at(i) << endl;
	}
*/
	}


void sokoban::movePlayer(sf::Keyboard::Key key, sf::RenderWindow &window){

	if(key == sf::Keyboard::Up || key == sf::Keyboard::W)
		this->up = true;
	if(key == sf::Keyboard::Down || key == sf::Keyboard::S)
		this->down = true;
	if(key == sf::Keyboard::Left || key == sf::Keyboard::A)
		this->left = true;
	if(key == sf::Keyboard::Right || key == sf::Keyboard::D)
		this->right = true;

	if(this->up && !std::count(this->myChar.begin(), this->myChar.end(), ((this->characterPositionX/64)*10)+((this->characterPositionY-64)/64))){
		this->oldCharacterPositionY = this->characterPositionY;
		this->characterPositionY -=64;
		this->character.setPosition(this->characterPositionX, this->characterPositionY);
		this->image.setPosition(this->characterPositionX, this->oldCharacterPositionY);
		this->character.setTexture(this->characterUpTexture);	
		this->prevImage = this->characterUpTexture;

		if(std::count(this->myBox.begin(), this->myBox.end(), ((this->characterPositionX/64)*10)+(this->characterPositionY/64)) && 
				!std::count(this->myChar.begin(), this->myChar.end(), ((this->characterPositionX/64)*10)+((this->characterPositionY)/64))){

			this->box.setPosition(this->characterPositionX, this->characterPositionY-64/64);
			this->myBox.push_back(((this->characterPositionX/64)*10)+((this->characterPositionY-64)/64));
			//this->myBox.begin(), this->myBox.end(),(((this->characterPositionX/64)*10)+((this->characterPositionY)/64));
		this->myBox.erase(std::remove(this->myBox.begin(), this->myBox.end(), (((this->characterPositionX/64)*10)+((this->characterPositionY)/64))), this->myBox.end());	
		}
			this->box.setTexture(this->boxTexture);
			
			//this->currPrevImage.setPosition(this->characterPositionX, this->characterPositionY);
			//this->currPrevImage.setTexture(this->emptySpaceTexture);
			window.draw(box);

		
		cout <<"Player moved up, characterPositionY = " << this->characterPositionY << endl;
	}
	else if (this->down && !std::count(this->myChar.begin(), this->myChar.end(), ((this->characterPositionX/64)*10)+((this->characterPositionY+64)/64))){// && this->map[this->characterPositionX][this->characterPositionY] != '#'){
		this->oldCharacterPositionY = this->characterPositionY;
		this->characterPositionY +=64;
		this->character.setPosition(this->characterPositionX, this->characterPositionY);
		this->image.setPosition(this->characterPositionX, this->oldCharacterPositionY);
		this->character.setTexture(this->initialPositionTexture);
		this->prevImage = this->initialPositionTexture;
		
		if(std::count(this->myBox.begin(), this->myBox.end(), ((this->characterPositionX/64)*10)+(this->characterPositionY/64)) &&
				!std::count(this->myChar.begin(), this->myChar.end(), ((this->characterPositionX/64)*10)+((this->characterPositionY)/64))){

			this->box.setPosition(this->characterPositionX, this->characterPositionY+64/64);
			this->myBox.push_back(((this->characterPositionX/64)*10)+((this->characterPositionY+64)/64));
		//	remove(this->myBox.begin(), this->myBox.end(),((this->characterPositionX/64)*10)+((this->characterPositionY)/64));
					this->myBox.pop_back();
			this->box.setTexture(this->boxTexture);
			                                                window.draw(box);
		}                                                                
		cout <<"Player moved down, characterPositionY = " << this->characterPositionY << endl;
	}
		else if(this->right && !std::count(this->myChar.begin(), this->myChar.end(), (((this->characterPositionX+64)/64)*10)+((this->characterPositionY)/64))){
			this->oldCharacterPositionX = this->characterPositionX;
			this->characterPositionX+=64;
			this->image.setPosition(this->oldCharacterPositionX, this->characterPositionY);	
			this->character.setPosition(this->characterPositionX, this->characterPositionY);
			this->character.setTexture(this->characterRightTexture);
			this->prevImage = this->characterRightTexture;
			
			if(std::count(this->myBox.begin(), this->myBox.end(), ((this->characterPositionX/64)*10)+(this->characterPositionY/64)) &&
					!std::count(this->myChar.begin(), this->myChar.end(), ((this->characterPositionX/64)*10)+((this->characterPositionY)/64))){
				this->box.setPosition(this->characterPositionX+64, this->characterPositionY/64);
				this->myBox.push_back(((this->characterPositionX+64/64)*10)+((this->characterPositionY)/64));
				remove(this->myBox.begin(), this->myBox.end(), ((this->characterPositionX/64)*10)+((this->characterPositionY)/64));
				this->box.setTexture(this->boxTexture);
				window.draw(box);

			}
			cout << "Player moved right, characterPositionX = " << this->characterPositionX << endl;
		}
	else if(this->left && !std::count(this->myChar.begin(), this->myChar.end(), (((this->characterPositionX-64)/64)*10)+((this->characterPositionY)/64))){
		this->oldCharacterPositionX = this->characterPositionX;
		this->characterPositionX -= 64;
		this->image.setPosition(this->oldCharacterPositionX, this->characterPositionY);
		this->character.setPosition(this->characterPositionX, this->characterPositionY);
		this->character.setTexture(this->characterLeftTexture);
		this->prevImage = this->characterLeftTexture;
		if(std::count(this->myBox.begin(), this->myBox.end(), ((this->characterPositionX/64)*10)+(this->characterPositionY/64)) &&
				!std::count(this->myChar.begin(), this->myChar.end(), ((this->characterPositionX/64)*10)+((this->characterPositionY)/64))){

			this->box.setPosition(this->characterPositionX-64, this->characterPositionY/64);
			this->myBox.push_back(((this->characterPositionX-64/64)*10)+((this->characterPositionY)/64));
			remove(this->myBox.begin(), this->myBox.end(), ((this->characterPositionX/64)*10)+((this->characterPositionY)/64));
			this->box.setTexture(this->boxTexture);
			                                                window.draw(box);
			
			                                                                }
		cout << "Player moved left, characterPositionX = " << this->characterPositionX << endl;	
	}
	else{
		this->characterPositionX = this->characterPositionX;
		this->characterPositionY = this->characterPositionY;
		this->character.setPosition(this->characterPositionX, this->characterPositionY);
		this->character.setTexture(this->prevImage);
		//cout <<"Player can no longer move" << endl;
		return;
	}
	this->image.setTexture(this->emptySpaceTexture);
	window.draw(this->image);
	window.draw(this->character);

	this->up = false;
	this->down = false;
	this->right = false;
	this->left = false;

	}
