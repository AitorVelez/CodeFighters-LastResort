#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#define MAX_FRAMES 25

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
		bool next_anim = true; 
		if (next_anim) {
			current_frame += speed;
			if (current_frame >= last_frame)
				if (repeat) current_frame = 0;
				else next_anim = false;
		}
		return frames[(int)current_frame];
	}
};

#endif