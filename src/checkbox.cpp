#include "checkbox.hpp"
#include <cstring>

const int CHK_WIDTH = 50;
const int CHK_INNER_WIDTH = 36;
const int CHK_INNER_OFFSET = (CHK_WIDTH - CHK_INNER_WIDTH) / 2;
const int CHK_TRUE_WIDTH = 22;
const int CHK_TRUE_OFFSET = (CHK_WIDTH - CHK_TRUE_WIDTH) / 2;

Checkbox::Checkbox(int _x, int _y):
x(_x),
y(_y),
val(false)
{
  label[0] = '\0';
}

Checkbox::Checkbox(int _x, int _y, bool _val):
x(_x),
y(_y),
val(_val)
{
  label[0] = '\0';  
}

Checkbox::Checkbox(int _x, int _y, bool _val, const char* _label):
x(_x),
y(_y),
val(_val)
{
  strcpy(label, _label);  
}

bool Checkbox::value(void)
{
  return val;
}

void Checkbox::set(bool _val)
{
  val = _val;
}

void Checkbox::draw(sf::RenderWindow &window)
{
  sf::RectangleShape rectangle(sf::Vector2f(CHK_WIDTH, CHK_WIDTH));
  rectangle.setFillColor(sf::Color::Green);
  rectangle.setPosition(sf::Vector2f(x, y));
  window.draw(rectangle);

  rectangle = sf::RectangleShape(sf::Vector2f(CHK_INNER_WIDTH, CHK_INNER_WIDTH));
  rectangle.setFillColor(sf::Color::White);
  rectangle.setPosition(sf::Vector2f(x + CHK_INNER_OFFSET, y + CHK_INNER_OFFSET));
  window.draw(rectangle);

  if (val)
  {
    rectangle = sf::RectangleShape(sf::Vector2f(CHK_TRUE_WIDTH, CHK_TRUE_WIDTH));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(sf::Vector2f(x + CHK_TRUE_OFFSET, y + CHK_TRUE_OFFSET));
    window.draw(rectangle);
  }
}

void Checkbox::draw(sf::RenderWindow &window, sf::Font font)
{
  draw(window);

  if (label[0] != '\0')
  {
    sf::Text text;
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(CHK_WIDTH);
    text.setPosition(sf::Vector2f(x + CHK_WIDTH + 5, y));
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    window.draw(text);
  }
}


void Checkbox::onClick(void)
{
  val = !val;
}

bool Checkbox::isMouseInside(int mouseX, int mouseY)
{
  return (
    (mouseX >= x)
    && (mouseY >= y)
    && (mouseX < (x + CHK_WIDTH))
    && (mouseY < (y + CHK_WIDTH))
  );
}
