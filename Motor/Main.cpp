#include "Main_Header.h"
#include "Grid.h"
GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
struct inter_tex
{
	sf::Texture texture;
	inter_tex *pre;
	inter_tex *next;
};
inter_tex a, b, c, *aux;
sf::Sprite spr;
void CreareLista();
sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "GeneRPG", sf::Style::Default, sf::ContextSettings(32));
sf::RenderWindow interfata(sf::VideoMode(halfScreenWidth, halfScreenHeight), "GeneRPG", sf::Style::Default, sf::ContextSettings(32));

int main()
{
	window.setVerticalSyncEnabled(true);
	Grid grid;
	sf::Texture texture;
	//window.pushGLStates();
	//window.popGLStates();
	interfata.pushGLStates();
	CreareLista();
	interfata.popGLStates();
	bool running = true;

	glViewport(0.0f, 0.0f,SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	sf::RectangleShape rectangle(sf::Vector2f(Grid_size, Grid_size));
	while (running)
	{
		// handle events
		sf::Vector2i globalPosition = sf::Mouse::getPosition(window);
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			window.setActive();
			if (Event.type == sf::Event::Closed)
			{
				// end the program
				running = false;
			}
			else if (Event.type == sf::Event::Resized)
			{
				glViewport(0, 0, Event.size.width, Event.size.height);
			}
			if (Event.type == sf::Event::KeyPressed)
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					break;
				case sf::Keyboard::Down:
					break;
				case sf::Keyboard::Right:
					break;
				case sf::Keyboard::Left:
					break;
				}
			if (Event.type == sf::Event::MouseButtonPressed)
			{
				int i, j;
				for (i = 1; i < SCREEN_WIDTH + Grid_size; i = i + Grid_size)
					for (j = 1; j < SCREEN_HEIGHT + Grid_size; j = j + Grid_size)
					{
						if (((globalPosition.x > i - Grid_size && globalPosition.x< i + Grid_size) && (globalPosition.y> j - Grid_size && globalPosition.y < j + Grid_size)))
						{
							cout << i << " " << j << endl;
							spr.setPosition(sf::Vector2f(i - Grid_size, j-2.5));
							break;
						}
						cout << endl;
					}
				
			}
			
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear buffer
		
		grid.Create(globalPosition);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		window.pushGLStates(); //SFML

		window.draw(spr);
		
		window.popGLStates(); //SFML
		window.display();

		//window2(interfata)
		interfata.setActive();
		sf::Event iEvent;
		while (interfata.pollEvent(iEvent))
		{
			
			

			if (iEvent.type == sf::Event::KeyPressed)
				switch (iEvent.key.code)
				{
				case sf::Keyboard::Right:
					interfata.pushGLStates();
					aux = aux->next; cout << "Changed" << endl;
					spr.setTexture(aux->texture);
					interfata.popGLStates();
					break;
				}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		interfata.display();
		
	}

	// release resources...

	return 0;
}

void CreareLista()
{

	ifstream fin("Textures.txt");
	string str;
	fin >> str;
	
	a.texture.loadFromFile(str);
	fin >> str;
	b.texture.loadFromFile(str);
	fin >> str;
	c.texture.loadFromFile(str);
	a.next = &b;
	b.next = &c;
	c.next = &a;
	aux = &a;
}
