#include <memory>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <math.h>
#include <memory>
#include <string>
#include <cstring>
#include "sokoban.hpp"
#include <vector>
#define WINDOW_SIZE 500
using namespace std;
using namespace sf;
int main(int argc, const char * argv[]){
	sokoban test;
	string filename = argv[1];
	int row_number = -1;
	std::vector<int> array_size;
	char** map;
	ifstream newfile(filename);
	if (!newfile.is_open()) {
		cout <<"File has not been opened" << endl;
	}
	else {
		string tp;
		if (newfile.is_open()) {
			while (getline(newfile, tp)) {
				if (row_number == -1) {
					test.tokenize(tp, ' ', array_size);
					map = new char*[array_size[0]];
					for(int i = 0; i < array_size[0]; ++i)
						map[i] = new char[array_size[1]];
				}
				else {strcpy (map[row_number], tp.c_str());}
				row_number++;
			}
		}
	}
	 int x = array_size[0]*64;
	 int y = array_size[1]*64;
	sf::Sprite image;
	sf::RenderWindow window(sf::VideoMode
			(x, y),"Sokoban!");
	test.draw(array_size, map, image, window);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			//test.draw(array_size, map, image, window);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
					test.draw(array_size, map, image, window);
					}
			if (event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::A)
				test.movePlayer(sf::Keyboard::A, window);
				if(event.key.code == sf::Keyboard::W)
					test.movePlayer(sf::Keyboard::W, window);
				if(event.key.code == sf::Keyboard::S)
					test.movePlayer(sf::Keyboard::S, window);
				if(event.key.code == sf::Keyboard::D)
					test.movePlayer(sf::Keyboard::D, window);
			}
		}
	//test.update(window);
//	window.draw(test.image);
	window.display();
	}
	cout << "Drawing is complete" << endl;
	newfile.close();
	return 0;
}

