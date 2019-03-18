#include "ncwm_manager.h"

int main()
{
	NcwmManager manager;

	Rect rect;
	rect.x = 5;
	rect.y = 5;
	rect.width = 50;
	rect.height = 10;

	std::shared_ptr<Frame> frame(new Frame(rect, manager.get_size(), true, true));
	manager.add_frame(frame);

	manager.run();
	return 0;
}
