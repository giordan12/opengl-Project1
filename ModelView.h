// ModelView.h - a basic combined Model and View for OpenGL

#ifndef MODELVIEW_H
#define MODELVIEW_H

class ShaderIF;

#include <string>

#ifdef __APPLE_CC__
#define GLFW_INCLUDE_GLCOREARB
#include "GLFW/glfw3.h"
#else
#include <GL/gl.h>
#endif

typedef float vec3[3];

class ModelView
{
public:
	ModelView();
	ModelView(float coordinates[][2]);
	virtual ~ModelView();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);
	void render() const;

	static void setMCRegionOfInterest(double xyz[6]);

private:
	// TODO: VAO(s), VBO(s), and other relevant INSTANCE variables
	GLuint vao[1];
	GLuint vbo[1];
	vec3 useColor[1];

	bool drawInBlack[1];
	bool visible[1];

	// we assume all instances share the same shader program:
	static ShaderIF* shaderIF;
	static int numInstances;
	static GLuint shaderProgram;
	
	// TODO: add uniform and attribute variable location CLASS variables

	static GLint ppuLoc_color;
	static GLint ppuLoc_scaleTrans;
	static GLint pvaLoc_mcPosition;

	// "pp": "per-primitive"; "pv": "per-vertex"
	static GLint ppUniformLocation(GLuint glslProgram, const std::string& name);
	static GLint pvAttribLocation(GLuint glslProgram, const std::string& name);

	// Routines for computing parameters necessary to map from arbitrary
	// model coordinate ranges into OpenGL's -1..+1 Logical Device Space.
	// 1. linearMap determines the scale and translate parameters needed in
	//    order to map a value, f (fromMin <= f <= fromMax) to its corresponding
	//    value, t (toMin <= t <= toMax). Specifically: t = scale*f + trans.
	static void linearMap(double fromMin, double fromMax,
		double toMin, double toMax, double& scale, double& trans);
	// 2. matchAspectRatio modifies (xmin,xmax) OR (ymin,ymax) to center that
	//    region in an expanded window that matches the given aspect ratio.
	static void matchAspectRatio(double& xmin, double& xmax,
		double& ymin, double& ymax, double vAR);
	// 3. compute2DScaleTrans uses the current model coordinate region of
	//    interest - modified as necessary to preserve aspect ratios - and
	//    then passes the modified limits to linearMap to compute the scale
	//    and translation needed to map MC to LDS.
	//    (The scales and translationes are returned in float[] because
	//    glUniform currently allows only float[].)
	static void compute2DScaleTrans(float* scaleTrans);

	static double mcRegionOfInterest[6];

	static void fetchGLSLVariableLocations();
};

#endif
