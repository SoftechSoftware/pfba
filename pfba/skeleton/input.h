//
// Created by cpasjuste on 11/01/17.
//

#ifndef _INPUT_H
#define _INPUT_H

#include <cstring>
#include <vector>

// TODO: enable custom axis mapping
#define JOY_AXIS_LX 0
#define JOY_AXIS_LY 1
#define JOY_AXIS_RX 2
#define JOY_AXIS_RY 3

#define PLAYER_COUNT 4

class Input {

public:

    enum Key {
        KEY_UP = 0x0001,
        KEY_DOWN = 0x0002,
        KEY_LEFT = 0x0004,
        KEY_RIGHT = 0x0008,
        KEY_COIN = 0x0010,
        KEY_START = 0x0020,
        KEY_FIRE1 = 0x0040,
        KEY_FIRE2 = 0x0080,
        KEY_FIRE3 = 0x0100,
        KEY_FIRE4 = 0x0200,
        KEY_FIRE5 = 0x0400,
        KEY_FIRE6 = 0x0800,
        KEY_QUIT = 0x1000,
        KEY_COUNT = 12 // don't parse KEY_QUIT
    };

    struct Player {
        int mapping[KEY_COUNT];
        unsigned int state;
        int dead_zone = 8000;
        bool enabled = false;
        void *custom = NULL;
    };

    // map keyboard to player 0
    struct Keyboard {
        int mapping[KEY_COUNT];
    };

    Input() {};

    virtual ~Input() {};

    virtual Player *Update(bool rotate = false) { return players; }; // to implement
    virtual int GetButton(int player) { return 0; }; // to implement
    virtual int Clear(int player) { return 0; }; // to implement

    void SetJoystickMapping(int player, int *mapping, int deadzone = 8000) {
        for(int i=0; i<KEY_COUNT; i++) {
            players[player].mapping[i] = mapping[i];
        }
        players[player].dead_zone = deadzone;
    }

    void SetKeyboardMapping(int *mapping) {
        for(int i=0; i<KEY_COUNT; i++) {
            keyboard.mapping[i] = mapping[i];
        }
    }

    Player players[PLAYER_COUNT];
    Keyboard keyboard;
};

#endif //_INPUT_H