/// GraphicsTown2006 - CS559 Sample Code
// written by Michael Gleicher - originally written Fall, 2000
// updated Fall, 2005
// updated Fall, 2006 - new texture manager, improvements for behaviors

// the simple example objects - not that exciting - yours should be
// better! 

// note - because this is a precompiled header, getting the name the same
// is more important than getting the path right
#include "../GrTown_PCH.H"
#include "../DrawUtils.H"
#include "Utilities/Texture.H"
#include "../MMatrix.H"
#include "Suburbs.H"
#include "../GrWorld.H"
#include "../glm/glm.hpp"
#include "Utilities/ShaderTools.H"

/***********************************************************************/
// a Really simple tree - just a cone with a stem...
// use normals to make it look rounder...
SimpleTree1::SimpleTree1(float h, float r)
  : height(h), radius(r)
{
}
void SimpleTree1::draw(DrawingState*)
{
  // cone for the body
  glFrontFace(GL_CW);
  glColor3f(0.f,.6f,.3f);
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f(0,1,0);
  glVertex3f(0,height,0);
  glNormal3f(1,0,0);
  glVertex3f(radius,height/4,0);
  glNormal3f(0,0,1);
  glVertex3f(0,height/4,radius);
  glNormal3f(-1,0,0);
  glVertex3f(-radius,height/4,0);
  glNormal3f(0,0,-1);
  glVertex3f(0,height/4,-radius);
  glNormal3f(1,0,0);
  glVertex3f(radius,height/4,0);
  glEnd();
  glFrontFace(GL_CCW);
  // stem
  glColor3f(.6f,.5f,.3f);
  glBegin(GL_QUAD_STRIP);
  glNormal3f(1,0,0);
  glVertex3f(radius/5,0,0);
  glVertex3f(radius/5,height/4,0);
  glNormal3f(0,0,1);
  glVertex3f(0,0,radius/5);
  glVertex3f(0,height/4,radius/5);
  glNormal3f(-1,0,0);
  glVertex3f(-radius/5,0,0);
  glVertex3f(-radius/5,height/4,0);
  glNormal3f(0,0,-1);
  glVertex3f(0,0,-radius/5);
  glVertex3f(0,height/4,-radius/5);
  glNormal3f(1,0,0);
  glVertex3f(radius/5,0,0);
  glVertex3f(radius/5,height/4,0);
  glEnd();
}

