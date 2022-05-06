/*
 *
 * Copyright (c) 2022 TheMrCerebro
 *
 * iRetro - Zlib license.
 *
 * This software is provided 'as-is', without any express or
 * implied warranty. In no event will the authors be held
 * liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute
 * it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 * you must not claim that you wrote the original software.
 * If you use this software in a product, an acknowledgment
 * in the product documentation would be appreciated but
 * is not required.
 *
 * 2. Altered source versions must be plainly marked as such,
 * and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any
 * source distribution.
 *
*/

#include <irrlicht.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace irr;
using namespace core;
using namespace video;
using namespace std;

//256x192
u32 ZXp[] = {
0x000000,
0x0000c0,
0xc00000,
0xc000c0,
0x00c000,
0x00c0c0,
0xc0c000,
0xc0c0c0,
0x000000,
0x0000ff,
0xff0000,
0xff00ff,
0x00ff00,
0x00ffff,
0xffff00,
0xffffff};

//280x192
u32 APPLE2p[] = {
0x000000,
0x6c2940,
0x403578,
0xd93cf0,
0x135740,
0x808080,
0x2697f0,
0xbfb4f8,
0x404b07,
0xd9680f,
0x808080,
0xeca8bf,
0x26c30f,
0xbfca87,
0x93d6bf,
0xffffff};

//160x100
u32 CGAp[] = {
0x000000,
0x0000aa,
0x00aa00,
0x00aaaa,
0xaa0000,
0xaa00aa,
0xaa5500,
0xaaaaaa,
0x555555,
0x5555ff,
0x55ff55,
0x55ffff,
0xff5555,
0xff55ff,
0xffff55,
0xffffff};

//160x144
u32 GBp[] = {
0x9bbc0f,
0x8bac0f,
0x306230,
0x0f380f};

//160x144
u32 GBCp[] = {
0x000000,
0x000000,
0xffad63,
0x833100,
0xffffff,
0xf7c4a5,
0x7bff30,
0x008300,
0x65a49b,
0x0000fe,
0xff8584,
0x943a3a,
0xe60000,
0xffe7c5,
0xce9c85,
0x846b29,
0x5b315b,
0xa56b31,
0x64a5ff,
0x8b8cde,
0x53528c,
0xa5a5a5,
0x525252,
0x949494,
0xfe9494,
0x9394fe,
0xffffa5,
0xff00fe,
0xffff00,
0xfe0000,
0x7d4900,
0xffff3a,
0x3a2802,
0x51ff00,
0xff4200,
0x0163c6,
0x008486,
0xffde00};

//256x192
u32 MSXp[] = {
0x000000,
0x010101,
0x24db24,
0x6dff6d,
0x2424ff,
0x496dff,
0xb62424,
0x49dbff,
0xff2424,
0xff6d6d,
0xdbdb24,
0xdbdb92,
0x249224,
0xdb49b6,
0xb6b6b6,
0xffffff};

//320x200
u32 C64p[] = {
0x000000,
0x626262,
0x898989,
0xadadad,
0xffffff,
0x9f4e44,
0xcb7e75,
0x6d5412,
0xa1683c,
0xc9d487,
0x9ae29b,
0x5cab5e,
0x6abfc6,
0x887ecb,
0x50459b,
0xa057a3};

//256x240
u32 NESp[] = {
0x000000,
0x000000,
0x797979,
0xa2a2a2,
0x305182,
0x4192c3,
0x61d3e3,
0xa2fff3,
0x306141,
0x49a269,
0x71e392,
0xa2ffcb,
0x386d00,
0x49aa10,
0x71f341,
0xa2f3a2,
0x386900,
0x51a200,
0x9aeb00,
0xcbf382,
0x495900,
0x8a8a00,
0xebd320,
0xfff392,
0x794100,
0xc37100,
0xffa200,
0xffdba2,
0xa23000,
0xe35100,
0xff7930,
0xffcbba,
0xb21030,
0xdb4161,
0xff61b2,
0xffbaeb,
0x9a2079,
0xdb41c3,
0xf361ff,
0xe3b2ff,
0x6110a2,
0x9241f3,
0xa271ff,
0xc3b2ff,
0x2800ba,
0x4141ff,
0x5182ff,
0xa2baff,
0x2000b2,
0x4161fb,
0x61a2ff,
0x92d3ff,
0x797979,
0xb2b2b2,
0xebebeb,
0xffffff};

