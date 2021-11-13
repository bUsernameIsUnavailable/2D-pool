#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "singleton.h"


namespace base {
    class engine : public utils::singleton<engine> {
        const class windowConfig* config;

    protected:
        static void onStart();
        static void render();
        static void cleanup();

    public:
        ~engine();

        void start(const class windowConfig*);
    };
}


#endif //GRAPHICS_ENGINE_H
