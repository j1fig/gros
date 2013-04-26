#include "src/GUI/debuggui.h"

int main(int argc, char **argv)
{
    DebugGUI gui(argc,argv,300,300);

    while (1)
        gui.redraw();

    return 0;
}
