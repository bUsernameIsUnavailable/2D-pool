#include <collider2DComponent.h>
#include <engine.h>
#include <meshComponent.h>
#include <polygonData.h>
#include <rigidbody2DComponent.h>
#include <transformComponent.h>


namespace pool {
    static unsigned int totalDifferentIndices = 0u;

    static void createTable() {
        {
            const base::Entity &table = base::engine::createEntity();
            base::engine::addComponent(table, base::transformComponent());
            base::engine::addComponent(table, base::meshComponent{
                    .vertices = {
                            -60.0f, -30.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
                            60.0f, -30.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                            60.0f, 30.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                            -60.0f, 30.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
                    },
                    .indices = {
                            totalDifferentIndices, totalDifferentIndices + 1u, totalDifferentIndices + 2u,
                            totalDifferentIndices + 3u, totalDifferentIndices, totalDifferentIndices + 2u
                    }
            });

            totalDifferentIndices += 4u;
        }

        {
            const base::Entity &leftMargin = base::engine::createEntity();
            base::engine::addComponent(leftMargin, base::transformComponent());
            base::engine::addComponent(leftMargin, base::meshComponent{
                    .vertices = {
                            -60.0f, -25.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 0.0f, 0.0f,
                            -55.0f, -20.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 1.0f, 0.0f,
                            -55.0f, 20.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 1.0f, 1.0f,
                            -60.0f, 25.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 0.0f, 1.0f
                    },
                    .indices = {
                            totalDifferentIndices, totalDifferentIndices + 1u, totalDifferentIndices + 2u,
                            totalDifferentIndices + 3u, totalDifferentIndices, totalDifferentIndices + 2u
                    }
            });
            base::engine::addComponent(leftMargin, base::collider2DComponent{
                    .points = {
                            {-60.0f, -25.0f},
                            {-55.0f, -20.0f},
                            {-55.0f, 20.0f},
                            {-60.0f, 25.0f}
                    }
            });
            base::engine::addComponent(leftMargin, base::rigidbody2DComponent());

            totalDifferentIndices += 4u;
        }

        {
            const base::Entity &rightMargin = base::engine::createEntity();
            base::engine::addComponent(rightMargin, base::transformComponent());
            base::engine::addComponent(rightMargin, base::meshComponent{
                    .vertices = {
                            60.0f, -25.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 0.0f, 0.0f,
                            60.0f, 25.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 1.0f, 0.0f,
                            55.0f, 20.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 1.0f, 1.0f,
                            55.0f, -20.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 0.0f, 1.0f
                    },
                    .indices = {
                            totalDifferentIndices, totalDifferentIndices + 1u, totalDifferentIndices + 2u,
                            totalDifferentIndices + 3u, totalDifferentIndices, totalDifferentIndices + 2u
                    }
            });
            base::engine::addComponent(rightMargin, base::collider2DComponent{
                    .points = {
                            {60.0f, -25.0f},
                            {60.0f, 25.0f},
                            {55.0f, 20.0f},
                            {55.0f, -20.0f}
                    }
            });
            base::engine::addComponent(rightMargin, base::rigidbody2DComponent());

            totalDifferentIndices += 4u;
        }

        {
            const base::Entity &lowerMargin = base::engine::createEntity();
            base::engine::addComponent(lowerMargin, base::transformComponent());
            base::engine::addComponent(lowerMargin, base::meshComponent{
                    .vertices = {
                            -55.0f, -30.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 0.0f, 0.0f,
                            55.0f, -30.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 1.0f, 0.0f,
                            50.0f, -25.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 1.0f, 1.0f,
                            -50.0f, -25.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 0.0f, 1.0f
                    },
                    .indices = {
                            totalDifferentIndices, totalDifferentIndices + 1u, totalDifferentIndices + 2u,
                            totalDifferentIndices + 3u, totalDifferentIndices, totalDifferentIndices + 2u
                    }
            });
            base::engine::addComponent(lowerMargin, base::collider2DComponent{
                    .points = {
                            {-55.0f, -30.0f},
                            {55.0f,  -30.0f},
                            {50.0f,  -25.0f},
                            {-50.0f, -25.0f}
                    }
            });
            base::engine::addComponent(lowerMargin, base::rigidbody2DComponent());

            totalDifferentIndices += 4u;
        }

        {
            const base::Entity &upperMargin = base::engine::createEntity();
            base::engine::addComponent(upperMargin, base::transformComponent());
            base::engine::addComponent(upperMargin, base::meshComponent{
                    .vertices = {
                            -55.0f, 30.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 0.0f, 0.0f,
                            -50.0f, 25.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 1.0f, 0.0f,
                            50.0f, 25.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 1.0f, 1.0f,
                            55.0f, 30.0f, 0.0f, 1.0f, 0.64705882352f, 0.16470588235f, 0.16470588235f, 0.0f, 1.0f
                    },
                    .indices = {
                            totalDifferentIndices, totalDifferentIndices + 1u, totalDifferentIndices + 2u,
                            totalDifferentIndices + 3u, totalDifferentIndices, totalDifferentIndices + 2u
                    }
            });
            base::engine::addComponent(upperMargin, base::collider2DComponent{
                    .points = {
                            {-55.0f, 30.0f},
                            {-50.0f, 25.0f},
                            {50.0f,  25.0f},
                            {55.0f,  30.0f}
                    }
            });
            base::engine::addComponent(upperMargin, base::rigidbody2DComponent());

            totalDifferentIndices += 4u;
        }
    }

