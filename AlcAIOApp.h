#include "BluetoothSerial.h"
#include "AlcAIODisplay.h"

class AlcAIOApp {
private:
    AlcAIODisplay* mDisplay;

    BluetoothSerial SerialBT;
    char serialData[128];

// All function below must be called
public:
    void init();
    void looper();
    void tick() { mDisplay->ticker(); }
};
