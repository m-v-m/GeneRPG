#include "Main_Header.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "GeneRPG", sf::Style::Default, sf::ContextSettings(32));
	window.setVerticalSyncEnabled(true);
	Grid grid;

	bool running = true;

	glViewport(0.0f, 0.0f,SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
	GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
	sf::RectangleShape rectangle(sf::Vector2f(Grid_size, Grid_size));
	while (running)
	{
		// handle events
		sf::Vector2i globalPosition = sf::Mouse::getPosition(window);
		sf::Event Event;
		while (window.pollEvent(Event))
		{
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
				rectangle.setPosition(sf::Vector2f(globalPosition.x-Grid_size/2,globalPosition.y - Grid_size / 2));
			}
			
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear buffer
		grid.Create(globalPosition);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		window.pushGLStates(); //SFML

		window.draw(rectangle);

		window.popGLStates(); //SFML
		
		window.display();
	}

	// release resources...

	return 0;
}
