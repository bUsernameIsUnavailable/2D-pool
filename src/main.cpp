#include <meshComponent.h>
#include <engine.h>
#include <renderSystem.h>
#include <windowManager.h>


namespace pool {
    static void registerComponents() {
        base::engine::registerComponent<base::meshComponent>();
    }

    static void registerSystems() {
        base::engine::registerSystem<base::renderSystem>(&base::renderSystem::getInstance());
    }

    static void setSystemSignatures() {
        base::Signature renderSignature;
        renderSignature.set(base::engine::getComponentType<base::meshComponent>());
        base::engine::setSystemSignature<base::renderSystem>(renderSignature);
    }

    static void createEntities() {
        const base::Entity& table = base::engine::createEntity();
        base::engine::addComponent(table, base::meshComponent {
            .vertices = {
                    -60.0f, -30.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
                     60.0f, -30.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                     60.0f,  30.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                    -60.0f,  30.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
            },

            .indices = {
                    0u, 1u, 2u,
                    3u, 0u, 2u
            }
        });

        /*
        std::vector<base::Entity> balls(16u);
        struct {
            GLfloat r = 1.0f;
            GLfloat g = 1.0f;
            GLfloat b = 1.0f;
        } colour;

        for (size_t index = 0u; index < balls.size(); ++index) {
            balls[index] = base::engine::createEntity();

            base::engine::addComponent(balls[index], base::meshComponent {
                .vertices = {
                        -5.0f, -5.0f, 0.0f, 1.0f, colour.r, colour.g, colour.b, 0.0f, 0.0f,
                         5.0f, -5.0f, 0.0f, 1.0f, colour.r, colour.g, colour.b, 1.0f, 0.0f,
                         5.0f,  5.0f, 0.0f, 1.0f, colour.r, colour.g, colour.b, 1.0f, 1.0f,
                        -5.0f,  5.0f, 0.0f, 1.0f, colour.r, colour.g, colour.b, 0.0f, 1.0f
                },

                .indices = {
                        0u, 1u, 2u,
                        3u, 0u, 2u
                }
            });
        }
        */
    }
}

int main(int argc, char** const argv) {
    base::engine::start();

    pool::registerComponents();
    pool::registerSystems();
    pool::setSystemSignatures();
    pool::createEntities();

    base::engine::play(base::windowManager::getInstance().createWindowConfig()
        ->setArguments(argc, argv)
        ->setDisplayMode(GLUT_SINGLE | GLUT_RGB)
        ->setPosition(300, 50)
        ->setSize(1000, 700)
        ->setTitle("2D Pool")
    );

    return 0;
}
