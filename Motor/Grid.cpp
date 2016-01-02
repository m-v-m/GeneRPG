#include "Grid.h"
void Grid::Create(sf::Vector2i globalPosition)
{
	int i;
	int j;
	for (i = 1; i < SCREEN_WIDTH + Grid_size; i = i + Grid_size)
		for (j = 1; j < SCREEN_HEIGHT + Grid_size; j = j + Grid_size)
		{
			GLfloat vertices[]{
				i - Grid_size,j - Grid_size,
				i + Grid_size,j - Grid_size,
				i + Grid_size,j + Grid_size,
				i - Grid_size,j + Grid_size,
			};
			GLfloat colour[]{
				255, 0, 0,
				255, 0, 0,
				255, 0, 0,
				255, 0, 0,
			};
			if (!((globalPosition.x > i - Grid_size && globalPosition.x< i + Grid_size) && (globalPosition.y>SCREEN_HEIGHT - j - Grid_size && globalPosition.y < SCREEN_HEIGHT - j + Grid_size)))
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(2, GL_FLOAT, 0, vertices);
			glDrawArrays(GL_POLYGON, 0, 4);
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(3, GL_FLOAT, 0, colour);
			glDrawArrays(GL_LINE_LOOP, 0, 4);
			glDisableClientState(GL_VERTEX_ARRAY);
			glDisableClientState(GL_COLOR_ARRAY);
		}
}