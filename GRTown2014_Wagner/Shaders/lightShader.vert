varying vec3 normal;

void main()
{
	gl_Position = ftransform();
	normal = abs(gl_Normal);
}