/***********************************************************************/
// Tree Cluster
TreeCluster::TreeCluster()
{
}
void TreeCluster::draw(DrawingState*)
{
	float l = 10.0;
	float nl = -0.25f * l;
	float pl = 0.25f * l;
	//Draw scenary
	glPushMatrix();

	glScalef(2000.f, 4000.f, 2000.f);
	glTranslated(2 * 70, 0, 2 * -50);
	glRotatef(45, 0, 1, 0);
	//BEGIN tree
	glBegin(GL_QUADS);

	//trunk
	//if (!shadows) glColor3ub(83, 53, 10);
	glColor3ub(222, 222, 222);
	glVertex3f(0.25f*l, 0, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0, 0.25f*l);

	glVertex3f(0.25f*l, 0, -0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0, -0.25f*l);

	glVertex3f(0.25f*l, 0, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(0.25f*l, 0, -0.25f*l);

	glVertex3f(-0.25f*l, 0, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0, -0.25f*l);

	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslated(70, 0, -50);
	glRotatef(45, 0, 1, 0);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(1.3f, 0.75f, 1.3f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glPopMatrix();

	//tree 2
	glPushMatrix();
	glScalef(0.85f, 0.85f, 0.85f);
	glPushMatrix();

	glScalef(0.5f, 1.0f, 0.5f);
	glTranslated(2 * 82, 0, 2 * -36);
	glRotatef(-25, 0, 1, 0);
	//BEGIN tree
	glBegin(GL_QUADS);

	//trunk
	//if (!shadows) glColor3ub(83, 53, 10);
	glColor3ub(222, 222, 222);
	glVertex3f(0.25f*l, 0, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0, 0.25f*l);

	glVertex3f(0.25f*l, 0, -0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0, -0.25f*l);

	glVertex3f(0.25f*l, 0, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(0.25f*l, 0, -0.25f*l);

	glVertex3f(-0.25f*l, 0, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0, -0.25f*l);

	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslated(82, 0, -36);
	glRotatef(-25, 0, 1, 0);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(1.3f, 0.75f, 1.3f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) glColor3ub(1, 121, 111);
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();
	glPopMatrix();
	glPopMatrix();

	//tree3
	glPushMatrix();
	glScalef(0.9f, 0.9f, 0.9f);
	glPushMatrix();

	glScalef(0.5f, 1.0f, 0.5f);
	glTranslated(2 * -62, 0, 2 * 46);
	glRotatef(18, 0, 1, 0);
	//BEGIN tree
	glBegin(GL_QUADS);

	//trunk
	//if (!shadows) 
	glColor3ub(222, 222, 222);
	glVertex3f(0.25f*l, 0, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0, 0.25f*l);

	glVertex3f(0.25f*l, 0, -0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0, -0.25f*l);

	glVertex3f(0.25f*l, 0, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(0.25f*l, 0, -0.25f*l);

	glVertex3f(-0.25f*l, 0, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0, -0.25f*l);

	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslated(-62, 0, 46);
	glRotatef(18, 0, 1, 0);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(1.3f, 0.75f, 1.3f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 	
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glPopMatrix();
	glPopMatrix();

	//tree4
	glPushMatrix();
	glScalef(1.85f, 1.75f, 1.80f);
	glPushMatrix();

	glScalef(0.5f, 1.0f, 0.5f);
	glTranslated(2 * -40, 0, 2 * -20);
	glRotatef(0, 0, 1, 0);
	//BEGIN tree
	glBegin(GL_QUADS);

	//trunk
	//if (!shadows) 
	glColor3ub(222, 222, 222);
	glVertex3f(0.25f*l, 0, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0, 0.25f*l);

	glVertex3f(0.25f*l, 0, -0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0, -0.25f*l);

	glVertex3f(0.25f*l, 0, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(0.25f*l, 0, -0.25f*l);

	glVertex3f(-0.25f*l, 0, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, 0.25f*l);
	glVertex3f(-0.25f*l, 0.6f*l, -0.25f*l);
	glVertex3f(-0.25f*l, 0, -0.25f*l);

	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslated(-40, 0, -20);
	glRotatef(0, 0, 1, 0);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows)
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(1.3f, 0.75f, 1.3f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glScalef(0.9f, 0.75f, 0.9f);
	glTranslatef(0.0f, 6.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//leaves
	//if (!shadows) 
	glColor3ub(105, 41, 16);
	glVertex3f(-0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(-0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(0.5f*l, 0.6f*l, -2.0f*pl);
	glVertex3f(0.0f*l, 3.0f*l, 0.0f*pl);
	glVertex3f(0.5f*l, 0.6f*l, 2.0f*pl);

	glVertex3f(-2.0f*pl, 0.6f*l, -0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, -0.5f*l);

	glVertex3f(-2.0f*pl, 0.6f*l, 0.5f*l);
	glVertex3f(0.0f*pl, 3.0f*l, 0.0f*l);
	glVertex3f(2.0f*pl, 0.6f*l, 0.5f*l);

	glEnd();

	glPopMatrix();
	glPopMatrix();

}

/***********************************************************************/
// draw a patch of lawn - use a repeating texture
Lawn::Lawn(float xi1, float zi1, float xi2, float zi2)
  : x1(xi1), z1(zi1), x2(xi2), z2(zi2)
{
}

void Lawn::draw(DrawingState* d)
{
  // the catch here is that we need to use a polygon offset to draw
  // the lawn just above the ground...
  if (d->drGrTex)
	fetchTexture("grass.png",true,true);
  else
    glBindTexture(GL_TEXTURE_2D,0);
  glEnable(GL_POLYGON_OFFSET_FILL);
  glPolygonOffset(-2.,-2.);
  glNormal3f(0,1,0);
  glColor3f(0,1,1);
  glBegin(GL_POLYGON);
  glTexCoord2f(0,(z2-z1)/4.f);            glVertex3f(x1,0,z2);
  glTexCoord2f((x2-x1)/4.f, (z2-z1)/4.f); glVertex3f(x2,0,z2);
  glTexCoord2f((x2-x1)/4.f,0);            glVertex3f(x2,0,z1);
  glTexCoord2f(0,0);                      glVertex3f(x1,0,z1);
  glEnd();
  glDisable(GL_POLYGON_OFFSET_FILL);
  glBindTexture(GL_TEXTURE_2D,0);
}


/***********************************************************************/
/* simplest possible house */
SimpleHouse1::SimpleHouse1()
{
  color(.6f,.7f,.8f);
}
void SimpleHouse1::draw(DrawingState*)
{
  glColor3fv(&color.r);
  fetchTexture("simpleHouse1-front.png");
  glBegin(GL_POLYGON);
  glNormal3f(0,0,-1);
  glTexCoord2f(0,0); glVertex3i(-20, 0, -25);
  glTexCoord2f(0,1); glVertex3i(-20,30, -25);
  glTexCoord2f(.5,1.5); glVertex3i(  0,45,-25);
  glTexCoord2f(1,1); glVertex3i( 20,30,-25);
  glTexCoord2f(1,0); glVertex3i( 20, 0,-25);
  glEnd();
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glTexCoord2f(0,0); glVertex3i(-20, 0,   25);
  glTexCoord2f(1,0); glVertex3i( 20, 0,   25);
  glTexCoord2f(1,1); glVertex3i( 20,30,   25);
  glTexCoord2f(.5,1.5); glVertex3i(  0,45,25);
  glTexCoord2f(0,1); glVertex3i(-20,30,   25);
  glEnd();
  glBindTexture(GL_TEXTURE_2D,0);
  //  polygoni( 5, -20,0,-25,  20,0,-25,   20, 30,-25,   0,45,-25, -20,30,-25);
  //polygoni( 5, -20,0, 25,  20,0, 25,   20, 30, 25,   0,45, 25, -20,30, 25);
  polygoni( 4, 20, 0,-25,  20, 0, 25,  20, 30, 25,  20, 30, -25);
  polygoni(-4,-20, 0,-25, -20, 0, 25, -20, 30, 25, -20, 30, -25);
  polygoni( 4, 20,30,-25,  20,30, 25,   0, 45, 25,   0, 45, -25);
  polygoni(-4, -20,30,-25, -20,30, 25,   0, 45, 25,   0, 45, -25);
}
/***********************************************************************/
/* simplest possible house */
SimpleHouse2::SimpleHouse2()
{
  color(.6f,.7f,.8f);
  rotMatrix(transform,'Y',3.14159f/2.f);
}
void SimpleHouse2::draw(DrawingState*)
{
  glColor3fv(&color.r);
  polygoni( 5, -20,0,-30, 20,0,-30, 20,30,-30, 0,45,-30, -20,30,-30);
  polygoni(-5, -20,0, 30, 20,0, 30, 20,30, 30, 0,45, 30, -20,30, 30);
  fetchTexture("simpleHouse2-front.png");
  glBegin(GL_POLYGON);
  glNormal3f(1,0,0);
  glTexCoord2f(0,1); glVertex3i( 20,30,-30);
  glTexCoord2f(1,1); glVertex3i( 20,30, 30);
  glTexCoord2f(1,0); glVertex3i( 20, 0, 30);
  glTexCoord2f(0,0); glVertex3i( 20, 0,-30);
  glEnd();
  glBegin(GL_POLYGON);
  glNormal3f(-1,0,0);
  glTexCoord2f(0,0); glVertex3i(-20, 0,-30);
  glTexCoord2f(1,0); glVertex3i(-20, 0, 30);
  glTexCoord2f(1,1); glVertex3i(-20,30, 30);
  glTexCoord2f(0,1); glVertex3i(-20,30,-30);
  glEnd();
  glBindTexture(GL_TEXTURE_2D,0);
  glBindTexture(GL_TEXTURE_2D,0);
  fetchTexture("roof3.png");
  polygoni( 4, 20,30,-30,  20,30, 30,   0, 45, 30,   0, 45, -30);
  polygoni(-4,-20,30,-30, -20,30, 30,   0, 45, 30,   0, 45, -30);
}

/***********************************************************************/
// OK, this is even simpler...
SimpleHouse3::SimpleHouse3()
{
  color(.6f,.7f,.8f);
}
void SimpleHouse3::draw(DrawingState*)
{
  glColor3fv(&color.r);
  fetchTexture("simpleHouse2-front.png");
  polygoni(4, -20, 0,-20,  20, 0,-20,  20,30,-20,  -20,30,-20);
  fetchTexture("simpleHouse3-side.png");
  polygoni(4,  20, 0,-20,  20, 0, 20,  20,30, 20,   20,30,-20);
  fetchTexture("simpleHouse2-front.png");
  polygoni(4,  20, 0, 20, -20, 0, 20, -20,30, 20,   20,30, 20);
  fetchTexture("simpleHouse3-side.png");
  polygoni(4, -20, 0, 20, -20, 0,-20, -20,30,-20,  -20,30, 20);
  fetchTexture("roof3.png");
  polygoni(3, -20,30,-20,  20,30,-20,   0,45,0);
  polygoni(3,  20,30,-20,  20,30, 20,   0,45,0);
  polygoni(3,  20,30, 20, -20,30, 20,   0,45,0);
  polygoni(3, -20,30, 20, -20,30,-20,   0,45,0);
}

/***********************************************************************/
Train::Train() : GrObject("Train")
{
	color(.6f, .7f, .8f);
}
void Train::draw(DrawingState*)
{
	/*
	//int controlPointNum = (int)floor(world->trainU);
	int controlPointNum = (int)floor(1);
	//from (A)
	fCPp->pos.x = world->trackPoints[(int)(ceilf(world->steps*world->trainU)) % world->trackPoints.size()][0];
	fCPp->pos.y = world->trackPoints[(int)(ceilf(world->steps*world->trainU)) % world->trackPoints.size()][1];
	fCPp->pos.z = world->trackPoints[(int)(ceilf(world->steps*world->trainU)) % world->trackPoints.size()][2];
	//to (B)
	tCPp->pos.x = world->trackPoints[(int)(ceilf(world->steps*world->trainU) + 1) % world->trackPoints.size()][0];
	tCPp->pos.y = world->trackPoints[(int)(ceilf(world->steps*world->trainU) + 1) % world->trackPoints.size()][1];
	tCPp->pos.z = world->trackPoints[(int)(ceilf(world->steps*world->trainU) + 1) % world->trackPoints.size()][2];

	float x = fCPp->pos.x;
	float y = fCPp->pos.y;
	float z = fCPp->pos.z;
	float l = 10.0;

	//construct basis
	Pnt3f tangentUnitVector;
	tangentUnitVector.x = tCPp->pos.x - fCPp->pos.x;
	tangentUnitVector.y = tCPp->pos.y - fCPp->pos.y;
	tangentUnitVector.z = tCPp->pos.z - fCPp->pos.z;
	Pnt3f rightUnitVector = tangentUnitVector * Pnt3f(0, 1, 0);
	Pnt3f upUnitVector = rightUnitVector * tangentUnitVector;

	//normalize vectors
	tangentUnitVector.normalize();
	rightUnitVector.normalize();
	upUnitVector.normalize();

	if (0) //draw local reference coordinate vectors
	{
		glLineWidth(5.0);
		glBegin(GL_LINES); //TEMP
		//if (!shadows) //if we aren't drawing shadows (first call)
			glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3d(x, y + (0.3*l), z);
		glVertex3d(x + tangentUnitVector.x * 25, y + (0.3*l) + tangentUnitVector.y * 25, z + tangentUnitVector.z * 25);

		//if (!shadows) //if we aren't drawing shadows (first call)
			glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3d(x, y + (0.3*l), z);
		glVertex3d(x + rightUnitVector.x * 25, y + (0.3*l) + rightUnitVector.y * 25, z + rightUnitVector.z * 25);

		//if (!shadows) //if we aren't drawing shadows (first call)
			glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3d(x, y + (0.3*l), z);
		glVertex3d(x + upUnitVector.x * 25, y + (0.3*l) + upUnitVector.y * 25, z + upUnitVector.z * 25);

		glEnd();
	}

	float nl = -0.25f * l;
	float pl = 0.25f * l;

	if (1) // don't draw the train if you're looking out the front window
	{
		glPushMatrix();

		float M[16]; //column major ordering
		M[0] = tangentUnitVector.x; M[1] = tangentUnitVector.y; M[2] = tangentUnitVector.z;
		M[4] = upUnitVector.x; M[5] = upUnitVector.y; M[6] = upUnitVector.z;
		M[8] = rightUnitVector.x; M[9] = rightUnitVector.y; M[10] = rightUnitVector.z;
		M[12] = fCPp->pos.x; M[13] = fCPp->pos.y; M[14] = fCPp->pos.z;
		M[3] = M[7] = M[11] = 0.0f;
		M[15] = 1.0f;
		glMultMatrixf(M);
		glTranslatef(0.75*l, 2.75, 0);
		glBegin(GL_QUADS); //draw main

		//glNormal3d(0, 0, 1);
		glNormal3d(0, 0, 1);
		if (!shadows) glColor3f(1.0, 0.0, 0.0);
		glVertex3d(0, pl, pl);
		if (!shadows) glColor3f(0.0, 1.0, 0.0);
		glVertex3d(-l, pl, pl);
		if (!shadows) glColor3f(0.0, 0.0, 1.0);
		glVertex3d(-l, nl, pl);
		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3d(0, nl, pl);

		//glNormal3f(rightUnitVector.x, rightUnitVector.y, rightUnitVector.z);
		glNormal3d(0, 0, -1);
		if (!shadows) glColor3f(1.0, 0.0, 0.0);
		glVertex3d(0, pl, nl);
		if (!shadows) glColor3f(0.0, 1.0, 0.0);
		glVertex3d(0, nl, nl);
		if (!shadows) glColor3f(0.0, 0.0, 1.0);
		glVertex3d(-l, nl, nl);
		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3d(-l, pl, nl);

		//glNormal3f(upUnitVector.x, upUnitVector.y, upUnitVector.z);
		glNormal3d(0, 1, 0);
		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3d(0, pl, pl);
		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3d(0, pl, nl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3d(-l, pl, nl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3d(-l, pl, pl);

		glNormal3d(0, -1, 0);
		glVertex3d(0, nl, pl);
		glVertex3d(-l, nl, pl);
		glVertex3d(-l, nl, nl);
		glVertex3d(0, nl, nl);

		glNormal3d(1, 0, 0);
		glVertex3d(0, pl, pl);
		glVertex3d(0, nl, pl);
		glVertex3d(0, nl, nl);
		glVertex3d(0, pl, nl);

		glNormal3d(-1, 0, 0);
		glVertex3d(-l, pl, pl);
		glVertex3d(-l, pl, nl);
		glVertex3d(-l, nl, nl);
		glVertex3d(-l, nl, pl);

		glNormal3f(0, 0, 1);
		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3d(-l, 0.75f*l, pl);
		if (!shadows) glColor3f(0.0, 1.0, 0.0);
		glVertex3d(-l, nl, pl);
		if (!shadows) glColor3f(0.0, 0.0, 1.0);
		glVertex3d(-l - (0.5f*l), nl, pl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3d(-l - (0.5f*l), 0.75f*l, pl);

		glNormal3d(0, 0, -1);
		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3d(-l, 0.75f*l, nl);
		if (!shadows) glColor3f(1.0, 0.0, 0.0);
		glVertex3d(-l, nl, nl);
		if (!shadows) glColor3f(0.0, 1.0, 0.0);
		glVertex3d(-l - (0.5f*l), nl, nl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3d(-l - (0.5f*l), 0.75f*l, nl);

		glNormal3d(0, 1, 0);
		glVertex3d(-l, 0.75f*l, pl);
		glVertex3d(-l - (0.5f*l), 0.75f*l, pl);
		glVertex3d(-l - (0.5f*l), 0.75f*l, nl);
		glVertex3d(-l, 0.75f*l, nl);


		glNormal3d(0, -1, 0);
		glVertex3d(-l - (0.5f*l), nl, pl);
		glVertex3d(-l, nl, pl);
		glVertex3d(-l, nl, nl);
		glVertex3d(-l - (0.5f*l), nl, nl);

		glNormal3d(1, 0, 0);
		glVertex3d(-l, 0.75f*l, pl);
		glVertex3d(-l, 0.75f*l, nl);
		glVertex3d(-l, nl, nl);
		glVertex3d(-l, nl, pl);

		glNormal3d(-1, 0, 0);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3d(-l - (0.5f*l), 0.75f*l, pl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3d(-l - (0.5f*l), 0.75f*l, nl);
		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3d(-l - (0.5f*l), nl, nl);
		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3d(-l - (0.5f*l), nl, pl);

		glEnd();

		//draw smoke chute
		glBegin(GL_QUADS);

		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.15f*l, pl, 0.5f*pl);
		if (!shadows) glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.15f*l, 0.6f*l, 0.5f*pl);
		if (!shadows) glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.45f*l, 0.6f*l, 0.5f*pl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.45f*l, pl, 0.5f*pl);

		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.15f*l, pl, -0.5f*pl);
		if (!shadows) glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.15f*l, 0.6f*l, -0.5f*pl);
		if (!shadows) glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.45f*l, 0.6f*l, -0.5f*pl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.45f*l, pl, -0.5f*pl);


		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.15f*l, pl, 0.5f*pl);
		if (!shadows) glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.15f*l, 0.6f*l, 0.5f*pl);
		if (!shadows) glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.15f*l, 0.6f*l, -0.5f*pl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.15f*l, pl, -0.5f*pl);

		if (!shadows) glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.45f*l, pl, 0.5f*pl);
		if (!shadows) glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.45f*l, 0.6f*l, 0.5f*pl);
		if (!shadows) glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.45f*l, 0.6f*l, -0.5f*pl);
		if (!shadows) glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.45f*l, pl, -0.5f*pl);

		glEnd();

		//OUTLINE TRAIN
		glLineWidth(2.0);
		if (!shadows) //if we aren't drawing shadows (first call)
			glColor3f(0.0, 0.0, 0.0);

		glBegin(GL_LINES); //draw borders

		//BEGIN front
		glVertex3d(0, pl, pl);
		glVertex3d(0, pl, nl);

		glVertex3d(0, nl, nl);
		glVertex3d(0, pl, nl);
		//END front

		//BEGIN sides
		//+z
		glVertex3d(0, pl, pl);
		glVertex3d(-l, pl, pl);

		glVertex3d(-l, pl, pl);
		glVertex3d(-l, 0.75f*l, pl);

		glVertex3d(-l, 0.75f*l, pl);
		glVertex3d(-l - (0.5f*l), 0.75f*l, pl);

		glVertex3d(-l - (0.5f*l), 0.75f*l, pl);
		glVertex3d(-l - (0.5f*l), nl, pl);

		glVertex3d(-l - (0.5f*l), nl, pl);
		glVertex3d(0, nl, pl);

		glVertex3d(0, nl, pl);
		glVertex3d(0, pl, pl);
		//-z
		glVertex3d(0, pl, nl);
		glVertex3d(-l, pl, nl);

		glVertex3d(-l, pl, nl);
		glVertex3d(-l, 0.75f*l, nl);

		glVertex3d(-l, 0.75f*l, nl);
		glVertex3d(-l - (0.5f*l), 0.75f*l, nl);

		glVertex3d(-l - (0.5f*l), 0.75f*l, nl);
		glVertex3d(-l - (0.5f*l), nl, nl);

		glVertex3d(-l - (0.5f*l), nl, nl);
		glVertex3d(0, nl, nl);

		glVertex3d(0, nl, nl);
		glVertex3d(0, pl, nl);
		//END sides

		//BEGIN top
		glVertex3d(-l - (0.5f*l), 0.75f*l, pl);
		glVertex3d(-l - (0.5f*l), 0.75f*l, nl);

		glVertex3d(-l, 0.75f*l, pl);
		glVertex3d(-l, 0.75f*l, nl);
		//END top

		//BEGIN back
		glVertex3d(-l - (0.5f*l), nl, pl);
		glVertex3d(-l - (0.5f*l), nl, nl);
		//END back
		glEnd();

		//BEGIN smoke chute
		glBegin(GL_LINES);

		glVertex3f(-0.15f*l, pl, 0.5f*pl);
		glVertex3f(-0.15f*l, 0.6f*l, 0.5f*pl);

		glVertex3f(-0.15f*l, 0.6f*l, 0.5f*pl);
		glVertex3f(-0.45f*l, 0.6f*l, 0.5f*pl);

		glVertex3f(-0.45f*l, 0.6f*l, 0.5f*pl);
		glVertex3f(-0.45f*l, pl, 0.5f*pl);

		glVertex3f(-0.15f*l, pl, -0.5f*pl);
		glVertex3f(-0.15f*l, 0.6f*l, -0.5f*pl);

		glVertex3f(-0.15f*l, 0.6f*l, -0.5f*pl);
		glVertex3f(-0.45f*l, 0.6f*l, -0.5f*pl);

		glVertex3f(-0.45f*l, 0.6f*l, -0.5f*pl);
		glVertex3f(-0.45f*l, pl, -0.5f*pl);

		glVertex3f(-0.15f*l, pl, 0.5f*pl);
		glVertex3f(-0.15f*l, 0.6f*l, 0.5f*pl);

		glVertex3f(-0.15f*l, 0.6f*l, 0.5f*pl);
		glVertex3f(-0.15f*l, 0.6f*l, -0.5f*pl);

		glVertex3f(-0.15f*l, 0.6f*l, -0.5f*pl);
		glVertex3f(-0.15f*l, pl, -0.5f*pl);

		glVertex3f(-0.45f*l, pl, 0.5f*pl);
		glVertex3f(-0.45f*l, 0.6f*l, 0.5f*pl);

		glVertex3f(-0.45f*l, 0.6f*l, 0.5f*pl);
		glVertex3f(-0.45f*l, 0.6f*l, -0.5f*pl);

		glVertex3f(-0.45f*l, 0.6f*l, -0.5f*pl);
		glVertex3f(-0.45f*l, pl, -0.5f*pl);

		glEnd();
		//END smoke chute

		glPopMatrix();
	}

	*/
}

//This balloon is drawn using an advanced technique called vertex arrays
// don't worry if you don't understand all of this code - that's why I left the comments in
/*
using namespace std;
using namespace glm;
std::vector<vec3> a6_GL_window::va_vertices;
std::vector<ivec3> a6_GL_window::va_indices;
std::vector<vec3> a6_GL_window::va_normals;

const float PI = 3.14159265f;
Blimp::Blimp() : GrObject("Blimp")
{
color(.6f, .7f, .8f);
}
void Blimp::draw(DrawingState*)
{

	//Source: https://uwmad.courses.wisconsin.edu/d2l/lms/content/viewer/main_frame.d2l?tId=11011796&ou=1821693
	//Example vertex array code used to figure out vertex arrays

	//GL_CULL_FACE is left enabled as disabling it leads to bizarre ripple effects
	glDisable(GL_COLOR_MATERIAL); //disabled, so that the color will be determined by the material specified below
	GLboolean blendAlreadyEnabled;
	glGetBooleanv(GL_BLEND, &blendAlreadyEnabled); //checks if blending is already enable, to later restore the previous state
	if (blendAlreadyEnabled) glBlendFunc(GL_ONE, GL_ONE);
	else glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	//Unique color and alpha values for each component of light result in giving a unique look to the
	//model. These values were chosen to simulate the appearance of a shiny, semi-transparent balloon
	GLfloat material_ambient_gold[] = { 0.25f, 0.20f, 0.08f, 0.8f };//{ 0.7f, 0.6f, 0.6f, 0.7f};
	GLfloat material_diffuse_gold[] = { 0.75f, 0.61f, 0.22f, 0.8f };//{ 0.7f, 0.6f, 0.6f, 0.7f};
	GLfloat material_specular_gold[] = { 0.63f, 0.56f, 0.37f, 0.7f };
	GLfloat material_shininess_gold[] = { .4f * 128.0f };

	GLfloat material_ambient_silver[] = { 0.7f, 0.6f, 0.6f, 0.7f };
	GLfloat material_diffuse_silver[] = { 0.7f, 0.6f, 0.6f, 0.7f };
	GLfloat material_specular_silver[] = { 0.7f, 0.6f, 0.6f, 0.7f };
	GLfloat material_shininess_silver[] = { .25f * 128.0f };

	GLfloat material_ambient_red[] = { 1.0f, 0.1f, 0.1f, 0.8f };//{ 0.7f, 0.6f, 0.6f, 0.7f};
	GLfloat material_diffuse_red[] = { 1.0f, 0.1f, 0.1f, 0.8f };//{ 0.7f, 0.6f, 0.6f, 0.7f};
	GLfloat material_specular_red[] = { 0.7f, 0.6f, 0.6f, 0.7f };
	GLfloat material_shininess_red[] = { .25f * 128.0f };

	GLfloat material_ambient_green[] = { 0.1f, 1.0f, 0.1f, 0.8f };//{ 0.7f, 0.6f, 0.6f, 0.7f};
	GLfloat material_diffuse_green[] = { 0.1f, 1.0f, 0.1f, 0.8f };//{ 0.7f, 0.6f, 0.6f, 0.7f};
	GLfloat material_specular_green[] = { 0.6f, 0.7f, 0.6f, 0.7f };
	GLfloat material_shininess_green[] = { .25f * 128.0f };

	GLfloat material_ambient_blue[] = { 0.1f, 0.1f, 1.0f, 0.8f };//{ 0.7f, 0.6f, 0.6f, 0.7f};
	GLfloat material_diffuse_blue[] = { 0.1f, 0.1f, 1.0f, 0.8f };//{ 0.7f, 0.6f, 0.6f, 0.7f};
	GLfloat material_specular_blue[] = { 0.6f, 0.6f, 0.7f, 0.7f };
	GLfloat material_shininess_blue[] = { .25f * 128.0f };


	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient_red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse_red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular_red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material_shininess_red);


	if (va_vertices.size() == 0) {

		GLfloat r;
		GLfloat o;
		GLfloat p;
		r = 1.0;

		//The balloon is drawn by specifying individual vertexes. In this case, the top half of the
		//balloon is drawn by loops that draw verticle stacks of circles of non-linear radius which are connected to form
		//a balloon shape. In this case, the circles are made by taking polar coordinates and converting
		//them back into cartesian.

		//The balloon's unique bottom shape is due to an equation which varies the distance of the stack of circles
		//from the center of the shape in a non-linear form.

		GLfloat omegaPoints = 91.0f;
		GLfloat omegaIncrement = 180 / (omegaPoints - 1);

		//The value to increment between the points is determined by the desired space to fill over the number
		//of points. In this case, a 1 is subtracted from the points, because 0 is counted as the first point
		//and the loop runs until the value equals the desired size.

		GLfloat phiPoints = 120.0f;
		GLfloat phiIncrement = 360 / phiPoints;

		//Source: http://electron9.phys.utk.edu/vectors/3dcoordinates.htm used to translate polar to 
		for (o = (GLfloat)0; o <= (GLfloat)180; o += omegaIncrement) {
			for (p = (GLfloat)0; p <(GLfloat)360; p += phiIncrement) {

				if (o < .5 * 180) r = (GLfloat)1;
				else r = (GLfloat)(1 + (1 - cos((o - 90)*(PI / 180))) / 2);

				this->va_vertices.push_back(glm::vec3((r * sin(o*(PI / 180))* cos(p*(PI / 180))),
					(r * cos(o*(PI / 180))), (r * sin(o*(PI / 180))* sin(p*(PI / 180)))));
			}
		}

		GLfloat height;
		GLfloat angle;
		r = 0.0;
		GLfloat heightPoints = 6.0;
		GLfloat heightIncrement = 0.1f / (heightPoints - 1);

		//The value to increment between the points is determined by the desired space to fill over the number
		//of points. In this case, a 1 is subtracted from the points, because 0 is counted as the first point
		//and the loop runs until the value equals the desired size.

		GLfloat anglePoints = 18.0;
		GLfloat angleIncrement = 360 / anglePoints;

		GLfloat radialIncreasePerHeightIncrement = 0.02f;

		//A small cone is created on the bottom of the balloon by drawing a stack of circles of a linear radius.
		//Source: http://electron9.phys.utk.edu/vectors/2dcoordinates.htm used to translate polar to cartesian 2D
		for (height = (GLfloat)-1.45f; height >= (GLfloat)-1.55f; height -= heightIncrement) {
			for (angle = 0; angle < 360; angle += angleIncrement){
				this->va_vertices.push_back(glm::vec3((r * cos(angle*(PI / 180))), height, (r * sin(angle*(PI / 180)))));
			}
			r += radialIncreasePerHeightIncrement;
		}

		r = 1; //the radius is reset to 1 as it is used later

		//The vertices are then grouped into triangles and have their normals calculated by normalizing 
		//the result of taking the cross-product between the two sides of every triangle that the vertex is involved in
		//and summing them. 

		GLfloat a;
		GLfloat aMax = (omegaPoints - 1) * phiPoints;
		//Iterates through the loop and connects the vertices into triangular shapes that blur together into the final shape
		//the max index of the loop does not include the last row of points as each row constructs triangles with the row
		//beneath it and thus the last row does not need to construct triangles
		for (a = 0; a < aMax; a++) {
			//the last vertex in a row is unique as the point considered next to it is actually the first point in the row
			if (((int)a % (int)phiPoints) != ((int)phiPoints - 1)) {
				this->va_indices.push_back(glm::ivec3(a, a + phiPoints + 1, a + phiPoints));
				this->va_indices.push_back(glm::ivec3(a, a + 1, a + phiPoints + 1));
			}
			else {
				this->va_indices.push_back(glm::ivec3(a, a + 1, a + phiPoints));
				this->va_indices.push_back(glm::ivec3(a, a - phiPoints + 1, a + 1));
			}
			//the top row of normals are easily predicted due to the shape of the balloon, the rest are calculated
			if (a < phiPoints) {
				this->va_normals.push_back(glm::vec3(0, 1, 0));
			}
			else {

				//Source: http://glm.g-truc.net/code.html used to figure our normal calculations

				glm::vec3 one;
				glm::vec3 two;
				glm::vec3 three;
				glm::vec3 four;
				glm::vec3 five;
				glm::vec3 six;

				//get all points starting at point directly above and going clockwise
				one = va_vertices[GLuint(a - phiPoints)];
				//points at the end of the row must wrap around the array to find their neighbor points
				if (((int)a % (int)phiPoints) != ((int)phiPoints - 1)) {
					two = va_vertices[GLuint(a + 1)];
					three = va_vertices[GLuint(a + phiPoints + 1)];
				}
				else {
					two = va_vertices[GLuint(a - phiPoints + 1)];
					three = va_vertices[GLuint(a + 1)];
				}
				four = va_vertices[GLuint(a + phiPoints)];
				//points at the end of the row must wrap around the array to find their neighbor points
				if (((int)a % (int)phiPoints) != 0) {
					five = va_vertices[GLuint(a - 1)];
					six = va_vertices[GLuint(a - phiPoints - 1)];
				}
				else {
					five = va_vertices[GLuint(a + phiPoints - 1)];
					six = va_vertices[GLuint(a - 1)];
				}

				vec3 sum = glm::cross(one - va_vertices[GLuint(a)], two - va_vertices[GLuint(a)]);
				sum += glm::cross(two - va_vertices[GLuint(a)], three - va_vertices[GLuint(a)]);
				sum += glm::cross(three - va_vertices[GLuint(a)], four - va_vertices[GLuint(a)]);
				sum += glm::cross(four - va_vertices[GLuint(a)], five - va_vertices[GLuint(a)]);
				sum += glm::cross(five - va_vertices[GLuint(a)], six - va_vertices[GLuint(a)]);
				sum += glm::cross(six - va_vertices[GLuint(a)], one - va_vertices[GLuint(a)]);
				this->va_normals.push_back(glm::normalize(sum));
			}
		}

		//The preceding loop did not address the final row of normals as it did not need to loop through the final
		//row to specify vertices. This loop fills in the rest of the normals as they are easily predicted due to the
		//shape of the balloon.
		for (a = 0; a < phiPoints; ++a) {
			this->va_normals.push_back(glm::vec3(0, -1, 0));
		}

		//The normals and indices of the cone beneath the balloon are calculated the same way.
		for (a = 0; a < anglePoints; ++a) {
			this->va_normals.push_back(glm::vec3(0, 1, 0));
		}

		GLfloat initial = omegaPoints * phiPoints;
		GLfloat b = initial;
		GLfloat bMax = b + (heightPoints - 1) * anglePoints;

		for (b = omegaPoints * phiPoints; b < bMax; b++) {
			if (((int)(b - initial) % (int)anglePoints) != ((int)anglePoints - 1)) {
				this->va_indices.push_back(glm::ivec3(b, b + anglePoints + 1, b + anglePoints));
				this->va_indices.push_back(glm::ivec3(b, b + 1, b + anglePoints + 1));
			}
			else {
				this->va_indices.push_back(glm::ivec3(b, b + 1, b + anglePoints));
				this->va_indices.push_back(glm::ivec3(b, b - anglePoints + 1, b + 1));
			}

			if (b < initial + anglePoints) {
				this->va_normals.push_back(glm::vec3(0, 1, 0));
			}
			else {
				glm::vec3 one;
				glm::vec3 two;
				glm::vec3 three;
				glm::vec3 four;
				glm::vec3 five;
				glm::vec3 six;

				//get all points starting at point directly above and going clockwise
				one = va_vertices[GLuint(b - anglePoints)];
				if (((int)(b - initial) % (int)anglePoints) != ((int)anglePoints - 1)) {
					two = va_vertices[GLuint(b + 1)];
					three = va_vertices[GLuint(b + anglePoints + 1)];
				}
				else {
					two = va_vertices[GLuint(b - anglePoints + 1)];
					three = va_vertices[GLuint(b + 1)];
				}
				four = va_vertices[GLuint(b + anglePoints)];
				if (((int)(b - initial) % (int)anglePoints) != 0) {
					five = va_vertices[GLuint(b - 1)];
					six = va_vertices[GLuint(b - anglePoints - 1)];
				}
				else {
					five = va_vertices[GLuint(b + anglePoints - 1)];
					six = va_vertices[GLuint(b - 1)];
				}

				glm::vec3 sum = glm::cross(one - va_vertices[GLuint(b)], two - va_vertices[GLuint(b)]);
				sum += glm::cross(two - va_vertices[GLuint(b)], three - va_vertices[GLuint(b)]);
				sum += glm::cross(three - va_vertices[GLuint(b)], four - va_vertices[GLuint(b)]);
				sum += glm::cross(four - va_vertices[GLuint(b)], five - va_vertices[GLuint(b)]);
				sum += glm::cross(five - va_vertices[GLuint(b)], six - va_vertices[GLuint(b)]);
				sum += glm::cross(six - va_vertices[GLuint(b)], one - va_vertices[GLuint(b)]);
				this->va_normals.push_back(glm::normalize(sum));
			}
		}

		for (a = 0; a < anglePoints; ++a) {
			for (angle = 0; angle < 360; angle += angleIncrement) {
				this->va_normals.push_back(glm::normalize(glm::vec3(r*cos(angle *(PI / 180)), 0, r*sin(angle *(PI / 180)))));
			}
		}

	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &va_vertices[0]);
	glNormalPointer(GL_FLOAT, 0, &va_normals[0]);

	glDrawElements(GL_TRIANGLES, 3 * va_indices.size(), GL_UNSIGNED_INT, &va_indices[0]);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

	glPushMatrix();
	glTranslated(0, -1.55, 0);
	glRotated(90, 1, 0, 0);
	glutSolidTorus((GLdouble) 0.018, (GLdouble) 0.11, (GLint)20, (GLint)20);
	//Source: http://www.nigels.com/glt/doc/class_glut_torus.html
	glPopMatrix();

	glEnable(GL_COLOR_MATERIAL);
	if (!blendAlreadyEnabled){
		glDisable(GL_BLEND);
	}
	else glBlendFunc(GL_ONE, GL_ONE);
}

/***********************************************************************/
Church::Church() : GrObject("Church")
{
  color(.6f,.7f,.8f);
}
void Church::draw(DrawingState*)
{
  int xsz = 30;
  int zsz = 40;
  int hgh = 50;
  int top = 65;

  glColor3fv(&color.r);
  fetchTexture("church-front.png");
  glBegin(GL_POLYGON);
  glNormal3f(0,0,-1);
  glTexCoord2f(0,0); glVertex3i(-xsz, 0, -zsz);
  glTexCoord2f(0,1); glVertex3i(-xsz,hgh, -zsz);
  glTexCoord2f(.5,1.5); glVertex3i(  0,top,-zsz);
  glTexCoord2f(1,1); glVertex3i( xsz,hgh,-zsz);
  glTexCoord2f(1,0); glVertex3i( xsz, 0,-zsz);
  glEnd();
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glTexCoord2f(0,0); glVertex3i(-xsz, 0,   zsz);
  glTexCoord2f(1,0); glVertex3i( xsz, 0,   zsz);
  glTexCoord2f(1,1); glVertex3i( xsz,hgh,   zsz);
  glTexCoord2f(.5,1.5); glVertex3i(  0,top,zsz);
  glTexCoord2f(0,1); glVertex3i(-xsz,hgh,   zsz);
  glEnd();
  glBindTexture(GL_TEXTURE_2D,0);

  polygoni( 4, xsz,hgh,-zsz,  xsz,hgh, zsz,   0, top, zsz,   0, top, -zsz);
  polygoni(-4, -xsz,hgh,-zsz, -xsz,hgh, zsz,   0, top, zsz,   0, top,
		   -zsz);

  fetchTexture("church-side.png");
  polygoni( 4, xsz, 0,-zsz,  xsz, 0, zsz,  xsz, hgh, zsz,  xsz, hgh, -zsz);
  polygoni(-4,-xsz, 0,-zsz, -xsz, 0, zsz, -xsz, hgh, zsz, -xsz, hgh, -zsz);


  glPushMatrix();
  glTranslatef(0,0,(float)zsz);
  int ss=10;					// steeple size
  int sh=60;					// height
  int th=120;					// top of point
  glBindTexture(GL_TEXTURE_2D,0);
  polygoni(4, -ss, 0,-ss,  ss, 0,-ss,  ss,sh,-ss,  -ss,sh,-ss);
  polygoni(4,  ss, 0,-ss,  ss, 0, ss,  ss,sh, ss,   ss,sh,-ss);
  polygoni(4,  ss, 0, ss, -ss, 0, ss, -ss,sh, ss,   ss,sh, ss);
  polygoni(4, -ss, 0, ss, -ss, 0,-ss, -ss,sh,-ss,  -ss,sh, ss);
  polygoni(3, -ss,sh,-ss,  ss,sh,-ss,   0,th,0);
  polygoni(3,  ss,sh,-ss,  ss,sh, ss,   0,th,0);
  polygoni(3,  ss,sh, ss, -ss,sh, ss,   0,th,0);
  polygoni(3, -ss,sh, ss, -ss,sh,-ss,   0,th,0);
  glPopMatrix();
}

Castle::Castle() : GrObject("Castle")
{
	//color(.6f, .7f, .8f);
}
void Castle::draw(DrawingState*)
{
	static bool draw = false;
	if (draw)
	{
		draw = false;
		// Read our .obj file
		std::vector< glm::vec3 > vertices;
		std::vector< glm::vec2 > uvs;
		std::vector< glm::vec3 > normals; // Won't be used at the moment.
		bool res = loadOBJ("data/cube2.obj", vertices, uvs, normals);
		glBegin(GL_LINES);
		for (int i = 0; i < ((vertices)._Mylast - (vertices)._Myfirst); i++)
		{
			glVertex3d(((vertices)._Myfirst)[i].x, ((vertices)._Myfirst)[i].y, ((vertices)._Myfirst)[i].z);
		}
		glEnd();
		//glBufferData(GL_ARRAY_BUFFER, ((vertices)._Mylast - (vertices)._Myfirst) * 3, &((vertices)._Myfirst)[0], GL_STATIC_DRAW);
	}
}

Volcano::Volcano() : GrObject("Volcano")
{
}
void Volcano::draw(DrawingState* d)
{
	//HEIGHT MAP
	int map[10][10] = {
			{ -5, -5, -5, -5, -5, -5, -5, -5, -5, -5 },
			{ -5, -5, 1, 1, 1, 1, 1, 1, -5, -5 },
			{ -5, 1, 2, 3, 3, 3, 3, 2, 1, -5 },
			{ -5, 1, 3, 5, 5, 6, 5, 3, 1, -5 },
			{ -5, 1, 3, 6, 4, 4, 7, 3, 1, -5 },
			{ -5, 1, 3, 8, 4, 5, 6, 3, 1, -5 },
			{ -5, 1, 3, 5, 6, 7, 5, 3, 1, -5 },
			{ -5, 1, 2, 3, 3, 3, 3, 2, 1, -5 },
			{ -5, -5, 1, 1, 1, 1, 1, 1, -5, -5 },
			{ -5, -5, -5, -5, -5, -5, -5, -5, -5, -5 } };
	int MAP_SIZE = 10;
	glPushMatrix();

	fetchTexture("Plains_texture.jpg", true, true);
	glScalef(135.0f, 85.0f, 145.0f);
	glTranslatef(-4.95f, -0.1f, 4.25f);
	glBegin(GL_QUADS);
	for (int x = 0; x < MAP_SIZE - 1; x++) {
		for (int z = 0; z < MAP_SIZE - 1; z++) {
			glTexCoord2f((float)x / MAP_SIZE, (float)z / MAP_SIZE);
			glVertex3f(x, map[x][z], z);
			glTexCoord2f((float)(x + 1) / MAP_SIZE, (float)z / MAP_SIZE);
			glVertex3f(x + 1, map[x + 1][z], z);
			glTexCoord2f((float)(x + 1) / MAP_SIZE, (float)(z + 1) / MAP_SIZE);
			glVertex3f(x + 1, map[x + 1][z + 1], z + 1);
			glTexCoord2f((float)x / MAP_SIZE, (float)(z + 1) / MAP_SIZE);
			glVertex3f(x, map[x][z + 1], z + 1);
			//if ()
		}
	}
	glEnd();

	glPopMatrix();

	if (d->timeOfDay >= 6 && d->timeOfDay <= (24 - 6))
	{
		//brown door -- CLOSED STATE
		fetchTexture("Volcano_Gate.jpg");
		glBegin(GL_POLYGON);
		glTexCoord2f(0.8, 0.05);
		glVertex3f(-100, 0, 700);
		glTexCoord2f(0.8, 0.76);
		glVertex3f(-100, 95, 700);
		glTexCoord2f(0.5, .95);
		glVertex3f(-50, 125, 700);
		glTexCoord2f(0.2, 0.76);
		glVertex3f(0, 95, 700);
		glTexCoord2f(0.2, 0.05);
		glVertex3f(0, 0, 700);
		glEnd();
	}
	else
	{
		//draw 1/6 way open
		if (d->timeOfDay == 5 || d->timeOfDay == (24 - 5))
		{
			fetchTexture("Volcano_Gate.jpg");
			glBegin(GL_POLYGON);
			glTexCoord2f(0.8f, 0.05f);	//
			glVertex3f(-100, 0, 700);	//
			glTexCoord2f(0.8f, 0.76f);	//
			glVertex3f(-100, 95, 700);	//
			glTexCoord2f(0.5f, .95f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(1 * pi / 12)))), 125, (float)(700 - (50 * sin(1 * pi / 12))));
			glTexCoord2f(0.5f, .05f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(1 * pi / 12)))), 0, (float)(700 - (50 * sin(1 * pi / 12))));
			glEnd();
			//glFrontFace(GL_CCW);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.5f, 0.05f);		//
			glVertex3f((float)(-(50 * cos(1 * pi / 12))), 0, (float)(700 - (50 * sin(1 * pi / 12))));
			glTexCoord2f(0.5f, 0.95f);		//
			glVertex3f((float)(-(50 * cos(1 * pi / 12))), 125, (float)(700 - (50 * sin(1 * pi / 12))));
			glTexCoord2f(0.2f, 0.76f);	//
			glVertex3f(0, 95, 700);		//
			glTexCoord2f(0.2f, 0.05f);	//
			glVertex3f(0, 0, 700);		//
			glEnd();
		}
		//draw 2/6 way open
		if (d->timeOfDay == 4 || d->timeOfDay == (24 - 4))
		{
			fetchTexture("Volcano_Gate.jpg");
			glBegin(GL_POLYGON);
			glTexCoord2f(0.8f, 0.05f);	//
			glVertex3f(-100, 0, 700);	//
			glTexCoord2f(0.8f, 0.76f);	//
			glVertex3f(-100, 95, 700);	//
			glTexCoord2f(0.5f, .95f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(2 * pi / 12)))), 125, (float)(700 - (50 * sin(2 * pi / 12))));
			glTexCoord2f(0.5f, .05f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(2 * pi / 12)))), 0, (float)(700 - (50 * sin(2 * pi / 12))));
			glEnd();
			//glFrontFace(GL_CCW);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.5f, 0.05f);		//
			glVertex3f((float)(-(50 * cos(2 * pi / 12))), 0, (float)(700 - (50 * sin(2 * pi / 12))));
			glTexCoord2f(0.5f, 0.95f);		//
			glVertex3f((float)(-(50 * cos(2 * pi / 12))), 125, (float)(700 - (50 * sin(2 * pi / 12))));
			glTexCoord2f(0.2f, 0.76f);	//
			glVertex3f(0, 95, 700);		//
			glTexCoord2f(0.2f, 0.05f);	//
			glVertex3f(0, 0, 700);		//
			glEnd();
		}
		//draw 3/6 way open -- HALF OPEN -- HALF LIGHT BEAM
		if (d->timeOfDay == 3 || d->timeOfDay == (24 - 3))
		{
			fetchTexture("Volcano_Gate.jpg");
			glBegin(GL_POLYGON);
			glTexCoord2f(0.8f, 0.05f);	//
			glVertex3f(-100, 0, 700);	//
			glTexCoord2f(0.8f, 0.76f);	//
			glVertex3f(-100, 95, 700);	//
			glTexCoord2f(0.5f, .95f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(3 * pi / 12)))), 125, (float)(700 - (50 * sin(3 * pi / 12))));
			glTexCoord2f(0.5f, .05f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(3 * pi / 12)))), 0, (float)(700 - (50 * sin(3 * pi / 12))));
			glEnd();
			//glFrontFace(GL_CCW);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.5f, 0.05f);		//
			glVertex3f((float)(-(50 * cos(3 * pi / 12))), 0, (float)(700 - (50 * sin(3 * pi / 12))));
			glTexCoord2f(0.5f, 0.95f);		//
			glVertex3f((float)(-(50 * cos(3 * pi / 12))), 125, (float)(700 - (50 * sin(3 * pi / 12))));
			glTexCoord2f(0.2f, 0.76f);	//
			glVertex3f(0, 95, 700);		//
			glTexCoord2f(0.2f, 0.05f);	//
			glVertex3f(0, 0, 700);		//
			glEnd();
		}
		//draw 4/6 way open
		if (d->timeOfDay == 2 || d->timeOfDay == (24 - 2))
		{
			fetchTexture("Volcano_Gate.jpg");
			glBegin(GL_POLYGON);
			glTexCoord2f(0.8f, 0.05f);	//
			glVertex3f(-100, 0, 700);	//
			glTexCoord2f(0.8f, 0.76f);	//
			glVertex3f(-100, 95, 700);	//
			glTexCoord2f(0.5f, .95f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(4 * pi / 12)))), 125, (float)(700 - (50 * sin(4 * pi / 12))));
			glTexCoord2f(0.5f, .05f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(4 * pi / 12)))), 0, (float)(700 - (50 * sin(4 * pi / 12))));
			glEnd();
			//glFrontFace(GL_CCW);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.5f, 0.05f);		//
			glVertex3f((float)(-(50 * cos(4 * pi / 12))), 0, (float)(700 - (50 * sin(4 * pi / 12))));
			glTexCoord2f(0.5f, 0.95f);		//
			glVertex3f((float)(-(50 * cos(4 * pi / 12))), 125, (float)(700 - (50 * sin(4 * pi / 12))));
			glTexCoord2f(0.2f, 0.76f);	//
			glVertex3f(0, 95, 700);		//
			glTexCoord2f(0.2f, 0.05f);	//
			glVertex3f(0, 0, 700);		//
			glEnd();
		}
		//draw 5/6 way open
		if (d->timeOfDay == 1 || d->timeOfDay == (24 - 1))
		{
			fetchTexture("Volcano_Gate.jpg");
			glBegin(GL_POLYGON);
			glTexCoord2f(0.8f, 0.05f);	//
			glVertex3f(-100, 0, 700);	//
			glTexCoord2f(0.8f, 0.76f);	//
			glVertex3f(-100, 95, 700);	//
			glTexCoord2f(0.5f, .95f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(5 * pi / 12)))), 125, (float)(700 - (50 * sin(5 * pi / 12))));
			glTexCoord2f(0.5f, .05f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(5 * pi / 12)))), 0, (float)(700 - (50 * sin(5 * pi / 12))));
			glEnd();
			//glFrontFace(GL_CCW);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.5f, 0.05f);		//
			glVertex3f((float)(-(50 * cos(5 * pi / 12))), 0, (float)(700 - (50 * sin(5 * pi / 12))));
			glTexCoord2f(0.5f, 0.95f);		//
			glVertex3f((float)(-(50 * cos(5 * pi / 12))), 125, (float)(700 - (50 * sin(5 * pi / 12))));
			glTexCoord2f(0.2f, 0.76f);	//
			glVertex3f(0, 95, 700);		//
			glTexCoord2f(0.2f, 0.05f);	//
			glVertex3f(0, 0, 700);		//
			glEnd();
		}
		//draw 6/6 way open -- FULLY OPEN + FULL BEAM
		if (d->timeOfDay == 0 || d->timeOfDay == (24 - 0))
		{
	
			//glMaterialfv(GL_FRONT, GL_EMISSION, mat);
			fetchTexture("Volcano_Gate.jpg");
			glBegin(GL_POLYGON);
			glTexCoord2f(0.8f, 0.05f);	//
			glVertex3f(-100, 0, 700);	//
			glTexCoord2f(0.8f, 0.76f);	//
			glVertex3f(-100, 95, 700);	//
			glTexCoord2f(0.5f, .95f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(6 * pi / 12)))), 125, (float)(700 - (50 * sin(6 * pi / 12))));
			glTexCoord2f(0.5f, .05f);		//
			glVertex3f((float)(-50 - (50 - (50 * cos(6 * pi / 12)))), 0, (float)(700 - (50 * sin(6 * pi / 12))));
			glEnd();
			//glFrontFace(GL_CCW);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.5f, 0.05f);		//
			glVertex3f((float)(-(50 * cos(6 * pi / 12))), 0, (float)(700 - (50 * sin(6 * pi / 12))));
			glTexCoord2f(0.5f, 0.95f);		//
			glVertex3f((float)(-(50 * cos(6 * pi / 12))), 125, (float)(700 - (50 * sin(6 * pi / 12))));
			glTexCoord2f(0.2f, 0.76f);	//
			glVertex3f(0, 95, 700);		//
			glTexCoord2f(0.2f, 0.05f);	//
			glVertex3f(0, 0, 700);		//
			glEnd();
		}

		//draw black entrance facade
		static unsigned int groundShader = 0;
		static bool triedGoundShader = false;
		
		if (!groundShader && !triedGoundShader) {
			triedGoundShader = true;
			char* error;
			if (!(groundShader = loadShader("groundShader.vert", "groundShader.frag", error))) {
			std::string s = "Can't Load Ground Shader:";
			s += error;
			//fl_alert(s.c_str());
			}
		}
		
		glUseProgram(groundShader);
		GLint u = glGetUniformLocation(groundShader, "timeOfDay");
		glUniform1f(u, d->timeOfDay);
		glColor3ub(20, 20, 20);
		glBegin(GL_POLYGON);
		glNormal3d(0, 0, -1);
		//glTexCoord2f(0.8, 0.05);
		glVertex3f(-100, 0, 730);
		//glTexCoord2f(0.8, 0.76);
		glVertex3f(-100, 95, 730);
		//glTexCoord2f(0.5, .95);
		glVertex3f(-50, 125, 730);
		//glTexCoord2f(0.2, 0.76);
		glVertex3f(0, 95, 730);
		//glTexCoord2f(0.2, 0.05);
		glVertex3f(0, 0, 730);
		glEnd();
		glUseProgram(0);
	}

	
	
	//entrance cavity
	glColor3ub(130, 20, 29);
	glBegin(GL_QUAD_STRIP);
	glNormal3d(1, 0, 0);
	glVertex3f(-100, 0, 700);
	glVertex3f(-100, 0, 800);
	glNormal3d(1, 0, 0);
	glVertex3f(-100, 95, 700);
	glVertex3f(-100, 95, 800);
	glNormal3d(0.375, 0.625, 0);
	glVertex3f(-50, 125, 700);
	glVertex3f(-50, 125, 800);
	glNormal3d(-0.375, -0.625, 0);
	glVertex3f(0, 95, 700);
	glVertex3f(0, 95, 800);
	glNormal3d(-1, 0, 0);
	glVertex3f(0, 0, 700);
	glVertex3f(0, 0, 800);
	glEnd();

}

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
StreetLight::StreetLight(double p) : poleZ(p)
{
	radius = 10;
}
void StreetLight::draw(DrawingState*)
{
  glColor3f(.6f,.5f,.3f);
  glBegin(GL_QUAD_STRIP);
  glNormal3d( 1, 0,0);
  glVertex3d( 1, 0,poleZ);
  glVertex3d( 1,20,poleZ);
  glNormal3d( 0, 0,1);
  glVertex3d( 0, 0,poleZ+1);
  glVertex3d( 0,20,poleZ+1);
  glNormal3d(-1, 0,0);
  glVertex3d(-1, 0,poleZ);
  glVertex3d(-1,20,poleZ);
  glNormal3d( 0, 0,-1);
  glVertex3d( 0, 0,poleZ-1);
  glVertex3d( 0,20,poleZ-1);
  glNormal3d( 1, 0,0);
  glVertex3d( 1, 0,poleZ);
  glVertex3d( 1,20,poleZ);
  glEnd();
  glBegin(GL_QUAD_STRIP);
  glNormal3d(0,1,0);
  glVertex3d( 0,21, 0);
  glVertex3d( 0,21, poleZ);
  glNormal3d(-.707,-.707, 0);
  glVertex3d(-1,20, 0);
  glVertex3d(-1,20, poleZ);
  glNormal3d(.707,-.707, 0);
  glVertex3d( 1,20, 0);
  glVertex3d( 1,20, poleZ);
  glNormal3d(0,1,0);
  glVertex3d( 0,21, 0);
  glVertex3d( 0,21, poleZ);
	glEnd();
}

