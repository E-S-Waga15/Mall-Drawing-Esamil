#define pai 3.14159265359

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "gltexture.h"
#include "Model_3DS.h"
#include "texture.h"
#include <math.h>
#include "sound.h"
#include "math3d.h"


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Context
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc
int cnt = 0;
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}



DirectSoundBuffer adan;
DirectSoundManager SoundManager;

DirectSoundBuffer birds;
DirectSoundManager SoundManager2;


/*			**********	*******	  *	   * **********	*	  *   ******	********
				*		*		   *  *		 *		*	  *   *		*	*		
				*		****	    **		 *		*	  *   ******	****	
				*		*		   *  *		 *		*	  *   *		*	*		
				*		*******	  *	   *	 *		*******   *		 *	********
*/

float R = 0, RR = 0;
int elevatorWallTexture,overdrive,ORIGI4,flowerTexture,buildingTexture,grassTexture, streetTexture, chairTexture,wallTexture2,overdriveTexture,tableTexture, elevatorButtomsTexture, floorTexture, wallTexture, coneTexture,doorTexture, groundTexture, groundSkybox, groundTexture2, groundWallTexture2, EXitTexture;
int resTexture1, resTexture2, resTexture3, resTexture4, resTexture5, resTexture6;
int cloTexture1, cloTexture2, cloTexture3, cloTexture4, cloTexture5, cloTexture6, cloTexture7, cloTexture8, cloTexture9,glassTexture,cl;
int clo1, clo2, clo3, clo4, clo5;
int markt1, markt2, markt3, markt4, markt5,p1,p2,p3,p4,p5,p6;
int ad1, ad2, ad3, ad4, ad5, ad6, ad7,rt,es,t1,t2,t3,t4,t5;

int sky1Texture, sky2Texture, sky3Texture, sky4Texture, night1Texture, night2Texture, night3Texture, night4Texture;
Model_3DS* manModel, * carModel, * sofaModel,* treeModel,*t_90;



class Draw {
public:

	void rectangleXY(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);
		
