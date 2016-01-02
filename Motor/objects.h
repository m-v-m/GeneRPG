#ifndef gard
#define gard
#endif

class thing {
public:
	int x, y;
	sf::Texture texture;
	sf::Sprite sprite;
	thing(sf::Texture, int, int);
};

thing::thing(sf::Texture tex, int x, int y) {
	texture = tex;
	this->x = x;
	this->y = y;
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}