#include "AlcAIOApp.h"

AlcAIOApp* mApplication;

void taskTicker(void* pvParameters);

void setup()
{
  Serial.begin(115200); /* prepare for possible serial debug */

  mApplication = new AlcAIOApp();
  mApplication->init();

  xTaskCreatePinnedToCore(
    taskTicker
    , "taskTicker"   // A name just for humans
    , 1024  // This stack size can be checked & adjusted by reading the Stack Highwater
    , NULL
    , 1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    , NULL
    , 0);
}

void loop()
{
  mApplication->looper();
}

void taskTicker(void* pvParameters) {
  (void)pvParameters;

  for (;;) {
    mApplication->tick();
    vTaskDelay(100); 
  }
}
