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
	//int rows = array_size[0];
	//int columns = array_size[1];
	//for(int i = 0; i<rows*columns; i++){
	sf::Sprite image;
	test.draw(array_size, map, image);
	//}
	newfile.close();
	//test.draw(array_size, map);
       return 0;
}

