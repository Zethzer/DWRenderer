#ifndef RENDERER_H
#define RENDERER_H

#include "opengl.h"

#include <QTime>

// GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"
#include "shader.h"
#include "texture.h"
#include "material.h"
#include "light.h"
#include "model.h"
#include "shapes.h"

class Renderer
{
public:
    Renderer(GLuint width, GLuint height, Camera *camera);
    ~Renderer();

    void initializeRenderer();
    void render(glm::mat4 view, glm::mat4 projection);
    void bindMatrix(ShaderProgram* shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);
	std::vector<Texture*> createTextures(int nbTexturesToCreate);
    void freeMemory();
    void reload();
    Camera *getCamera() const;
    void setCamera(Camera *camera);
    void setWidth(const GLfloat w);
    void setHeight(const GLfloat h);
	GLboolean getHdr() const;
	void setHdr(GLboolean hdr);
	GLfloat getExposure() const;
	void setExposure(GLfloat exposure);
	GLuint colorBuffers() const;
	void setColorBuffers(GLuint val);
	GLboolean bloom() const;
	void setBloom(GLboolean val);
	GLuint nbLights() const;
	void setNbLights(GLuint val);

private:
    // System
    GLuint m_screenWidth;
    GLuint m_screenHeight;
    Camera *m_camera;

	// For HDR and effects
	ShaderProgram *m_hdrShader;
	ShaderProgram *m_blurShader;
	GLuint m_nbColorBuffers;
	std::vector<Texture*> m_colorbuffers;
	GLboolean m_hdr;
	GLfloat m_exposure;
	GLboolean m_bloom;
	GLboolean m_horizontal;
	GLuint m_amount;
	GLuint m_pingPongFBO[2];
	std::vector<Texture*> m_pingPongBuffers;

    // For the scene
	Shapes *m_shapes;
	GLuint m_FBO;
    ShaderProgram *m_baseShader;
	Model *m_model;

    ShaderProgram *m_lightShader;
	GLuint m_nbLights;
    std::vector<Light*> m_lights;
};

#endif // RENDERER_H

