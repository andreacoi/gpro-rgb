#ifndef CHECK_DEVICE_H
#define CHECK_DEVICE_H

#include <libusb-1.0/libusb.h>
#include <stdint.h>
// defines all the constants for the keyboard
extern const uint16_t L_VENDOR_ID;
extern const uint16_t L_PRODUCT_ID;

int check_device(libusb_device_handle *dev);
#endif // ! CHECK_DEV
