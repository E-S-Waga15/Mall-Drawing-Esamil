// TextureHandler.h
#ifndef TEXTURE_HANDLER_H
#define TEXTURE_HANDLER_H

#include <vector>
#include <string>
#include <glut.h>

class TextureHandler {
public:
    static TextureHandler& Instance();

    void LoadTextureByHandler(char *filename, int alpha);
    GLuint GetTexture(int index) const;

private:
    TextureHandler(); // Make the constructor private

    GLuint LoadTextureFromFile(char *filename, int alpha);

    std::vector<GLuint> textures;
};

#endif // TEXTURE_HANDLER_H

