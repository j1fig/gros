#include "debuggui.h"

int width;
int height;

Display* DebugGUI::dpy = 0;
Window  DebugGUI::win = 0;

int DebugGUI::width = 0;
int DebugGUI::height = 0;

bool DebugGUI::needRedraw = 0;
GLboolean DebugGUI::doubleBuffer = 0;

DebugGUI::DebugGUI()
{
    DebugGUI::needRedraw = GL_FALSE;
}

DebugGUI::DebugGUI(int argc, char** argv, int width, int height)
{
    DebugGUI::needRedraw = GL_FALSE;
    DebugGUI::doubleBuffer = GL_TRUE;
    DebugGUI::width = width;
    DebugGUI::height = height;

    DebugGUI::init(argc,argv);
}

DebugGUI::~DebugGUI()
{
    //dtor
}


void DebugGUI::fatalError(char *message)
{
  fprintf(stderr, "main: %s\n", message);
  exit(1);
}


void DebugGUI::redraw(void)
{
    static GLboolean   displayListInited = GL_FALSE;

    if (displayListInited)
    {
        /* if display list already exists, just execute it */
        glCallList(1);
    }
    else
    {
        /* otherwise compile and execute to create the display list */
        glNewList(1, GL_COMPILE_AND_EXECUTE);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* front face */
        glBegin(GL_QUADS);
          glColor3f(0.0, 0.7, 0.1);  /* green */
          glVertex3f(-1.0, 1.0, 1.0);
          glVertex3f(1.0, 1.0, 1.0);
          glVertex3f(1.0, -1.0, 1.0);
          glVertex3f(-1.0, -1.0, 1.0);

          /* back face */
          glColor3f(0.9, 1.0, 0.0);  /* yellow */
          glVertex3f(-1.0, 1.0, -1.0);
          glVertex3f(1.0, 1.0, -1.0);
          glVertex3f(1.0, -1.0, -1.0);
          glVertex3f(-1.0, -1.0, -1.0);

          /* top side face */
          glColor3f(0.2, 0.2, 1.0);  /* blue */
          glVertex3f(-1.0, 1.0, 1.0);
          glVertex3f(1.0, 1.0, 1.0);
          glVertex3f(1.0, 1.0, -1.0);
          glVertex3f(-1.0, 1.0, -1.0);

          /* bottom side face */
          glColor3f(0.7, 0.0, 0.1);  /* red */
          glVertex3f(-1.0, -1.0, 1.0);
          glVertex3f(1.0, -1.0, 1.0);
          glVertex3f(1.0, -1.0, -1.0);
          glVertex3f(-1.0, -1.0, -1.0);
        glEnd();
        glEndList();
        displayListInited = GL_TRUE;
    }
    if (doubleBuffer)
        glXSwapBuffers(dpy, win);/* buffer swap does implicit glFlush */
    else
        glFlush();  /* explicit flush for single buffered case */
}

void DebugGUI::init(int argc, char** argv)
{
    XVisualInfo         *vi;
    Colormap             cmap;
    XSetWindowAttributes swa;
    GLXContext           cx;
    int                  dummy;

    /*** (1) open a connection to the X server ***/

    DebugGUI::dpy = XOpenDisplay(NULL);
    if (DebugGUI::dpy == NULL)
        fatalError("could not open display");

    /*** (2) make sure OpenGL's GLX extension supported ***/

    if(!glXQueryExtension(DebugGUI::dpy, &dummy, &dummy))
        fatalError("X server has no OpenGL GLX extension");

    /*** (3) find an appropriate visual ***/

    /* find an OpenGL-capable RGB visual with depth buffer */
    vi = glXChooseVisual(DebugGUI::dpy, DefaultScreen(DebugGUI::dpy), dblBuf);
    if (vi == NULL)
    {
        vi = glXChooseVisual(DebugGUI::dpy, DefaultScreen(DebugGUI::dpy), snglBuf);
        if (vi == NULL) fatalError("no RGB visual with depth buffer");
        doubleBuffer = GL_FALSE;
    }
//    if(vi->class != TrueColor)
//        fatalError("TrueColor visual required for this program");

    /*** (4) create an OpenGL rendering context  ***/

    /* create an OpenGL rendering context */
    cx = glXCreateContext(DebugGUI::dpy, vi, /* no shared dlists */ None,
                    /* direct rendering if possible */ GL_TRUE);
    if (cx == NULL)
        fatalError("could not create rendering context");

    /*** (5) create an X window with the selected visual ***/

    /* create an X colormap since probably not using default visual */
    cmap = XCreateColormap(DebugGUI::dpy, RootWindow(DebugGUI::dpy, vi->screen), vi->visual, AllocNone);
    swa.colormap = cmap;
    swa.border_pixel = 0;
    swa.event_mask = KeyPressMask    | ExposureMask
             | ButtonPressMask | StructureNotifyMask;
    DebugGUI::win = XCreateWindow(DebugGUI::dpy, RootWindow(DebugGUI::dpy, vi->screen), 0, 0,
                  DebugGUI::width, DebugGUI::height, 0, vi->depth, InputOutput, vi->visual,
                  CWBorderPixel | CWColormap | CWEventMask, &swa);
    XSetStandardProperties(DebugGUI::dpy, DebugGUI::win, "main", "main", None,
                     argv, argc, NULL);

    /*** (6) bind the rendering context to the window ***/

    glXMakeCurrent(DebugGUI::dpy, DebugGUI::win, cx);

    /*** (7) request the X window to be displayed on the screen ***/

    XMapWindow(DebugGUI::dpy, DebugGUI::win);

    /*** (8) configure the OpenGL context for rendering ***/

    glEnable(GL_DEPTH_TEST); /* enable depth buffering */
    glDepthFunc(GL_LESS);    /* pedantic, GL_LESS is the default */
    glClearDepth(1.0);       /* pedantic, 1.0 is the default */

    /* frame buffer clears should be to black */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /* set up projection transform */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
    /* establish initial viewport */
    /* pedantic, full window size is default viewport */
    glViewport(0, 0, 300, 300);

}

