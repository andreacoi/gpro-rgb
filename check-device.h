#ifndef CHECK_DEVICE_H
#define CHECK_DEVICE_H

#include <libusb-1.0/libusb.h>
#include <stdint.h>
// defines all the constants for the keyboard
extern const uint16_t VENDOR_ID;
extern const uint16_t PRODUCT_ID;

// declare struct as a KeyboardIdentifier
typedef struct {
  uint16_t product_id;
  uint16_t vendor_id;
} KeyboardIdentifier;

int check_device(libusb_device_handle *dev, KeyboardIdentifier *keyboard_id);
#endif // ! CHECK_DEV
