/*
    eSPI Configuration:
        1.  #define ST7789_DRIVER
        2.  #define TFT_WIDTH  240 // ST7789 240 x 240 and 240 x 320
            #define TFT_HEIGHT 240 // ST7789 240 x 240
        3.  #define TFT_MISO 34
            #define TFT_MOSI 21
            #define TFT_SCLK 22
            #define TFT_CS   2  // Chip select control pin
            #define TFT_DC    12  // Data Command control pin
            #define TFT_RST   4  // Reset pin (could connect to RST pin)

    Rewrite rotation MADCTL for ST7789(C:\Users\Alcatraz\Documents\Arduino\libraries\TFT_eSPI\TFT_Drivers\ST7789_Rotation.h):
        case 4: // Flip
            writedata(TFT_MAD_MX);

    lvgl Configuration:
        #define LV_COLOR_DEPTH     16
*/

#include <lvgl.h>
#include <TFT_eSPI.h>

#include "Configuration.h"

class AlcAIODisplay {
public:
    static const uint32_t mScreenWidth = 240;
    static const uint32_t mScreenHeight = 240;

private:
    lv_obj_t* label1, * label2;

    lv_color_t mDisplayBufferArr[mScreenWidth * 10];
    lv_color_t mDisplayBufferArrSecondary[mScreenWidth * 10];
    lv_disp_draw_buf_t mDisplayBuffer;

public:
    void init();

    // Functions below must be called
    void taskHandler() { lv_task_handler(); /* let the GUI do its work */ }
    void ticker() { lv_tick_inc(1); }
};
