uniform float time;
varying vec3 normal;

void main()
{
	float reducedTime = time/40; 
	vec3 mycolor = sin(reducedTime) * normal * .5 + vec3(.8,.6,.13);
	gl_FragColor = vec4(mycolor.x,mycolor.y,mycolor.z,1);
}
