#include <engine.h>
#include <meshComponent.h>
#include <renderSystem.h>
#include <transformComponent.h>

#include <fstream>
#include <SOIL.h>


namespace base {
    extern "C"
    void initialiseCallback() {
        renderSystem::getInstance().initialise();
    }

    extern "C"
    void renderCallback() {
        renderSystem::getInstance().render();
    }

    std::string renderSystem::vertexShader;
    std::string renderSystem::fragmentShader;

    GLuint renderSystem::vaoId;
    GLuint renderSystem::vboId;
    GLuint renderSystem::eboId;
    GLuint renderSystem::programId;

    std::vector<GLuint> renderSystem::textureIds;

    GLfloat renderSystem::screenWidth = 80.0f;
    GLfloat renderSystem::screenHeight = 60.0f;

    glm::mat4 renderSystem::currentTransform;
    glm::mat4 renderSystem::resizeMatrix;

    GLint renderSystem::currentTransformId;
    GLint renderSystem::colourCodeId;

    std::vector<GLfloat> renderSystem::totalVertices;
    std::vector<GLuint> renderSystem::totalIndices;


    void renderSystem::initialise() {
        std::printf("Initialising...\n");
        vertexShader = "../shaders/pool_shader.vert";
        fragmentShader = "../shaders/pool_shader.frag";

        textureIds = std::vector<GLuint>(maxEntityCount);

        resizeMatrix = glm::ortho(-screenWidth, screenWidth, -screenHeight, screenHeight);

        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

        createVbo();
        loadShaders();
        loadTextures();
    }

    void renderSystem::createWindow(const windowConfig* const config) {
        glutInit(config->getArgumentCount(), config->getArgumentVector());
        glutInitDisplayMode(config->getDisplayMode());
        glutInitWindowPosition(config->getPosition().x, config->getPosition().y);
        glutInitWindowSize(config->getSize().width, config->getSize().height);
        glutCreateWindow(config->getTitle().c_str());

        glewInit();
        initialiseCallback();
        glutDisplayFunc(renderCallback);
        glutReshapeFunc(renderSystem::reshapeWindow);
        glutCloseFunc(renderSystem::cleanup);
    }

    void renderSystem::update() {
        glutMainLoopEvent();
        glutPostRedisplay();
    }

    void renderSystem::render() {
        glClear(GL_COLOR_BUFFER_BIT);

        unsigned int index = 0u;
        size_t previousMeshIndexSize = 0u;

        for (const auto& entity : entities) {
            const auto& transform = engine::getComponent<transformComponent>(entity);
            const auto& mesh = engine::getComponent<meshComponent>(entity);

            glActiveTexture(GL_TEXTURE0 + index);
            glBindTexture(GL_TEXTURE_2D, textureIds[index]);

            currentTransform = resizeMatrix * transform.translation;
            currentTransformId = glGetUniformLocation(programId, "currentTransform");
            glUniformMatrix4fv(currentTransformId, 1u, GL_FALSE, &currentTransform[0u][0u]);

            colourCodeId = glGetUniformLocation(programId, "colourCode");
            glUniform1i(colourCodeId, (GLint) textureIds[index]);

            glDrawElements(
                    GL_TRIANGLES,
                    (GLsizei) mesh.indices.size(),
                    GL_UNSIGNED_INT,
                    (GLvoid*) (previousMeshIndexSize * sizeof(GLuint))
            );

            previousMeshIndexSize += mesh.indices.size();
            ++index;
        }

        glFlush();
    }

    void renderSystem::reshapeWindow(const GLint newWidth, const GLint newHeight) {
        windowConfig* const window = windowManager::getWindow();
        window->setSize(newWidth, newHeight);

        glViewport(0, 0, window->getSize().width, window->getSize().height);
    }

