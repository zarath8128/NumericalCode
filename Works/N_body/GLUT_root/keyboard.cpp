#include "../GLUT_root.h"

namespace zarath
{
	
	void keyboard(unsigned char key, int x, int y)
	{
		switch(key)
		{
		case 0x1B://ESC
			exit(0);
			break;	
		}
		return;
	}
}
