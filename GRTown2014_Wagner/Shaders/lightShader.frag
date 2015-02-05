varying vec3 normal;

void main()
{

  	//float directional_light = normal* vec3(.707,0,0);
  	float directional_light = normal.x*0.707;
    gl_FragColor = vec4(normal,1) * (.9*directional_light);
}
