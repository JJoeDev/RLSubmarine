#include <iostream>
#include <raylib.h>

#include "ShaderManager.h"

namespace fragMgr {
    waterShader::waterShader(const char* shaderFile){
        _waterShader = LoadShader(0, shaderFile);
        _waterTimeLoc = GetShaderLocation(_waterShader, "time");
    }

    waterShader::~waterShader(){
        // Cant unload shader in destructor because CloseWindow() gets called before destructor.
    }

    void waterShader::RenderShader(float delta){
        _time += delta;

        SetShaderValue(_waterShader, _waterTimeLoc, &_time, SHADER_UNIFORM_FLOAT);

        BeginShaderMode(_waterShader); //This just renders the background lol
        DrawRectangle(0, 0, 800, 450, WHITE);
        EndShaderMode();
    }
}