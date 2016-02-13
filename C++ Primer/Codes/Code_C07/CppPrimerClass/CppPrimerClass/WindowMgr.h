#ifndef WINDOW_MGR
#define WINDOW_MGR

#include <iostream>
#include <vector>
#include "Screen.h"

class BitMap;

extern std::ostream& storeOn(std::ostream &, Screen &);
extern BitMap& storeOn(BitMap &, Screen &);

class Window_mgr {
public:
	typedef std::vector<Screen>::size_type ScreenIndex;
	
	ScreenIndex addScreen(const Screen&);
	void clear(ScreenIndex);
	void resize(Screen::pos r,Screen::pos c,ScreenIndex i);
private:
	std::vector<Screen> screens{ Screen(24,80,' ') };
};

inline
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

inline
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

inline
void Window_mgr::resize(Screen::pos r, Screen::pos c, ScreenIndex i)
{
	screens[i].height = r;  // Window_mgr is a friend of Screen
	screens[i].width = c;   // so it is ok to use Screen's private members
							// resize and clear the contents member
	screens[i].contents = std::string(r * c, ' ');
}
#endif