    static void createBalls() {
        const utils::polygonData whiteBallData(0.0f, 0.0f, 2.0f, 360u, totalDifferentIndices, 1.0f, 1.0f, 1.0f);
        const base::Entity& whiteBall = base::engine::createEntity();
        base::engine::addComponent(whiteBall, base::transformComponent());
        base::engine::addComponent(whiteBall, base::meshComponent {
                .vertices = whiteBallData.getVertices(),
                .indices = whiteBallData.getIndices()
        });
        base::engine::addComponent(whiteBall, base::collider2DComponent {
                .points = whiteBallData.getPoints()
        });
        base::engine::addComponent(whiteBall, base::rigidbody2DComponent {
                .velocity = { 0.02f, -0.004f },
                .mass = 5.0f
        });

        for (unsigned int index = 0u; index < 3u; ++index) {
            const utils::polygonData ballData(
                    10.0f + 6.0f * (float) index, 0.0f, 2.0f,
                    360u, totalDifferentIndices,
                    0.0f, 0.0f, 0.0f
            );
            const base::Entity& ball = base::engine::createEntity();
            base::engine::addComponent(ball, base::transformComponent());
            base::engine::addComponent(ball, base::meshComponent {
                    .vertices = ballData.getVertices(),
                    .indices = ballData.getIndices()
            });
            base::engine::addComponent(ball, base::collider2DComponent {
                    .points = ballData.getPoints()
            });
            base::engine::addComponent(ball, base::rigidbody2DComponent {
                    //.velocity = { -0.002f, (float) (2 * (index % 2) - 1) * 0.004f },
                    .velocity = { -0.002f, -0.004f },
                    .mass = 10.0f + (float) index * 3.0f
            });
        }
    }

    static void registerComponents() {
        base::engine::registerComponent<base::transformComponent>();
        base::engine::registerComponent<base::meshComponent>();
        base::engine::registerComponent<base::collider2DComponent>();
        base::engine::registerComponent<base::rigidbody2DComponent>();
    }

    static void registerSystems() {
        base::engine::registerSystem<base::renderSystem>(&base::renderSystem::getInstance());
        base::engine::registerSystem<base::collisionSystem>(&base::collisionSystem::getInstance());
        base::engine::registerSystem<base::movementSystem>(&base::movementSystem::getInstance());
    }

    static void setSystemSignatures() {
        base::Signature renderSignature;
        renderSignature.set(base::engine::getComponentType<base::transformComponent>());
        renderSignature.set(base::engine::getComponentType<base::meshComponent>());
        base::engine::setSystemSignature<base::renderSystem>(renderSignature);

        base::Signature collisionSignature;
        collisionSignature.set(base::engine::getComponentType<base::transformComponent>());
        collisionSignature.set(base::engine::getComponentType<base::rigidbody2DComponent>());
        collisionSignature.set(base::engine::getComponentType<base::collider2DComponent>());
        base::engine::setSystemSignature<base::collisionSystem>(collisionSignature);

        base::Signature movementSignature;
        movementSignature.set(base::engine::getComponentType<base::transformComponent>());
        movementSignature.set(base::engine::getComponentType<base::collider2DComponent>());
        movementSignature.set(base::engine::getComponentType<base::rigidbody2DComponent>());
        base::engine::setSystemSignature<base::movementSystem>(movementSignature);
    }

    static void createEntities() {
        createTable();
        createBalls();

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

    base::engine::play(base::windowManager::createWindowConfig()
        ->setArguments(argc, argv)
        ->setDisplayMode(GLUT_SINGLE | GLUT_RGB)
        ->setPosition(300, 50)
        ->setSize(1000, 750)
        ->setTitle("2D Pool")
    );

    return 0;
}
