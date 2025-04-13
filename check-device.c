#include "check-device.h"
#include <stdio.h>

int check_device(libusb_device_handle *dev, KeyboardIdentifier *keyboard_id) {
  uint16_t vendor_id, product_id;
  int ret;

  // Get the device descriptor
  struct libusb_device_descriptor desc;
  ret = libusb_get_device_descriptor(libusb_get_device(dev), &desc);
  if (ret < 0) {
    fprintf(stderr, "Failed to get device descriptor: %s\n",
            libusb_error_name(ret));
    return -1;
  }

  // Check if the device matches the keyboard identifier
  vendor_id = desc.idVendor;
  product_id = desc.idProduct;

  if (vendor_id == keyboard_id->vendor_id &&
      product_id == keyboard_id->product_id) {
    return 1; // Device matches
  } else {
    return 0; // Device does not match
  }
}