void StreetLight::drawAfter(DrawingState* d)
{
  int tod = d->timeOfDay;
  bool daytime;
  if (tod >=6 && tod <= 19)
	daytime = true;
  else 
	daytime = false;

  if (!daytime) {

	// glEnable(GL_BLEND);
	// glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA);
	float cone_length = 20;
	float radius = 10;
	float theta,dtheta = pi/16;
	int c;

	float norm[3];
	float sum;
	// Beam One
	glPushMatrix();
			
	glFrontFace(GL_CW);
			
	glBegin(GL_TRIANGLE_FAN);
	glColor4f(1,1,0,.8f);
	glVertex3f(0,cone_length,0);
	for ( c=0,theta = 0.0 ; c <= 32  ; theta += dtheta, c++ ) {
	  float z = sin(theta) * radius;
	  float x = cos(theta) * radius;
	  glColor4f(1,1,0,.2f);
	
	  norm[0] = 0; norm[1] = x; norm[2] = z; sum = norm[0] + norm[1] + norm[2];
	  norm[0] /= sum; norm[1] /= sum; norm[2] /= sum;				
	  glNormal3f( norm[0],norm[1],norm[2]);
	
	  glVertex3f( x, cone_length/6, z );
	}  
			
	glEnd();

			
	glPopMatrix();

	//glDisable(GL_BLEND);
	glClearColor(1,1,1,1);

  }
}

