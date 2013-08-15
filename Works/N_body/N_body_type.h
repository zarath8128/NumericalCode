#ifndef ZARATH_N_BODY_N_BODY_TYPE
#define ZARATH_N_BODY_N_BODY_TYPE

namespace zarath
{
	typedef struct tag_Param
	{
		int x;
		int y;
		uint32_t width;
		uint32_t height;
		float clear_color[4];

		float range_x;
		float range_y;

		float unit_per_pixel;
	}Param;

	
}

#endif
