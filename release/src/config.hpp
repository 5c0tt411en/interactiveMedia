#pragma once

namespace config {
    const bool DEBUG = false;
    const bool USE_DUMMY_DATA = false;
//    const int MACCHINE_ID = 0;
    const int WINDOW_ID = 0;
    const int OSC_POS_RECV_PORT = 60020;
    const int OSC_SCN_RECV_PORT = 60024;
    const int FPS = 30;
    const int DIVIDED_WIDTH = 800;
    const int WIDTH = 4 * DIVIDED_WIDTH;
    const int HEIGHT = 1280;
    const double ASPECT_RATIO = (double) WIDTH /  (double) HEIGHT;
};
