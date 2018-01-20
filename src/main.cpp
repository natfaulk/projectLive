#include <iostream>
#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "astar.hpp"
#include "constants.hpp"
#include "map.hpp"
#include "utils.hpp"
#include "checkbox.hpp"
#include "moveable.hpp"
#include "person.hpp"

int frameCount = 0;
// const int FRAME_DIVIDER = 60 / 10;
bool done = false;

int main(int argc, char const *argv[]) {
  /* code */
  UTIL_RandSeed();
  // std::cout << "Hello world!\r\n";

  sf::Font font;
  if (!font.loadFromFile("res/Roboto-Regular.ttf")) {
    std::cout << "Failed to load font. Exiting..." << std::endl;
    return 1;
  }

  // Checkbox testChk(5, 5, false, "Select for timelapse");

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

  // astar(&src, &dest);
  // ASTAR_PrintOpen();
  // MAP_Print();

  // ASTAR_Begin(&src, &dest);
  // MAP_SetData(&src, SRC);
  // MAP_SetData(&dest, DEST);

  if (!UTIL_DirectoryExists("maps"))
  {
    UTIL_Mkdir("maps");
  }
  MAP_SaveToFile("test.mapsav");

  Person hero(10, 10);
  Person hero2(20, 20);
  Moveable player1(1, 1);
  Camera myCam;
  myCam.attachToObject(&player1);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::R) {
            done = false;
            MAP_Clear();
            MAP_GenRandom();
            MAP_SetData(&hero, WALL);
            MAP_SetData(&hero2, WALL);
            MAP_SetData(&player1, WALL);            
            hero.setPos(10, 10);
            hero2.setPos(20, 20);
            player1.setPos(1, 1);
            hero.draw();
            hero2.draw();
            player1.draw();

            // xpos = UTIL_RandBetween(1, MAP_WIDTH - 2);
            // ypos = UTIL_RandBetween(1, MAP_HEIGHT - 2);
            // src = Point(xpos, ypos);

            // xpos = UTIL_RandBetween(1, MAP_WIDTH - 2);
            // ypos = UTIL_RandBetween(1, MAP_HEIGHT - 2);
            // dest = Point(xpos, ypos);

            // ASTAR_Begin(&src, &dest);
            // MAP_SetData(&src, SRC);
            // MAP_SetData(&dest, DEST);
          }
          else if (event.key.code == sf::Keyboard::Up) {
            player1.move(UP);
          }
          else if (event.key.code == sf::Keyboard::Down) {
            player1.move(DOWN);
          }
          else if (event.key.code == sf::Keyboard::Left) {
            player1.move(LEFT);
          }
          else if (event.key.code == sf::Keyboard::Right) {
            player1.move(RIGHT);
          }
        }
        
        if (event.type == sf::Event::MouseButtonPressed) {
          // sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
          // if (testChk.isMouseInside(mousePosition.x, mousePosition.y)) testChk.onClick();
        }
    }

    hero.tick();
    hero2.tick();

    // if (!testChk.value() && !done)
    // {
    //   while (!ASTAR_Step())
    //   {
    //     MAP_SetData(ASTAR_LatestSearched(), SEARCHED);
    //   }

    //   Point nextPoint = ASTAR_PathNextPoint();
    //   while(nextPoint.x >= 0)
    //   {
    //     MAP_SetData(&nextPoint, BEST);
    //     nextPoint = ASTAR_PathNextPoint();
    //   }
    //   MAP_SetData(&src, SRC);
    //   MAP_SetData(&dest, DEST);
    //   done = true;
    // }
    // else if (frameCount++ >= FRAME_DIVIDER)
    // {
    //   frameCount = 0;
    //   if (!ASTAR_Step())
    //   {
    //     MAP_SetData(ASTAR_LatestSearched(), SEARCHED);
    //   }
    //   else if(!done)
    //   {
    //     Point nextPoint = ASTAR_PathNextPoint();
    //     while(nextPoint.x >= 0)
    //     {
    //       MAP_SetData(&nextPoint, BEST);
    //       nextPoint = ASTAR_PathNextPoint();
    //     }
    //     MAP_SetData(&src, SRC);
    //     MAP_SetData(&dest, DEST);
    //     done = true;
    //   }

    //   MAP_Draw(window);
    //   testChk.draw(window, font);
    //   window.display();
    // }

    MAP_Draw(window, &myCam);
    // testChk.draw(window, font);
    window.display();


  }

  return 0;
}