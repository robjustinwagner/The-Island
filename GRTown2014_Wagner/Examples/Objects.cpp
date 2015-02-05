/// GraphicsTown2006 - CS559 Sample Code
// written by Michael Gleicher - originally written Fall, 2000
// updated Fall, 2005
// updated Fall, 2006 - new texture manager, improvements for behaviors

#include "../GrTown_PCH.H"
#include "Objects.H"
#include "../DrawUtils.H"
#include "Utilities/Texture.H"
#include "../MMatrix.H"
#include <FL/fl_ask.h>

#include "Utilities/ShaderTools.H"
#include <windows.h>				// Header File For Windows
#include <stdio.h>					// Header File For Standard Input/Output
#include <gl\gl.h>					// Header File For The OpenGL32 Library
#include <gl\glu.h>					// Header File For The GLu32 Library
#include "Utilities/glaux.h"				// Header File For The Glaux Library
#include "../TownViewWidget.H"


// some very basic classes of objects...
// mainly for debugging
Cube::Cube(float x, float y, float z, float s, 
		   float r, float g, float b)
  : color(r,g,b), size(s)
{
  transMatrix(transform,x,y,z);
}
void Cube::draw(DrawingState*)
{
  glColor4fv(&color.r);
  cube(0,0,0,size);
}

VolcanoDoors::VolcanoDoors()
{
	//used to showcase volcano doors
}

void VolcanoDoors::draw(DrawingState* d)
{
}

Skybox::Skybox()
{
}

void Skybox::draw(DrawingState* d)
{
	//previous camera coords
	bool init = true;
	static float prev_x;
	static float prev_y;
	static float prev_z;
	//curr camera coords
	static float next_x;
	static float next_y;
	static float next_z;
	if (init)
	{
		prev_x = 0;
		prev_y = 0;
		prev_z = 0;
	}

	//get current camera pos
	Matrix curr_camera;
	d->camera->getCamera(curr_camera);
	invertMatrix(curr_camera);

	//update current camera coords
	next_x = curr_camera[3][0];
	next_y = curr_camera[3][1];
	next_z = curr_camera[3][2];

	glPushMatrix();

	//translate skybox
	glTranslatef(next_x - prev_x, next_y - prev_y, next_z - prev_z);

	//update coords
	prev_x = next_x;
	prev_y = next_y;
	prev_z = next_z;

	//sides
	fetchTexture("skybox.jpg");
	glBegin(GL_QUADS);
		
		glFrontFace(GL_CCW);
		glTexCoord2f(0, 0.33333333333);
		glVertex3f(-2 * 6250, -6250, -2 * 6250);
		glTexCoord2f(0, 2 * 0.33333333333);
		glVertex3f(-2 * 6250, 6250, -2 * 6250);
		glTexCoord2f(0.25, 0.33333333333);
		glVertex3f(-2 * 6250, -6250, 2 * 6250);
		glTexCoord2f(0.25, 2 * 0.33333333333);
		glVertex3f(-2 * 6250, 6250, 2 * 6250);
		glFrontFace(GL_CCW);
		glTexCoord2f(0.25, 0.33333333333);
		glVertex3f(-2 * 6250, -6250, 2 * 6250);
		glTexCoord2f(0.25, 2 * 0.33333333333);
		glVertex3f(-2 * 6250, 6250, 2 * 6250);
		glTexCoord2f(0.5, 0.33333333333);
		glVertex3f(2 * 6250, -6250, 2 * 6250);
		glTexCoord2f(0.5, 2 * 0.33333333333);
		glVertex3f(2 * 6250, 6250, 2 * 6250);
		glFrontFace(GL_CCW);
		glTexCoord2f(0.5, 0.33333333333);
		glVertex3f(2 * 6250, -6250, 2 * 6250);
		glTexCoord2f(0.5, 2 * 0.33333333333);
		glVertex3f(2 * 6250, 6250, 2 * 6250);
		glTexCoord2f(0.75, 0.33333333333);
		glVertex3f(2 * 6250, -6250, -2 * 6250);
		glTexCoord2f(0.75, 2 * 0.33333333333);
		glVertex3f(2 * 6250, 6250, -2 * 6250);
		glFrontFace(GL_CCW);
		glTexCoord2f(0.75, 0.33333333333);
		glVertex3f(2 * 6250, -6250, -2 * 6250);
		glTexCoord2f(0.75, 2 * 0.33333333333);
		glVertex3f(2 * 6250, 6250, -2 * 6250);
		glTexCoord2f(1, 0.33333333333);
		glVertex3f(-2 * 6250, -6250, -2 * 6250);
		glTexCoord2f(1, 2 * 0.33333333333);
		glVertex3f(-2 * 6250, 6250, -2 * 6250);
		//glFrontFace(GL_CW);
	glEnd();

	//top/bottom
	//fetchTexture("skybox.jpg");
	glBegin(GL_QUADS);

	/*	dont really need to draw bottom as we'll never see it, slightly increase performance instead
		glTexCoord2f(0.25, 0);
		glVertex3f(-6250, -6250, -6250);
		glTexCoord2f(0.25, 0);
		glVertex3f(-6250, -6250, 6250);
		glTexCoord2f(0.25, (1 / 3));
		glVertex3f(6250, -6250, 6250);
		glTexCoord2f(0.25, (1 / 3));
		glVertex3f(6250, -6250, -6250);
	*/
	glFrontFace(GL_CCW);
		///glVertex3f(-6250, -6250, 6250);
	//		glVertex3f(-6250, 6250, -6250);
		glTexCoord2f(0.25, 2 * 0.33333333333);
		glVertex3f(-2 * 6250, 6250, 2 * 6250);
		glTexCoord2f(0.25, 1);
		glVertex3f(-2 * 6250, 6250, -2 * 6250);
		glTexCoord2f(0.5, 1);
		glVertex3f(2 * 6250, 6250, -2 * 6250);
		glTexCoord2f(0.5, 2 * 0.33333333333);
		glVertex3f(2 * 6250, 6250, 2 * 6250);
	glEnd();

	//GL_SEAMLESS OR WHATEVER

	glPopMatrix();
}

