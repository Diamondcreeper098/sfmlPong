//
// Created by seyed ali on 1/8/20.
//

#include "Asset.h"

//This is where we actually declare the char*'s content.
//Notice how you have to put the type before the name, even though
//the variable has been defined.
namespace _Asset {
    namespace Fonts{
        namespace OpenSans{
            const char* Regular = "Assets/Fonts/OpenSans/OpenSans-Regular.ttf";
            const char* Bold = "Assets/Fonts/OpenSans/OpenSans-Bold.ttf";
            const char* Italic = "Assets/Fonts/OpenSans/OpenSans-Italic.ttf";
            const char* BoldItalic = "Assets/Fonts/OpenSans/OpenSans-BoldItalic.ttf";
        };
    };
    namespace Sound{
        const char* Pong_E4 = "Assets/Sound/Pong_E4.wav";
        const char* Pong_E5 = "Assets/Sound/Pong_E5.wav";
    };
};