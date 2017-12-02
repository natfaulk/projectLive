#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const int MAP_WIDTH = 75;
const int MAP_HEIGHT = 20;

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

enum MapTiles {FLOOR, WALL, SRC, DEST, CUR_POS, SEARCHED, BEST};

// ----------------------------------------------------------------------------
// Mapgen
// ----------------------------------------------------------------------------
const int MG_NUM_WALLS_MIN = 10;
const int MG_NUM_WALLS_MAX = (MAP_WIDTH - 2) * (MAP_HEIGHT - 2) * 0.5;

#endif /* end of include guard: CONSTANTS_HPP */