#version 410 core

// replace the placeholder implementation here

in vec2 mcPosition; // vertex position; "mc" stands for "model coordinates"
uniform vec4 scaleTrans; // for mapping coordinates into Logical Device Space

void main()
{
//        xLDS =      sx      *  xMC        +      tx
	float ldsX = scaleTrans[0]*mcPosition.x + scaleTrans[1];

//        yLDS =      sy      *  yMC        +      ty
	float ldsY = scaleTrans[2]*mcPosition.y + scaleTrans[3];

	gl_Position = vec4(ldsX, ldsY, 0, 1);
}

