#version 440 core

uniform int pyramidColor;
out vec4 fragColor;

void main()
{
	if(pyramidColor < 2)
		fragColor = vec4(1.0, 0.0, 0.0, 1.0);
	else if (pyramidColor < 4 && pyramidColor >= 2 )
		fragColor = vec4(0.0, 1.0, 0.0, 1.0);
	else if (pyramidColor < 6 && pyramidColor >= 4 )
		fragColor = vec4(0.0, 0.0, 1.0, 1.0);

}