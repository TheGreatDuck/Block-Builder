#include <windows.h>
#include <winuser.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "blockGraph.hpp"
#include "blockAlchemy.hpp"

HDC g_HDC;
extern vector* blockModelAsset[(int)numberOfBlocks_3D];
extern unsigned int numberOfBlockModelTriangles;

void drawBlock(int blockID)
{
    int i = blockID;
    vector p1 = blkGph->blockGraph[i].v[0];
    vector p2 = blkGph->blockGraph[i].v[1];
    vector p3 = blkGph->blockGraph[i].v[2];
    vector p4 = blkGph->blockGraph[i].v[3];

    vector pn1 = blkGph->blockGraph[i].n[0];
    vector pn2 = blkGph->blockGraph[i].n[1];
    vector pn3 = blkGph->blockGraph[i].n[2];
    vector pn4 = blkGph->blockGraph[i].n[3];

    glColor3f((blkGph->blockGraph[blockID].type/numberOfBlocks_3D), (blkGph->blockGraph[blockID].type/numberOfBlocks_3D), (blkGph->blockGraph[blockID].type/numberOfBlocks_3D));

    glVertex3f(p1.x,p1.y,p1.z);
    glVertex3f(p3.x,p3.y,p3.z);
    glVertex3f(p4.x,p4.y,p4.z);

    glVertex3f(p1.x,p1.y,p1.z);
    glVertex3f(p4.x,p4.y,p4.z);
    glVertex3f(p2.x,p2.y,p2.z);

    glVertex3f(p1.x,p1.y,p1.z);
    glVertex3f(p4.x,p4.y,p4.z);
    glVertex3f(p3.x,p3.y,p3.z);

    glVertex3f(p1.x,p1.y,p1.z);
    glVertex3f(p2.x,p2.y,p2.z);
    glVertex3f(p4.x,p4.y,p4.z);

    for (unsigned int j = 0; j < numberOfBlockModelTriangles*3; j++)
    {
        vector v;
        if (blockModelAsset[0][j].x > 1 - blockModelAsset[0][j].y)
            v = (1-blockModelAsset[0][j].x)*(p3-p4) + (1-blockModelAsset[0][j].y)*(p2-p4) + p4;
        else
            v = blockModelAsset[0][j].x*(p2-p1) + blockModelAsset[0][j].y*(p3-p1) + p1;

        double x = blockModelAsset[0][j].x;
        double y = blockModelAsset[0][j].y;
        double z = blockModelAsset[0][j].z;

        vector n;
        if (blockModelAsset[0][j].x > 1 - blockModelAsset[0][j].y)
            n = (x + y - 1)*pn4 + (1-y)*pn2 + (1-x)*pn3;
        else
            n = (-x - y + 1)*pn1 + (x)*pn2 + (y)*pn3;

        v = v + z*(1/(n*blkGph->blockGraph[i].normal))*n;
        glVertex3f(v.x,v.y,v.z);
    }

    for (unsigned int j = 0; j < numberOfBlockModelTriangles*3; j++)
    {
        vector v;
        if (blockModelAsset[0][j].x > 1 - blockModelAsset[0][j].y)
            v = (1-blockModelAsset[0][j].x)*(p3-p4) + (1-blockModelAsset[0][j].y)*(p2-p4) + p4;
        else
            v = blockModelAsset[0][j].x*(p2-p1) + blockModelAsset[0][j].y*(p3-p1) + p1;

        double x = blockModelAsset[0][j].x;
        double y = blockModelAsset[0][j].y;
        double z = blockModelAsset[0][j].z;

        vector n;
        if (blockModelAsset[0][j].x > 1 - blockModelAsset[0][j].y)
            n = (x + y - 1)*pn4 + (1-y)*pn2 + (1-x)*pn3;
        else
            n = (-x - y + 1)*pn1 + (x)*pn2 + (y)*pn3;

        v = v + z*(1/(n*blkGph->blockGraph[i].normal))*n;
        glVertex3f(v.x,v.y,v.z);
    }

    for (unsigned int j = 0; j < numberOfBlockModelTriangles*3; j++)
    {
        vector v;
        if (blockModelAsset[0][j].x > 1 - blockModelAsset[0][j].y)
            v = (1-blockModelAsset[0][j].x)*(p3-p4) + (1-blockModelAsset[0][j].y)*(p2-p4) + p4;
        else
            v = blockModelAsset[0][j].x*(p2-p1) + blockModelAsset[0][j].y*(p3-p1) + p1;

        double x = blockModelAsset[0][j].x;
        double y = blockModelAsset[0][j].y;
        double z = blockModelAsset[0][j].z;

        vector n;
        if (blockModelAsset[0][j].x > 1 - blockModelAsset[0][j].y)
            n = (x + y - 1)*pn4 + (1-y)*pn2 + (1-x)*pn3;
        else
            n = (-x - y + 1)*pn1 + (x)*pn2 + (y)*pn3;

        v = v + z*(1/(n*blkGph->blockGraph[i].normal))*n;
        glVertex3f(v.x,v.y,v.z);
    }
}

