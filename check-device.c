#include "check-device.h"
#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <sys/types.h>

int check_device() {
  const uint16_t L_VENDOR_ID = 0x174f;  // Example vendor ID
  const uint16_t L_PRODUCT_ID = 0x1176; // Example vendor ID

  // initialize context for libusb
  libusb_context *ctx = NULL;
  // create a list of devices - iterable
  libusb_device **list = NULL;
  // initialize the context for libusb
  int r = libusb_init(&ctx);
  // get the list of devices
  ssize_t count_usb_devices = libusb_get_device_list(ctx, &list);
  printf("Dispositivi visibili da libusb: %zd\n", count_usb_devices);
  // iterate over the list of devices
  for (ssize_t i = 0; i < count_usb_devices; i++) {
    // initialize a struct lib device descriptor
    struct libusb_device_descriptor desc;
    // get the device libusb_device_descriptor - a struct that contains all the
    // information about the device
    int r = libusb_get_device_descriptor(list[i], &desc);
    printf("Dispositivo %zd → VID: %04x, PID: %04x\n", i, desc.idVendor,
           desc.idProduct);
    if (r < 0) {
      fprintf(stderr,
              "Errore nel leggere il descrittore del dispositivo %zd: %s\n", i,
              libusb_error_name(r));
      continue;
    }
    int ru = 0;
    // check if the device (my Logitech GPRO) is the device we are looking for
    if (desc.idVendor == L_VENDOR_ID && desc.idProduct == L_PRODUCT_ID) {
      fprintf(stderr, "Device found\n");
      // free the list of devices
      libusb_device_handle *handle;
      // open the device
      if (libusb_open(list[i], &handle) == 0) {
        fprintf(stderr, "Device opened\n");
        // close the device
        libusb_close(handle);
        ru = 1;
      } else {
        fprintf(stderr, "Error: Device not opened\n");
        ru = 0;
      };
      libusb_free_device_list(list, 1);
      // close the context
      libusb_exit(ctx);
      ru = 0;
    } else {
      fprintf(stderr, "Device not found\n");
      ru = 0;
    }
  }
  if (r < 0) {
    fprintf(stderr, "Error: libusb_init failed\n");
    int ru = 0;
  }
  return ru;
}
