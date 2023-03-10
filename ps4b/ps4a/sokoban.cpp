// Copyright 2022 Philopater Askander
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include "sokoban.hpp"
using namespace std;
using namespace sf;

sokoban::sokoban() {
    this->initialPositionTexture.loadFromFile("sokoban/player_05.png");
    this->emptySpaceTexture.loadFromFile("sokoban/ground_01.png");
    this->wallTexture.loadFromFile("sokoban/block_06.png");
    this->boxTexture.loadFromFile("sokoban/crate_03.png");
    this->storageLocationTexture.loadFromFile("sokoban/ground_04.png");
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
void sokoban::draw(std::vector<int> array_size, char** map, sf::Sprite image){
        int count = 0;      
	sf::RenderWindow window(sf::VideoMode
			(array_size[0]*64, array_size[1]*64),"Sokoban!");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type== sf::Event::Closed)
				window.close();
			for (int i = 0; i < array_size[0]; ++i) {
				for (int j = 0; j < array_size[1]; ++j) {
					if (map[j][i] == '#') {
						count++;  
						this->image.setPosition(i*64, j*64);
						this->image.setTexture(this->wallTexture);
						//cout << "wall texture has been read" << endl;
					}  // put all this into istream operator
					else if (map[j][i] == 'O') {
						count++; 
						this->image.setPosition(i*64, j*64);
						this->image.setTexture(this->boxTexture);
						//cout << "box texture has been read" << endl;
					}
					else if (map[j][i] == '@') {
						count++;
						this->image.setPosition(i*64, j*64);
						this->image.setTexture(
								this->initialPositionTexture);
						//cout << 
						//	"initialPosition texture has been read" << endl;
					}
					else if (map[j][i] == '.') {
						count++;
						this->image.setPosition(i*64, j*64);
						this->image.setTexture(this->emptySpaceTexture);
						//cout << 
						//	"empty space texture has been read" << endl;
					}
					else {
						count++;
						this->image.setPosition(i*64, j*64);
						this->image.setTexture
							(this->storageLocationTexture);
						//cout << 
						//	"storageLocation texture has been read" << endl;
					}
					window.draw(this->image);	
				}
				//cout <<count << endl;
			}
		}
		window.display();
	}
}


