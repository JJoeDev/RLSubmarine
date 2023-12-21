#pragma once

#include <raylib.h>

namespace fragMgr{
    class waterShader{
    public:
        waterShader(const char* shaderFile);
        ~waterShader();

        void RenderShader(float delta);

        inline void ManualUnloadShader() { UnloadShader(_waterShader); }

    private:
        Shader _waterShader;

        int _waterTimeLoc;
        float _time;
    };
}