void drawBlockGraph()
{
    glBegin(GL_TRIANGLES);
    for (unsigned int blockID = 0; blockID < blkGph->numberOfBlockModels; blockID++)
        drawBlock(blockID);
    glEnd();
}

void Render()
{
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);

        glClearColor(1.0f, 0.5f, 0.25f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        glPushMatrix();
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -300.0f);
        drawBlockGraph();
        glPopMatrix();

        glFlush();

        /*      Bring back buffer to foreground
        */
        SwapBuffers(g_HDC);
}

void SetupPixelFormat(HDC hDC)
{
        /*      Pixel format index
        */
        int nPixelFormat;

        static PIXELFORMATDESCRIPTOR pfd = {
                sizeof(PIXELFORMATDESCRIPTOR),          //size of structure
                1,                                      //default version
                PFD_DRAW_TO_WINDOW |                    //window drawing support
                PFD_SUPPORT_OPENGL |                    //opengl support
                PFD_DOUBLEBUFFER,                       //double buffering support
                PFD_TYPE_RGBA,                          //RGBA color mode
                32,                                     //32 bit color mode
                0, 0, 0, 0, 0, 0,                       //ignore color bits
                0,                                      //no alpha buffer
                0,                                      //ignore shift bit
                0,                                      //no accumulation buffer
                0, 0, 0, 0,                             //ignore accumulation bits
                16,                                     //16 bit z-buffer size
                0,                                      //no stencil buffer
                0,                                      //no aux buffer
                PFD_MAIN_PLANE,                         //main drawing plane
                0,                                      //reserved
                0, 0, 0 };                              //layer masks ignored

                /*      Choose best matching format*/
                nPixelFormat = ChoosePixelFormat(hDC, &pfd);

                /*      Set the pixel format to the device context*/
                SetPixelFormat(hDC, nPixelFormat, &pfd);
}

