#ifndef GRAPHICS_SINGLETON_H
#define GRAPHICS_SINGLETON_H


namespace utils {
    template<class T>
    class singleton {
    protected:
        singleton() = default;

    public:
        singleton(const T&) = delete;
        singleton(T&&) = delete;

        T& operator= (const T&) = delete;
        T& operator= (T&&) = delete;

        static T& getInstance() {
            static T instance;
            return instance;
        }
    };
}


#endif //GRAPHICS_SINGLETON_H
