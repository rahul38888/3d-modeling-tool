cmake_minimum_required(VERSION 3.29)
project(3d_modeling_tool)

set(CMAKE_CXX_STANDARD 20)

add_executable(3d_modeling_tool
        main.cpp
        GL/glui.cpp
        GL/glut.h
        camera.h
        control_info.h
        create_object.h
        dat_stuct.h
        default_objects.h
        gravity_physics.h
        hello.cpp
        includedlibs.h
        initVariables.h
        light.h
        load_file.h
        minecraft_mode.h
        object_draw.h
        save_file.h
        shaderReader.h
        splines.h
        text_info.h
        texture.h
)