//256x192
u32 SMSp[] = {
0x000000,
0x550000,
0xaa0000,
0xff0000,
0x005500,
0x555500,
0xaa5500,
0xff5500,
0x00aa00,
0x55aa00,
0xaaaa00,
0xffaa00,
0x00ff00,
0x55ff00,
0xaaff00,
0xffff00,
0x000055,
0x550055,
0xaa0055,
0xff0055,
0x005555,
0x555555,
0xaa5555,
0xff5555,
0x00aa55,
0x55aa55,
0xaaaa55,
0xffaa55,
0x00ff55,
0x55ff55,
0xaaff55,
0xffff55,
0x0000aa,
0x5500aa,
0xaa00aa,
0xff00aa,
0x0055aa,
0x5555aa,
0xaa55aa,
0xff55aa,
0x00aaaa,
0x55aaaa,
0xaaaaaa,
0xffaaaa,
0x00ffaa,
0x55ffaa,
0xaaffaa,
0xffffaa,
0x0000ff,
0x5500ff,
0xaa00ff,
0xff00ff,
0x0055ff,
0x5555ff,
0xaa55ff,
0xff55ff,
0x00aaff,
0x55aaff,
0xaaaaff,
0xffaaff,
0x00ffff,
0x55ffff,
0xaaffff,
0xffffff};

//320x200
u32 CPCp[] = {
0x000000,
0x000080,
0x0000ff,
0x800000,
0x800080,
0x8000ff,
0xff0000,
0xff0080,
0xff00ff,
0x008000,
0x008080,
0x0080ff,
0x808000,
0x808080,
0x8080ff,
0xff8000,
0xff8080,
0xff80ff,
0x00ff00,
0x00ff80,
0x00ffff,
0x80ff00,
0x80ff80,
0x80ffff,
0xffff00,
0xffff80,
0xffffff};

//160x192
u32 A2600[] = {
0x000000,
0x000000,
0x805800,
0x445c00,
0x703400,
0x006414,
0x700014,
0x005c5c,
0x70005c,
0x003c70,
0x580070,
0x002070,
0x3c0080,
0x000088,
0x000000,
0x000000,
0x404040,
0x404040,
0x947020,
0x5c7820,
0x885020,
0x208034,
0x882034,
0x207474,
0x842074,
0x1c5888,
0x6c2088,
0x1c3c88,
0x542094,
0x20209c,
0x404040,
0x404040,
0x6c6c6c,
0x6c6c6c,
0xa8843c,
0x74903c,
0xa0683c,
0x3c9850,
0xa03c50,
0x3c8c8c,
0x943c88,
0x3874a0,
0x803ca0,
0x3858a0,
0x6c3ca8,
0x3c3cb0,
0x6c6c6c,
0x6c6c6c,
0x909090,
0x909090,
0xbc9c58,
0x8cac58,
0xb48458,
0x58b06c,
0xb4586c,
0x58a4a4,
0xa8589c,
0x508cb4,
0x9458b4,
0x5074b4,
0x8058bc,
0x5858c0,
0x909090,
0x909090,
0xb0b0b0,
0xb0b0b0,
0xccac70,
0xa0c070,
0xc89870,
0x70c484,
0xc87084,
0x70b8b8,
0xb470b0,
0x68a4c8,
0xa470c8,
0x6888c8,
0x9470cc,
0x7070d0,
0xb0b0b0,
0xb0b0b0,
0xc8c8c8,
0xc8c8c8,
0xdcc084,
0xb0d484,
0xdcac84,
0x84d89c,
0xdc849c,
0x84c8c8,
0xc484c0,
0x7cb8dc,
0xb484dc,
0x7ca0dc,
0xa884dc,
0x8484e0,
0xc8c8c8,
0xc8c8c8,
0xdcdcdc,
0xdcdcdc,
0xecd09c,
0xc0e89c,
0xecc09c,
0x9ce8b4,
0xec9cb4,
0x9cdcdc,
0xd09cd0,
0x90ccec,
0xc49cec,
0x90b4ec,
0xb89cec,
0x9c9cec,
0xdcdcdc,
0xdcdcdc,
0xececec,
0xececec,
0xfce0b0,
0xd4fcb0,
0xfcd4b0,
0xb0fcc8,
0xfcb0c8,
0xb0ecec,
0xe0b0e0,
0xa4e0fc,
0xd4b0fc,
0xa4c8fc,
0xc8b0fc,
0xb0b0fc,
0xececec,
0xececec};

