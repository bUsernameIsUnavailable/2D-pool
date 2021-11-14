#include <windowConfig.h>


namespace base {
    windowConfig* windowConfig::setArguments(int& argc, char** const argv) {
        argumentCount = &argc;
        argumentVector = argv;
        return this;
    }

    windowConfig* windowConfig::setDisplayMode(const unsigned int newDisplayMode) {
        displayMode = newDisplayMode;
        return this;
    }

    windowConfig* windowConfig::setPosition(const int newX, const int newY) {
        position.x = newX;
        position.y = newY;
        return this;
    }

    windowConfig* windowConfig::setSize(const int newWidth, const int newHeight) {
        size.width = newWidth;
        size.height = newHeight;
        return this;
    }

    windowConfig* windowConfig::setTitle(const char* const newTitle) {
        title = newTitle;
        return this;
    }
}
