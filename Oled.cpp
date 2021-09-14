#include "Oled.h"

void Oled::updateScreen() {
    if(mAvailable) {
        mDisplay->clearDisplay();
        mDisplay->setTextSize(0.03);
        mDisplay->setTextColor(WHITE);
        mDisplay->setCursor(0,0);
        mDisplay->println(mDisplayContent[0] == nullptr ? " " : mDisplayContent[0]);
        mDisplay->println(mDisplayContent[1] == nullptr ? " " : mDisplayContent[1]);
        mDisplay->println(mDisplayContent[2] == nullptr ? " " : mDisplayContent[2]);
        mDisplay->println(mDisplayContent[3] == nullptr ? " " : mDisplayContent[3]);
        mDisplay->display();
    }
}

void Oled::init() {
    mDisplay = new Adafruit_SSD1306(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
    mDisplay->begin(SSD1306_SWITCHCAPVCC);
    mDisplay->clearDisplay();
    mAvailable = true;
}

void Oled::setTitle(char* str) {
    if(str != nullptr) {
        mDisplayContent[0] = str;
        updateScreen();
    }
}

void Oled::updateLine(uint8_t position, char* content) {
    if(position < 3 && content != nullptr) {
        mDisplayContent[position + 1] = content;    //prevent title change
        updateScreen();
    }
}

void Oled::updateLine(char* content) {
    if(content != nullptr) {
        mDisplayContent[3] = content;
        updateScreen();
    }
}

void Oled::println(char* content) {
    if(content != nullptr) {
        mDisplayContent[1] = mDisplayContent[2];
        mDisplayContent[2] = mDisplayContent[3];
        mDisplayContent[3] = content;
        updateScreen();
    }
}

void Oled::showContent() {
    if(mAvailable) {
        mDisplay->display();
        mDisplayShows = true;
    }
}

void Oled::clearDisplayContent() {
    if(mAvailable) {
        mDisplay->clearDisplay();
        mDisplayShows = false;
    }
}

void Oled::clearContent() {
    if(mAvailable) {
        mDisplayContent[1] = "";
        mDisplayContent[2] = "";
        mDisplayContent[3] = "";
        updateScreen();
    }
}