/*      Windows Event Procedure Handler
*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
        /*      Rendering and Device Context
                variables are declared here.
        */
        static HGLRC hRC;
        static HDC hDC;

        /*      Width and Height for the
                window our robot is to be
                displayed in.
        */
        int width, height;

        switch(message)
        {
                case WM_CREATE: //window being created

                        hDC = GetDC(hwnd);  //get current windows device context
                        g_HDC = hDC;
                        SetupPixelFormat(hDC); //call our pixel format setup function

                        /*      Create rendering context and make it current
                        */
                        hRC = wglCreateContext(hDC);
                        wglMakeCurrent(hDC, hRC);

                        return 0;
                        break;

                case WM_CLOSE:  //window is closing

                        /*      Deselect rendering context and delete it*/
                        wglMakeCurrent(hDC, NULL);
                        wglDeleteContext(hRC);

                        /*      Send quit message to queue*/
                        PostQuitMessage(0);

                        return 0;
                        break;

                case WM_SIZE:

                        /*      Retrieve width and height*/
                        height = HIWORD(lParam);
                        width = LOWORD(lParam);

                        /*      Don't want a divide by 0*/
                        if (height == 0)
                        {
                                height = 1;
                        }

                        /*      Reset the viewport to new dimensions*/
                        glViewport(0, 0, width, height);

                        /*      Set current Matrix to projection*/
                        glMatrixMode(GL_PROJECTION);
                        glLoadIdentity(); //reset projection matrix

                        /*      Time to calculate aspect ratio of
                                our window.
                        */
                        gluPerspective(54.0f, (GLfloat)width/(GLfloat)height, 1.0f, 1000.0f);

                        glMatrixMode(GL_MODELVIEW); //set modelview matrix
                        glLoadIdentity(); //reset modelview matrix

                        return 0;
                        break;

                default:

                        break;
        }

        return (DefWindowProc(hwnd, message, wParam, lParam));
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
    WNDCLASSEX windowClass;    //window class
    HWND       hwnd;           //window handle
    MSG        msg;            //message
    bool       done;           //flag for completion of app
    DWORD      dwExStyle;      //window extended style
    DWORD      dwStyle;        //window style
    RECT       windowRect;

    /*      Screen/display attributes*/
    int width = 800;
    int height = 600;
    int bits = 32;

    windowRect.left =(long)0;       //set left value to 0
    windowRect.right =(long)width;  //set right value to requested width
    windowRect.top =(long)0;        //set top value to 0
    windowRect.bottom =(long)height;//set bottom value to requested height

    /*      Fill out the window class structure*/
    windowClass.cbSize              = sizeof(WNDCLASSEX);
    windowClass.style               = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc         = WndProc;
    windowClass.cbClsExtra          = 0;
    windowClass.cbWndExtra          = 0;
    windowClass.hInstance           = hInstance;
    windowClass.hIcon               = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hCursor             = LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground       = NULL;
    windowClass.lpszMenuName        = NULL;
    windowClass.lpszClassName       = "MyClass";
    windowClass.hIconSm             = LoadIcon(NULL, IDI_WINLOGO);

    /*      Register window class*/
    if (!RegisterClassEx(&windowClass))
    {
        return 0;
    }

    dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE; //window extended style
    dwStyle = WS_OVERLAPPEDWINDOW; //windows style

    AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);

    /*      Class registerd, so now create our window*/
    hwnd = CreateWindowEx(NULL, "MyClass",  //class name
                                              "OpenGL Robot", //app name
                                              dwStyle |
                                              WS_CLIPCHILDREN |
                                              WS_CLIPSIBLINGS,
                                              0, 0, //x and y coords
                                              windowRect.right - windowRect.left,
                                              windowRect.bottom - windowRect.top,//width, height
                                              NULL, //handle to parent
                                              NULL, //handle to menu
                                              hInstance, //application instance
                                              NULL); //no xtra params

    /*Check if window creation failed (hwnd = null ?)*/
    if (!hwnd)
    {
        return 0;
    }

    ShowWindow(hwnd, SW_SHOW); //display window
    UpdateWindow(hwnd); //update window

    done = false; //initialize loop condition variable

    blockGraph_initBlockModelAssets("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\", "YggdrasilQuest");
    blockGraph_loadFromFile("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\Worlds\\YggdrasilQuest\\Level 1\\Level.ter");
    blockGraph_setUpBlockGraphList();

    /*Main message loop*/
    while (!done)
    {
        PeekMessage(&msg, hwnd, NULL, NULL, PM_REMOVE);

        if (msg.message == WM_QUIT)     //did we receive a quit message?
        {
            done = true;
        } else
        {
            if (GetKeyState(0x0D) & 0x8000)
                blockGraph_updateBlockGraphWithList();
            Render();
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return msg.wParam;
}