int main()
{
    cout << "          ___   ______    _______  _______  ______    _______ " << endl;
    cout << "         |   | |    _ |  |       ||       ||    _ |  |       |" << endl;
    cout << "         |   | |   | ||  |    ___||_     _||   | ||  |   _   |" << endl;
    cout << "         |   | |   |_||_ |   |___   |   |  |   |_||_ |  | |  |" << endl;
    cout << "         |   | |    __  ||    ___|  |   |  |    __  ||  |_|  |" << endl;
    cout << "         |   | |   |  | ||   |___   |   |  |   |  | ||       |" << endl;
    cout << "         |___| |___|  |_||_______|  |___|  |___|  |_||_______|" << endl;
    cout << " (o)===============================================================(o)" << endl;
    cout << "          - IMAGE CONVERTER TO RETRO STYLE [by TheMrCerebro] -" << endl;
    cout << " (o)===============================================================(o)" << endl;
    cout << endl;
    cout << "     With this tool you can convert the color palette of any image" << endl;
    cout << "      to a specific one used by game consoles and older computers," << endl;
    cout << "                       as well as its resolution." << endl;
    cout << endl;

    cout << " File: ";

    std::string path;
    getline(cin,path);

    // Elimina las comillas (") de la ruta del archivo
    path.erase(std::remove(path.begin(), path.end(), '\"'), path.end());

    cout << endl;

    cout << " Select the Palette:" << endl;
    cout << "   (1) - Game Boy" << endl;
    cout << "   (2) - NES" << endl;
    cout << "   (3) - Game Boy Color" << endl;
    cout << "   (4) - Commodore 64" << endl;
    cout << "   (5) - MSX" << endl;
    cout << "   (6) - CGA" << endl;
    cout << "   (7) - APPLE 2" << endl;
    cout << "   (8) - ZX Spectrum" << endl;
    cout << "   (9) - Master System" << endl;
    cout << "   (10) - Amstrad CPC" << endl;
    cout << "   (11) - Atari 2600" << endl;
    u32 palette;
    cin >> palette;

    cout << endl;

    cout << " Old resolution? (y/n):" << endl;
    c8 res;
    cin >> res;

    cout << endl;
    cout << " Converting..." << endl;

    IrrlichtDevice *device = createDevice(video::EDT_OPENGL, dimension2du(1,1));

    video::IVideoDriver* driver = device->getVideoDriver();

    //
    video::ITexture* img = driver->getTexture(path.c_str());

    core::array<u32> pixA;
    u32 w1 = img->getSize().Width, h1 = img->getSize().Height, w2 = 0, h2 = 0;

    switch(palette)
    {
    case 1: pixA.set_pointer(GBp,4); w2=160; h2=144; break;
    case 2: pixA.set_pointer(NESp,56); w2=256; h2=240; break;
    case 3: pixA.set_pointer(GBCp,38); w2=160; h2=144; break;
    case 4: pixA.set_pointer(C64p,16); w2=320; h2=200; break;
    case 5: pixA.set_pointer(MSXp,16); w2=256; h2=192; break;
    case 6: pixA.set_pointer(CGAp,16); w2=160; h2=100; break;
    case 7: pixA.set_pointer(APPLE2p,16); w2=280; h2=192; break;
    case 8: pixA.set_pointer(ZXp,16); w2=256; h2=192; break;
    case 9: pixA.set_pointer(SMSp,64); w2=256; h2=192; break;
    case 10: pixA.set_pointer(CPCp,27); w2=320; h2=200; break;
    case 11: pixA.set_pointer(A2600,128); w2=160; h2=192; break;
    }

    // CONVERT
    u32 *p = (u32*)img->lock();

    for(u32 pixel=0; pixel<w1*h1; ++pixel)
    {
        u32 inR = (p[pixel] >> 16) & 0xff;
        u32 inG = (p[pixel] >> 8) & 0xff;
        u32 inB = p[pixel] & 0xff;

        s32 minColorDistance = 100000;

        for(u32 i=0; i<pixA.size(); ++i)
        {
            u32 tmpR = (pixA[i] >> 16) & 0xff;
            u32 tmpG = (pixA[i] >> 8) & 0xff;
            u32 tmpB = pixA[i] & 0xff;

            //treat colors as 3D points and get distance between them to find closest color
            f32 colorDistance = core::vector3df(inR,inG,inB).getDistanceFromSQ(core::vector3df(tmpR,tmpG,tmpB));

            if(colorDistance < minColorDistance)
            {
                p[pixel] = pixA[i];
                minColorDistance = colorDistance;
            }
        }
    }

    img->unlock();

    // RESIZE
    video::IImage* imgw =0;

    if(res=='y')
    {
        imgw = driver->createImage(video::ECF_A8R8G8B8, core::dimension2du(w2,h2));

        u32 *p2 = (u32*)imgw->lock();

        u32 x_ratio = (u32)((w1 << 16) / w2) + 1;
        u32 y_ratio = (u32)((h1 << 16) / h2) + 1;

        for(u32 i=0; i<h2; i++)
        {
            for(u32 j=0; j<w2; j++)
            {
                u32 x2 = (j * x_ratio) >> 16;
                u32 y2 = (i * y_ratio) >> 16;
                p2[(i * w2) + j] = p[(y2 * w1) + x2];
            }
        }

        imgw->unlock();
    }
    else
    {
        w2 = w1, h2 = h1;
        imgw = driver->createImage(img,core::vector2di(0,0),img->getSize());
    }

    cout << endl;

    if(driver->writeImageToFile(imgw,"img_retro.bmp"))
        cout << " Image saved" << endl;

    device->closeDevice();
    device->drop();

    cout << endl;
    system("pause");
    return 0;
}

