#include "GUI/debuggui.h"

int main(int argc, char **argv)
{
    DebugGUI gui(argc,argv,1000,900);

    while (1)
        gui.redraw();

    return 0;
}

