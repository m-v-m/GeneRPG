#include "Main_Header.h"
GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
struct inter_tex
{
	sf::Texture texture;
	inter_tex *pre;
	inter_tex *next;
	string name;
};
inter_tex a, b, c, *aux;
sf::Sprite spr;
sf::RenderWindow window;
void CreareLista();
void CreateArt();
void CreateLevel();
int main()
{
	bool update = 1;
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "GeneRPG", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	Grid grid;
	sf::Texture texture;
	window.pushGLStates();

	CreareLista();

	window.popGLStates();

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
				int gasit=0;
				update = 1;
				for (i = 1; i < SCREEN_WIDTH + Grid_size; i = i + Grid_size)
					for (j = 1; j < SCREEN_HEIGHT + Grid_size; j = j + Grid_size)
					{
						ofstream fout("level1.txt", std::ios_base::app | std::ios_base::out);
						if (((globalPosition.x > i - Grid_size && globalPosition.x< i + Grid_size) && (globalPosition.y> j - Grid_size && globalPosition.y < j + Grid_size)))
						{
							if (gasit != 1)
							{
								
								gasit++;
							}
							else
							{
								fout << i - Grid_size << " " << j << " " << aux->name << endl;
								fout.close();
							}
							break;
						}
						
					}
			}
			
			if (Event.type == sf::Event::KeyPressed)
				switch (Event.key.code)
				{
				case sf::Keyboard::Right:

					aux = aux->next;
					spr.setTexture(aux->texture);
				}
				
			
		}
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear buffer
		grid.Create(globalPosition);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//window.pushGLStates();
		
		//window.draw(spr);
		//window.popGLStates();
		//window.popGLStates();
		
		ifstream fin("level1.txt");
		sf::Sprite sprit;
		while (!fin.eof())
		{
			string str;

			float x;
			float y;
			sf::Texture texture;

			fin >> x >> y >> str;
			if(str!="")
			{ 
			texture.loadFromFile(str);
			sprit.setPosition(sf::Vector2f(x, y));
			sprit.setTexture(texture);
			cout << x << " " << y << " " << str << endl;
			window.pushGLStates();
			window.draw(sprit);
			window.popGLStates();
			}
		}
		fin.close();
		//window.popGLStates();
		window.display();
		
	}

	// release resources...

	return 0;
}

void CreareLista()
{
	ifstream fin("Textures.txt");
	string str;
	fin >> str; cout << str << endl;
	a.texture.loadFromFile(str);
	a.name = str;
	fin >> str; cout << str << endl;
	b.texture.loadFromFile(str);
	b.name = str;
	fin >> str; cout << str << endl;
	c.texture.loadFromFile(str);
	c.name = str;
	a.next = &b;
	b.next = &c;
	c.next = &a;
	aux = &a;
	fin.close();
}
