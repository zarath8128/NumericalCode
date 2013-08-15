#include "N_body.h"

using namespace zarath;

int main(int argc, char **argv)
{
	std::cout << "Hallo N_body!" << std::endl;

	std::cout << "GLUT initialize..." << std::endl;
	glutInit(&argc, argv);
	
	initialize();	
	atexit(finalize);

	std::cout << "Create Window..." << std::endl;

	glutInitWindowPosition(root.x, root.y);
	glutInitWindowSize(root.width, root.height);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	

	glutCreateWindow("N_body root");

	std::cout << "Set Callback Functions..." << std::endl;

	glClearColor(initial_clear_color[0], initial_clear_color[1],initial_clear_color[2],initial_clear_color[3]);
	glOrtho(-(root.width/root.unit_per_pixel), (root.width/root.unit_per_pixel), -(root.height/root.unit_per_pixel), (root.height/root.unit_per_pixel), 0, 4);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);

	std::cout << "Enterirng GLUT main loop..." << std::endl;

	glutMainLoop();


	return 0;
}

void zarath::initialize(void)
{
	root.x = initial_x;
	root.y = initial_y;
	root.width = initial_width;
	root.height = initial_height;
	for(int i = 0; i < 4; ++i)
		root.clear_color[i] = initial_clear_color[i];
	root.unit_per_pixel = initial_unit_per_pixel;
}

void zarath::finalize(void)
{
	std::cout << "Successfuly terminated.\ngood bye..." << std::endl;
}
