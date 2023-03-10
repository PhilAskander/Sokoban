// Copyright 2022 Philopater Askander
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
using namespace std;
class sokoban: public sf::Drawable {
       public: 
              sokoban();
              void tokenize(std::string const &str,
              const char delim, std::vector<int> &out);
                  std::vector<int> getLevel(string infile);
              //sokoban movePlayer(void);  // Not supposed to do anything
              void movePlayer(sf::Keyboard::Key key, sf::RenderWindow &window); 
	     // void update(sf::RenderWindow &window);
	      void draw(std::vector<int> array_size, char** map, sf::Sprite image, sf::RenderWindow& window); 
              //void draw(sf::RenderWindow& window);
       private:
               char **map;  // dynamic two-dimensional array
               void getCurrent();
               sf::Texture initialPositionTexture;
               sf::Texture emptySpaceTexture;
               sf::Texture wallTexture;
               sf::Texture boxTexture;  // all textures go in class body
               sf::Texture storageLocationTexture;
               sf::Sprite image;
	       sf::Sprite box;
	       sf::Sprite character;
	       sf::Texture characterUpTexture;
	       sf::Texture characterLeftTexture;
               sf::Texture characterRightTexture;
	       sf::Texture prevImage;
	       sf::Sprite currPrevImage;
	       vector <int> myChar;
	       vector <int> myBox;
	    //   map<int, int> wallCoordinates;
	       unsigned int characterPositionX;
	       unsigned int characterPositionY;
	       unsigned int oldCharacterPositionX;
	       unsigned int oldCharacterPositionY;
	       bool up;
	       bool down;
	       bool left;
	       bool right;
	       //sf::Sprite imageTwo;
               virtual void draw(sf::RenderTarget& target,
                sf::RenderStates states)const {
               target.draw(image);
                }
};

