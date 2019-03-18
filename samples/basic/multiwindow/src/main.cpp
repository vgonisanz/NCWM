#include "ncwm_manager.h"

int main()
{
	NcwmManager manager;

	Rect rect;
	rect.x = 0;
	rect.y = 1;
	rect.width = 15;
	rect.height = 15;

	Rect rect2;
	rect2.x = 6;
	rect2.y = 7;
	rect2.width = 15;
	rect2.height = 15;

	std::shared_ptr<Frame> frame(new Frame(rect, manager.get_size(), true, true));
	manager.add_frame(frame);

	std::shared_ptr<Frame> frame2(new Frame(rect2, manager.get_size(), true, true));
	manager.add_frame(frame2);

	manager.run();
	return 0;
}
