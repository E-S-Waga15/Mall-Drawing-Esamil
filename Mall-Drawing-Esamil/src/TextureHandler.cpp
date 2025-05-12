// TextureHandler.cpp
#include "TextureHandler.h"
#include "texture.h"

TextureHandler::TextureHandler() {
    // Constructor implementation, if needed
}

TextureHandler& TextureHandler::Instance() {
    static TextureHandler instance;
    return instance;
}

void TextureHandler::LoadTextureByHandler(char *filename, int alpha) {
    GLuint textureID = LoadTextureFromFile(filename, alpha);
    textures.push_back(textureID);
}

GLuint TextureHandler::GetTexture(int index) const {
    if (index >= 0 && index < textures.size()) {
        return textures[index];
    } else {
        // Handle the out-of-bounds case, e.g., return a default texture ID.
        return 0;
    }
}

GLuint TextureHandler::LoadTextureFromFile(char *filename, int alpha) {
    // Your texture loading logic here
    // Return the OpenGL texture ID
	int texture  = LoadTexture(filename,alpha);
    return texture;
}

// Usage example:
// Load textures somewhere in your initialization
// TextureHandler::Instance().LoadTexture("texture1.bmp", 1);
// TextureHandler::Instance().LoadTexture("texture2.bmp", 1);

// Use textures in any class or function
// GLuint textureID = TextureHandler::Instance().GetTexture(0);
