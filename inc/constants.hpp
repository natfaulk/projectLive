#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <SFML/Graphics/Color.hpp>

const int MAP_WIDTH = 65;
const int MAP_HEIGHT = 40;

// ----------------------------------------------------------------------------
// Graphics
// ----------------------------------------------------------------------------
const char CHAR_FLOOR = '_';
const char CHAR_WALL = '8';
const char CHAR_SRC = 'S';
const char CHAR_DEST = 'D';
const char CHAR_CURRENT_POS = 'C';
const char CHAR_SEARCHED = '*';
const char CHAR_BESTPATH = '.';

enum MapTiles {FLOOR, WALL, SRC, DEST, CUR_POS, SEARCHED, BEST, MOVEABLE, MAP_TILES_LEN};

// ----------------------------------------------------------------------------
// SFML Graphics
// ----------------------------------------------------------------------------
const int TILE_SIZE = 25;
const int SCREEN_WIDTH = MAP_WIDTH * TILE_SIZE;
const int SCREEN_HEIGHT= MAP_HEIGHT * TILE_SIZE;
const char* const WINDOW_TITLE = "A STAR SFML";

const sf::Color FLOOR_COLOR = sf::Color::White;
const sf::Color WALL_COLOR = sf::Color::Red;
const sf::Color SRC_COLOR = sf::Color::Yellow;
const sf::Color DEST_COLOR = sf::Color::Blue;
const sf::Color CURRENT_POS_COLOR = sf::Color::Black;
const sf::Color SEARCHED_COLOR = sf::Color(150, 150, 150);
const sf::Color BESTPATH_COLOR = sf::Color::Black;
const sf::Color MOVEABLE_COLOR = sf::Color::Blue;

const sf::Color* const MapTileColors[MAP_TILES_LEN] =
{
  &FLOOR_COLOR
  , &WALL_COLOR
  , &SRC_COLOR
  , &DEST_COLOR
  , &CURRENT_POS_COLOR
  , &SEARCHED_COLOR
  , &BESTPATH_COLOR
  , &MOVEABLE_COLOR
};

// ----------------------------------------------------------------------------
// Mapgen
// ----------------------------------------------------------------------------
const int MG_NUM_WALLS_MIN = 10;
const int MG_NUM_WALLS_MAX = (MAP_WIDTH - 2) * (MAP_HEIGHT - 2) * 0.5;

#endif /* end of include guard: CONSTANTS_HPP */