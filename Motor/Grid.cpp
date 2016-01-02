#include "Grid.h"
void Grid::Create()
{
	int i;
	int j;
	for (i = 1; i <= SCREEN_WIDTH ; i = i + Grid_size)
		for (j = 1; j <= SCREEN_HEIGHT ; j = j + Grid_size)
		{
			GLfloat vertices[]{
				i - Grid_size,j - Grid_size,
				i + Grid_size,j - Grid_size,
				i + Grid_size,j + Grid_size,
				i - Grid_size,j + Grid_size,
			};
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(2, GL_FLOAT, 0, vertices);
			glDrawArrays(GL_LINE_LOOP, 0, 4);
			glDisableClientState(GL_VERTEX_ARRAY);
		}
}