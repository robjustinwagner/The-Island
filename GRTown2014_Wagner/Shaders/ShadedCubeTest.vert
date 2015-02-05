// Very simple shader for CS559 Example Code
// doesn't do much
//

varying vec3 normal;

void main()
{
	// inline comments should work
	gl_Position = ftransform();	// like this one
	normal = gl_Normal;
}






uniform mat3 normalMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform vec2 resolution;
uniform float time;
attribute vec4 color; 
varying vec4 pcolor;

attribute vec3 position;
attribute vec3 normal;

varying vec3 fNormal;
varying vec3 fPosition;
varying vec4 pos;

// the ghostly, hallucinigenic dragon: crazy colors, fades in and out of lighting

void main()
{
  // sets the normal to the abs(normal),thereby affecting how the lighting (and ultimately, color) shows up.
  fNormal = normalize(normalMatrix * abs(normal));
  //scales object which follows the abs value of the sin(time).. you can see the object slowly get smaller (to 0) then larger (to orignial size) but never flips over because pos never goes negative
  vec4 position = modelViewMatrix * vec4(position*abs(sin(time)), 0.75);
  fPosition += pos.xyz*vec3(0,dot(resolution, resolution), 0);
  //pcolor = color; 
  gl_Position = projectionMatrix * position;
}