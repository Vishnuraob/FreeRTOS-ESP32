#include "error_handler.h"
#include "esp_log.h"

static const char *TAG = "ERROR";

void error_handler(const char *msg)
{
    ESP_LOGE(TAG, "Error: %s", msg);
}
