#include "AlcAIODisplay.h"

TFT_eSPI mTFTDrv;

/* Display flushing */
void displayFlush(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    mTFTDrv.startWrite();
    mTFTDrv.setAddrWindow(area->x1, area->y1, w, h);
    mTFTDrv.pushColors((uint16_t*)&color_p->full, w * h, true);
    mTFTDrv.endWrite();

    lv_disp_flush_ready(disp);
}

void AlcAIODisplay::init() {
    lv_init();

    mTFTDrv.begin();
    mTFTDrv.setRotation(4);

    lv_disp_draw_buf_init(&mDisplayBuffer,
        mDisplayBufferArr, mDisplayBufferArrSecondary, mScreenWidth * 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = mScreenWidth;
    disp_drv.ver_res = mScreenHeight;
    disp_drv.flush_cb = displayFlush;
    disp_drv.draw_buf = &mDisplayBuffer;
    lv_disp_drv_register(&disp_drv);

    /* Create simple label */
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Alc AIOPrototype");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    label1 = lv_label_create(lv_scr_act());
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, 20);

    label2 = lv_label_create(lv_scr_act());
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 40);
}
