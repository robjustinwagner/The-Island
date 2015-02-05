/// GraphicsTown2006 - CS559 Sample Code
// written by Michael Gleicher - originally written Fall, 2000
// updated Fall, 2005
// updated Fall, 2006 - new texture manager, improvements for behaviors

// simple example behaviors - something to learn from
#include "../GrTown_PCH.H"
#include "../DrawUtils.H"
#include "Utilities/Texture.H"
#include "../MMatrix.H"
#include "../GrObject.H"

#include "SimpleBehaviors.H"

//////////////////////////////////////////////////////////////////////
// a trick - since we don't care much about what the rotation is (only
// the rate), we can tie the rotation to the absolute time
Spin::Spin(GrObject* o, float v) : Behavior(o), vel(v)
{
}
void Spin::simulateUntil(unsigned long t)
{
  // remember position
  float x = owner->transform[3][0];
  float y = owner->transform[3][1];
  float z = owner->transform[3][2];
  // set rotation based on time
  rotMatrix(owner->transform, 'y', vel * static_cast<float>(t));
  // put the position back
  owner->transform[3][0] = x;
  owner->transform[3][1] = y;
  owner->transform[3][2] = z;

  lastV = t;
}


Orbit::Orbit(GrObject* o, float v) : Behavior(o), vel(v)
{
}
void Orbit::simulateUntil(unsigned long t)
{
	//parametric circle eqn
	owner->transform[3][0] += -1 * cosf((float)(t / 1003));
	owner->transform[3][2] += 1 * sinf((float)(t / 1004));
	
	lastV = t;
}

//appear that object is floating
Float::Float(GrObject* o, float v) : Behavior(o), vel(v)
{
}
void Float::simulateUntil(unsigned long t)
{
	// remember position
	/*
	float x = owner->transform[3][0];
	float y = owner->transform[3][1];
	float z = owner->transform[3][2];
	*/

	// set transformation matrix based on time
	//vel * sinf(static_cast<float>(t))
	//transformMatrix(owner->transform, 1.f, (float)(vel * sinf(static_cast<float>(t))), 1.f, x, y, z);
	// put the position back
	owner->transform[3][0] += cosf((float)(t / 200));
	owner->transform[3][1] += 2 * sinf((float)(t/300));
	owner->transform[3][2] += cosf((float)(t / 100));
	
	lastV = t;
}

////////////////////////////////////////////////////////////////////////
ForwardAlways::ForwardAlways(GrObject* o, float v)
  : Behavior(o), vel(v)
{
}
void ForwardAlways::simulateUntil(unsigned long t)
{
  unsigned long dt = t - lastV;	// how long since last update
  float secs = ((float) dt) / 1000;	// convert ms to sec
  lastV = t;
  owner->transform[3][0] += owner->transform[2][0] * secs * vel;
  owner->transform[3][1] += owner->transform[2][1] * secs * vel;
  owner->transform[3][2] += owner->transform[2][2] * secs * vel;

  lastV = t;
}

////////////////////////////////////////////////////////////////////////
TurnAlways::TurnAlways(GrObject* o, float v)
  : Behavior(o), vel(v)
{
}
void TurnAlways::simulateUntil(unsigned long t)
{
  unsigned long dt = t - lastV;	// how long since last update
  float secs = ((float) dt) / 1000;	// convert ms to sec
  lastV = t;
  Matrix delta, newT;
  rotMatrix(delta,'Y',secs * vel);
  multMatrix(delta,owner->transform,newT);
  copyMatrix(newT,owner->transform);

  lastV = t;
}

// $Header: /p/course/cs559-gleicher/private/CVS/GrTown/Examples/SimpleBehaviors.cpp,v 1.3 2009/11/10 22:40:03 gleicher Exp $
