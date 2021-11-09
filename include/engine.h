#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H


#include "singleton.h"

#include <string>

namespace base {
    class engine : public utils::singleton<engine> {
    protected:
        unsigned int seed = 0u;

        unsigned int displayMode;
        std::string title;

        struct {
            int x;
            int y;
        } windowPosition;

        struct {
            int width;
            int height;
        } windowSize;

        static void onStart();
        static void render();
        static void cleanup();

    public:
        engine initialise(int*, char**) const;
        engine setDisplayMode(unsigned int);
        engine setWindowPosition(int, int);
        engine setWindowSize(int, int);
        engine createWindow(const char*);
        engine setSeed(unsigned int);
        void start(unsigned int = 0u);
    };
}


#endif //GRAPHICS_ENGINE_H
