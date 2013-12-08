#ifndef DEBUGGUI_H
#define DEBUGGUI_H

#include <stdio.h>
#include <stdlib.h>

#include <GL/glx.h>    /* this includes the necessary X headers */
#include <GL/gl.h>

#include <X11/X.h>    /* X11 constant (e.g. TrueColor) */
#include <X11/keysym.h>

static int snglBuf[] = {GLX_RGBA, GLX_DEPTH_SIZE, 16, None};
static int dblBuf[]  = {GLX_RGBA, GLX_DEPTH_SIZE, 16, GLX_DOUBLEBUFFER, None};

/* A simple program to show how to set up an X window for OpenGL rendering.
 * X86 compilation: gcc -o -L/usr/X11/lib   main main.c -lGL -lX11
 * X64 compilation: gcc -o -L/usr/X11/lib64 main main.c -lGL -lX11
 */

class DebugGUI
{
public:
    DebugGUI();
    DebugGUI(int argc, char** argv, int width, int height);
    virtual ~DebugGUI();

    static void redraw (void);


protected:

private:
    static void init        (int argc, char** argv);

    static void fatalError  (char *message);

private:
    static int width;
    static int height;

    static Display *dpy;
    static Window  win;

    static bool needRedraw;
    static GLboolean doubleBuffer;

};

#endif // DebugGUI_H
