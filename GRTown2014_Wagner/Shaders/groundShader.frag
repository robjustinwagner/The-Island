uniform float timeOfDay;
varying vec3 normal;

void main()
{
	float reducedTime = timeOfDay/24; 	
	vec3 mycolor =  reducedTime * vec3(.9,.1,.1) + vec3(.1,.1,.1);
	gl_FragColor = vec4(mycolor.x,mycolor.y,mycolor.z,1);
}