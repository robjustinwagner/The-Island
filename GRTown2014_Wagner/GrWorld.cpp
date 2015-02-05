/// GraphicsTown2006 - CS559 Sample Code
// written by Michael Gleicher - originally written Fall, 2000
// updated Fall, 2005
//
#include "GrTown_PCH.H"

#include "GrWorld.H"
#include "DrawingState.H"
#include "DrawUtils.H"
#include "Utilities/Texture.H"
#include "glm\glm.hpp"

#include "Utilities/ShaderTools.H"

using std::vector;

// stuff in the world
vector<GrObject*> theObjects;

// things for drawing the world

// remember, these function have some responsibilities defined in the
// header... 
// for now these do simple things. in the future, maybe they will draw
// more nicely
void drawSky(DrawingState* st)
{
  // figure out the sky color...
  if (st->timeOfDay < 5) st->sky(0,0,.2f);
  else if (st->timeOfDay < 8) st->sky(.2f,.2f,.8f);
  else if (st->timeOfDay < 16) st->sky(.7f,.7f,1);
  else if (st->timeOfDay < 19) st->sky(.2f,.2f,.8f);
  else st->sky(0,0,.2f);

  glClearColor(st->sky.r,st->sky.g,st->sky.b,st->sky.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT /*| GL_STENCIL_BUFFER_BIT*/);

}

