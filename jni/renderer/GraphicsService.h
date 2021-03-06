#ifndef GRAPHICSSERVICE_H
#define GRAPHICSSERVICE_H

#include <string>
#include <vector>
#include <unordered_map>
#include "platform/CwqGL.h"

#include "base/Types.h"
#include "math/Mat4.h"
//#include "TextureCache.h"

class GraphicsSprite;
class Shader;
class TextureShader;

class GraphicsService {
public:
    static const int VBO_SIZE = 65536;
    static const int INDEX_VBO_SIZE = VBO_SIZE * 6 / 4;

    typedef std::vector<GraphicsSprite*> SpriteVector;
    typedef std::vector<GraphicsSprite*>::iterator SpriteVectorIterator;
    GraphicsService();
    ~GraphicsService();
    
    int getHeight() const;
    int getWidth() const;

    bool start(int width, int height);
    void end();
    //ms
    void update(int playedTime);

    void screenSizeChanged(int width, int height);

    GraphicsSprite* registerSprite(const std::string& filename);

    void addSprite(GraphicsSprite* pSprite);
    void removeSprite(GraphicsSprite* pSprite);

protected:

    void registerShader(Shader* pShader);
    void removeShader(Shader* pShader);

    void setupVBO();
    void mapBuffers();
    
    void drawBatchedQuads();

    void fillQuads(GraphicsSprite* pSprite, int playedTime);

private:
    int mWidth;
    int mHeight;

    TextureShader* mCommonShader;

    //TextureCache textureCache;

    SpriteVector mSprites;
    //std::vector<Shader*> mShaders;

    //for QuadCommand
    //sprite info
    V3F_C4F_T2F _quadVerts[VBO_SIZE];
    GLushort _quadIndices[INDEX_VBO_SIZE];
    //GLuint _quadVAO;
    GLuint _quadbuffersVBO[2]; //0: vertex  1: indices
    int _numberQuads;

    Mat4 vMat;
    Mat4 pMat;
    Mat4 mvpMat;

    //for TextureCache, must less than TextureCache::MAX_CACHE
    static int cacheNum;
    int cacheIndex;

    bool started;

};

#endif // !GRAPHICSSERVICE_H
