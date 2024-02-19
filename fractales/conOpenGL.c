/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

/**************
 *Declaraciones
 **************/

#include "logo.h"
#include "koch.h"
#include "curvac.h"
#include "corner.h"
#include "hilbert.h"
#include "sierpinski.h"
#include "gosper.h"
#include "dragon.h"
#include "weave.h"
#include "snowsq.h"
#include "nestedtriangle.h"
#include "hooksnow.h"
//#include "rama.h"
//#include "misFuncs.h"
#define escX 0.125
#define escY 0.125
#define MX 0.0
#define MY 0.0

void segmento(double, double, double, double);
//DibujaSegmentos dibujaSegmento=segmento; es de graficos



/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "graficos";
    RegisterClass (&wc);

    misFractales miFractal;
    int nRecursion = 5;
    LOGO miTortuga;
    char *miParametro;

    if (iCmdShow>1) miParametro = lpCmdLine;
    if (strlen(lpCmdLine)==0) miParametro="Hooksnow"; //Cambia cual se imprime "rama" "koch", "kochI","kochII"
	
	asignaModoDibujarSegmento(segmento, &miTortuga);
    if((strncmp(miParametro, "koch", 4)==0) ){
        iniciaKoch(nRecursion, 10.0, -5.0, 0.0, &miTortuga);
        miFractal = dibujaKoch;}
    if (strncmp(miParametro, "kochII", 6)==0){
        iniciaKoch(nRecursion, 10.0, -5.0, -2.5, &miTortuga);
        miFractal = dibujaKochII;
    } else if (strncmp(miParametro, "kochI", 5)==0){
        iniciaKoch(nRecursion, 10.0, -5.0, 2.5, &miTortuga);
        miFractal = dibujaKochI;
    } 
	if(strncmp(miParametro,"curvac",6)==0){
        iniciaC(14, 0.06, 1.0, -3.8, &miTortuga);
        miFractal = dibujaC;		
	}
	if(strncmp(miParametro,"corner",6)==0){   //clase extra
		iniciaCorner(144,5.4,0.08,-2.8,0.8,&miTortuga);
		miFractal = dibujaCorner;
	}
	if(strncmp(miParametro,"hilbert",7)==0){  
		iniciaHilbert(8,/*0.063*/0.059,-7.6,-7.6,&miTortuga);
		miFractal = dibujaHilbert;
	}
	if(strncmp(miParametro,"sierpin",7)==0){  
		iniciaSierpinski(6,0.12,-7.6,7.5,&miTortuga);
		miFractal = dibujaSierpinski;
	}
	if(strncmp(miParametro,"gosper",6)==0){  
		iniciaGosper(5,13.0,-7.5,1.0,&miTortuga);
		miFractal = dibujaGosper;
	}
	if(strncmp(miParametro,"dragon",6)==0){  
		iniciaDragon(14,0.08,2.0,4.0,&miTortuga);
		miFractal = dibujaDragon;
	}
	if(strncmp(miParametro,"weave",5)==0){  
		iniciaWeave(3,12.0,-0.7,-7.7,&miTortuga);
		miFractal = dibujaWeave;
	}
	if(strncmp(miParametro,"maze",5)==0){  
		iniciaWeave(3,15.0,0.0,-7.5,&miTortuga);
		miFractal = dibujaWeave;
	}
	if(strncmp(miParametro,"snowsq",6)==0){  
		iniciaSnow(4,9.0,-4.0,4.0,&miTortuga);
		miFractal = dibujaSnow;
	}
	if(strncmp(miParametro,"triang",6)==0){  
		iniciaNest(7,15,-7.5,5.5,&miTortuga);
		miFractal = dibujaNest;
	}
	if(strncmp(miParametro,"Hooksnow",8)==0){  
		iniciaHooksnow(4,15,-7.3,-4.0,&miTortuga);
		miFractal = dibujaHooksnow;
	}
    /* create main window */
    hWnd = CreateWindow (
      "graficos", 
      "Fractales con OpenGL", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 2*256, 2*256,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor (1.0f, 1.0f, 1.0f, 0.5f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            glRotatef (theta-90, 0.0f, 0.0f, 1.0f);
            glColor3d(0.5, 0.0, 0.0);

            
            miFractal();

            glPopMatrix ();

            SwapBuffers (hDC);

            //theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}

void segmento(double x1, double y1, double x2, double y2)
{
  glBegin (GL_LINES);
    glVertex2d (MX+escX*x1, MY+escY*y1);
    glVertex2d (MX+escX*x2, MY+escY*y2);
  glEnd ();
}

