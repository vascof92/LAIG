uniform float time;
uniform float wavesFac;
uniform float speedFac;
uniform float waveSizeFac;

void main() 
{
	float Verx = gl_Vertex.x;
	float displacementY = sin(Verx*wavesFac + time * speedFac)*waveSizeFac;

	vec4 modifiedPosition = gl_ModelViewProjectionMatrix * gl_Vertex;
	modifiedPosition.y += displacementY;
	gl_Position =modifiedPosition ;
	gl_TexCoord[0]=gl_MultiTexCoord0;

}