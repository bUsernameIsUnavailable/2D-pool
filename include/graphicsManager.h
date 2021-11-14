#ifndef INC_2D_POOL_GRAPHICSMANAGER_H
#define INC_2D_POOL_GRAPHICSMANAGER_H

#include "singleton.h"
#include "windowConfig.h"

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>


namespace base {
    class graphicsManager : public utils::singleton<graphicsManager> {
        static GLuint vaoId;
        static GLuint vboId;
        static GLuint eboId;

        static std::vector<GLfloat> totalVertices;
        static std::vector<GLuint> totalIndices;

    public:
        static void createWindow(const windowConfig*);

        static void createVbo();
        static void destroyVbo();

        static void onStart();
        static void render();
        static void cleanup();
    };
}


#endif //INC_2D_POOL_GRAPHICSMANAGER_H