    void renderSystem::createVbo() {
        totalVertices.clear();
        totalIndices.clear();

        for (const auto& entity : entities) {
            const auto& mesh = engine::getComponent<meshComponent>(entity);

            totalVertices.insert(totalVertices.end(), mesh.vertices.begin(), mesh.vertices.end());
            totalIndices.insert(totalIndices.end(), mesh.indices.begin(), mesh.indices.end());
        }

        glGenBuffers(1u, &vboId);
        glGenBuffers(1u, &eboId);

        glGenVertexArrays(1u, &vaoId);
        glBindVertexArray(vaoId);

        const auto totalVertexSize = (GLsizeiptr) (totalVertices.size() * sizeof(GLfloat));
        const auto totalIndexSize = (GLsizeiptr) (totalIndices.size() * sizeof(GLuint));

        glBindBuffer(GL_ARRAY_BUFFER, vboId);
        glBufferData(GL_ARRAY_BUFFER, totalVertexSize, totalVertices.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, totalIndexSize, totalIndices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0u, 4u, GL_FLOAT, GL_FALSE, 9u * sizeof(GLfloat), nullptr);
        glVertexAttribPointer(1u, 3u, GL_FLOAT, GL_FALSE, 9u * sizeof(GLfloat), (GLvoid*) (4u * sizeof(GLfloat)));
        glVertexAttribPointer(2u, 2u, GL_FLOAT, GL_FALSE, 9u * sizeof(GLfloat), (GLvoid*) (7u * sizeof(GLfloat)));

        glEnableVertexAttribArray(0u);
        glEnableVertexAttribArray(1u);
        glEnableVertexAttribArray(2u);
    }

    void renderSystem::loadShaders() {
        const GLuint& vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
        const GLuint& fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertexShaderCode;
        std::ifstream vertexShaderStream(vertexShader, std::ios::in);
        if (vertexShaderStream.is_open())
        {
            std::string line;
            while (getline(vertexShaderStream, line))
            {
                vertexShaderCode += line + "\n";
            }
            vertexShaderStream.close();
        }

        std::string fragmentShaderCode;
        std::ifstream fragmentShaderStream(fragmentShader, std::ios::in);
        if (fragmentShaderStream.is_open())
        {
            std::string line;
            while (getline(fragmentShaderStream, line))
            {
                fragmentShaderCode += "\n" + line;
            }
            fragmentShaderStream.close();
        }

        printf("Compiling shader: %s\n", vertexShader.c_str());
        const char* const vertexSourcePointer = vertexShaderCode.c_str();
        glShaderSource(vertexShaderId, 1u, &vertexSourcePointer, nullptr);
        glCompileShader(vertexShaderId);

        printf("Compiling shader: %s\n", fragmentShader.c_str());
        const char* const fragmentSourcePointer = fragmentShaderCode.c_str();
        glShaderSource(fragmentShaderId, 1u, &fragmentSourcePointer, nullptr);
        glCompileShader(fragmentShaderId);

        fprintf(stdout, "Binding program...\n");
        programId = glCreateProgram();
        glAttachShader(programId, vertexShaderId);
        glAttachShader(programId, fragmentShaderId);
        glLinkProgram(programId);

        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);

        glUseProgram(0u);

        glDetachShader(programId, vertexShaderId);
        glDetachShader(programId, fragmentShaderId);

        glDeleteShader(fragmentShaderId);
        glDeleteShader(vertexShaderId);

        glUseProgram(programId);
    }

    void renderSystem::loadTextures() {
        unsigned int index = 0u;

        for (const auto& entity : entities) {
            const auto& mesh = engine::getComponent<meshComponent>(entity);

            glGenTextures(1u, &textureIds[index]);
            glBindTexture(GL_TEXTURE_2D, textureIds[index]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

            int imageWidth, imageHeight;
            unsigned char* const image = SOIL_load_image(
                    mesh.textureFile.c_str(),
                    &imageWidth,
                    &imageHeight,
                    nullptr,
                    SOIL_LOAD_RGB
            );

            glTexImage2D(GL_TEXTURE_2D,
                         0,
                         GL_RGB,
                         imageWidth,
                         imageHeight,
                         0,
                         GL_RGB,
                         GL_UNSIGNED_BYTE,
                         image
            );
            glGenerateMipmap(GL_TEXTURE_2D);

            SOIL_free_image_data(image);
            glBindTexture(GL_TEXTURE_2D, textureIds[index]);

            ++index;
        }

        textureIds.resize(index);
    }

    void renderSystem::cleanup() {
        std::printf("Cleaning up...\n");
        destroyShaders();
        destroyVbo();
        std::printf("Cleanup successful!\n\n");
    }

    void renderSystem::destroyShaders() {
        glDeleteProgram(programId);
    }

    void renderSystem::destroyVbo() {
        glDisableVertexAttribArray(2u);
        glDisableVertexAttribArray(1u);
        glDisableVertexAttribArray(0u);

        glBindBuffer(GL_ARRAY_BUFFER, 0u);
        glDeleteBuffers(1u, &eboId);
        glDeleteBuffers(1u, &vboId);

        glBindVertexArray(0u);
        glDeleteVertexArrays(1u, &vaoId);
    }
}
