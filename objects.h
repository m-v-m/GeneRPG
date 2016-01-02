#ifndef OBJECTS
#define OBJECTS

class obiect {
public:
	int x, y;
	sf::Texture texture;
	sf::Sprite sprite;
	obiect(sf::Texture, int, int);
};

obiect::obiect(sf::Texture tex, int x, int y) {
	texture = tex;
	this->x = x;
	this->y = y;
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}