/***********************************************************************/
TestCubes::TestCubes()
{
}

void TestCubes::draw(DrawingState*)
{
  glColor3f(1,0,0);
  cube( 20,0,0, 3);
  cube(-20,0,0, 3);
  cube(0, 20,0, 3);
  cube(0,-20,0, 3);
  cube(0,0, 20, 3);
  cube(0,0,-20, 3);

  glColor3f(1,1,0);
  cube(20,10,20,3);
  glColor3f(0,1,1);
  cube(-20,10,20,3);
  glColor3f(1,0,1);
  cube(-20,10,-20,3);
  glColor3f(1,1,1);
  cube(20,10,-20,3);
}

// some very basic classes of objects...
// mainly for debugging
ShadedCube::ShadedCube(float x, float y, float z, float s, 
					   float r, float g, float b)
  : color(r,g,b), size(s)
{
  transMatrix(transform,x,y,z);
}

// load the shader in the first time the cube draws (since that way we
// know we have a GL context)
// we only try to load it once
static unsigned int shadedCubeShader = 0;
static bool triedCubeShader=false;

void ShadedCube::draw(DrawingState*)
{
	if (!shadedCubeShader && !triedCubeShader) {
		triedCubeShader = true;
		char* error;
		if (!(shadedCubeShader=loadShader("ShadedCubeTest.vert","ShadedCubeTest.frag",error))) {
			std::string s = "Can't Load Cube Shader:";
			s += error;
			fl_alert(s.c_str());
		}
	}

	glUseProgram(shadedCubeShader);
	glColor4fv(&color.r);
	cube(0,0,0,size);
	glUseProgram(0);
}