//draw horizon box
void drawHorizonBox(DrawingState* st)
{
	/*  sides */
	/*  Macro for sin & cos in degrees */
	#define PI 3.1415926535898
	#define Cos(th) cos(PI/180*(th))
	#define Sin(th) sin(PI/180*(th))
	/*  D degrees of rotation */
	#define DEF_D 5
	glNormal3f(0, 1, 0);
	fetchTexture("mountains.jpg", true, true);
	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j <= 360; j += DEF_D) {
		glTexCoord2f((float)(0.0 + ((float)j / 360)), 1.0);
		glVertex3f(Cos(j)*5000, +1500, Sin(j)*5000);
		glTexCoord2f((float)(0.0 + ((float)j / 360)), 0.0);
		glVertex3f(Cos(j)*5000, -220, Sin(j)*5000);
	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

// draw earth/island
void drawEarth(DrawingState* st)
{
	glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(1.,10);
		glNormal3f(0, 1, 0);
		//fetchTexture("plain2_texture.jpg", true, true);  
		glColor3ub(18,18,18);
		glBegin(GL_POLYGON);
			glTexCoord2f(0, 0);
			glVertex3d(-1000, -1, 700);
			glTexCoord2f(0, 1);
			glVertex3d(-675, -1, 1550);
			glTexCoord2f(1, 1);
			glVertex3d(-500, -1, 1800);
			glTexCoord2f(1, 0);
			glVertex3d(-200, 100, 2000);
			glTexCoord2f(0, 0);
			glVertex3d(150, 150, 2100);
			glTexCoord2f(0, 1);
			glVertex3d(450, 90, 1600);
			glTexCoord2f(1, 1);
			glVertex3d(900, -1, 1200);
			glTexCoord2f(1, 0);
			glVertex3d(1200, -1, 475);
			glTexCoord2f(0, 0);
			glVertex3d(800, -1, -100);
			glTexCoord2f(0, 1);
			glVertex3d(500, -1, -500);
			glTexCoord2f(1, 1);
			glVertex3d(50, -1, -700);
			glTexCoord2f(1, 0);
			glVertex3d(-250, -1, -650);
			glTexCoord2f(0, 0);
			glVertex3d(-300, -1, -575);
			glTexCoord2f(0, 1);
			glVertex3d(-800, -1, 50);
		glEnd();
		glColor3f(1.f, 1.f, 1.f);
	//cliff
		glPolygonOffset(1., 10);
		glNormal3f(0, 1, 0);
		fetchTexture("granite_rock.jpg", true, true);  
		glBegin(GL_QUAD_STRIP);
			glTexCoord2f(1, 1);
			glVertex3d(-1050, -200, 725);
			glTexCoord2f(0, 1);
			glVertex3d(-1000, -1, 700); 
			glTexCoord2f(0, 0);
			glVertex3d(-650, -200, 1550);
			glTexCoord2f(1, 0);
			glVertex3d(-675, -1, 1550);
			glTexCoord2f(1, 1);
			glVertex3d(-500, -200, 1850);
			glTexCoord2f(0, 1);
			glVertex3d(-500, -1, 1800);
			glTexCoord2f(0, 0);
			glVertex3d(-175, -200, 2050);
			glTexCoord2f(1, 0);
			glVertex3d(-200, 100, 2000);
			glTexCoord2f(1, 1);
			glVertex3d(150, -200, 2025);
			glTexCoord2f(0, 1);
			glVertex3d(150, 150, 2100);
			glTexCoord2f(0, 0);
			glVertex3d(475, -200, 1625);
			glTexCoord2f(1, 0);
			glVertex3d(450, 90, 1600);
			glTexCoord2f(1, 1);
			glVertex3d(925, -200, 1175);
			glTexCoord2f(0, 1);
			glVertex3d(900, -1, 1200);
			glTexCoord2f(0, 0);
			glVertex3d(1200, -200, 400);
			glTexCoord2f(1, 0);
			glVertex3d(1200, -1, 475);
			glTexCoord2f(1, 1);
			glVertex3d(800, -200, -125);
			glTexCoord2f(1, 0);
			glVertex3d(800, -1, -100);
			glTexCoord2f(0, 0);
			glVertex3d(425, -200, -500);
			glTexCoord2f(0, 1);
			glVertex3d(500, -1, -500);
			glTexCoord2f(1, 1);
			glVertex3d(50, -200, -725);
			glTexCoord2f(1, 0);
			glVertex3d(50, -1, -700);
			glTexCoord2f(0, 0);
			glVertex3d(-225, -200, -650);
			glTexCoord2f(0, 1);
			glVertex3d(-250, -1, -650);
			glTexCoord2f(1, 1);
			glVertex3d(-300, -200, -500);
			glTexCoord2f(0, 1);
			glVertex3d(-300, -1, -575);
			glTexCoord2f(0, 0);
			glVertex3d(-800, -200, 75);
			glTexCoord2f(1, 0);
			glVertex3d(-800, -1, 50);
			glTexCoord2f(1, 1);
			glVertex3d(-1050, -200, 725);
			glTexCoord2f(0, 1);
			glVertex3d(-1000, -1, 700);
			glTexCoord2f(0, 0);
			glTexCoord2f(1, 0);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_POLYGON_OFFSET_FILL);
}

// draw earth/island
void drawWater(DrawingState* st)
{
	glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(1., 10);
		glNormal3f(0, 1, 0);
		//fetchTexture("water.jpg", true, true);
		fetchTexture("Dark-Red-lava.jpg", true, true);
		//glFrontFace(GL_CCW);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex3d(-5000, -220, -5000);
			glTexCoord2f(0, 1);
			glVertex3d(-5000, -220, 5000);
			glTexCoord2f(1, 1);
			glVertex3d(5000, -220, 5000);
			glTexCoord2f(1, 0);
			glVertex3d(5000, -220, -5000);
		glEnd();
	glDisable(GL_POLYGON_OFFSET_FILL);

}

