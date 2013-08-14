#include "N_body.h"

using namespace zarath;

int main(int argc, char **argv)
{
	std::cout << "Hallo N_body!" << std::endl;

	std::cout << "GLUT initialize..." << std::endl;
	glutInit(&argc, argv);
	
	initialize();	

	std::cout << "Create Window..." << std::endl;

	glutInitWindowPosition(initial_x, initial_y);
	glutInitWindowSize(initial_width, initial_height);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	

	glutCreateWindow("N_body root");

	std::cout << "Set Callback Functions..." << std::endl;
	glClearColor(initial_clear_color[0], initial_clear_color[1],initial_clear_color[2],initial_clear_color[3]);
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	std::cout << "Enterirng GLUT main loop..." << std::endl;

	glutMainLoop();

	atexit(finalize);

	return 0;
}

void zarath::initialize(void)
{
}

void zarath::finalize(void)
{
	std::cout << "Successfuly terminated.\ngood bye..." << std::endl;
}