FloatingBall2::FloatingBall2()
{
}
void FloatingBall2::draw(DrawingState* st)
{
	GLUquadricObj *wireframe = gluNewQuadric();
	GLUquadricObj *solid = gluNewQuadric();
	gluQuadricDrawStyle(wireframe, GLU_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushMatrix();

	static unsigned int lightShader = 0;
	static bool triedLightShader = false;

	if (!lightShader && !triedLightShader) {
		triedLightShader = true;
		char* error;
		if (!(lightShader = loadShader("lightShader.vert", "lightShader.frag", error))) {
			std::string s = "Can't Load Light Shader:";
			s += error;
			//fl_alert(s.c_str());
		}
	}

	glLineWidth(1);
	glUseProgram(lightShader);
	glColor3ub(84, 84, 84);
	gluSphere(wireframe, 40, 10, 16);
	glUseProgram(0);
	glLineWidth(2);
	glColor3f(1, 0, 1);
	gluSphere(solid, 18, 10, 16);

	if (!st->drGrTex)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	glPopMatrix();

}
FloatingBall::FloatingBall()
{
}
void FloatingBall::draw(DrawingState* st)
{

	GLUquadricObj *wireframe = gluNewQuadric();
	GLUquadricObj *solid = gluNewQuadric();
	gluQuadricDrawStyle(wireframe, GLU_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushMatrix();

	glLineWidth(1);
	glColor3f(0, 1, 1);
	gluSphere(wireframe, 25, 10, 16);
	if (!st->drGrTex)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glColor3ub(131, 37, 33);
	gluSphere(solid, 22, 10, 16);



	glPopMatrix();
}
Lava::Lava()
{
}
// load the shader in the first time the cube draws (since that way we
// know we have a GL context)
// we only try to load it once
static unsigned int lavaShader = 0;
static bool triedLavaShader = false;
void Lava::draw(DrawingState* ds)
{
	
	if (!lavaShader && !triedLavaShader) {
		triedLavaShader = true;
		char* error;
		if (!(lavaShader = loadShader("lavaShader.vert", "lavaShader.frag", error))) {
			std::string s = "Can't Load Lava Shader:";
			s += error;
			fl_alert(s.c_str());
		}
	}
	static float t = 0;
	glUseProgram(lavaShader);
		GLint u = glGetUniformLocation(lavaShader, "time");
		glUniform1f(u, t);
		t++;
		fetchTexture("Dark-Red-lava.jpg",true,true);
		glBegin(GL_QUADS);
			glNormal3d(0, 1, 0);
			glTexCoord2f(0, 0);
			glVertex3f(0, 85 * 4.5, 0);
			//glVertex3f(5, 5, 5);
			glTexCoord2f(0, 1);
			glVertex3f(0, 85 * 4.5, 325);
			//glVertex3f(5, 5, 10);
			//glVertex3f(10, 5, 10);
			glTexCoord2f(1, 1);
			glVertex3f(325, 85 * 4.5, 325);
			//glVertex3f(10, 5, 5);
			glTexCoord2f(1, 0);
			glVertex3f(325, 85 * 4.5, 0);
		glEnd();
	glUseProgram(0);
}
Goblet::Goblet()
{
	/*
	static char name[] = "Goblet";
	char * ptr = &name[0];
	static int ctr = 0;
	int&namectr = ctr;
	GrObject(ptr, namectr, (char*)0);
	ctr++;
	*/
	//http://www.it.uu.se/edu/course/homepage/grafik1/ht07/examples/revolution.cpp
}
#define R  100.0f
#define M_PI 3.141592654

double M_PI_2 = M_PI / 2.0;
float gobletx(float v)
/* This function evaluates the x(v) function for the goblet. */
{
	if (v >= 0.95) return R;
	if (v >= 0.8) return R - (0.95 - v) / 0.15*0.75*R;
	if (v >= 0.3) return R / 4;
	if (v >= 0.2) return R / 4 + (0.3 - v) / 0.1*R;
	if (v >= 0.1) return 0.15*R*cos(-M_PI_2 + 10.0*(v - 0.1)*M_PI) + 1.25*R;
	return 0.15*R*cos(M_PI_2 + 10.0*v*M_PI) + 1.25*R;
}

float goblety(float v)
/* This function evaluates the y(v) function for the goblet. */
{
	if (v >= 0.95) return 3 * R*(0.5 - v);
	if (v >= 0.8) return -3 * R*0.45;
	if (v >= 0.3) return 3 * R*(0.35 - v);
	if (v >= 0.2) return 3 * R*(0.05);
	if (v >= 0.1) return -0.15*R*sin(-M_PI_2 + 10.0*(v - 0.1)*M_PI) + 0.3*R;
	return 0.15*R*sin(M_PI_2 + 10.0*v*M_PI) + 0.6*R;
}

float gobletxuv(float u, float v)
/* This function evaluates the x(u, v) function for the goblet. */
{
	return gobletx(v) * cos(u);
}

float gobletyuv(float u, float v)
/* This function evaluates the y(u, v) function for the goblet. */
{
	return goblety(v);
}

float gobletzuv(float u, float v)
/* This function evaluates the z(u, v) function for the goblet. */
{
	return gobletx(v) * sin(u);
}


/* This function draws a goblet as a surface of revolution. */
void Goblet::draw(DrawingState*)
{

	float u, v;
	for (int k = 0; k < 8; k++)
	{

		glScalef(0.99,1.0,0.99);
	/* Draw the end meridians (constant u values). */

	for (u = 0.0; u<2 * M_PI + M_PI / 10; u += M_PI_2)
	{
		glBegin(GL_LINE_STRIP);
		for (v = 0.0; v < 1.005; v += 0.01)
		{
			glColor3f(u / (2 * M_PI + M_PI / 10), v / 1.005, (u / (2 * M_PI + M_PI / 10) + (v / 1.005))/2);
			glVertex3f(gobletxuv(u, v), gobletyuv(u, v), gobletzuv(u, v));
		}
		glEnd();
	}

	/* Draw the parallels (constant v values). */

	for (v = 0.0; v<1.025; v += 0.05)
	{
		glBegin(GL_LINE_STRIP);
		for (u = 0.0; u < 2 * M_PI + 0.005; u += 0.01)
		{
			glColor3f(v / (2 * M_PI + 0.005), v / 1.025, (u / (2 * M_PI + 0.005) + (v / 1.025))/2);
			glVertex3f(gobletxuv(u, v), gobletyuv(u, v), gobletzuv(u, v));
		}
		glEnd();
		if (fabs(v - 0.2)<1e-6) v = 0.25;
		if (fabs(v - 0.3)<1e-6) v = 0.75;
		if (fabs(v - 0.8)<1e-6) v = 0.9;
	}
	}
}


goblet_profile::goblet_profile(void)
{
}

void goblet_profile::draw(DrawingState*)
/* This function draws the profile of the goblet. */
{
	glPushMatrix();
	float v;

	glBegin(GL_LINE_STRIP);
	//glScalef(100.f, 100.f, 100.f);
	for (v = 0.0; v<1.005; v += 0.01)
		glVertex2f(gobletx(v), goblety(v));
	glEnd();
	glPopMatrix();
}


#define	MAX_PARTICLES	500		// Number Of Particles To Create
HDC			hDC = NULL;				// Private GDI Device Context
HGLRC		hRC = NULL;				// Permanent Rendering Context
HWND		hWnd = NULL;				// Holds Our Window Handle
HINSTANCE	hInstance;				// Holds The Instance Of The Application

bool	keys[256];					// Array Used For The Keyboard Routine
bool	active = TRUE;				// Window Active Flag Set To TRUE By Default
bool	fullscreen = TRUE;			// Fullscreen Flag Set To Fullscreen Mode By Default
bool	rainbow = true;				// Rainbow Mode?
bool	sp;							// Spacebar Pressed?
bool	rp;							// Enter Key Pressed?

float	slowdown = 2.0f;				// Slow Down Particles
float	xspeed;						// Base X Speed (To Allow Keyboard Direction Of Tail)
float	yspeed;						// Base Y Speed (To Allow Keyboard Direction Of Tail)
float	zoom = -40.0f;				// Used To Zoom Out

GLuint	loop;						// Misc Loop Variable
GLuint	col;						// Current Color Selection
GLuint	delay;						// Rainbow Effect Delay
GLuint	texture[1];					// Storage For Our Particle Texture

typedef struct						// Create A Structure For Particle
{
	bool	active;					// Active (Yes/No)
	float	life;					// Particle Life
	float	fade;					// Fade Speed
	float	r;						// Red Value
	float	g;						// Green Value
	float	b;						// Blue Value
	float	x;						// X Position
	float	y;						// Y Position
	float	z;						// Z Position
	float	xi;						// X Direction
	float	yi;						// Y Direction
	float	zi;						// Z Direction
	float	xg;						// X Gravity
	float	yg;						// Y Gravity
	float	zg;						// Z Gravity
}
particles;							// Particles Structure

particles particle[MAX_PARTICLES];	// Particle Array (Room For Particle Info)

static GLfloat colors[12][3] =		// Rainbow Of Colors
{
	{ 1.0f, 0.5f, 0.5f }, { 1.0f, 0.75f, 0.5f }, { 1.0f, 1.0f, 0.5f }, { 0.75f, 1.0f, 0.5f },
	{ 0.5f, 1.0f, 0.5f }, { 0.5f, 1.0f, 0.75f }, { 0.5f, 1.0f, 1.0f }, { 0.5f, 0.75f, 1.0f },
	{ 0.5f, 0.5f, 1.0f }, { 0.75f, 0.5f, 1.0f }, { 1.0f, 0.5f, 1.0f }, { 1.0f, 0.5f, 0.75f }
};

goblet_particle::goblet_particle(void)
{
		if (!LoadGLTextures())								// Jump To Texture Loading Routine
		{
			//return FALSE;									// If Texture Didn't Load Return FALSE
			exit(1);
		}

		glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);					// Black Background
		glClearDepth(1.0f);									// Depth Buffer Setup
		glDisable(GL_DEPTH_TEST);							// Disable Depth Testing
		glEnable(GL_BLEND);									// Enable Blending
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);					// Type Of Blending To Perform
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);				// Really Nice Point Smoothing
		glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
		glBindTexture(GL_TEXTURE_2D, texture[0]);			// Select Our Texture

		for (loop = 0; loop<MAX_PARTICLES; loop++)				// Initials All The Textures
		{
			particle[loop].active = true;								// Make All The Particles Active
			particle[loop].life = 1.0f;								// Give All The Particles Full Life
			particle[loop].fade = float(rand() % 100) / 1000.0f + 0.003f;	// Random Fade Speed
			particle[loop].r = colors[loop*(12 / MAX_PARTICLES)][0];	// Select Red Rainbow Color
			particle[loop].g = colors[loop*(12 / MAX_PARTICLES)][1];	// Select Red Rainbow Color
			particle[loop].b = colors[loop*(12 / MAX_PARTICLES)][2];	// Select Red Rainbow Color
			particle[loop].xi = float((rand() % 50) - 26.0f)*10.0f;		// Random Speed On X Axis
			particle[loop].yi = float((rand() % 50) - 25.0f)*10.0f;		// Random Speed On Y Axis
			particle[loop].zi = float((rand() % 50) - 25.0f)*10.0f;		// Random Speed On Z Axis
			particle[loop].xg = 0.0f;									// Set Horizontal Pull To Zero
			particle[loop].yg = -0.8f;								// Set Vertical Pull Downward
			particle[loop].zg = 0.0f;									// Set Pull On Z Axis To Zero
		}

		//return TRUE;										// Initialization Went OK

}
AUX_RGBImageRec *LoadBMP(char *Filename)				// Loads A Bitmap Image
{
	FILE *File = NULL;								// File Handle
	if (!Filename)									// Make Sure A Filename Was Given
	{
		return NULL;							// If Not Return NULL
	}
	File = fopen(Filename, "r");						// Check To See If The File Exists
	if (File)										// Does The File Exist?
	{
		fclose(File);								// Close The Handle
		return auxDIBImageLoad(Filename);			// Load The Bitmap And Return A Pointer
	}
	return NULL;									// If Load Failed Return NULL
}

