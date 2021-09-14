#include "AlcAIOApp.h"

void AlcAIOApp::init() {
    SerialBT.begin(AIO_BEAM_NAME);

    mDisplay = new AlcAIODisplay();
    mDisplay->init();
}

void AlcAIOApp::looper() {
    mDisplay->taskHandler();

    if (SerialBT.available()) {
        SerialBT.readBytes(serialData, 128);
        const char s[2] = ";";
        char* token;

        Serial.println(serialData);

        token = strtok(serialData, s);
        char* spliter[5];

        int i = 0;
        while (token != NULL) {
            spliter[i++] = token;
            token = strtok(NULL, s);
        }

        char toDisplayL1[16];
        sprintf(toDisplayL1, "%s %s", spliter[0], spliter[1]);

        Serial.println(toDisplayL1);

        char toDisplayL2[16];
        sprintf(toDisplayL2, "%s %sV %sC", spliter[2], spliter[3], spliter[4]);

        Serial.println(toDisplayL1);
    }
    delay(100);
}
