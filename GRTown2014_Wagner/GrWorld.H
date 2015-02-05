#ifndef GrWorld_H
#define GrWorld_H

/// GraphicsTown2006 - CS559 Sample Code
// written by Michael Gleicher - originally written Fall, 2000
// updated Fall, 2005
// updated Fall, 2008 - convert from linked lists to vectors
#include <vector>
#include "glm\glm.hpp"
//
// "the world" - framework for stuff to go into
//
class DrawingState;
class GrObject;

// the sky and "earth" are special objects, so we draw them
// differently - they are not GrObjects. 
// they always get drawn before all other objects
// draw sky gets called first, and is responsible for doing the clear
// 
void drawSky(DrawingState*);
void drawHorizonBox(DrawingState*);
void drawEarth(DrawingState*);
void drawWater(DrawingState*);

// basic lighting...
void setupLights(DrawingState*);

bool loadOBJ(const char * path,
	std::vector < glm::vec3 > & out_vertices,
	std::vector < glm::vec2 > & out_uvs,
	std::vector < glm::vec3 > & out_normals
	);

// all of the objects in the world, kept in a big linked list...
// except that now its a big stl vector
// and its defined in GrObject.H

// $Header: /p/course/cs559-gleicher/private/CVS/GrTown/GrWorld.H,v 1.3 2008/11/11 03:48:23 gleicher Exp $


#endif