int goblet_particle::LoadGLTextures()									// Load Bitmap And Convert To A Texture
{
	int Status = FALSE;								// Status Indicator
	AUX_RGBImageRec *TextureImage[1];				// Create Storage Space For The Textures
	memset(TextureImage, 0, sizeof(void *) * 1);		// Set The Pointer To NULL

	if (TextureImage[0] = LoadBMP("data/Particle.bmp"))	// Load Particle Texture
	{
		Status = TRUE;								// Set The Status To TRUE
		glGenTextures(1, &texture[0]);				// Create One Texture

		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
	}

	if (TextureImage[0])							// If Texture Exists
	{
		if (TextureImage[0]->data)					// If Texture Image Exists
		{
			free(TextureImage[0]->data);			// Free The Texture Image Memory
		}
		free(TextureImage[0]);						// Free The Image Structure
	}
	return Status;									// Return The Status
}

void goblet_particle::draw(DrawingState*)
/* This function draws the particles of the goblet. */
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
	//glLoadIdentity();										// Reset The ModelView Matrix
	glScalef(75.f, 25.f, 75.f);
	for (loop = 0; loop<MAX_PARTICLES; loop++)					// Loop Through All The Particles
	{
		if (particle[loop].active)							// If The Particle Is Active
		{
			float x = particle[loop].x;						// Grab Our Particle X Position
			float y = particle[loop].y;						// Grab Our Particle Y Position
			float z = particle[loop].z + zoom;					// Particle Z Pos + Zoom

			// Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
			glColor4f(particle[loop].r, particle[loop].g, particle[loop].b, particle[loop].life);

			glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
			glTexCoord2d(1, 1); glVertex3f(x + 0.5f, y + 0.5f, z); // Top Right
			glTexCoord2d(0, 1); glVertex3f(x - 0.5f, y + 0.5f, z); // Top Left
			glTexCoord2d(1, 0); glVertex3f(x + 0.5f, y - 0.5f, z); // Bottom Right
			glTexCoord2d(0, 0); glVertex3f(x - 0.5f, y - 0.5f, z); // Bottom Left
			glEnd();										// Done Building Triangle Strip

			particle[loop].x += particle[loop].xi / (slowdown * 1000);// Move On The X Axis By X Speed
			particle[loop].y += particle[loop].yi / (slowdown * 1000);// Move On The Y Axis By Y Speed
			particle[loop].z += particle[loop].zi / (slowdown * 1000);// Move On The Z Axis By Z Speed

			particle[loop].xi += particle[loop].xg;			// Take Pull On X Axis Into Account
			particle[loop].yi += particle[loop].yg;			// Take Pull On Y Axis Into Account
			particle[loop].zi += particle[loop].zg;			// Take Pull On Z Axis Into Account
			particle[loop].life -= particle[loop].fade;		// Reduce Particles Life By 'Fade'

			if (particle[loop].life<0.0f)					// If Particle Is Burned Out
			{
				particle[loop].life = 1.0f;					// Give It New Life
				particle[loop].fade = float(rand() % 100) / 1000.0f + 0.003f;	// Random Fade Value
				particle[loop].x = 0.0f;						// Center On X Axis
				particle[loop].y = 0.0f;						// Center On Y Axis
				particle[loop].z = 0.0f;						// Center On Z Axis
				particle[loop].xi = xspeed + float((rand() % 60) - 32.0f);	// X Axis Speed And Direction
				particle[loop].yi = yspeed + float((rand() % 60) - 30.0f);	// Y Axis Speed And Direction
				particle[loop].zi = float((rand() % 60) - 30.0f);	// Z Axis Speed And Direction
				particle[loop].r = colors[col][0];			// Select Red From Color Table
				particle[loop].g = colors[col][1];			// Select Green From Color Table
				particle[loop].b = colors[col][2];			// Select Blue From Color Table
			}

			// If Number Pad 8 And Y Gravity Is Less Than 1.5 Increase Pull Upwards
			//if (keys[VK_NUMPAD8] && (particle[loop].yg<1.5f)) particle[loop].yg += 0.01f;

			// If Number Pad 2 And Y Gravity Is Greater Than -1.5 Increase Pull Downwards
			//if (keys[VK_NUMPAD2] && (particle[loop].yg>-1.5f)) particle[loop].yg -= 0.01f;

			// If Number Pad 6 And X Gravity Is Less Than 1.5 Increase Pull Right
			//if (keys[VK_NUMPAD6] && (particle[loop].xg<1.5f)) particle[loop].xg += 0.01f;

			// If Number Pad 4 And X Gravity Is Greater Than -1.5 Increase Pull Left
			//if (keys[VK_NUMPAD4] && (particle[loop].xg>-1.5f)) particle[loop].xg -= 0.01f;
			int r = rand() % 1000;	//blast particles every once in a while
			if (r == 7)										// Tab Key Causes A Burst
			{
				particle[loop].x = 0.0f;								// Center On X Axis
				particle[loop].y = 0.0f;								// Center On Y Axis
				particle[loop].z = 0.0f;								// Center On Z Axis
				particle[loop].xi = float((rand() % 50) - 26.0f)*10.0f;	// Random Speed On X Axis
				particle[loop].yi = float((rand() % 50) - 25.0f)*10.0f;	// Random Speed On Y Axis
				particle[loop].zi = float((rand() % 50) - 25.0f)*10.0f;	// Random Speed On Z Axis
			}
			
		}
	}
	//return TRUE;
}


// $Header: /p/course/cs559-gleicher/private/CVS/GrTown/Examples/Objects.cpp,v 1.6 2009/11/10 22:40:03 gleicher Exp $
