#ifndef WINDOW_MGR_h
#define WINDOW_MGR_h
#include<vector>
#include"Screen.h"

class Window_mgr {

   private :
	   std::vector<Screen> screens{Screen(24,80,' ')};
};


#endif