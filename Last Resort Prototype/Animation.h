#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"

#define MAX_FRAMES 40


class Animation
{
public:
	float speed = 1.0f;
	SDL_Rect frames[MAX_FRAMES];
	bool repeat = true; 

private:
	float current_frame;
	int last_frame = 0;

public:

	void PushBack(const SDL_Rect& rect)
	{
		frames[last_frame++] = rect;
	}

	SDL_Rect& GetCurrentFrame()
	{
		switch (repeat) {
		case true:
			current_frame += speed;
			if (current_frame >= last_frame)
				current_frame = 0;

			return frames[(int)current_frame];
			break; 

		case false: 
			if (current_frame < last_frame-1)
				current_frame += speed;
			return frames[(int)current_frame]; 
			break; 
		}
	}
};

#endif