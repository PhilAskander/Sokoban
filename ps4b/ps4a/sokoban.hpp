// Copyright 2022 Philopater Askander
#include <iostream>
#include <fstream>
#include <string>
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
              sokoban movePlayer(void);  // Not supposed to do anything
              void draw(std::vector<int> array_size, char** map, sf::Sprite image); 
        
       private:
               char **map;  // dynamic two-dimensional array
               void getCurrent();
               sf::Texture initialPositionTexture;
               sf::Texture emptySpaceTexture;
               sf::Texture wallTexture;
               sf::Texture boxTexture;  // all textures go in class body
               sf::Texture storageLocationTexture;
               sf::Sprite image;
               virtual void draw(sf::RenderTarget& target,
                sf::RenderStates states)const {
               target.draw(image);
                }
};

