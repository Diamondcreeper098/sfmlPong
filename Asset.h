//
// Created by seyed ali on 1/8/20.
// Game Assets: Fonts, Texture, sprites, musics and etc
//

#ifndef SFMLGAME_ASSET_H
#define SFMLGAME_ASSET_H


//This was giving me warnings about the strings being static and char*s:
//Static and constant identifiers fixes non-iso C++ warnings.
namespace Asset {
    namespace Fonts{
        namespace OpenSans{
            static const char* Regular = "Assets/Fonts/OpenSans/OpenSans-Regular.ttf";
            static const char* Bold = "Assets/Fonts/OpenSans/OpenSans-Bold.ttf";
            static const char* Italic = "Assets/Fonts/OpenSans/OpenSans-Italic.ttf";
            static const char* BoldItalic = "Assets/Fonts/OpenSans/OpenSans-BoldItalic.ttf";
        };
    };
    namespace Sound{
        static const char* Pong_E4 = "Assets/Sound/Pong_E4.wav";
        static const char* Pong_E5 = "Assets/Sound/Pong_E5.wav";
    };
};

//Another option is to do this:
namespace _Asset {
    namespace Fonts{
        namespace OpenSans{
            //They are undeclared here (external [extern]) and will 
            //be declared in the implementation file (the matching .cpp file):
            extern const char* Regular;
            extern const char* Bold;
            extern const char* Italic;
            extern const char* BoldItalic;
        };
    };
    namespace Sound{
        extern const char* Pong_E4;
        extern const char* Pong_E5;
    };
};

#endif //SFMLGAME_ASSET_H
