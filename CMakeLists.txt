cmake_minimum_required(VERSION 3.27)
project(DXLibTemplate)

set(CMAKE_CXX_STANDARD 17)

include_directories(./dxlib)
link_directories(./dxlib)

add_executable(DXLibTemplate main.cpp
        Game.cpp
        Game.hpp
        GameObjects/GameObject.cpp
        GameObjects/GameObject.hpp
        Commons/Vector2.cpp
        Commons/Vector2.hpp
        Components/Component.cpp
        Components/Component.hpp
        Components/SpriteComponent.cpp
        Components/SpriteComponent.hpp
        Commons/Math.hpp
        Scenes/Scene.cpp
        Scenes/Scene.hpp
        Scenes/TestScene.cpp
        Scenes/TestScene.hpp)

target_link_libraries(
        DXLibTemplate
        DxLib
        DxUseCLib
        DxDrawFunc
        jpeg
        png
        zlib
        tiff
        theora_static
        vorbis_static
        vorbisfile_static
        ogg_static
        bulletdynamics
        bulletcollision
        bulletmath
        opusfile
        opus
        silk_common
        celt
)