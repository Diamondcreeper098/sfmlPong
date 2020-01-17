//
// Created by seyed ali on 1/8/20.
// Game Assets: Fonts, Texture, sprites, musics and etc
//

#ifndef SFMLGAME_ASSET_H
#define SFMLGAME_ASSET_H


namespace Asset {
    namespace Fonts{
        namespace OpenSans{
            static char* Regular = "Assets/Fonts/OpenSans/OpenSans-Regular.ttf";
            static char* Bold = "Assets/Fonts/OpenSans/OpenSans-Bold.ttf";
            static char* Italic = "Assets/Fonts/OpenSans/OpenSans-Italic.ttf";
            static char* BoldItalic = "Assets/Fonts/OpenSans/OpenSans-BoldItalic.ttf";
        };
    };
    namespace Sound{
        static char* Pong_E4 = "Assets/Sound/Pong_E4.wav";
        static char* Pong_E5 = "Assets/Sound/Pong_E5.wav";
    };
};


#endif //SFMLGAME_ASSET_H