		glNormal3d(0, 0, N);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x + w, y, z);
		glTexCoord2d(sru, tru);
		glVertex3f(x + w, y + h, z);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y + h, z);
		glEnd();

	}
	

	void rectangleXZ(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);

		glNormal3d(0, N, 0);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x + w, y, z);
		glTexCoord2d(sru, tru);
		glVertex3f(x + w, y, z - h);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y, z - h);
		glEnd();

	}

	void rectangleYZ(float x, float y, float z, float w, float h, int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);

		glNormal3d(N, 0, 0);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x, y, z - w);
		glTexCoord2d(sru, tru);
		glVertex3f(x, y + h, z - w);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y + h, z);
		glEnd();

	}

	void cylinder(float x, float y, float z, float h, float r, int texture)
	{
		glBindTexture(GL_TEXTURE_2D, texture);

		for (float i = 0; i < 2 * 3.14; i += 0.3)
		{
			glNormal3d(sin(i), 0, cos(i));
			float xx = r * cos(i);
			float zz = r * sin(i);
			float xxx = r * cos(i + 0.3);
			float zzz = r * sin(i + 0.3);
			glTexCoord2d(0, 0);
			glVertex3f(x + xx, y, z - zz);
			glTexCoord2d(1, 0);
			glVertex3f(x + xxx, y, z - zzz);
			glTexCoord2d(1, 1);
			glVertex3f(x + xxx, y + h, z - zzz);
			glTexCoord2d(0, 1);
			glVertex3f(x + xx, y + h, z - zz);

		}
	}

	void cone(float x, float y, float z, float h, float r, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu)
	{
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		for (float i = 0; i < 2 * 3.14; i += 0.3)
		{
			glNormal3d(sin(i), atan2(r , h)+pai, cos(i));
			float xx = r * cos(i);
			float zz = r * sin(i);
			float xxx = r * cos(i + 0.3);
			float zzz = r * sin(i + 0.3);
			glTexCoord2d(sld, tld);
			glVertex3f(x + xx, y, z - zz);
			glTexCoord2d(srd, trd);
			glVertex3f(x + xxx, y, z - zzz);
			glTexCoord2d(sru, tru);
			glVertex3f(x + xxx, y + h, z - zzz);
			glTexCoord2d(slu, tlu);
			glVertex3f(x + xx, y + h, z - zz);

		}
		glEnd();
	}


	void parallel_rectangles(float x, float y, float z, float w, float h, float d, int texture)
	{
		rectangleXY(x, y, z, w, h,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleXY(x, y, z-d, w, h,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleXZ(x, y, z, w, d,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleXZ(x, y+h, z, w, d,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleYZ(x, y, z, d, h,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleYZ(x+w, y, z, d, h,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
	}
	void table(float x, float y, float z, float w, float h, float d, int texture)
	{
		parallel_rectangles(x, y, z, w, 0.1, d, texture);
		parallel_rectangles(x + 0.2, y - h, z - 0.3, 0.1, h,0.1,texture);
		parallel_rectangles(x +w- 0.3, y - h, z - 0.3, 0.1, h, 0.1, texture);
		parallel_rectangles(x +w-0.3 , y - h, z -d+ 0.3, 0.1, h, 0.1, texture);
		parallel_rectangles(x + 0.2, y - h, z -d+ 0.3, 0.1, h, 0.1, texture);
	}
	void chair(float x, float y, float z,int texture)
	{
		parallel_rectangles(x, y+0.6, z, 0.5, 0.1, 0.5, texture);
		parallel_rectangles(x, y, z, 0.1, 0.6, 0.1, texture);
		parallel_rectangles(x+0.4, y, z, 0.1, 0.6, 0.1, texture);
		parallel_rectangles(x+0.4, y, z-0.4, 0.1, 0.6, 0.1, texture);
		parallel_rectangles(x, y, z-0.4, 0.1, 0.6, 0.1, texture);
		parallel_rectangles(x, y+0.6, z, 0.5, 0.6, 0.1, texture);
	}

	////////

	void elevator(float w,float h,float d) {

		glPushMatrix();
		glTranslatef(-w / 2, -h / 2, d / 2);

		// left side
		rectangleYZ(0, 0, 0, d, h,1, elevatorWallTexture, 0, 0, 1, 0, 1, 1, 0, 1);
		// right side
		rectangleYZ(w, 0, 0, d, h,1, elevatorWallTexture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleYZ(w-0.01, (1.0 / 3.0)*h, -(1.0 / 4.0)*d, 0.1*d, 0.1*h,1, elevatorButtomsTexture, 0, 0, 1, 0, 1, 1, 0, 1);
		// floor
		rectangleXZ(0, 0, 0, w, d,1, elevatorWallTexture, 0, 0, 1, 0, 1, 1, 0, 1);
		// roof
		rectangleXZ(0, h, 0, w, d,1, elevatorWallTexture, 0, 0, 1, 0, 1, 1, 0, 1);
		glPopMatrix();
	}

	void fence(float w, float h) {
		glPushMatrix();
		glTranslatef(-w / 2, -h / 2, 0);
		
		float destance = 0.25;
		int times = w / destance;

		glBegin(GL_QUADS);

		// up
		glVertex3f(0,h-0.1,0);
		glVertex3f(w,h-0.1,0);
		glVertex3f(w,h,0);
		glVertex3f(0,h,0);
		//down
		glVertex3f(0, 0, 0);
		glVertex3f(w, 0, 0);
		glVertex3f(w, 0.1, 0);
		glVertex3f(0, 0.1, 0);

		// rest

		glVertex3f(0, 0.1, 0);
		glVertex3f(0.1, 0.1, 0);
		glVertex3f(0.1, h-0.1, 0);
		glVertex3f(0, h-0.1, 0);

		for (int i = 1; i < times; i++) {
			glVertex3f(i*destance-0.1, 0.1, 0);
			glVertex3f(i*destance, 0.1, 0);
			glVertex3f(i*destance, h-0.1, 0);
			glVertex3f(i*destance-0.1, h-0.1, 0);
		}

		glEnd();

		glPopMatrix();
	}

	void stairs(float w,float h,float d,int texture) {

		int timesH = h / 0.2;
		
		float stepD = d / timesH;

		for (int i = 0; i < timesH; i++) {
			rectangleXY(0, 0.2*i, -stepD*i, w, 0.2,1, texture,0,0,w,0,w,0.2,0,0.2);
			rectangleXZ(0, 0.2*i+0.2, -stepD*i, w, stepD,1, texture,0,0,w,0,w,stepD,0,stepD);

		}


	}
	void draw_Sphare(float x, float y, float z, float radios, float R, float G, float B, float terms) {

		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(R, G, B);

		for (float Y = y - radios; Y <= y + radios; Y += terms) {

			float Y2 = Y + terms;

			float r = sqrt(radios*radios - (y - Y)*(y - Y));
			float r2 = sqrt(radios*radios - (y - Y2)*(y - Y2));

			int times = max(2 * pai*r / terms, 2 * pai*r2 / terms);

			for (int i = 0; i < times; i++) {

				float X = x + cos(2 * i*pai / times)*r;
				float Z = z - sin(2 * i*pai / times)*r;
				float X2 = x + cos(2 * i*pai / times)*r2;
				float Z2 = z - sin(2 * i*pai / times)*r2;

				glVertex3f(X, Y, Z);
				glVertex3f(X2, Y2, Z2);

			}
		}
		glEnd();
	}


	void parking() {
		glBindTexture(GL_TEXTURE_2D, streetTexture);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex3d(12, -12, -31);
		glTexCoord2d(0, 0);
		glVertex3d(18, -12, -31);
		glTexCoord2d(1, 0);
		glVertex3d(18, -12, -43);
		glTexCoord2d(1, 1);
		glVertex3d(12, -12, -43);

		glTexCoord2d(1, 0);
		glVertex3d(6, -6, -5);
		glTexCoord2d(0, 0);
		glVertex3d(18, -6, -5);
		glTexCoord2d(0, 1);
		glVertex3d(18, -6, 0);
		glTexCoord2d(1, 1);
		glVertex3d(6, -6, 0);

		glTexCoord2d(0, 0);
		glVertex3d(6, -3, -31);
		glTexCoord2d(1, 0);
		glVertex3d(12, -3, -31);
		glTexCoord2d(1, 1);
		glVertex3d(12, -3, -43);
		glTexCoord2d(0, 1);
		glVertex3d(6, -3, -43);
		

		glTexCoord2d(0, 1);
		glVertex3d(12, -6, -5);
		glTexCoord2d(0, 0);
		glVertex3d(17.8, -6, -5);
		glTexCoord2d(1, 0);
		glVertex3d(17.8, -12, -31);
		glTexCoord2d(1, 1);
		glVertex3d(12, -12, -31);
		
		glTexCoord2d(0, 1);
		glVertex3d(6, -6, -5);
		glTexCoord2d(0, 0);
		glVertex3d(12, -6, -5);
		glTexCoord2d(1, 0);
		glVertex3d(12, -3, -31);
		glTexCoord2d(1, 1);
		glVertex3d(6, -3, -31);

		glTexCoord2d(0, 0);
		glVertex3d(-10, 0, -31);
		glTexCoord2d(1, 0);
		glVertex3d(6, -3, -31);
		glTexCoord2d(1, 1);
		glVertex3d(6, -3, -43);
		glTexCoord2d(0, 1);
		glVertex3d(-10, -0, -43);

		glEnd();
		rectangleXY(-10, -12, -43, 28, 12,1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleYZ(12, -12, -5, 38, 12,1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleYZ(6, -12, 0, 31, 12,1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleXY(6, -6, 0, 12, 6,1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleXY(-10, -3, -31, 16, 3,-1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	}

	void stairs_circle(float x, float y, float z, float w, float h, int texture) {
		int T = h / 0.2;
		glPushMatrix();
		glTranslated(x, y, z);

		glEnable(GL_LIGHTING);
		glPushMatrix();
		for (int i = 0; i < T; i++) {
			parallel_rectangles(-0.1, -h + (0.2*i), 0, 1.5, 0.1, w, texture);
			glRotated(10, 0, 1, 0);
		}
		glPopMatrix();
		glDisable(GL_LIGHTING);

		for (int i = 0; i < T - 3; i++)
		{
			glColor3ub(138, 138, 138);
			cone(1, -h + (0.2*i) + 0.1, -w + 0.1, (h - (0.2*i)) / 2, 0.1, -1, 0, 0, 0.2, 0, 0.2, 0.3, 0, 0.3);
			draw_Sphare(1, -(h - (0.2*i)) / 2 + 0.2, -w + 0.1, 0.2, 1, 0, 0, 0.01);
			glColor3d(1, 1, 1);
			glRotated(10, 0, 1, 0);
		}
		glColor3ub(138, 138, 138);
		cone(0, -h, 0, h, 0.1, -1, 0, 0, 1, 0, 1, 1, 0, 1);
		glColor3d(1, 1, 1);
		glPopMatrix();
	}



	void stairs_dinamic(float x, float y, float z, float w, float h, int texture)
	{
		
		int T = h / 0.5;
		float W = w / T;
		for (int i = 0; i < T; i++) {
			
			parallel_rectangles(x + (i*W)-R, -h + (0.5*i)-RR, 0, 2, 1, W, -1);
		}
		R += 10 / 0.5;
		RR += 0.5;

	}



	void wall(float x, float y, float z, float h, int texture, int texture2)
	{
		for (float i = 0; i <= h; i += 1) {
			cone(x + i, y, z, 1, 0.1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		}
		parallel_rectangles(x, y + 1, z + 0.1, h, 0.2, 0.2, texture2);
	}
   
	void wall_circle(float x, float y, float z, float h, int texture, int texture2,float r,float hh)
	{
	
		for (float i = 0; i <= h; i += 1) {
			cone(x + i, y, z, hh, r, texture, 0, 0, 1, 0, 1, 1, 0, 1);
			if (i >= h - 1&&hh==1)continue;
			if (i == h)continue;

			for (float j = 0; j < 3.14; j += 0.2)
			{
				float xx =hh* cos(j); float yy =hh* sin(j);
				float xxx =hh* cos(j + 0.2); float yyy =hh* sin(j + 0.2);
				glBegin(GL_QUADS);
				glVertex3d(xx  +  i+x+hh, yy    + hh+y, z);
				glVertex3d(xxx  + i+x+hh, yyy   + hh+y, z);
				glVertex3d(xxx*1.2 + i+x+hh, yyy*1.2 + hh+y, z);
				glVertex3d(xx*1.2 +  i+x+hh, yy * 1.2 + hh+y, z);
	         	glEnd();
			}
		}
		
	}

	void prism(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float deep) {

		glBegin(GL_TRIANGLES);

		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);

		glVertex3f(x1, y1, z1 - deep);
		glVertex3f(x2, y2, z2 - deep);
		glVertex3f(x3, y3, z3 - deep);

		glEnd();

		glBegin(GL_QUADS);

		glVertex3f(x1, y1, z1 - deep);
		glVertex3f(x1, y1, z1);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3, y3, z3 - deep);

		glVertex3f(x1, y1, z1);
		glVertex3f(x1, y1, z1 - deep);
		glVertex3f(x2, y2, z2 - deep);
		glVertex3f(x2, y2, z2);

		glVertex3f(x2, y2, z2);
		glVertex3f(x2, y2, z2 - deep);
		glVertex3f(x3, y3, z3 - deep);
		glVertex3f(x3, y3, z3);

		glEnd();
	}

	void elelctronic_stairs(float w, float h, float d) {
		glPushMatrix();
		int timesH = h / 0.2;

		float stepD = d / timesH;

		glColor3f(0.3, 0.3, 0.3);
		rectangleXY(0, 0, -d, w, h,1, -1, 0, 0, 0, 1, 1, 1, 1, 0);

		glTranslatef(0.1, 0, 0);

		w -= 0.2;
		glBegin(GL_QUADS);

		if (cnt % 24 < 6) {
			for (int i = 0; i < timesH; i++) {
				glVertex3f(0, 0.2*i, -stepD * i);
				glVertex3f(w / 2, 0.2*i, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2 / 4, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD / 4);
				//
				glVertex3f(w / 2, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD);

			}
			glColor3f(0, 0, 0);
			for (int i = 0; i < timesH; i++) {
				glVertex3f(0, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD);
				//
				glVertex3f(w / 2, 0.2*i, -stepD * i);
				glVertex3f(w, 0.2*i, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 * 3 / 4, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
			}
		}
		else if (cnt % 24 < 12) {
			for (int i = 0; i < timesH; i++) {
				glVertex3f(0, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2 / 2, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD / 2);
				//
				glVertex3f(w / 2, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 * 3 / 4, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);


			}
			glColor3f(0, 0, 0);
			for (int i = 0; i < timesH; i++) {
				glVertex3f(0, 0.2*i, -stepD * i);
				glVertex3f(w / 2, 0.2*i, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2 / 4, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD / 4);

				glVertex3f(0, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD);

				//
				glVertex3f(w / 2, 0.2*i, -stepD * i);
				glVertex3f(w, 0.2*i, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 2, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 2);

				glVertex3f(w / 2, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD);


			}
		}
		else if (cnt % 24 < 18) {
			for (int i = 0; i < timesH; i++) {
				glVertex3f(0, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2 * 3 / 4, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				//
				glVertex3f(w / 2, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 2, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 2);


			}
			glColor3f(0, 0, 0);
			for (int i = 0; i < timesH; i++) {
				glVertex3f(0, 0.2*i, -stepD * i);
				glVertex3f(w / 2, 0.2*i, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2 / 2, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD / 2);

				glVertex3f(0, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD);

				//

				glVertex3f(w / 2, 0.2*i, -stepD * i);
				glVertex3f(w, 0.2*i, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 4, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 4);

				glVertex3f(w / 2, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 / 2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD / 2);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD);

			}
		}
		else {
			for (int i = 0; i < timesH; i++) {
				glVertex3f(0, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD);
				//
				glVertex3f(w / 2, 0.2*i, -stepD * i);
				glVertex3f(w, 0.2*i, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 / 4, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 4);

			}
			glColor3f(0, 0, 0);
			for (int i = 0; i < timesH; i++) {
				glVertex3f(0, 0.2*i, -stepD * i);
				glVertex3f(w / 2, 0.2*i, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2 * 3 / 4, -stepD * i);
				glVertex3f(0, 0.2*i + 0.2 * 3 / 4, -stepD * i);

				glVertex3f(0, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				glVertex3f(0, 0.2*i + 0.2, -stepD * i - stepD * 3 / 4);
				//
				glVertex3f(w / 2, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2 / 4, -stepD * i);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i);

				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD / 4);
				glVertex3f(w, 0.2*i + 0.2, -stepD * i - stepD);
				glVertex3f(w / 2, 0.2*i + 0.2, -stepD * i - stepD);
			}
		}
		w += 0.2;

		glColor3f(0.3, 0.3, 0.3);

		glEnd();
		glTranslatef(-0.1, 0, -d);
		glRotatef(-90, 0, 1, 0);

		prism(0, 0, 0, d + 1, 0, 0, 0, h + 1, 0, 0.1);
		parallel_rectangles(-1, h, 0, 1, 1, 0.1, -1);
		glTranslatef(0, 0, -w / 2 + 0.1);
		prism(0, 0, 0, d + 1, 0, 0, 0, h + 1, 0, 0.2);
		parallel_rectangles(-1, h, 0, 1, 1, 0.2, -1);
		glTranslatef(0, 0, -w / 2);
		prism(0, 0, 0, d + 1, 0, 0, 0, h + 1, 0, 0.1);
		parallel_rectangles(-1, h, 0, 1, 1, 0.1, -1);

		glColor3f(1, 1, 1);

		glPopMatrix();
	}



};
////////////////////////////////////////////////////////////////////////////////end
float pos0[4] = { 31,0,-6,1 };
float diff0[4] = { 1,1,1,1 };
float spec0[4] = { 1,1,1,1 };
float amb0[4] = { 0.2,0.2,0.2,1 };

float pos1[4] = { -10.5,5.5,5.5,1 };
float diff1[4] = { 1,1,1,1 };
float spec1[4] = { 0.2,0.2,0.2,1 };
float amb1[4] = { 0.2,0.2,0.2,1 };

float elevatorHight = 0;
 


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.4f, 0.4f, 1, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spec0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb0);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, amb1);


	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	floorTexture = LoadTexture((char*)"assets/textures/fl5.bmp");
	wallTexture = LoadTexture((char*)"assets/textures/ground.bmp");
	wallTexture2= LoadTexture((char*)"assets/textures/white tiles.bmp");
	elevatorWallTexture = LoadTexture((char*)"assets/textures/metal.bmp");
	elevatorButtomsTexture = LoadTexture((char*)"assets/textures/elevator buttoms.bmp");
	coneTexture = LoadTexture((char*)"assets/textures/f1.bmp");
	doorTexture = LoadTexture((char*)"assets/textures/cone.bmp",150);
	groundTexture = LoadTexture((char*)"assets/textures/black floor.bmp");
	groundTexture2 = LoadTexture((char*)"assets/textures/-2ground.bmp");
	groundWallTexture2 = LoadTexture((char*)"assets/textures/kk.bmp");
	EXitTexture = LoadTexture((char*)"assets/textures/exit.bmp");
	groundSkybox = LoadTexture((char*)"assets/textures/groundSkybox.bmp");
	resTexture1 = LoadTexture((char*)"assets/textures/restaurants/r1.bmp");
	resTexture2 = LoadTexture((char*)"assets/textures/restaurants/r5.bmp");
	resTexture3 = LoadTexture((char*)"assets/textures/restaurants/r8.bmp");
	resTexture4 = LoadTexture((char*)"assets/textures/restaurants/r2.bmp");
	resTexture5 = LoadTexture((char*)"assets/textures/restaurants/r3.bmp");
	resTexture6 = LoadTexture((char*)"assets/textures/restaurants/r4.bmp");
	overdriveTexture = LoadTexture((char*)"assets/textures/glass roof.bmp");
	cloTexture1 = LoadTexture((char*)"assets/textures/clothes/8.bmp");
	cloTexture2 = LoadTexture((char*)"assets/textures/clothes/1.bmp");
	cloTexture3 = LoadTexture((char*)"assets/textures/clothes/9.bmp");
	cloTexture4 = LoadTexture((char*)"assets/textures/clothes/2.bmp");
	cloTexture5 = LoadTexture((char*)"assets/textures/clothes/3.bmp");
	cloTexture6 = LoadTexture((char*)"assets/textures/clothes/6.bmp");
	cloTexture7 = LoadTexture((char*)"assets/textures/clothes/4.bmp");
	cloTexture8 = LoadTexture((char*)"assets/textures/clothes/5.bmp");
	cloTexture9 = LoadTexture((char*)"assets/textures/clothes/7.bmp");
	cl = LoadTexture((char*)"assets/textures/white tiles.bmp");
	clo1 = LoadTexture((char*)"assets/textures/clothes/c1.bmp");
	clo2 = LoadTexture((char*)"assets/textures/clothes/c2.bmp");
	clo3 = LoadTexture((char*)"assets/textures/clothes/c3.bmp");
	clo4 = LoadTexture((char*)"assets/textures/clothes/manbarnoorD.bmp");
	tableTexture = LoadTexture((char*)"assets/textures/table/1.bmp");
	chairTexture = LoadTexture((char*)"assets/textures/table/3.bmp");
	overdrive = LoadTexture((char*)"assets/textures/ground.bmp");//
	streetTexture = LoadTexture((char*)"assets/textures/road2.bmp");
	ORIGI4 = LoadTexture((char*)"assets/textures/origi-4.bmp");
	grassTexture=LoadTexture((char*)"assets/textures/grass_1.bmp");
	flowerTexture = LoadTexture((char*)"assets/textures/flowers.bmp");
	buildingTexture=LoadTexture((char*)"assets/textures/b2.bmp");
	
	sky1Texture = LoadTexture((char*)"assets/textures/sky1.bmp");
	sky2Texture = LoadTexture((char*)"assets/textures/sky2.bmp");
	sky3Texture = LoadTexture((char*)"assets/textures/sky3.bmp");
	sky4Texture = LoadTexture((char*)"assets/textures/sky4.bmp");

	night1Texture = LoadTexture((char*)"assets/textures/night1.bmp");
	night2Texture = LoadTexture((char*)"assets/textures/night2.bmp");
	night3Texture = LoadTexture((char*)"assets/textures/night3.bmp");
	night4Texture = LoadTexture((char*)"assets/textures/night4.bmp");

	markt1= LoadTexture((char*)"assets/textures/markt/superMarketAd.bmp",150);
	markt2 = LoadTexture((char*)"assets/textures/markt/market1.bmp");
	markt3 = LoadTexture((char*)"assets/textures/markt/market2.bmp");
	markt4 = LoadTexture((char*)"assets/textures/markt/market3.bmp");

	p1 = LoadTexture((char*)"assets/textures/ads/1.bmp");
	p2 = LoadTexture((char*)"assets/textures/ads/2.bmp");
	p3 = LoadTexture((char*)"assets/textures/ads/3.bmp");
	p4 = LoadTexture((char*)"assets/textures/ads/4.bmp");
	p5 = LoadTexture((char*)"assets/textures/ads/5.bmp");


	t1 = LoadTexture((char*)"assets/textures/markt/t1.bmp");
	t2 = LoadTexture((char*)"assets/textures/markt/t2.bmp");
	t3 = LoadTexture((char*)"assets/textures/markt/t6.bmp");
	t4 = LoadTexture((char*)"assets/textures/markt/t4.bmp");
	t5 = LoadTexture((char*)"assets/textures/markt/t5.bmp");

	rt= LoadTexture((char*)"assets/textures/AD/rt.bmp");
	ad1= LoadTexture((char*)"assets/textures/AD/a2.bmp");
	ad2= LoadTexture((char*)"assets/textures/AD/a5.bmp");
	ad3= LoadTexture((char*)"assets/textures/AD/a4.bmp");
	ad4= LoadTexture((char*)"assets/textures/AD/a7.bmp");
	ad5= LoadTexture((char*)"assets/textures/AD/a5.bmp");
	ad6= LoadTexture((char*)"assets/textures/AD/a6.bmp");
	es = LoadTexture((char*)"assets/textures/AD/es.bmp");


	glassTexture = LoadTexture((char*)"assets/textures/glass.bmp",200);

	manModel = new Model_3DS();
	carModel = new Model_3DS();
	sofaModel = new Model_3DS();
	t_90 = new Model_3DS();

	carModel->Load((char*)"assets/models/car/car.3DS");
	carModel->Materials[0].tex.LoadBMP((char*)"assets/models/car/car.bmp");
	carModel->Materials[1].tex.LoadBMP((char*)"assets/models/car/glass1.bmp");
	carModel->Materials[2].tex.LoadBMP((char*)"assets/models/car/glass2.bmp");
	carModel->scale = 0.1;
	carModel->rot.y = 90;
	carModel->pos.x = 35;
	carModel->pos.y = -11;
	carModel->pos.z = -5;

	manModel->Load((char*)"assets/models/man/man.3DS");
	manModel->Materials[0].tex.LoadBMP((char*)"assets/models/man/body.bmp");
	manModel->scale = 0.7;
	manModel->pos.y = -1;
	manModel->pos.z = -1.5;

	sofaModel->Load((char*)"assets/models/sofa/sofa.3DS");
	sofaModel->Materials[0].tex.LoadBMP((char*)"assets/models/sofa/legs.bmp");
	sofaModel->Materials[1].tex.LoadBMP((char*)"assets/models/sofa/leather.bmp");
	sofaModel->Materials[2].tex.LoadBMP((char*)"assets/models/sofa/buttons.bmp");

	sofaModel->scale = 0.07;

	t_90->Load((char*)"assets/models/T-90/T-90.3DS");
	t_90->Materials[2].tex.LoadBMP((char*)"assets/models/T-90/Main Body.bmp");
	t_90->Materials[1].tex.LoadBMP((char*)"assets/models/T-90/Turret.bmp");
	t_90->Materials[0].tex.LoadBMP((char*)"assets/models/T-90/Gun.bmp");
	t_90->Materials[3].tex.LoadBMP((char*)"assets/models/T-90/Main Body 2.bmp");
	
	//Sounds
	SoundManager.Initialize(hWnd);
	SoundManager.CreateSound((char*)"Sounds/mondos.wav", adan);

	SoundManager2.Initialize(hWnd);
	SoundManager2.CreateSound((char*)"Sounds/birds.wav", birds);


	treeModel = new Model_3DS();
	treeModel->Load((char*)"assets/models/Tree/Tree1.3DS");
	
	treeModel->Materials[0].tex.LoadBMP((char*)"assets/models/Tree/bark_loo.bmp"); // إذا كان لديك نسيج للشجرة
	treeModel->Materials[1].tex.LoadBMP((char*)"assets/models/Tree/bat.bmp");
	treeModel->Materials[2].tex.LoadBMP((char*)"assets/models/Tree/bat.bmp");
	treeModel->Materials[3].tex.LoadBMP((char*)"assets/models/Tree/bat.bmp");
	treeModel->Materials[4].tex.LoadBMP((char*)"assets/models/Tree/bat.bmp");
	treeModel->Materials[5].tex.LoadBMP((char*)"assets/models/Tree/bat.bmp");
	treeModel->Materials[6].tex.LoadBMP((char*)"assets/models/Tree/bat.bmp");
	treeModel->Materials[7].tex.LoadBMP((char*)"assets/models/Tree/bat.bmp");
	treeModel->scale = 0.6; // اضبط المقياس حسب الحاجة

	return TRUE;	// Initialization Went OK
}


//void checkPositionToPlaySound() {
//	// التحقق من الإحداثيات لتشغيل صوت العصافير خارج البناء
//	if (xx >= -10 && xx <= 15 && yy >= -12 && zz >= -5 && zz <= 15) {
//		birds.Play(0);
//	}
//	else {
//		birds.Stop();
//	}
//
//	// التحقق من الإحداثيات لتشغيل صوت الأذان داخل البناء
//	if ((xx >= 17 && yy >= -15 && zz >= -30 && zz <= 30)
//		|| (xx >= -50 && xx <= 50 && yy >= -15 && zz <= -5)) {
//		adan.Play(0);
//	}
//	else {
//		adan.Stop();
//	}
//}

float radian(float teta) {
	return teta * pai / 180;
}

bool isClicked = 0, isRClicked = 0;
int mouseX = 0, mouseY = 0;
float xx = -20, yy = 0, zz = 15, xxx = -20, yyy = 0, zzz = 15, teta = 85, mousexx = 0, mouseyy = 0, mouseSensitivity = 0.2,door=0;
bool thirdPerson,isNight;
int pressed,rot=0;
float mousexxDiff = 0, mousexxCurrent = 0, mousexxPrev = 0;

void drawParallelepiped(float length, float width, float height, float x, float y, float z, float r, float g, float b, float alpha) {

	glPushMatrix();
	glBegin(GL_QUADS);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// تعيين اللون والشفافية
	glColor4f(r, g, b, alpha);

	// الوجه الأمامي
	glVertex3f(x - length / 2, y - width / 2, z + height / 2);
	glVertex3f(x + length / 2, y - width / 2, z + height / 2);
	glVertex3f(x + length / 2, y + width / 2, z + height / 2);
	glVertex3f(x - length / 2, y + width / 2, z + height / 2);

	// الوجه الخلفي
	glVertex3f(x - length / 2, y - width / 2, z - height / 2);
	glVertex3f(x + length / 2, y - width / 2, z - height / 2);
	glVertex3f(x + length / 2, y + width / 2, z - height / 2);
	glVertex3f(x - length / 2, y + width / 2, z - height / 2);

	// الوجه الأيمن
	glVertex3f(x + length / 2, y - width / 2, z - height / 2);
	glVertex3f(x + length / 2, y - width / 2, z + height / 2);
	glVertex3f(x + length / 2, y + width / 2, z + height / 2);
	glVertex3f(x + length / 2, y + width / 2, z - height / 2);

	// الوجه الأيسر
	glVertex3f(x - length / 2, y - width / 2, z - height / 2);
	glVertex3f(x - length / 2, y - width / 2, z + height / 2);
	glVertex3f(x - length / 2, y + width / 2, z + height / 2);
	glVertex3f(x - length / 2, y + width / 2, z - height / 2);

	// الوجه العلوي
	glVertex3f(x - length / 2, y + width / 2, z - height / 2);
	glVertex3f(x + length / 2, y + width / 2, z - height / 2);
	glVertex3f(x + length / 2, y + width / 2, z + height / 2);
	glVertex3f(x - length / 2, y + width / 2, z + height / 2);

	// الوجه السفلي
	glVertex3f(x - length / 2, y - width / 2, z - height / 2);
	glVertex3f(x + length / 2, y - width / 2, z - height / 2);
	glVertex3f(x + length / 2, y - width / 2, z + height / 2);
	glVertex3f(x - length / 2, y - width / 2, z + height / 2);

	glEnd();
	glPopMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	rot += 2;
	if (rot >= 360)rot = 0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();			
	

	glDisable(GL_LIGHTING);
	
	glScalef(0.3, 0.3, 0.3);

	// داخل الدالة DrawGLScene

// التحقق من الإحداثيات لتشغيل صوت العصافير خارج البناء
	if ((xx < 0 || xx > 100) || (zz < -50 || zz > 50)) {
		birds.Play(0);
	}
	else {
		birds.Stop();
	}

	// التحقق من الإحداثيات لتشغيل صوت الأذان داخل البناء
	if (xx >= 0 && xx <= 100 && zz >= -50 && zz <= 50) {
		adan.Play(0);
	}
	else {
		adan.Stop();
	}
	
	
	mousexx = mouseSensitivity * (mouseX - 500);
	mouseyy = mouseSensitivity * -1 * (mouseY - 300);

	mousexxPrev = mousexxCurrent;
	mousexxCurrent = mousexx;
	mousexxDiff = mousexxCurrent - mousexxPrev;

	pressed = max(0, pressed - 1);

	if (keys['W'])		 zz -= sin(radian(teta))*0.65, xx += cos(radian(teta))*0.65;
	if (keys['S'])		 zz += sin(radian(teta))*0.65, xx -= cos(radian(teta))*0.65;
	if (keys['A'])		 xx -= sin(radian(teta))*0.65, zz -= cos(radian(teta))*0.65;
	if (keys['D'])		 xx += sin(radian(teta))*0.65, zz += cos(radian(teta))*0.65;
	if (keys[VK_UP])	 yy += 0.2;
	if (keys[VK_DOWN])	 yy -= 0.2;
	if (keys['E'])		 elevatorHight += 0.2;
	if (keys['Q'])		 elevatorHight -= 0.2;
	if (keys['T'])		 if (pressed == 0)		 thirdPerson = !thirdPerson, pressed = 4;
	if (keys['N'])		 if (pressed == 0)		 isNight = !isNight, pressed = 4;




	teta = mouseX >= 990 ? teta - 5 : mouseX <= 10 ? teta + 5 : teta - mousexxDiff;

	if (thirdPerson) yy += 1, zz += 1.5;

	if (xx > 36.75&&xx < 40.75&&zz<-43 && zz>-46) {
		yy = elevatorHight + 1;
	}

	if (xx > 55.25&&xx < 59.25&&zz<-43 && zz>-46) {
		yy = elevatorHight + 1;
	}

	if (xx > 65 && xx < 68 && zz<-21.5 && zz>-24.5) {
		yy = elevatorHight + 1;
	}

	if (xx > 41.5&&xx < 54.5&&zz<-43 && zz>-46) {
		yy = -43 - zz + 1;
	}

	if (xx > 30 && xx < 36 && zz<-43 && zz>-46) {
		yy = 46 + zz + 4;
	}

	if (xx > 60 && xx < 66 && zz<-43 && zz>-46) {
		yy = 46 + zz + 4;
	}

	if (xx > 21 && xx < 31 && zz<-19.75 && zz>-21.5&&yy >= 0) {
		xx += 0.1;
	}

	if (xx > 21 && xx < 31 && zz<-23 && zz>-24.5&&yy<2 && yy>-6) {
		xx += 0.1;
	}

	if (xx > 21 && xx < 31 && zz<-21.5 && zz>-23 && yy<2 && yy>-6) {
		xx -= 0.1;
	}

	if (xx > 21 && xx < 31 && zz<-18 && zz>-19.75&&yy >= 0) {
		xx -= 0.1;
	}


	if (xx > 21 && xx < 31 && zz<-21.5&&zz>-24.5&& yy<2 && yy>-6) {
		yy = (31 - xx)*6.0 / 10.0 - 6 + 1;
	}

	if (xx > 21 && xx < 31 && zz<-18 && zz>-21.5&&yy >= 0) {
		yy = (xx - 21)*6.0 / 10.0 + 1;
	}


	if (sqrt((xx - 48)*(xx - 48) + (zz + 23)*(zz + 23)) < 3 && yy > -6) {
		float X = xx - 48;
		float Z = -23 - zz;
		Z *= -1;
		X *= -1;
		if (X != 0) {
			float T = atan2(Z, X);

			yy = -6 + ((T + pai) / (2 * pai)) * 6 + 1;
		}	
	}




	xxx = xx + cos(radian(teta));
	zzz = zz - sin(radian(teta));
	yyy = yy;
	if (thirdPerson) yyy -= 0.2;

	if (thirdPerson)  manModel->Draw();

	gluLookAt(xx, yy, zz, xxx, yyy, zzz, 0, 1, 0);

	carModel->Draw();

	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);

	Draw draw;

	glTranslatef(0, -1.5, 0);
	
	

	if (isNight) {
		glPushMatrix();

		glTranslatef(-60, 0, 35);
		draw.rectangleXY(0, 0, 0, 138, 100, 1, night1Texture, 0, 0, 1, 0, 1, 1, 0, 1);
		glTranslatef(138, 0, 0);
		glRotatef(90, 0, 1, 0);
		draw.rectangleXY(0, 0, 0, 85, 100, 1, night2Texture, 0, 0, 1, 0, 1, 1, 0, 1);
		glTranslatef(85, 0, 0);
		glRotatef(90, 0, 1, 0);
		draw.rectangleXY(0, 0, 0, 138, 100, 1, night3Texture, 0, 0, 1, 0, 1, 1, 0, 1);
		glTranslatef(138, 0, 0);
		glRotatef(90, 0, 1, 0);
		draw.rectangleXY(0, 0, 0, 85, 100, 1, night4Texture, 0, 0, 1, 0, 1, 1, 0, 1);

		glPopMatrix();
	}
	else {
		glPushMatrix();
		
		glTranslatef(-60, 0, 35);
		draw.rectangleXY(0, 0, 0, 138, 100, 1, sky1Texture, 0, 0, 1, 0, 1, 1, 0, 1);
		glTranslatef(138, 0, 0);
		glRotatef(90, 0, 1, 0);
		draw.rectangleXY(0, 0, 0, 85, 100, 1, sky2Texture, 0, 0, 1, 0, 1, 1, 0, 1);
		glTranslatef(85, 0, 0);
		glRotatef(90, 0, 1, 0);
		draw.rectangleXY(0, 0, 0, 138, 100, 1, sky3Texture, 0, 0, 1, 0, 1, 1, 0, 1);
		glTranslatef(138, 0, 0);
		glRotatef(90, 0, 1, 0);
		draw.rectangleXY(0, 0, 0, 85, 100, 1, sky4Texture, 0, 0, 1, 0, 1, 1, 0, 1);

		glPopMatrix();
	}

	
	draw.rectangleYZ(-5.1 + 18, 2 - 12, -32, 10, 3, 1, EXitTexture, 0, 0, 1, 0, 1, 1, 0, 1);

	draw.rectangleXZ(0, 0.001, -43, 17, 7, 1, floorTexture, 0, 0, 1, 0, 1, 1, 0, 1);

	cnt = (cnt + 1) % 24;

	// down half floor
	glPushMatrix();
	glTranslatef(18, 0, 0);
	draw.rectangleXZ(0, 0, 0, 3, 43,1, floorTexture, 0, 0, 1, 0, 1, 14, 0, 14);
	draw.rectangleXZ(3, 0, 0, 10, 21.5,1, floorTexture, 0, 0, 2, 0, 2, 4, 0,4);
	draw.rectangleXZ(13, 0, 0, 5, 43,1, floorTexture, 0, 0, 1, 0, 1, 9, 0, 9);
	draw.rectangleXZ(18, 0, 0, 4, 21.5,1, floorTexture, 0, 0, 1, 0, 1, 5, 0,5);
	draw.rectangleXZ(22, 0, 0, 5, 43,1, floorTexture, 0, 0, 1, 0, 1, 9, 0, 9);
	draw.rectangleXZ(27, 0, 0, 6, 20,1, floorTexture, 0, 0, 1, 0, 1, 4, 0, 4);
	draw.rectangleXZ(33, 0, 0, 5, 43,1, floorTexture, 0, 0, 1, 0, 1, 9, 0, 9);
	draw.rectangleXZ(38, 0, 0, 4, 21.5,1, floorTexture, 0, 0, 1, 0, 1, 5, 0, 5);
	draw.rectangleXZ(42, 0, 0, 5, 43,1, floorTexture, 0, 0, 1, 0, 1, 9, 0, 9);
	draw.rectangleXZ(47, 0, 0, 3, 21.5,1, floorTexture, 0, 0, 1, 0, 1, 7, 0, 7);
	draw.rectangleXZ(50, 0, 0, 10, 43,1, floorTexture, 0, 0, 2, 0, 2, 9, 0, 9);
     
	//overdrive -1
	draw.rectangleXZ(0,  -0.2, 0, 3, 43,   -1,overdrive, 0, 0, 0.05, 0, 0.05, 1, 0, 1);
	draw.rectangleXZ(3,  -0.2, 0, 10, 21.5, -1, overdrive, 0, 0, 0.16, 0, 0.16, 0.5, 0, 0.5);
	draw.rectangleXZ(13, -0.2, 0, 5, 43, -1, overdrive, 0, 0, 0.08, 0, 0.08, 1, 0, 1);
	draw.rectangleXZ(18, -0.2, 0, 4, 21.5, -1, overdrive, 0, 0, 0.06, 0, 0.06, 0.5, 0, 0.5);
	draw.rectangleXZ(22, -0.2, 0, 5, 43, -1, overdrive, 0, 0, 0.08, 0, 0.08, 1, 0, 1);
	draw.rectangleXZ(27, -0.2, 0, 6, 20, -1, overdrive, 0, 0, 0.1, 0, 0.1, 0.46, 0, 0.46);
	draw.rectangleXZ(33, -0.2, 0, 5, 43, -1, overdrive, 0, 0, 0.08, 0, 0.08, 1, 0, 1);
	draw.rectangleXZ(38, -0.2, 0, 4, 21.5, -1, overdrive, 0, 0, 0.06, 0, 0.06, 0.5, 0, 0.5);
	draw.rectangleXZ(42, -0.2, 0, 5, 43, -1, overdrive, 0, 0, 0.08, 0, 0.08, 1, 0, 1);
	draw.rectangleXZ(47, -0.2, 0, 3, 21.5, -1, overdrive, 0, 0, 0.05, 0, 0.05, 0.5, 0, 0.5);
	draw.rectangleXZ(50, -0.2, 0, 10, 43, -1, overdrive, 0, 0, 0.16, 0, 0.16, 1, 0, 1);

	glPopMatrix();

	// up half floor
	glPushMatrix();
	glTranslatef(0, 0, -18);
	draw.rectangleXZ(0, 0, 0, 18, 25,1, floorTexture, 0, 0, 4, 0, 4, 6, 0, 6);
	glTranslatef(18, 0, -5);
	draw.rectangleXZ(3, 0, -1.5, 10, 18.5, 1, floorTexture, 0, 0, 2, 0, 2, 3, 0, 3);
	draw.rectangleXZ(18, 0, -1.5, 4, 18.5, 1, floorTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(27, 0, -3, 6, 17, 1, floorTexture, 0, 0, 1, 0, 1, 3, 0, 3);
	draw.rectangleXZ(38, 0, -1.5, 4, 18.5, 1, floorTexture, 0, 0, 1, 0, 1, 3, 0, 3);
	draw.rectangleXZ(47, 0, -1.5, 3, 18.5, 1, floorTexture, 0, 0, 1, 0, 1, 3, 0, 3);
	
	//overdrive -1
	
	draw.rectangleXZ(3,  -0.2,  -1.5, 10, 18.5,-1, overdrive, 0, 0,0.16, 0, 0.16, 0.41, 0, 0.41);
	draw.rectangleXZ(18, -0.2, -1.5, 4, 18.5, -1, overdrive, 0, 0, 0.06, 0, 0.06, 0.41, 0, 0.41);
	draw.rectangleXZ(27, -0.2, -3  , 6, 17, -1, overdrive, 0, 0, 0.1, 0, 0.1, 0.39, 0, 0.39);
	draw.rectangleXZ(38, -0.2, -1.5, 4, 18.5, -1, overdrive, 0, 0, 0.06, 0, 0.06, 0.41, 0, 0.41);
	draw.rectangleXZ(47, -0.2, -1.5, 3, 18.5, -1, overdrive, 0, 0, 0.05, 0, 0.05, 0.41, 0, 0.41);

	glPopMatrix();

	// overdrive floor i/
	draw.rectangleXZ(18, 12, 0, 60, 50,-1, overdriveTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(0, 12, -18, 18, 32,-1, overdriveTexture, 0, 0, 0.3, 0, 0.3, 0.6, 0, 0.6);
	// center circle
	glPushMatrix();
	glTranslatef(48, 0, -23);

	float unit = pai / 40;

	// up left corner
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-3, 0, -3);
	glVertex3f(-3, 0, 0);
	for (int i = 0; i <= 10; i++) {
		float teta = -2 * i * unit + pai;
		float x = 3 * cos(teta);
		float z = -3 * sin(teta);

		glVertex3f(x, 0, z);
	}
	glEnd();

	// up right corner
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(3, 0, -3);
	glVertex3f(0, 0, -3);
	for (int i = 0; i <= 10; i++) {
		float teta = -2 * i * unit + pai / 2;
		float x = 3 * cos(teta);
		float z = -3 * sin(teta);

		glVertex3f(x, 0, z);
	}
	glEnd();

	// down right corner
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(3, 0, 3);
	glVertex3f(3, 0, 0);
	for (int i = 0; i <= 10; i++) {
		float teta = -2 * i * unit;
		float x = 3 * cos(teta);
		float z = -3 * sin(teta);

		glVertex3f(x, 0, z);
	}
	glEnd();

	// down left corner
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-3, 0, 3);
	glVertex3f(0, 0, 3);
	for (int i = 0; i <= 10; i++) {
		float teta = -2 * i * unit + 3 * pai / 2;
		float x = 3 * cos(teta);
		float z = -3 * sin(teta);

		glVertex3f(x, 0, z);
	}
	glEnd();

	glPopMatrix();

	// center-right elevator
	glPushMatrix();
	
	if (elevatorHight < -6)
		glTranslatef(66.5, 1.5 - 6, -23);
	else
		glTranslatef(66.5, 1.5 + elevatorHight, -23);

	glRotatef(90, 0, 1, 0);
	draw.elevator(3, 3, 3);
	glPopMatrix();

	// left fence
	glPushMatrix();

	glColor3f(1, 0, 0);
	glTranslatef(38, 0.5, -21.5);
	draw.fence(4, 1);
	glColor3f(1, 1, 0);
	glTranslatef(2, 0, -1.5);
	glRotatef(90, 0, 1, 0);
	draw.fence(3, 1);
	glColor3f(1, 0, 0);
	glTranslatef(1.5, 0, -2);
	glRotatef(90, 0, 1, 0);
	draw.fence(4, 1);
	glColor3f(1, 1, 0);
	glTranslatef(2, 0, -1.5);
	glRotatef(90, 0, 1, 0);
	draw.fence(3, 1);

	// right fence
	glTranslatef(0, 0, -22);
	glColor3f(1, 0, 0);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, 1.5);
	draw.fence(4, 1);
	glColor3f(1, 1, 0);
	glTranslatef(2, 0, -1.5);
	glRotatef(90, 0, 1, 0);
	draw.fence(3, 1);
	glColor3f(1, 0, 0);
	glTranslatef(1.5, 0, -2);
	glRotatef(90, 0, 1, 0);
	draw.fence(4, 1);
	glColor3f(1, 1, 0);
	glTranslatef(2, 0, -1.5);
	glRotatef(90, 0, 1, 0);
	draw.fence(3, 1);

	glPopMatrix();
	glColor3f(1, 1, 1);

	// left & right walls & center stairs & elevators

	glPushMatrix();
	glTranslatef(36, 0, -43);
	glTranslatef(0, -12, 0);
	draw.rectangleXY(0, 0, 0, 0.75, 24, 1, wallTexture, 0, 0, 0.75, 0, 0.75, 24, 0, 24);
	draw.rectangleXY(0, 0, -3, 0.75, 24, 1, wallTexture, 0, 0, 0.75, 0, 0.75, 24, 0, 24);
	draw.rectangleYZ(0, 0, 0, 3, 24, 1, wallTexture, 0, 0, 3, 0, 3, 24, 0, 24);

	glTranslatef(0.75, 0, 0);

	draw.rectangleYZ(0, 0, 0, 3, 24, 1, wallTexture, 0, 0, 3, 0, 3, 24, 0, 24);
	draw.rectangleXY(0, 0, -3, 4, 24, 1, wallTexture, 0, 0, 4, 0, 4, 24, 0, 24);
	draw.rectangleXZ(0, 0, 0, 4, 3, 1, wallTexture, 0, 0, 4, 0, 4, 3, 0, 3);

	glTranslatef(0, 12, 0);

	draw.rectangleXY(0, 3, 0, 4, 3, 1, wallTexture, 0, 0, 4, 0, 4, 3, 0, 3);
	draw.rectangleXY(0, 9, 0, 4, 3, 1, wallTexture, 0, 0, 4, 0, 4, 3, 0, 3);


	glTranslatef(2, 1.5 + elevatorHight, -1.5);

	draw.elevator(4 - 0.02, 3, 3);

	glTranslatef(2, -1.5 - elevatorHight, 1.5);

	glTranslatef(0, -12, 0);
	draw.rectangleXY(0, 0, 0, 0.75, 24, 1, wallTexture, 0, 0, 0.75, 0, 0.75, 24, 0, 24);
	draw.rectangleXY(0, 0, -3, 0.75, 24, 1, wallTexture, 0, 0, 0.75, 0, 0.75, 24, 0, 24);
	draw.rectangleYZ(0, 0, 0, 3, 24, 1, wallTexture, 0, 0, 3, 0, 3, 24, 0, 24);
	glTranslatef(0.75, 0, 0);
	draw.rectangleYZ(0, 0, 0, 3, 24, 1, wallTexture, 0, 0, 3, 0, 3, 24, 0, 24);

	glTranslatef(0, 12, 0);

	draw.stairs(13, 3, 3, floorTexture);

	glTranslatef(13, 0, 0);

	glTranslatef(0, -12, 0);

	draw.rectangleXY(0, 0, 0, 0.75, 24, 1, wallTexture, 0, 0, 0.75, 0, 0.75, 24, 0, 24);
	draw.rectangleXY(0, 0, -3, 0.75, 24, 1, wallTexture, 0, 0, 0.75, 0, 0.75, 24, 0, 24);
	draw.rectangleYZ(0, 0, 0, 3, 24, 1, wallTexture, 0, 0, 3, 0, 3, 24, 0, 24);
	glTranslatef(0.75, 0, 0);

	draw.rectangleYZ(0, 0, 0, 3, 24, 1, wallTexture, 0, 0, 3, 0, 3, 24, 0, 24);
	draw.rectangleXY(0, 0, -3, 4, 24, 1, wallTexture, 0, 0, 4, 0, 4, 24, 0, 24);
	draw.rectangleXZ(0, 0, 0, 4, 3, 1, wallTexture, 0, 0, 4, 0, 4, 3, 0, 3);

	glTranslatef(0, 12, 0);

	draw.rectangleXY(0, 3, 0, 4, 3, 1, wallTexture, 0, 0, 4, 0, 4, 3, 0, 3);
	draw.rectangleXY(0, 9, 0, 4, 3, 1, wallTexture, 0, 0, 4, 0, 4, 3, 0, 3);

	glTranslatef(2, 1.5 + elevatorHight, -1.5);

	draw.elevator(4 - 0.02, 3, 3);

	glTranslatef(2, -1.5 - elevatorHight, 1.5);

	glTranslatef(0, -12, 0);

	draw.rectangleXY(0, 0, 0, 0.75, 24, 1, wallTexture, 0, 0, 0.75, 0, 0.75, 24, 0, 24);
	draw.rectangleXY(0, 0, -3, 0.75, 24, 1, wallTexture, 0, 0, 0.75, 0, 0.75, 24, 0, 24);
	draw.rectangleYZ(0, 0, 0, 3, 24, 1, wallTexture, 0, 0, 3, 0, 3, 24, 0, 24);
	glTranslatef(0.75, 0, 0);
	draw.rectangleYZ(0, 0, 0, 3, 24, 1, wallTexture, 0, 0, 3, 0, 3, 24, 0, 24);

	glTranslatef(0, 12, 0);

	glPopMatrix();

	// left & right stairs
	glPushMatrix();
	glTranslatef(36, 3, -46);
	glRotatef(180, 0, 1, 0);
	draw.rectangleXY(0, 0, -3, 6, 3,1, wallTexture, 0, 0, 6, 0, 6, 3, 0, 3);
	draw.stairs(6, 3, 3, floorTexture);
	draw.rectangleYZ(6, 0, 4, 7, 9,1, wallTexture, 0, 0, 7, 0, 7, 9, 0, 9);
	glTranslatef(-30, 0, 0);
	draw.rectangleXY(0, 0, -3, 6, 3,1, wallTexture, 0, 0, 6, 0, 6, 3, 0, 3);
	draw.rectangleYZ(0, 0, 4, 7, 9,1, wallTexture, 0, 0, 7, 0, 7, 9, 0, 9);
	draw.stairs(6, 3, 3, floorTexture);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(30, 3, -46);
	draw.rectangleXZ(0, 0, 0, 36, 4,1, floorTexture, 0, 0, 1, 0,1, 1, 0, 1);
	draw.rectangleXY(0, 0, -4, 36, 9,1, floorTexture, 0, 0, 36, 0, 36, 9, 0, 9);
	glPopMatrix();

	glPushMatrix();
	// ground 1 up floor
	glTranslatef(0, 6, -33);
	draw.rectangleXZ(0, 0, 0, 78, 10,1, floorTexture, 0, 0, 8, 0, 8, 1, 0, 1);
	glPopMatrix();

	// ground 1 down floor
	glPushMatrix();
	glTranslatef(18, 6, 0);
	draw.rectangleXZ(0, 0, 0, 60, 18,1, floorTexture, 0, 0, 6, 0, 6, 1, 0, 1);
	draw.rectangleXZ(25, 0, 0, 10, 8,1, floorTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(13, 0, -18, 5, 15, 1, floorTexture, 0, 0, 1, 0, 1, 4, 0, 4);
	// ground 1 right floor
	glTranslatef(50, 0, -18);
	draw.rectangleXZ(0, 0, 0, 10, 15,1, floorTexture, 0, 0, 1, 0, 1, 1, 0, 1);

	glPopMatrix();

	//wall inside 
	draw.rectangleYZ(18.2, 0, 0, 18.2, 12,1,  wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);

	draw.rectangleXY(32,4,-8,-3,2,-1, cloTexture2, 0.35, 0.8, 0.65, 0.8, 0.65, 1, 0.35, 1);
	draw.rectangleXY(32, 11, -8, -3, 1, -1, cloTexture7, 0.35, 0.8, 0.65, 0.8, 0.65, 0.9, 0.35, 0.9);

	draw.rectangleXY(67, 5, -8, -3, 1, -1, cloTexture7, 0.35, 0.8, 0.65, 0.8, 0.65, 0.9, 0.35, 0.9);
	draw.rectangleXY(67, 10, -8, -3, 2, -1, cloTexture2, 0.35, 0.8, 0.65, 0.8, 0.65, 1, 0.35, 1);

	draw.rectangleXY(43, 6, -8, 10, 6,-1, wallTexture2, 0, 0.5, 0.37, 0.5, 0.37, 1, 0, 1);
	draw.rectangleYZ(77.9, 0, 0, 50, 12,-1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(0.2, 0, -24, 26, 12,1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(0.2, 0, -18, 2, 12,1, wallTexture2, 0, 0, 0.076, 0, 0.076, 1, 0, 1);
	draw.rectangleYZ(0.2, 6, -20, 4, 6,1, wallTexture2, 0, 0.5, 0.1, 0.5, 0.15, 1, 0, 1);
	draw.rectangleXY(0, 0, -18.2, 18.2,-1, 12, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	//
	//draw.rectangleXY(0, 0, -49.9, 17, 12,1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	//draw.rectangleXY(0, 0, -43, 13, 12,1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	//draw.rectangleYZ(17, 0, -43, 6.9, 12,-1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(17, 0, -43, 13, 12,1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	
	draw.rectangleXY(41.5, 6, -43, 13, 6,1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);

	draw.rectangleXY(26, 0, -49.8, 44, 12,1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	
	draw.rectangleXY(66, 0, -49.9, 13, 12,1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(66, 0, -43, 7, 12, 1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(70, 0, -43, 8, 12, 1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);


	draw.rectangleXY(30, 0, -43, 6, 6,1, wallTexture2, 0, 0, 0.16, 0, 0.16, 0.5, 0,0.5);
	draw.rectangleXY(60, 0, -43, 6, 6,1, wallTexture2, 0, 0, 0.16, 0, 0.16, 0.5, 0, 0.5);

	draw.rectangleYZ(43, 0, 0, 8.2, 12,1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(53, 0, 0, 8.2, 12,-1, wallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);

	//-1 ground

	glEnable(GL_LIGHTING);
	
	draw.rectangleXZ(18, -6, 0, 60, 43,1, groundTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	
	glPushMatrix();
	glTranslated(18, -6, 0);
	for (int i = 10; i < 55; i += 5) {
		draw.table(i, 1, -7.5, 2, 1, 2,  tableTexture);
		draw.table(i, 1, -12.5, 2, 1, 2, tableTexture);
		draw.table(i, 1, -17.5, 2, 1, 2, tableTexture);
		if (i >= 40)
		{
			draw.table(i, 1, -27.5, 2, 1, 2, tableTexture);
			draw.table(i, 1, -32.5, 2, 1, 2, tableTexture);
			draw.table(i, 1, -37.5, 2, 1, 2, tableTexture);
		}
		draw.chair(i+1, 0, -7, chairTexture);
		draw.chair(i+1, 0, -12, chairTexture);
		draw.chair(i + 1, 0, -17, chairTexture);
		if (i >= 40)draw.chair(i + 1, 0, -27, chairTexture), draw.chair(i + 1, 0, -32, chairTexture), draw.chair(i + 1, 0, -37, chairTexture);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		draw.chair(  8.5, 0, i + 2.5, chairTexture);
		draw.chair(13.5, 0, i + 2.5, chairTexture);
		draw.chair(18.5, 0, i + 2.5, chairTexture);
		if(i>=40) draw.chair(28.5, 0, i + 2.5, chairTexture), draw.chair(33.5, 0, i+2.5, chairTexture), draw.chair(38.5, 0, i+2.5, chairTexture);
		glRotated(90, 0, 1, 0);
		draw.chair(-i - 1, 0,  10, chairTexture);
		draw.chair(-i - 1, 0, 15, chairTexture);
		draw.chair(-i - 1, 0, 20, chairTexture);
		if(i>=40)draw.chair(-i - 1, 0, 30, chairTexture), draw.chair(-i - 1, 0, 35, chairTexture), draw.chair(-i - 1, 0, 40, chairTexture);
		glRotated(90, 0, 1, 0);
		draw.chair(-9, 0,  -i+0.5, chairTexture);
		draw.chair(-14, 0, -i+0.5, chairTexture);
		draw.chair(-19, 0, -i+0.5, chairTexture );
		if(i>=40)draw.chair(-29, 0, -i + 0.5, chairTexture), draw.chair(-34, 0, -i+0.5, chairTexture), draw.chair(-39, 0, -i+0.5, chairTexture);
		glPopMatrix();
		
	}
	glPopMatrix();


	glDisable(GL_LIGHTING);

	//-2 ground
	draw.rectangleXZ(18, -12, 0, 60, 43,1, groundTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(18, -6.1, 0, 60, 43,-1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	glPushMatrix();
	glTranslated(18, -12, 0);
	for (int i = 12; i < 45; i+=15)
		for (int j = -1; j > -34; j -= 16)
		{
			if (j == -33 && i == 12)continue;
			draw.rectangleXZ(i, 0, j, 0.2, 8,1, -1, 0, 0, 1, 0, 1, 1, 0, 1);
			draw.rectangleXZ(i + 11, 0, j, 0.2, 8,1, -1, 0, 0, 1, 0, 1, 1, 0, 1);
			draw.rectangleXZ(i, 0, j, 11, 0.2,1, -1, 0, 0, 1, 0, 1, 1, 0, 1);
			draw.rectangleXZ(i, 0, j - 8, 11, 0.2,1, -1, 0, 0, 1, 0, 1, 1, 0, 1);
		}
	glPopMatrix();

	//wall -1ground
	draw.rectangleXY(18, -12, 0, 60, 12,-1, groundWallTexture2, 0, 0, 3, 0, 3, 1, 0, 1);
	draw.rectangleYZ(78, -12, 0, 43, 12,-1, groundWallTexture2, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(18, -12, 0, 31, 6,1, groundWallTexture2, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(18, -6, 0, 43, 6,1, groundWallTexture2, 0, 0, 2, 0, 2, 0.5, 0, 0.5);
	draw.rectangleXY(18, -12, -43, 18, 12,1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(41.5, -12, -43, 13, 12,1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(60, -12, -43, 18, 12,1, groundWallTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	
	glColor3d(1, 1, 1);
	//cone -2ground
	glPushMatrix();
	glTranslated(18, -12, 0);
	for (int i = 10; i <= 60; i += 15) {
		draw.cone(i, 0, -12, 5.9, 1, groundWallTexture2,0,0,0.2,0,0.2,1,0,1);
		draw.cone(i, 0, -30, 5.9, 1, groundWallTexture2,0,0,0.1,0,0.1,1,0,1);
	}
	glPopMatrix();

	//street car parking 
	draw.parking();

	glColor3d(1, 1, 1);
	//Circle staris
	draw.stairs_circle(48, 0, -23, 3, 6, groundSkybox);
	for (float i = -0.1; i > -5.6; i -= 0.2)
	{
		float q = 3.1 * cos(i);
		float w = 3.1 * sin(i);
		glColor3ub(138, 138, 138);
		draw.cone(48 + q, 0, -23 + w, 1, 0.1, -1, 0, 0, 1, 0, 1, 1, 0, 1);
		draw.draw_Sphare(48 + q, 1.1, -23 + w, 0.1, 1, 0, 0, 0.01);
		glColor3ub(138, 138, 138);
		if (i == -0.5)
		{
			glPushMatrix();
			glTranslated(48, 0, -23);

			for (float j = 0; j <= 3; j += 0.7) {
				draw.cone(j, -0.1, 0, 1, 0.1, -1, 0, 0, 1, 0, 1, 1, 0, 1);
				draw.draw_Sphare(j, 1, 0, 0.1, 1, 0, 0, 0.01);
				glColor3ub(138, 138, 138);
			}
			for (float j = 0.3; j <= 1.5; j += 0.5)
			{
				draw.cone(0, -0.1, j, 1, 0.1, -1, 0, 0, 1, 0, 1, 1, 0, 1);
				draw.draw_Sphare(0, 1, j, 0.1, 1, 0, 0, 0.01);
				glColor3ub(138, 138, 138);
			}
			glPopMatrix();
			glColor3d(1, 1, 1);
		}
	}
	glColor3d(1, 1, 1);
	//texture -1ground 
	glPushMatrix();
	glTranslated(18, -6, 0);
	glRotated(180, 0, 1, 0);
	draw.rectangleXY(-10, 0, 0.5, 9, 6, -1, resTexture1, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(-20, 0, 0.5, 9, 6, -1, resTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(-30, 0, 0.5, 9, 6, -1, resTexture3, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(-40, 0, 0.5, 9, 6, -1, resTexture4, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(-50, 0, 0.5, 9, 6, -1, resTexture5, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(-60, 0, 0.5, 9, 6, -1, resTexture6, 0, 0, 1, 0, 1, 1, 0, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(18, -6, 0);
	draw.rectangleYZ(0.5, 0, -1, 9, 6, 1, resTexture5, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(0.5, 0, -11, 9, 6, 1, resTexture6, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(44, 0, -42.5, 15, 6, 1, resTexture4, 0, 0, 1, 0, 1, 1, 0, 1);

	draw.rectangleYZ(59.5, 0, -10, -9, 6, -1, resTexture1, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(59.5, 0, -20, -9, 6, -1, resTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(59.5, 0, -42, -15, 6, -1, resTexture5, 0, 0, 1, 0, 1, 1, 0, 1);
	glBindTexture(GL_TEXTURE_2D, ORIGI4);

	glNormal3d(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(0.2, 3, -39);
	glTexCoord2d(1, 0);
	glVertex3f(3, 3, -42.8);
	glTexCoord2d(1, 1);
	glVertex3f(3, 5.8, -42.8);
	glTexCoord2d(0, 1);
	glVertex3f(0.2, 5.8, -39);
	glEnd();
	draw.wall_circle(0.2, 0, -28, 11, tableTexture, tableTexture, 0.2, 1);
	sofaModel->rot.y = 90;
	sofaModel->pos.x = 6.2;
	sofaModel->pos.y = 1;
	sofaModel->pos.z = -29.8;
	sofaModel->Draw();

	glTranslated(15, 0, -28);
	glRotated(90, 0, 1, 0);
	draw.wall_circle(1.8, 0, 0, 13, tableTexture, tableTexture, 0.2, 1);
	sofaModel->pos.x = 5.2;
	sofaModel->pos.y = 1;
	sofaModel->pos.z = -1.8;
	sofaModel->Draw();
	sofaModel->pos.x = 10.4;
	sofaModel->Draw();
	glPopMatrix();

	//wall 2
	draw.wall(0.1, 6, -33.1, 31, groundWallTexture2, groundSkybox);
	draw.wall(36, 6, -33.1, 32, groundWallTexture2, groundSkybox);
	draw.wall(18, 6, -17.9, 13, groundWallTexture2, groundSkybox);
	draw.wall(36, 6, -17.9, 32, groundWallTexture2, groundSkybox);
	glPushMatrix();
	glTranslated(31, 6, -18);
	glRotated(90, 0, 1, 0);
	draw.wall(3.5, 0, 0, 11, groundWallTexture2, groundSkybox);
	draw.wall(0, 0, 5, 15, groundWallTexture2, groundSkybox);

	glPopMatrix();
	glPushMatrix();
	glTranslated(68.1, 6, -18);
	glRotated(90, 0, 1, 0);
	draw.wall(0, 0, 0, 3.5, groundWallTexture2, groundSkybox);
	draw.wall(6.5, 0, 0, 8, groundWallTexture2, groundSkybox);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-18, 0,-40); // اضبط الموضع حسب الحاجة
	glRotatef(90, 0, 1, 0);
	t_90->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-35, 0, -20); // اضبط الموضع حسب الحاجة
	treeModel->Draw();
	glPopMatrix();


	//wall 1&&2 texture

	draw.rectangleXZ(0, 6, -43, 17, 7, 1, floorTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(66, 6, -43, 12, 7, 1, floorTexture, 0, 0, 1, 0, 1, 1, 0, 1);


	//محلات
	//////////////////////////////////////////////////////////////////////
	//امام
	draw.rectangleXY(0, 0, -42.8, 13, 6, 1, p1, 0, 0, 1, 0, 1, 1, 0, 1);
	//
	draw.rectangleXY(13, 0, -43.2, -13, 6, -1, p4, 0, 0, 1, 0, 1, 1, 0, 1);
	//خلف
	draw.rectangleXY(0, 0, -49.9, 17, 6, 1, p2, 0, 0, 1, 0, 1, 1, 0, 1);

	draw.rectangleYZ(0.2, 0, -43, 6.9, 6, 1, p5, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(16.9, 0, -49.9, -6.9, 6, -1, p3, 0, 0, 1, 0, 1, 1, 0, 1);
	//
	
	sofaModel->rot.y = 90;
	sofaModel->pos.x = 3;
	sofaModel->pos.y = 0;
	sofaModel->pos.z = -48;
	sofaModel->Draw();

	sofaModel->rot.y = 90;
	sofaModel->pos.x = 8;
	sofaModel->pos.y = 0;
	sofaModel->pos.z = -48;
	sofaModel->Draw();

	sofaModel->rot.y = 90;
	sofaModel->pos.x = 14;
	sofaModel->pos.y = 0;
	sofaModel->pos.z = -48;
	sofaModel->Draw();
	
	draw.rectangleXY(18.5, 0, -42.8, 16.5, 6, 1, cloTexture7, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(61, 0, -42.8, 16, 6, 1, cloTexture9, 0, 0, 1, 0, 1, 1, 0, 1);
	//
	draw.rectangleXY(1, 6, -42.8, 13, 6, 1, cloTexture8, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(14, 6, -43.2, -13, 6, -1, clo5, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(0, 6, -49.9, 17, 6, 1, clo4, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(0.2, 6, -43, 6.9, 6, 1, clo1, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(16.9, 6, -49.9, -6.9, 6, -1, clo2, 0, 0, 1, 0, 1, 1, 0, 1);
	//

	draw.rectangleXY(18.5, 6, -42.8, 10.5, 6, 1, cloTexture4, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(42.5, 6, -42.8, 11, 6, 1, cloTexture5, 0, 0, 1, 0, 1, 1, 0, 1);
	//
	draw.rectangleXY(70, 6, -42.8, 8, 6, 1, cloTexture6, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(78, 6, -43.2, -8, 6, -1, clo5, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(66, 6, -49.8, 12, 6, 1, clo4, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(66.1, 6, -43, 6.9, 6, 1, clo1, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(77.7, 6, -49.9, -6.9, 6, -1, clo2, 0, 0, 1, 0, 1, 1, 0, 1);


	// 
	draw.rectangleXY(43, 0, -8, -11, 6, -1, cloTexture2, 0, 0, 0.35, 0, 0.35, 1, 0, 1);
	draw.rectangleXY(29, 0, -8, -11, 6, -1, cloTexture2, 0.65, 0, 1, 0, 1, 1, 0.65, 1);
	draw.rectangleXY(42.8, 0, -0.2, -24.6, 6, -1, clo4, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(18.2, 0, -7.9, 10.6, 6, 1, clo5, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(32, 0, -7.9, 11, 6, 1, clo3, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(18.2, 0, -0.2, 7.7, 6, 1, clo1, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(42.8, 0, -0.2, 7.7, 6, 1, clo2, 0, 0, 1, 0, 1, 1, 0, 1);
	//2فوق السمانة
	draw.rectangleXY(78, 6, -8, -11, 6, -1, t3, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(64, 6, -8, -11, 6, -1, t3, 0, 0, 1, 0, 1, 1, 0, 1);
	//b
	draw.rectangleXY(77.8, 6, -0.2, -24.6, 6, -1, t2, 0, 0, 2, 0, 2, 1, 0, 1);

	draw.rectangleXY(53.2, 6, -7.9, 10.6, 6, 1, t4, 0, 0, 1, 0, 1, 1, 0, 1);

	draw.rectangleXY(67, 6, -7.9, 11, 6, 1, t4, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(53.2, 6, -0.2, 7.7, 6, 1, t5, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(77.8, 6, -0.2, 7.7, 6, 1, t3, 0, 0, 1, 0, 1, 1, 0, 1);

	//
	draw.rectangleXY(43, 6, -8, -11, 6, -1, cloTexture7, 0, 0.2, 0.35, 0.2, 0.35, 0.9, 0, 0.9);
	draw.rectangleXY(29, 6, -8, -11, 6, -1, cloTexture7, 0.65, 0.2, 1, 0.2, 1, 0.9, 0.65, 0.9);
	draw.rectangleXY(42.8, 6, -0.2, -24.6, 6, -1, clo4, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(18.2, 6, -7.9, 10.6, 6, 1, clo5, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(32, 6, -7.9, 11, 6, 1, clo3, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(18.2, 6, -0.2, 7.7, 6, 1, clo1, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(42.8, 6, -0.2, 7.7, 6, 1, clo2, 0, 0, 1, 0, 1, 1, 0, 1);
	//

	
	// محل الي حد الباب من اليسار
	// 
	draw.rectangleXY(78, 0, -8, -11, 6, -1, markt1, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(64, 0, -8, -11, 6, -1, markt1, 0, 0, 1, 0, 1, 1, 0, 1);

	/*drawParallelepiped(-11, 6, -1, 78, 0, -8, 1, 1, 1, 0.5);
	drawParallelepiped(-11, 6, -1, 64, 0, -8, 1, 1, 1, 0.5);*/

	draw.rectangleXY(77.8, 0, -0.2, -24.6, 6, -1, markt3, 0, 0, 3, 0, 3, 1, 0, 1);

	//draw.rectangleXY(53.2, 0, -7.9, 10.6, 6, 1, clo5, 0, 0, 1, 0, 1, 1, 0, 1);

	//draw.rectangleXY(60, 4, -8, 15, 1.3, -1, cl, 0, 0.2, 0.35, 0.2, 0.35, 0.9, 0, 0.9);

	//draw.rectangleXY(67, 0, -7.9, 11, 6, 1, clo3, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(53.2, 0, -0.2, 7.7, 6, 1, markt2, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(77.8, 0, -0.2, 7.7, 6, 1, markt2, 0, 0, 2, 0, 2, 1, 0, 1);
	//F,B
	draw.rectangleXY(75, 0, -4, -7, 2, -1, markt4, 0, 0, 3, 0, 3, 1, 0, 1);
	draw.rectangleXY(75, 0, -2, -7, 2, -1, markt4, 0, 0, 3, 0, 3, 1, 0, 1);
	//L,R
	draw.rectangleYZ(75, 0, -2, 2, 2, 1, markt4, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(68, 0, -2, 2, 2, 1, markt4, 0, 0, 2, 0, 2, 1, 0, 1);
	//TOP
	draw.rectangleXZ(75, 2, -2, -7, 2, 1, markt4, 0, 0, 1, 0, 1, 1, 0, 1);


	glPushMatrix();
	glTranslated(-14,0,0);
	draw.rectangleXY(75, 0, -4, -7, 2, -1, markt4, 0, 0, 3, 0, 3, 1, 0, 1);
	draw.rectangleXY(75, 0, -2, -7, 2, -1, markt4, 0, 0, 3, 0, 3, 1, 0, 1);
	//L,R
	draw.rectangleYZ(75, 0, -2, 2, 2, 1, markt4, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(68, 0, -2, 2, 2, 1, markt4, 0, 0, 2, 0, 2, 1, 0, 1);
	//TOP
	draw.rectangleXZ(75, 2, -2, -7, 2, 1, markt4, 0, 0, 1, 0, 1, 1, 0, 1);
	glPopMatrix();

	draw.rectangleYZ(77.8, 0, -42, -15.5, 6, -1, cloTexture1, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(77.8, 0, -24.5, -16.5, 6, -1, cloTexture2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(77.8, 6, -42, -15.5, 6, -1, cloTexture3, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(77.8, 6, -24.5, -16.5, 6, -1, cloTexture4, 0, 0, 1, 0, 1, 1, 0, 1);



	//ads
	//1
	glPushMatrix();
	glTranslated(1.5,3.4,2.2);
	//F,B
	draw.rectangleXY(75, 0, -2.2, -4, 5, -1, ad1, 0, 0, 0, 1, 1, 1, 1, 0);
	draw.rectangleXY(75, 0, -2, -4, 5, -1, ad1, 1, 0,0, 0,0, 1,1, 1);
	//L,R
	draw.rectangleYZ(75, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(71, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	//TOP
	draw.rectangleXZ(75, 5, -2, -4, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(75, 0, -2, -4, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslated(-10, 3.4, 2.2);
	//F,B
	draw.rectangleXY(75, 0, -2.2, -4, 5, -1, ad2, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(75, 0, -2, -4, 5, -1, ad2, 1, 0, 0, 0, 0, 1, 1, 1);
	//L,R
	draw.rectangleYZ(75, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(71, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	//TOP
	draw.rectangleXZ(75, 5, -2, -4, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(75, 0, -2, -4, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslated(-39.285, 3.4, 2.2);
	//F,B
	draw.rectangleXY(75, 0, -2.2, -4, 5, -1, ad3, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(75, 0, -2, -4, 5, -1, ad3, 1, 0, 0, 0, 0, 1, 1, 1);
	//L,R
	draw.rectangleYZ(75, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(71, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	//TOP
	draw.rectangleXZ(75, 5, -2, -4, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(75, 0, -2, -4, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslated(-50.9, 3.4, 2.2);
	//F,B
	draw.rectangleXY(75, 0, -2.2, -4, 5, -1, ad4, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(75, 0, -2, -4, 5, -1, ad4, 1, 0, 0, 0, 0, 1, 1, 1);
	//L,R
	draw.rectangleYZ(75, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(71, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	//TOP
	draw.rectangleXZ(75, 5, -2, -4, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(75, 0, -2, -4, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 12, -58); // نقل اللوحة إلى الموقع الأولي  

	// تدوير اللوحة حول المحور Y بزاوية معينة (مثلاً 10 درجات)  
	glRotatef(-45, 0, 1, 0); // تدوير 10 درجات حول المحور Y  

	// رسم الأوجه  
	// F,B  
	draw.rectangleXY(75, 0, -2.2, -10, 5, -1, es, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(75, 0, -2, -10, 5, -1, es, 1, 0, 0, 0, 0, 1, 1, 1);
	// L,R  
	draw.rectangleYZ(75, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	draw.rectangleYZ(69, 0, -2, 0.2, 5, 1, rt, 0, 0, 2, 0, 2, 1, 0, 1);
	// TOP  
	draw.rectangleXZ(75, 5, -2, -6, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXZ(75, 0, -2, -6, 0.2, 1, rt, 0, 0, 1, 0, 1, 1, 0, 1);
	glPopMatrix();

	// electronic stairs
	glPushMatrix();
	glTranslatef(31, -6, -21.5);
	glRotatef(90, 0, 1, 0);
	draw.elelctronic_stairs(3, 6, 10);
	glTranslatef(0, 6, -10);
	glRotatef(180, 0, 1, 0);
	draw.elelctronic_stairs(3.5, 6, 10);
	glPopMatrix();



	door = max(0, door - 0.1);
	if (xx >= 41 && xx <= 55 && zz > -10 && zz < 10) {
		door = min(5, door + 0.2);
	}


	draw.cone(-9.5, 0, 4.5, 6, 0.25, groundSkybox, 0, 0, 1, 0, 1, 1, 0, 1);
	glPushMatrix();
	glTranslatef(-9.5, 6, 4.5);
	glRotatef(135, 0, 1, 0);
	draw.parallel_rectangles(-0.3, -0.25, 0.25, 0.6, 0.3, 1.5, groundSkybox);
	draw.draw_Sphare(0, -0.3, -1, 0.25, 1, 1, 1, 0.01);
	glPopMatrix();


	if (isNight) {
		glEnable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}
	

	// cone 
	draw.cone(12, 0, -12, 12, 6, coneTexture, 0, 0, 1, 0, 1, 1, 0, 1);

	//wall 
	draw.rectangleYZ(18, 0, 0, 18, 12, -1, coneTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(18, 0, 0, 25, 12, 1, coneTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(53, 0, 0, 25, 12, 1, coneTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(43, 6, 0, 10, 6, 1, coneTexture, 0, 0.5, 0.37, 0.5, 0.37, 1, 0, 1);


	draw.rectangleYZ(78.02, 0, 0, 50, 12, 1, coneTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(0, 0, -50, 78, 12, -1, coneTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(0, 0, -24, 26, 12, -1, coneTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(0, 0, -18, 2, 12, -1, coneTexture, 0, 0, 0.076, 0, 0.076, 1, 0, 1);
	draw.rectangleYZ(0, 6, -20, 4, 6, -1, coneTexture, 0, 0.5, 0.1, 0.5, 0.15, 1, 0, 1);
	draw.rectangleXY(0, 0, -18, 18, 12, 1, coneTexture, 0, 0, 1, 0, 1, 1, 0, 1);


	//skybox
	draw.rectangleXZ(-10, 0, 5,88, 5,1, cl, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleXZ(-10, 0, 0, 28, 18,1, cl, 0, 0, 3, 0, 3, 3, 0, 3);	
	draw.rectangleXZ(-10, 0, 0, 10, 31,1, cl, 0, 0, 0.3, 0, 0.3, 6, 0, 6);
	draw.rectangleXZ(-10, 0, 15, 88, 10,1, streetTexture, 0, 0, 9, 0, 9, 1, 0, 1);
	draw.rectangleXZ(-50, 0, 15, 30, 10,1, streetTexture, 0, 0, 9, 0, 9, 1, 0, 1);
	draw.rectangleXZ(-60, 0, -31, 50, 12,1, streetTexture, 0, 0, 9, 0, 9, 1, 0, 1);
	draw.rectangleXZ(-20, 0, 15, 10, 46,1, streetTexture, 3, 0, 3, 1, 0, 1, 0, 0);
	draw.rectangleXZ(-60, 0, 35, 10, 66,1, streetTexture, 3, 0, 3, 1, 0, 1, 0, 0);
	
	draw.rectangleXZ(-50, 0, 5, 30, 36,1, grassTexture, 0, 0, 6, 0, 6, 6, 0, 6);

	draw.rectangleXY(-21, 0, 3, -28, 0.5,-1,flowerTexture, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleXY(-49, 0, 4, 28, 0.5,1, flowerTexture, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleXZ(-49, 0.5, 4, 28, 1,1, flowerTexture, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleYZ(-49, 0, 4, 1, 0.5,-1, flowerTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(-21, 0, 4, 1, 0.5,1, flowerTexture, 0, 0, 1, 0, 1, 1, 0, 1);

	
	draw.rectangleXY(-21, 0, -30, -28, 0.5, -1, flowerTexture, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleXY(-49, 0, -29, 28, 0.5, 1, flowerTexture, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleXZ(-49, 0.5, -29, 28, 1, 1, flowerTexture, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleYZ(-49, 0, -29, 1, 0.5, -1, flowerTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(-21, 0,  -29, 1, 0.5,1, flowerTexture, 0, 0, 1, 0, 1, 1, 0, 1);

	draw.rectangleYZ(-22, 0, 3, 12, 0.5,-1, flowerTexture, 0, 0, 4, 0, 4, 1, 0, 1);
	draw.rectangleYZ(-21, 0, 3, 12, 0.5,1, flowerTexture, 0, 0, 4, 0, 4, 1, 0, 1);
	draw.rectangleXZ(-22, 0.5, 3, 1, 12,1, flowerTexture, 0, 0, 1, 0, 1, 4, 0, 4);
	draw.rectangleXY(-22,0,-9,1,0.5,-1, flowerTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(-22, 0, -14, 15, 0.5,-1, flowerTexture, 0, 0, 6, 0, 6, 1, 0, 1);
	draw.rectangleYZ(-21, 0, -14, 15, 0.5,1, flowerTexture, 0, 0, 6, 0, 6, 1, 0, 1);
	draw.rectangleXZ(-22, 0.5, -14, 1, 15,1, flowerTexture, 0, 0, 1, 0, 1, 6, 0, 6);
	draw.rectangleXY(-22, 0, -14, 1, 0.5,1, flowerTexture, 0, 0, 1, 0, 1, 1, 0, 1);

	draw.rectangleYZ(-49, 0, 3, 33, 0.5,-1, flowerTexture, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleYZ(-48, 0, 3, 33, 0.5,1, flowerTexture, 0, 0, 10, 0, 10, 1, 0, 1);
	draw.rectangleXZ(-49, 0.5, 3, 1, 33,1, flowerTexture, 0, 0, 1, 0, 1, 10, 0, 10);

	draw.rectangleXZ(-60,0,-43,70,7, wallTexture2,1, 0, 0, 10, 0, 10, 1, 0, 1);

	draw.rectangleXZ(-50,0,35,128,20, wallTexture2,1, 0, 0, 14, 0, 14, 4, 0, 4);
	draw.wall_circle(-50, 0, 5, 30, tableTexture, -1,0.1,0.5);
	draw.wall_circle(-50, 0, -31, 30, tableTexture, -1,0.1,0.5);
	glPushMatrix();
	glTranslated(-20, 0, 5);
	glRotated(90,0,1,0);
	draw.wall_circle(0, 0, 0, 13, tableTexture, -1,0.1,0.5);
	draw.wall_circle(19, 0, 0, 17, tableTexture, -1,0.1,0.5);
	draw.wall_circle(0, 0, -30, 36, tableTexture, -1,0.1,0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 35);
	
	for (int i = -60; i <= 60; i += 20) {
		draw.parallel_rectangles(i, 0, 0, 10, 18, 10, buildingTexture);
		draw.rectangleXY(i + 10, 0, -10, 10, 3,-1,groundWallTexture2,0,0,1,0,1,1,0,1);
	}
	
	glPopMatrix();

	if (isNight) {

		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHTING);
	}

	
	glBindTexture(GL_TEXTURE_2D, doorTexture);
	glBindTexture(GL_TEXTURE_2D, glassTexture);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	draw.rectangleXY(43 - door, 0, 0, 5, 6, 1, doorTexture, 0, 0, 0.5* 0.37, 0, 0.5* 0.37, 0.5, 0, 0.5);
	draw.rectangleXY(48 + door, 0, 0, 5, 6, 1, doorTexture, 0, 0, 0.5* 0.37, 0, 0.5* 0.37, 0.5, 0, 0.5);

	glPushMatrix();
	glTranslatef(0, 0, -22);
	glRotatef(rot, 0, 1, 0);
	draw.rectangleXY(-2, 0, 0, 4, 6, 1, glassTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(0, 0, 2, 4, 6, 1, glassTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	
	glPopMatrix();

	draw.rectangleXY(65, -6, -21.5+0.01, 3, 18, 1, glassTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleXY(65, -6, -24.5-0.01, 3, 18, -1, glassTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(65-0.01, -6, -21.5, 3, 18, -1, glassTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(68+0.01, -3, -21.5, 3, 3, 1, glassTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(68+0.01-0.01, 3, -21.5, 3, 3, 1, glassTexture, 0, 0, 1, 0, 1, 1, 0, 1);
	draw.rectangleYZ(68+0.01, 9, -21.5, 3, 3, 1, glassTexture, 0, 0, 1, 0, 1, 1, 0, 1);

	if (thirdPerson) yy -= 1, zz -= 1.5;

	SwapBuffers(hDC);
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(const char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
	case WM_MOUSEMOVE:

		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);

		isClicked = (LOWORD(wParam)&MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam)&MK_RBUTTON) ? true : false;

		break;

	case WM_LBUTTONUP:
		isClicked = false;	break;
	case WM_RBUTTONUP:
		isRClicked = false;	break;
	case WM_LBUTTONDOWN:
		isClicked = true;	break;
	case WM_RBUTTONDOWN:
		isRClicked = true;	break;

	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;

	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Mall Drawing", 1000, 600, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer = SetTimer(hWnd, 0, 50, (TIMERPROC)NULL);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;

}
