#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include <SFML/Graphics.hpp>

class Checkbox {
public:
  Checkbox(int _x, int _y);
  Checkbox(int _x, int _y, bool _val);
  Checkbox(int _x, int _y, bool _val, const char* _label);
  bool value(void);
  void set(bool _val);
  void draw(sf::RenderWindow &window);
  void draw(sf::RenderWindow &window, sf::Font font);
  void onClick(void);
  bool isMouseInside(int mouseX, int mouseY);
private:
  int x;
  int y;
  bool val;
  char label[50];
};

#endif /* end of include guard: CHECKBOX_HPP */