// 
// setup lighting
void setupLights(DrawingState* dr)
{
  // depending on time of day, the lighting changes
  // ambient is either night or day
  if ((dr->timeOfDay >= 5) && (dr->timeOfDay <=19)) {
	float a0[] = {.4f,.4f,.4f,.4f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, a0);

  } else {
	float a0[] = {.2f,.2f,.2f,.2f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, a0);
  }
  // depending on time of day, the lighting changes
  // ambient is either night or day
  if ((dr->timeOfDay >= 6) && (dr->timeOfDay <= 18))
  {
	  //dont have any light in volcano doors
  }
  else if (dr->timeOfDay == 5 || dr->timeOfDay == (24 - 5))
  {
	  //add glow from volcano doors
	  GLfloat glow[] = { 0.9843f, 0.4471f, 0.f, 0.166666f };
	  glMaterialfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, glow);
  }
  else if (dr->timeOfDay == 4 || dr->timeOfDay == (24 - 4))
  {
	  //add glow from volcano doors
	  GLfloat glow[] = { 0.9843f, 0.4471f, 0.f, 2*0.166666f };
	  glMaterialfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, glow);
  }

  else if (dr->timeOfDay == 3 || dr->timeOfDay == (24 - 3))
  {
	  //add glow from volcano doors
	  GLfloat glow[] = { 0.9843f, 0.4471f, 0.f, 3*0.166666f };
	  glMaterialfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, glow);
  }

  else if (dr->timeOfDay == 2 || dr->timeOfDay == (24 - 2))
  {
	  //add glow from volcano doors
	  GLfloat glow[] = { 0.9843f, 0.4471f, 0.f, 4*0.166666f };
	  glMaterialfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, glow);
  }

  else if (dr->timeOfDay == 1 || dr->timeOfDay == (24 - 1))
  {
	  //add glow from volcano doors
	  GLfloat glow[] = { 0.9843f, 0.4471f, 0.f, 5*0.166666f };
	  glMaterialfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, glow);
  }
  else if (dr->timeOfDay == 0 || dr->timeOfDay == (24 - 0))
  {
	  //add glow from volcano doors
	  GLfloat glow[] = { 0.9843f, 0.4471f, 0.f, 6*0.166666f };
	  glMaterialfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, glow);
  }
  
  // directional, if its on, depends on what hour it is
  float pos0[4] = {0,0,0,0};
  if ((dr->timeOfDay >= 5) && (dr->timeOfDay <=19)) {
	float angle = (((float)(dr->timeOfDay-5)) / 7.f) * (3.14159f/2.f);
	pos0[0] = (float) cos(angle);
	pos0[1] = (float) sin(angle);
  }
  else {
	  pos0[1] = -1;
  }
  glLightfv(GL_LIGHT0, GL_POSITION, pos0);

  float pos1[] = { -50.f, 62.5f, 725.f, 1.f };
  //float pos1[] = { 0.f, 1.5f, 0.f, 1.f };
  glLightfv(GL_LIGHT1, GL_POSITION, pos1);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_COLOR_MATERIAL);
}

bool loadOBJ(const char * path,
	std::vector < glm::vec3 > & out_vertices,
	std::vector < glm::vec2 > & out_uvs,
	std::vector < glm::vec3 > & out_normals
	)
{
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;

	FILE * file = fopen(path, "r");
	if (file == NULL){
		printf("Impossible to open the file !\n");
		return false;
	}

	while (1){

		char lineHeader[128];
		//read first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		if (strcmp(lineHeader, "v") == 0){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0){
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "f") == 0){
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9){
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
	}
	// For each vertex of each triangle
	for (unsigned int i = 0; i < vertexIndices.size(); i++){
		unsigned int vertexIndex = vertexIndices[i];
		glm::vec3 vertex = temp_vertices[vertexIndex - 1];
		out_vertices.push_back(vertex);
	}
	/*
	// For each uv of each triangle
	for (unsigned int i = 0; i < uvIndices.size(); i++){
	unsigned int uvIndex = uvIndices[i];
	glm::vec3 vertex = temp_vertices[vertexIndex - 1];
	out_vertices.push_back(vertex);
	}
	// For each normal of each triangle
	for (unsigned int i = 0; i < vertexIndices.size(); i++){
	unsigned int vertexIndex = vertexIndices[i];
	glm::vec3 vertex = temp_vertices[vertexIndex - 1];
	out_vertices.push_back(vertex);
	}
	*/

}

// $Header: /p/course/cs559-gleicher/private/CVS/GrTown/GrWorld.cpp,v 1.3 2008/11/11 03:48:23 gleicher Exp $