/**********************************************************************/
Sign::Sign(float sxi, float syi, float hi, char* tex, 
		   SignShape ss)
  : sx(sxi), sy(syi), h(hi), texName(tex), shape(ss)
{
}
void Sign::draw(DrawingState*)
{
	/*
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_MODULATE);
  fetchTexture(texName);
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glColor3f(1,1,1);
  drawShape(0);
  glEnd();
  // back of the sign
  glBindTexture(GL_TEXTURE_2D,0);
  glNormal3f(0,0,-1);
  drawShape(-.1f);
  // post
  glBegin(GL_POLYGON);
    glNormal3f(0,0,1);
	glVertex3f(-.1f,h,0);
	glVertex3f( .1f,h,0);
	glVertex3f( .1f,0,0);
	glVertex3f(-.1f,0,0);
  glEnd();
  glFrontFace(GL_CW);
  glBegin(GL_POLYGON);
    glNormal3f(0,0,1);
	glVertex3f(-.1f,h,-.05f);
	glVertex3f( .1f,h,-.05f);
	glVertex3f( .1f,0,-.05f);
	glVertex3f(-.1f,0,-.05f);
  glEnd();
  glFrontFace(GL_CCW);	
  */
}
void Sign::drawShape(float z)
{
  glFrontFace(GL_CW);
  switch(shape) {
  case rectangle:
	glBegin(GL_POLYGON);
	glTexCoord2f(0.,0.); glVertex3f(-sx/2,h,z);
	glTexCoord2f(1.,0.); glVertex3f( sx/2,h,z);
	glTexCoord2f(1.,1.); glVertex3f( sx/2,h+sy,z);
	glTexCoord2f(0.,1.); glVertex3f(-sx/2,h+sy,z);
	glEnd();
	break;
  case octagon:
	glBegin(GL_POLYGON);
	glTexCoord2f(0.25f,0.f); glVertex3f(-sx/4,h,z);
	glTexCoord2f(0.75f,0.f); glVertex3f( sx/4,h,z);
	glTexCoord2f(1.f,.25f); glVertex3f( sx/2.f,h+    sy/4.f,z);
	glTexCoord2f(1.f,.75f); glVertex3f( sx/2.f,h+3.f*sy/4.f,z);
	glTexCoord2f(.75f,1); glVertex3f( sx/4,h+sy,z);
	glTexCoord2f(.25f,1); glVertex3f(-sx/4,h+sy,z);
	glTexCoord2f(0,.75f); glVertex3f(-sx/2.f,h+3.f*sy/4.f,z);
	glTexCoord2f(0,.25f); glVertex3f(-sx/2.f,h+sy/4.f,z);
	glEnd();
	break;
  case diamond:
	glBegin(GL_POLYGON);
	glTexCoord2f(0.45f, 0.f); glVertex3f(-sx/10,h,z);
	glTexCoord2f(0.55f, 0.f); glVertex3f( sx/10,h,z);
	glTexCoord2f(   1 ,.45f); glVertex3f( sx/2,h+9*sy/20.f,z);
	glTexCoord2f(   1 ,.55f); glVertex3f( sx/2,h+11*sy/20.f,z);
	glTexCoord2f(.55f, 1   ); glVertex3f( sx/10,h+sy,z);
	glTexCoord2f(.45f, 1   ); glVertex3f(-sx/10,h+sy,z);
	glTexCoord2f(   0 ,.55f); glVertex3f(-sx/2,h+11*sy/20.f,z);
	glTexCoord2f(   0 ,.45f); glVertex3f(-sx/2,h+ 9*sy/20.f,z);
	glEnd();
	break;
  };
  glFrontFace(GL_CCW);
}

