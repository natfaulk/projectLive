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

enum MapTiles {
  FLOOR
  , WALL
  , SRC
  , DEST
  , CUR_POS
  , SEARCHED
  , BEST
  , MOVEABLE
  , WATER
  , FOOD
  , BED

  // -------------------------
  // new items above this line
  , MAP_TILES_LEN
};

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
const sf::Color MOVEABLE_COLOR = sf::Color::Black;
const sf::Color WATER_COLOR = sf::Color::Blue;
const sf::Color FOOD_COLOR = sf::Color(0x9e, 0x66, 0x06);
const sf::Color BED_COLOR = sf::Color(0x8b, 0x07, 0xb7);

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
  , &WATER_COLOR
  , &FOOD_COLOR
  , &BED_COLOR
};

// ----------------------------------------------------------------------------
// Mapgen
// ----------------------------------------------------------------------------
const int MG_NUM_WALLS_MIN = 10;
const int MG_NUM_WALLS_MAX = (MAP_WIDTH - 2) * (MAP_HEIGHT - 2) * 0.1;

#endif /* end of include guard: CONSTANTS_HPP */