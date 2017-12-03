#include <iostream>
#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "astar.hpp"
#include "constants.hpp"
#include "map.hpp"
#include "utils.hpp"

int main(int argc, char const *argv[]) {
  /* code */
  UTIL_RandSeed();
  // std::cout << "Hello world!\r\n";

  sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);
  window.setFramerateLimit(60);

  // ASTAR_Test();
  MAP_Clear();
  MAP_GenRandom();

  int xpos = UTIL_RandBetween(1, MAP_WIDTH - 2);
  int ypos = UTIL_RandBetween(1, MAP_HEIGHT - 2);
  Point src(xpos, ypos);

  xpos = UTIL_RandBetween(1, MAP_WIDTH - 2);
  ypos = UTIL_RandBetween(1, MAP_HEIGHT - 2);
  Point dest(xpos, ypos);

  // MAP_Gen();

  astar(&src, &dest);
  // ASTAR_PrintOpen();
  MAP_Print();

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::R) {
              MAP_Clear();
              MAP_GenRandom();

              int xpos = UTIL_RandBetween(1, MAP_WIDTH - 2);
              int ypos = UTIL_RandBetween(1, MAP_HEIGHT - 2);
              src = Point(xpos, ypos);

              xpos = UTIL_RandBetween(1, MAP_WIDTH - 2);
              ypos = UTIL_RandBetween(1, MAP_HEIGHT - 2);
              dest = Point(xpos, ypos);

              // MAP_Gen();

              astar(&src, &dest);
          }
        }
        // if (event.type == sf::Event::MouseButtonPressed) {
        //   blobs.push_back(Blob(BLOB_RADIUS, 2.2 * BLOB_RADIUS, mousePosition.x, mousePosition.y));
        //   std::cout << "blob added" << '\n';
        // }
    }

    MAP_Draw(window);
    window.display();

  }

  return 0;
}