// make the houses we create be from a set of colors
/////////////////////////////////////////
// stuff for all houses
static int houseColors[][3] = {
	{240,240,240}, {180,175,100}, 
	{200,100,100}, {147,144,244},
	{250,249,157}, {199,144,186}
};
int nHouseColors = 6;


////////////////////////////////////////////////////////////////////////
// draw a little suburban dream...
// a 100x200 lot...
SimpleLot::SimpleLot(int ht, int hc)  
{
  // make the things we want
  add(new Lawn(0,0,100,200),0,0,0,0);
  switch(ht % 3) {
  case 0: {
	  SimpleHouse1* h1 = new SimpleHouse1();
	  h1->color(houseColors[hc % nHouseColors]);
	  add(h1,50.,0,60.,0);
	  break; }
  case 1: {
	  SimpleHouse2* h2 = new SimpleHouse2();
	  h2->color(houseColors[hc% nHouseColors]);
	  add(h2,50.,0,60.,0);
	  break; }
  case 2: {
	  SimpleHouse3* h3 = new SimpleHouse3();
	  h3->color(houseColors[hc% nHouseColors]);
	  add(h3,50.,0,60.,0);
	  break; }
  } 
  add(new SimpleTree1(15,5), 10,0, 10,0);
  add(new SimpleTree1(15,5), 10,0,190,0);
  add(new SimpleTree1(15,5), 30,0,190,0);
  add(new SimpleTree1(15,5), 50,0,190,0);
  add(new SimpleTree1(15,5), 70,0,190,0);
}

/***********************************************************************/
// a set of houses going down the street
// the street is along the X axis from (0,0) to ( (nh+1)*100, 0)
SimpleSubdivision::SimpleSubdivision(int nh) 
{
	// street lights in front of every other house
	// alternate sides of the street
	for(int sl=0; sl<nh; sl ++) {
		add(new StreetLight(sl%2 ? 9 : -9), static_cast<float>(sl*100 + 25), 0, (float)((sl%2) ? 8 : -9));
	}
	
    // add houses - one on each side of the street
	for (int hc=0; hc<nh; hc++) {
		GrObject* g1 = new SimpleLot(rand(), rand());
		GrObject* g2 = new SimpleLot(rand(), rand());

		add(g1, (float) (hc*100)    ,0, 15, 0);
		add(g2, (float) (hc*100+100),0,-15,pi);
	}

  add(new Sign(4,4,4,"stop.png",octagon),(float)(100*nh-2),0,17,-(3.141592f/2.f));
  add(new Sign(4,4,4,"stop.png",octagon),  2,0,-17 ,(3.141592f/2.f));
}


// $Header: /p/course/cs559-gleicher/private/CVS/GrTown/Examples/Suburbs.cpp,v 1.4 2010/11/17 22:50:22 gleicher Exp $
