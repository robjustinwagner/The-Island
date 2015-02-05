// Very simple shader for CS559 example code
// colors each face based on the normal vector
// so the vertex shader has to pass the normal vector

varying vec3 normal;

void main()
{
	//	gl_FragColor = vec4(1,0,0,1);
	vec3 mycolor = normal * .5 + vec3(.5,.5,.5);
	gl_FragColor = vec4(mycolor.x,mycolor.y,mycolor.z,1);
}





precision highp float;
uniform float time;
uniform vec2 resolution;
varying vec3 fPosition;
varying vec3 fNormal;
varying vec4 position;

// the ghostly, hallucinigenic dragon: crazy colors, fades in and out of lighting

void main()
{
 //provides directional lightiing, fades in and out based upon normal's direction vs directional lighting
  float directional_light = max(0.0, dot(fNormal, vec3(.707,0,0)));
    gl_FragColor = vec4(fNormal,1) * (.9*directional_light);
}