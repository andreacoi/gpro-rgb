#ifndef CHECK_DEVICE_H
#define CHECK_DEVICE_H

#include <libusb-1.0/libusb.h>
#include <stdint.h>

typedef struct {
  uint16_t vendor_id;
  uint16_t product_id;
} KeyboardIdentifier;
#endif // ! CHECK_DEV
