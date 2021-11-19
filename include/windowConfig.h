#ifndef INC_2D_POOL_WINDOWCONFIG_H
#define INC_2D_POOL_WINDOWCONFIG_H

#include <string>


namespace base {
    class windowConfig final {
        int* argumentCount;
        char** argumentVector;

        unsigned int displayMode;

        struct WindowPosition {
            int x;
            int y;
        } position;

        struct WindowSize {
            int width;
            int height;
        } size;

        std::string title;

    public:
        windowConfig* setArguments(int&, char**);
        windowConfig* setDisplayMode(unsigned int);
        windowConfig* setPosition(int, int);
        windowConfig* setSize(int, int);
        windowConfig* setTitle(const char*);

        [[nodiscard]] inline int* getArgumentCount() const { return argumentCount; }
        [[nodiscard]] inline char** getArgumentVector() const { return argumentVector; }
        [[nodiscard]] inline const unsigned int& getDisplayMode() const { return displayMode; }
        [[nodiscard]] inline const WindowPosition& getPosition() const { return position; }
        [[nodiscard]] inline const WindowSize& getSize() const { return size; }
        [[nodiscard]] inline const std::string& getTitle() const { return title; }
    };
}


#endif //INC_2D_POOL_WINDOWCONFIG_H
