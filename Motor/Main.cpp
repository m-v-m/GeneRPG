#include "Main_Header.h"

int main()
{
	sf::Window window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "GeneRPG", sf::Style::Default, sf::ContextSettings(32));
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

	while (running)
	{
		// handle events
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
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear buffer
		//glPushMatrix();
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//glPushMatrix();
		/*
		GLfloat vertices[] =
		{
			200, 100,
			100, 300,
			500, 50,
			320, 100, 
			10, 10,
		};
				
				glEnableClientState(GL_VERTEX_ARRAY);
				glVertexPointer(2, GL_FLOAT, 0, vertices);
				glDrawArrays(GL_LINE_LOOP, 0, 5);
				glDisableClientState(GL_VERTEX_ARRAY);
				//glPopMatrix();*/
		//glPopMatrix();
		grid.Create();
		window.display();
	}

	// release resources...

	return 0;
}
