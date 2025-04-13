#ifndef CHECK_DEVICE_H
#define CHECK_DEVICE_H

#include <libusb-1.0/libusb.h>
#include <stdint.h>
// defines all the constants for the keyboard
#define LOGITECH_VENDOR_ID 0x46d;
#define LOGITECH_PRDOCUCT_ID 0xfff; // exaample product id

// declare struct as a KeyboardIdentifier
typedef struct {
  uint16_t vendor_id;
  uint16_t product_id;
} KeyboardIdentifier;

int check_device(libusb_device_handle *dev, KeyboardIdentifier *keyboard_id);
#endif // ! CHECK_DEV
