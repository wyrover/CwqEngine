#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include <string>
#include <GLES2/gl2.h>

#include "../GraphicsSprite.h"

class Shader
{
private:
    void LoadShader(GLenum shaderType, std::string& shaderCode);

protected:
    GLuint			m_vertexShaderId;
    GLuint			m_fragmentShaderId;
    GLint			m_programId;

    std::string		m_vertexShaderCode;
    std::string		m_fragmentShaderCode;

    bool			m_isLinked;

public:
    Shader();
    virtual ~Shader();

    virtual void Link();
    virtual void Setup(GraphicsSprite& sprite);

    bool IsLinked() { return m_isLinked; }
};


#endif // !RENDERER_SHADER_H
