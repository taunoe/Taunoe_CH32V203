/********************************** (C) COPYRIGHT *******************************
 * File Name          : ch32v20x_usbfs_device.h
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : This file provides all the USBFS firmware functions.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/
#ifndef __CH32V20x_USBFS_DEVICE_H_
#define __CH32V20x_USBFS_DEVICE_H_

#include "debug.h"
#include "string.h"

#ifndef NULL
#define NULL                    0
#endif

#ifndef VOID
#define VOID                    void
#endif
#ifndef CONST
#define CONST                   const
#endif
#ifndef BOOL
typedef unsigned char           BOOL;
#endif
#ifndef BOOLEAN
typedef unsigned char           BOOLEAN;
#endif
#ifndef CHAR
typedef char                    CHAR;
#endif
#ifndef INT8
typedef char                    INT8;
#endif
#ifndef INT16
typedef short                   INT16;
#endif
#ifndef INT32
typedef long                    INT32;
#endif
#ifndef UINT8
typedef unsigned char           UINT8;
#endif
#ifndef UINT16
typedef unsigned short          UINT16;
#endif
#ifndef UINT32
typedef unsigned long           UINT32;
#endif
#ifndef UINT8V
typedef unsigned char volatile  UINT8V;
#endif
#ifndef UINT16V
typedef unsigned short volatile UINT16V;
#endif
#ifndef UINT32V
typedef unsigned long volatile  UINT32V;
#endif

#ifndef PVOID
typedef void                    *PVOID;
#endif
#ifndef PCHAR
typedef char                    *PCHAR;
#endif
#ifndef PCHAR
typedef const char              *PCCHAR;
#endif
#ifndef PINT8
typedef char                    *PINT8;
#endif
#ifndef PINT16
typedef short                   *PINT16;
#endif
#ifndef PINT32
typedef long                    *PINT32;
#endif
#ifndef PUINT8
typedef unsigned char           *PUINT8;
#endif
#ifndef PUINT16
typedef unsigned short          *PUINT16;
#endif
#ifndef PUINT32
typedef unsigned long           *PUINT32;
#endif
#ifndef PUINT8V
typedef volatile unsigned char  *PUINT8V;
#endif
#ifndef PUINT16V
typedef volatile unsigned short *PUINT16V;
#endif
#ifndef PUINT32V
typedef volatile unsigned long  *PUINT32V;
#endif


/* USB constant and structure define */

/* USB PID */
#ifndef USB_PID_SETUP
#define USB_PID_NULL            0x00    /* reserved PID */
#define USB_PID_SOF             0x05
#define USB_PID_SETUP           0x0D
#define USB_PID_IN              0x09
#define USB_PID_OUT             0x01
#define USB_PID_ACK             0x02
#define USB_PID_NAK             0x0A
#define USB_PID_STALL           0x0E
#define USB_PID_DATA0           0x03
#define USB_PID_DATA1           0x0B
#define USB_PID_PRE             0x0C
#endif

/* USB standard device request code */
#ifndef USB_GET_DESCRIPTOR
#define USB_GET_STATUS          0x00
#define USB_CLEAR_FEATURE       0x01
#define USB_SET_FEATURE         0x03
#define USB_SET_ADDRESS         0x05
#define USB_GET_DESCRIPTOR      0x06
#define USB_SET_DESCRIPTOR      0x07
#define USB_GET_CONFIGURATION   0x08
#define USB_SET_CONFIGURATION   0x09
#define USB_GET_INTERFACE       0x0A
#define USB_SET_INTERFACE       0x0B
#define USB_SYNCH_FRAME         0x0C
#endif

/* USB hub class request code */
#ifndef HUB_GET_DESCRIPTOR
#define HUB_GET_STATUS          0x00
#define HUB_CLEAR_FEATURE       0x01
#define HUB_GET_STATE           0x02
#define HUB_SET_FEATURE         0x03
#define HUB_GET_DESCRIPTOR      0x06
#define HUB_SET_DESCRIPTOR      0x07
#endif

/* USB HID class request code */
#ifndef HID_GET_REPORT
#define HID_GET_REPORT          0x01
#define HID_GET_IDLE            0x02
#define HID_GET_PROTOCOL        0x03
#define HID_SET_REPORT          0x09
#define HID_SET_IDLE            0x0A
#define HID_SET_PROTOCOL        0x0B
#endif

/* Bit define for USB request type */
#ifndef USB_REQ_TYP_MASK
#define USB_REQ_TYP_IN          0x80            /* control IN, device to host */
#define USB_REQ_TYP_OUT         0x00            /* control OUT, host to device */
#define USB_REQ_TYP_READ        0x80            /* control read, device to host */
#define USB_REQ_TYP_WRITE       0x00            /* control write, host to device */
#define USB_REQ_TYP_MASK        0x60            /* bit mask of request type */
#define USB_REQ_TYP_STANDARD    0x00
#define USB_REQ_TYP_CLASS       0x20
#define USB_REQ_TYP_VENDOR      0x40
#define USB_REQ_TYP_RESERVED    0x60
#define USB_REQ_RECIP_MASK      0x1F            /* bit mask of request recipient */
#define USB_REQ_RECIP_DEVICE    0x00
#define USB_REQ_RECIP_INTERF    0x01
#define USB_REQ_RECIP_ENDP      0x02
#define USB_REQ_RECIP_OTHER     0x03
#endif

/* USB request type for hub class request */
#ifndef HUB_GET_HUB_DESCRIPTOR
#define HUB_CLEAR_HUB_FEATURE   0x20
#define HUB_CLEAR_PORT_FEATURE  0x23
#define HUB_GET_BUS_STATE       0xA3
#define HUB_GET_HUB_DESCRIPTOR  0xA0
#define HUB_GET_HUB_STATUS      0xA0
#define HUB_GET_PORT_STATUS     0xA3
#define HUB_SET_HUB_DESCRIPTOR  0x20
#define HUB_SET_HUB_FEATURE     0x20
#define HUB_SET_PORT_FEATURE    0x23
#endif

/* Hub class feature selectors */
#ifndef HUB_PORT_RESET
#define HUB_C_HUB_LOCAL_POWER   0
#define HUB_C_HUB_OVER_CURRENT  1
#define HUB_PORT_CONNECTION     0
#define HUB_PORT_ENABLE         1
#define HUB_PORT_SUSPEND        2
#define HUB_PORT_OVER_CURRENT   3
#define HUB_PORT_RESET          4
#define HUB_PORT_POWER          8
#define HUB_PORT_LOW_SPEED      9
#define HUB_C_PORT_CONNECTION   16
#define HUB_C_PORT_ENABLE       17
#define HUB_C_PORT_SUSPEND      18
#define HUB_C_PORT_OVER_CURRENT 19
#define HUB_C_PORT_RESET        20
#endif

/* USB descriptor type */
#ifndef USB_DESCR_TYP_DEVICE
#define USB_DESCR_TYP_DEVICE    0x01
#define USB_DESCR_TYP_CONFIG    0x02
#define USB_DESCR_TYP_STRING    0x03
#define USB_DESCR_TYP_INTERF    0x04
#define USB_DESCR_TYP_ENDP      0x05
#define USB_DESCR_TYP_QUALIF    0x06
#define USB_DESCR_TYP_SPEED     0x07
#define USB_DESCR_TYP_OTG       0x09
#define USB_DESCR_TYP_BOS       0X0F
#define USB_DESCR_TYP_HID       0x21
#define USB_DESCR_TYP_REPORT    0x22
#define USB_DESCR_TYP_PHYSIC    0x23
#define USB_DESCR_TYP_CS_INTF   0x24
#define USB_DESCR_TYP_CS_ENDP   0x25
#define USB_DESCR_TYP_HUB       0x29
#endif

/* USB device class */
#ifndef USB_DEV_CLASS_HUB
#define USB_DEV_CLASS_RESERVED  0x00
#define USB_DEV_CLASS_AUDIO     0x01
#define USB_DEV_CLASS_COMMUNIC  0x02
#define USB_DEV_CLASS_HID       0x03
#define USB_DEV_CLASS_MONITOR   0x04
#define USB_DEV_CLASS_PHYSIC_IF 0x05
#define USB_DEV_CLASS_POWER     0x06
#define USB_DEV_CLASS_PRINTER   0x07
#define USB_DEV_CLASS_STORAGE   0x08
#define USB_DEV_CLASS_HUB       0x09
#define USB_DEV_CLASS_VEN_SPEC  0xFF
#endif

/* USB endpoint type and attributes */
#ifndef USB_ENDP_TYPE_MASK
#define USB_ENDP_DIR_MASK       0x80
#define USB_ENDP_ADDR_MASK      0x0F
#define USB_ENDP_TYPE_MASK      0x03
#define USB_ENDP_TYPE_CTRL      0x00
#define USB_ENDP_TYPE_ISOCH     0x01
#define USB_ENDP_TYPE_BULK      0x02
#define USB_ENDP_TYPE_INTER     0x03
#endif

#ifndef USB_DEVICE_ADDR
#define USB_DEVICE_ADDR             0x02
#endif
#ifndef DEFAULT_ENDP0_SIZE
#define DEFAULT_ENDP0_SIZE      8       /* default maximum packet size for endpoint 0 */
#endif
#ifndef MAX_PACKET_SIZE
#define MAX_PACKET_SIZE         64      /* maximum packet size */
#endif
#ifndef USB_BO_CBW_SIZE
#define USB_BO_CBW_SIZE             0x1F
#define USB_BO_CSW_SIZE             0x0D
#endif
#ifndef USB_BO_CBW_SIG0
#define USB_BO_CBW_SIG0         0x55
#define USB_BO_CBW_SIG1         0x53
#define USB_BO_CBW_SIG2         0x42
#define USB_BO_CBW_SIG3         0x43
#define USB_BO_CSW_SIG0         0x55
#define USB_BO_CSW_SIG1         0x53
#define USB_BO_CSW_SIG2         0x42
#define USB_BO_CSW_SIG3         0x53
#endif

#ifndef __PACKED
#define __PACKED            __attribute__((packed))
#endif

typedef struct __PACKED _USB_SETUP_REQ {
    UINT8 bRequestType;
    UINT8 bRequest;
    UINT16 wValue;
    UINT16 wIndex;
    UINT16 wLength;
} USB_SETUP_REQ, *PUSB_SETUP_REQ;


typedef struct __PACKED _USB_DEVICE_DESCR {
    UINT8 bLength;
    UINT8 bDescriptorType;
    UINT16 bcdUSB;
    UINT8 bDeviceClass;
    UINT8 bDeviceSubClass;
    UINT8 bDeviceProtocol;
    UINT8 bMaxPacketSize0;
    UINT16 idVendor;
    UINT16 idProduct;
    UINT16 bcdDevice;
    UINT8 iManufacturer;
    UINT8 iProduct;
    UINT8 iSerialNumber;
    UINT8 bNumConfigurations;
} USB_DEV_DESCR, *PUSB_DEV_DESCR;


typedef struct __PACKED _USB_CONFIG_DESCR {
    UINT8 bLength;
    UINT8 bDescriptorType;
    UINT16 wTotalLength;
    UINT8 bNumInterfaces;
    UINT8 bConfigurationValue;
    UINT8 iConfiguration;
    UINT8 bmAttributes;
    UINT8 MaxPower;
} USB_CFG_DESCR, *PUSB_CFG_DESCR;


typedef struct __PACKED _USB_INTERF_DESCR {
    UINT8 bLength;
    UINT8 bDescriptorType;
    UINT8 bInterfaceNumber;
    UINT8 bAlternateSetting;
    UINT8 bNumEndpoints;
    UINT8 bInterfaceClass;
    UINT8 bInterfaceSubClass;
    UINT8 bInterfaceProtocol;
    UINT8 iInterface;
} USB_ITF_DESCR, *PUSB_ITF_DESCR;


typedef struct __PACKED _USB_ENDPOINT_DESCR {
    UINT8 bLength;
    UINT8 bDescriptorType;
    UINT8 bEndpointAddress;
    UINT8 bmAttributes;
    UINT16 wMaxPacketSize;
    UINT8 bInterval;
} USB_ENDP_DESCR, *PUSB_ENDP_DESCR;


typedef struct __PACKED _USB_CONFIG_DESCR_LONG {
    USB_CFG_DESCR   cfg_descr;
    USB_ITF_DESCR   itf_descr;
    USB_ENDP_DESCR  endp_descr[1];
} USB_CFG_DESCR_LONG, *PUSB_CFG_DESCR_LONG;


typedef struct __PACKED _USB_HUB_DESCR {
    UINT8 bDescLength;
    UINT8 bDescriptorType;
    UINT8 bNbrPorts;
    UINT8 wHubCharacteristicsL;
    UINT8 wHubCharacteristicsH;
    UINT8 bPwrOn2PwrGood;
    UINT8 bHubContrCurrent;
    UINT8 DeviceRemovable;
    UINT8 PortPwrCtrlMask;
} USB_HUB_DESCR, *PUSB_HUB_DESCR;


typedef struct __PACKED _USB_HID_DESCR {
    UINT8 bLength;
    UINT8 bDescriptorType;
    UINT16 bcdHID;
    UINT8 bCountryCode;
    UINT8 bNumDescriptors;
    UINT8 bDescriptorTypeX;
    UINT8 wDescriptorLengthL;
    UINT8 wDescriptorLengthH;
} USB_HID_DESCR, *PUSB_HID_DESCR;


typedef struct __PACKED _UDISK_BOC_CBW {/* command of BulkOnly USB-FlashDisk */
    UINT32 mCBW_Sig;
    UINT32 mCBW_Tag;
    UINT32 mCBW_DataLen;                /* uppest byte of data length, always is 0 */
    UINT8 mCBW_Flag;                    /* transfer direction and etc. */
    UINT8 mCBW_LUN;
    UINT8 mCBW_CB_Len;                  /* length of command block */
    UINT8 mCBW_CB_Buf[16];              /* command block buffer */
} UDISK_BOC_CBW, *PXUDISK_BOC_CBW;


typedef struct __PACKED _UDISK_BOC_CSW {/* status of BulkOnly USB-FlashDisk */
    UINT32 mCBW_Sig;
    UINT32 mCBW_Tag;
    UINT32 mCSW_Residue;                /* return: remainder bytes */         /* uppest byte of remainder length, always is 0 */
    UINT8 mCSW_Status;                  /* return: result status */
} UDISK_BOC_CSW, *PXUDISK_BOC_CSW;


#define USE_SYS_CLK        0
//#define USBFS_HOST         0
//#define USB_OTG            0

/******************************************************************************/
/* USBFSD DEVICE USB_CONTROL */
/* BASE USB_CTRL */
#define   USBFS_BASE_CTRL       (USBFSD->BASE_CTRL)  // USB base control
#define     USBFS_UC_HOST_MODE     0x80      // enable USB host mode: 0=device mode, 1=host mode
#define     USBFS_UC_LOW_SPEED     0x40      // enable USB low speed: 0=12Mbps, 1=1.5Mbps
#define     USBFS_UC_DEV_PU_EN     0x20      // USB device enable and internal pullup resistance enable
#define     USBFS_UC_SYS_CTRL1     0x20      // USB system control high bit
#define     USBFS_UC_SYS_CTRL0     0x10      // USB system control low bit
#define     USBFS_UC_SYS_CTRL_MASK 0x30      // bit mask of USB system control
// UC_HOST_MODE & UC_SYS_CTRL1 & UC_SYS_CTRL0: USB system control
//   0 00: disable USB device and disable internal pullup resistance
//   0 01: enable USB device and disable internal pullup resistance, need external pullup resistance
//   0 1x: enable USB device and enable internal pullup resistance
//   1 00: enable USB host and normal status
//   1 01: enable USB host and force UDP/UDM output SE0 state
//   1 10: enable USB host and force UDP/UDM output J state
//   1 11: enable USB host and force UDP/UDM output resume or K state
#define     USBFS_UC_INT_BUSY      0x08      // enable automatic responding busy for device mode or automatic pause for host mode during interrupt flag UIF_TRANSFER valid
#define     USBFS_UC_RESET_SIE     0x04      // force reset USB SIE, need software clear
#define     USBFS_UC_CLR_ALL       0x02      // force clear FIFO and count of USB
#define     USBFS_UC_DMA_EN        0x01      // DMA enable and DMA interrupt enable for USB
/* DEVICE USB_CTRL */
#define   USBFS_UDEV_CTRL        (USBFSD->UDEV_CTRL)  // USB device physical prot control
#define     USBFS_UD_PD_DIS        0x80      // disable USB UDP/UDM pulldown resistance: 0=enable pulldown, 1=disable
#define     USBFS_UD_DP_PIN        0x20      // ReadOnly: indicate current UDP pin level
#define     USBFS_UD_DM_PIN        0x10      // ReadOnly: indicate current UDM pin level
#define     USBFS_UD_LOW_SPEED     0x04      // enable USB physical port low speed: 0=full speed, 1=low speed
#define     USBFS_UD_GP_BIT        0x02      // general purpose bit
#define     USBFS_UD_PORT_EN       0x01      // enable USB physical port I/O: 0=disable, 1=enable
/* USB INT EN */
#define   USBFS_INT_EN           (USBFSD->INT_EN)    // USB interrupt enable
#define     USBFS_UIE_DEV_NAK      0x40      // enable interrupt for NAK responded for USB device mode
#define     USBFS_UIE_FIFO_OV      0x10      // enable interrupt for FIFO overflow
#define     USBFS_UIE_HST_SOF      0x08      // enable interrupt for host SOF timer action for USB host mode
#define     USBFS_UIE_SUSPEND      0x04      // enable interrupt for USB suspend or resume event
#define     USBFS_UIE_TRANSFER     0x02      // enable interrupt for USB transfer completion
#define     USBFS_UIE_DETECT       0x01      // enable interrupt for USB device detected event for USB host mode
#define     USBFS_UIE_BUS_RST      0x01      // enable interrupt for USB bus reset event for USB device mode
/* USB_DEV_ADDR */
#define   USBFS_DEV_ADDR         (USBFSD->DEV_ADDR)   // USB device address
#define     USBFS_UDA_GP_BIT       0x80      // general purpose bit
#define     USBFS_USB_ADDR_MASK    0x7F      // bit mask for USB device address
/* USBFSD DEVICE USB_STATUS */
/* USB_MIS_ST */
#define   USBFS_MIS_ST           (USBFSD->MIS_ST)     // USB miscellaneous status
#define     USBFS_UMS_SOF_PRES     0x80      // RO, indicate host SOF timer presage status
#define     USBFS_UMS_SOF_ACT      0x40      // RO, indicate host SOF timer action status for USB host
#define     USBFS_UMS_SIE_FREE     0x20      // RO, indicate USB SIE free status
#define     USBFS_UMS_R_FIFO_RDY   0x10      // RO, indicate USB receiving FIFO ready status (not empty)
#define     USBFS_UMS_BUS_RESET    0x08      // RO, indicate USB bus reset status
#define     USBFS_UMS_SUSPEND      0x04      // RO, indicate USB suspend status
#define     USBFS_UMS_DM_LEVEL     0x02      // RO, indicate UDM level saved at device attached to USB host
#define     USBFS_UMS_DEV_ATTACH   0x01      // RO, indicate device attached status on USB host
/* USB_INT_FG */
#define   USBFS_INT_FG           (USBFSD->INT_FG)    // USB interrupt flag
#define     USBFS_U_IS_NAK         0x80    // RO, indicate current USB transfer is NAK received
#define     USBFS_U_TOG_OK         0x40    // RO, indicate current USB transfer toggle is OK
#define     USBFS_U_SIE_FREE       0x20    // RO, indicate USB SIE free status
#define     USBFS_UIF_FIFO_OV      0x10    // FIFO overflow interrupt flag for USB, direct bit address clear or write 1 to clear
#define     USBFS_UIF_HST_SOF      0x08    // host SOF timer interrupt flag for USB host, direct bit address clear or write 1 to clear
#define     USBFS_UIF_SUSPEND      0x04    // USB suspend or resume event interrupt flag, direct bit address clear or write 1 to clear
#define     USBFS_UIF_TRANSFER     0x02    // USB transfer completion interrupt flag, direct bit address clear or write 1 to clear
#define     USBFS_UIF_DETECT       0x01    // device detected event interrupt flag for USB host mode, direct bit address clear or write 1 to clear
#define     USBFS_UIF_BUS_RST      0x01    // bus reset event interrupt flag for USB device mode, direct bit address clear or write 1 to clear
/* USB_INT_ST */
#define   USBFS_INT_ST           (USBFSD->INT_ST)    // USB interrupt flag
#define     USBFS_UIS_IS_SETUP     0x80      // RO, indicate current USB transfer is setup received for USB device mode
#define     USBFS_UIS_IS_NAK       0x80      // RO, indicate current USB transfer is NAK received for USB device mode
#define     USBFS_UIS_TOG_OK       0x40      // RO, indicate current USB transfer toggle is OK
#define     USBFS_UIS_TOKEN1       0x20      // RO, current token PID code bit 1 received for USB device mode
#define     USBFS_UIS_TOKEN0       0x10      // RO, current token PID code bit 0 received for USB device mode
#define     USBFS_UIS_TOKEN_MASK   0x30      // RO, bit mask of current token PID code received for USB device mode
#define     USBFS_UIS_TOKEN_OUT    0x00
#define     USBFS_UIS_TOKEN_IN     0x20
#define     USBFS_UIS_TOKEN_SETUP  0x30
// UIS_TOKEN1 & UIS_TOKEN0: current token PID code received for USB device mode
//   00: OUT token PID received
//   10: IN token PID received
//   11: SETUP token PID received
#define     USBFS_UIS_ENDP_MASK    0x0F      // RO, bit mask of current transfer endpoint number for USB device mode
/* USB_RX_LEN */
#define   USBFS_RX_LEN        (USBFSD->Rx_Len)      // USB receiving length
/* USB_BUF_MOD */
#define   USBFS_UEP4_1_MOD    (USBFSD->UEP4_1_MOD)  // endpoint 4/1 mode
#define     USBFS_UEP1_RX_EN       0x80      // enable USB endpoint 1 receiving (OUT)
#define     USBFS_UEP1_TX_EN       0x40      // enable USB endpoint 1 transmittal (IN)
#define     USBFS_UEP1_BUF_MOD     0x10      // buffer mode of USB endpoint 1
// UEPn_RX_EN & UEPn_TX_EN & UEPn_BUF_MOD: USB endpoint 1/2/3 buffer mode, buffer start address is UEPn_DMA
//   0 0 x:  disable endpoint and disable buffer
//   1 0 0:  64 bytes buffer for receiving (OUT endpoint)
//   1 0 1:  dual 64 bytes buffer by toggle bit bUEP_R_TOG selection for receiving (OUT endpoint), total=128bytes
//   0 1 0:  64 bytes buffer for transmittal (IN endpoint)
//   0 1 1:  dual 64 bytes buffer by toggle bit bUEP_T_TOG selection for transmittal (IN endpoint), total=128bytes
//   1 1 0:  64 bytes buffer for receiving (OUT endpoint) + 64 bytes buffer for transmittal (IN endpoint), total=128bytes
//   1 1 1:  dual 64 bytes buffer by bUEP_R_TOG selection for receiving (OUT endpoint) + dual 64 bytes buffer by bUEP_T_TOG selection for transmittal (IN endpoint), total=256bytes
#define     USBFS_UEP4_RX_EN       0x08      // enable USB endpoint 4 receiving (OUT)
#define     USBFS_UEP4_TX_EN       0x04      // enable USB endpoint 4 transmittal (IN)
// UEP4_RX_EN & UEP4_TX_EN: USB endpoint 4 buffer mode, buffer start address is UEP0_DMA
//   0 0:  single 64 bytes buffer for endpoint 0 receiving & transmittal (OUT & IN endpoint)
//   1 0:  single 64 bytes buffer for endpoint 0 receiving & transmittal (OUT & IN endpoint) + 64 bytes buffer for endpoint 4 receiving (OUT endpoint), total=128bytes
//   0 1:  single 64 bytes buffer for endpoint 0 receiving & transmittal (OUT & IN endpoint) + 64 bytes buffer for endpoint 4 transmittal (IN endpoint), total=128bytes
//   1 1:  single 64 bytes buffer for endpoint 0 receiving & transmittal (OUT & IN endpoint)
//           + 64 bytes buffer for endpoint 4 receiving (OUT endpoint) + 64 bytes buffer for endpoint 4 transmittal (IN endpoint), total=192bytes

#define  USBFS_UEP2_3_MOD     (USBFSD->UEP2_3_MOD)  // endpoint 2/3 mode
#define     USBFS_UEP3_RX_EN       0x80      // enable USB endpoint 3 receiving (OUT)
#define     USBFS_UEP3_TX_EN       0x40      // enable USB endpoint 3 transmittal (IN)
#define     USBFS_UEP3_BUF_MOD     0x10      // buffer mode of USB endpoint 3
#define     USBFS_UEP2_RX_EN       0x08      // enable USB endpoint 2 receiving (OUT)
#define     USBFS_UEP2_TX_EN       0x04      // enable USB endpoint 2 transmittal (IN)
#define     USBFS_UEP2_BUF_MOD     0x01      // buffer mode of USB endpoint 2

#define  USBFS_UEP5_6_MOD     (USBFSD->UEP5_6_MOD)  // endpoint 5/6 mode
#define     USBFS_UEP6_RX_EN       0x80      // enable USB endpoint 6 receiving (OUT)
#define     USBFS_UEP6_TX_EN       0x40      // enable USB endpoint 6 transmittal (IN)
#define     USBFS_UEP6_BUF_MOD     0x10      // buffer mode of USB endpoint 6
#define     USBFS_UEP5_RX_EN       0x08      // enable USB endpoint 5 receiving (OUT)
#define     USBFS_UEP5_TX_EN       0x04      // enable USB endpoint 5 transmittal (IN)
#define     USBFS_UEP5_BUF_MOD     0x01      // buffer mode of USB endpoint 5

#define  USBFS_UEP7_MOD       (USBFSD->UEP7_MOD)  // endpoint 7 mode
#define     USBFS_UEP7_RX_EN       0x08      // enable USB endpoint 7 receiving (OUT)
#define     USBFS_UEP7_TX_EN       0x04      // enable USB endpoint 7 transmittal (IN)
#define     USBFS_UEP7_BUF_MOD     0x01      // buffer mode of USB endpoint 7
/* USB_DMA */
#define  USBFS_UEP0_DMA       (USBFSD->UEP0_DMA) // endpoint 0 DMA buffer address
//#define  USBFS_UEP1_DMA       (USBFSD->UEP1_DMA) // endpoint 1 DMA buffer address
#define  USBFS_UEP2_DMA       (USBFSD->UEP2_DMA) // endpoint 2 DMA buffer address
//#define  USBFS_UEP3_DMA       (USBFSD->UEP3_DMA) // endpoint 3 DMA buffer address
//#define  USBFS_UEP4_DMA       (USBFSD->UEP4_DMA) // endpoint 4 DMA buffer address
//#define  USBFS_UEP5_DMA       (USBFSD->UEP5_DMA) // endpoint 5 DMA buffer address
//#define  USBFS_UEP6_DMA       (USBFSD->UEP6_DMA) // endpoint 6 DMA buffer address
//#define  USBFS_UEP7_DMA       (USBFSD->UEP7_DMA) // endpoint 7 DMA buffer address
/* USB_EP_CTRL */
#define  USBFS_UEP0_T_LEN     (USBFSD->UEP0_TX_LEN)   // endpoint 0 transmittal length
#define  USBFS_UEP0_TX_CTRL   (USBFSD->UEP0_TX_CTRL)  // endpoint 0 control
#define  USBFS_UEP0_RX_CTRL   (USBFSD->UEP0_RX_CTRL)  // endpoint 0 control

//#define  USBFS_UEP1_T_LEN     (USBFSD->UEP1_TX_LEN)   // endpoint 1 transmittal length
//#define  USBFS_UEP1_TX_CTRL   (USBFSD->UEP1_TX_CTRL)  // endpoint 1 control
//#define  USBFS_UEP1_RX_CTRL   (USBFSD->UEP1_RX_CTRL)  // endpoint 1 control

#define  USBFS_UEP2_T_LEN     (USBFSD->UEP2_TX_LEN)   // endpoint 2 transmittal length
#define  USBFS_UEP2_TX_CTRL   (USBFSD->UEP2_TX_CTRL)  // endpoint 2 control
#define  USBFS_UEP2_RX_CTRL   (USBFSD->UEP2_RX_CTRL)  // endpoint 2 control

//#define  USBFS_UEP3_T_LEN     (USBFSD->UEP3_TX_LEN)   // endpoint 3 transmittal length
//#define  USBFS_UEP3_TX_CTRL   (USBFSD->UEP3_TX_CTRL)  // endpoint 3 control
//#define  USBFS_UEP3_RX_CTRL   (USBFSD->UEP3_RX_CTRL)  // endpoint 3 control
//
//#define  USBFS_UEP4_T_LEN     (USBFSD->UEP4_TX_LEN)   // endpoint 4 transmittal length
//#define  USBFS_UEP4_TX_CTRL   (USBFSD->UEP4_TX_CTRL)  // endpoint 4 control
//#define  USBFS_UEP4_RX_CTRL   (USBFSD->UEP4_RX_CTRL)  // endpoint 4 control
//
//#define  USBFS_UEP5_T_LEN     (USBFSD->UEP5_TX_LEN)   // endpoint 5 transmittal length
//#define  USBFS_UEP5_TX_CTRL   (USBFSD->UEP5_TX_CTRL)  // endpoint 5 control
//#define  USBFS_UEP5_RX_CTRL   (USBFSD->UEP5_RX_CTRL)  // endpoint 5 control
//
//#define  USBFS_UEP6_T_LEN     (USBFSD->UEP6_TX_LEN)   // endpoint 6 transmittal length
//#define  USBFS_UEP6_TX_CTRL   (USBFSD->UEP6_TX_CTRL)  // endpoint 6 control
//#define  USBFS_UEP6_RX_CTRL   (USBFSD->UEP6_RX_CTRL)  // endpoint 6 control
//
//#define  USBFS_UEP7_T_LEN     (USBFSD->UEP7_TX_LEN)   // endpoint 7 transmittal length
//#define  USBFS_UEP7_TX_CTRL   (USBFSD->UEP7_TX_CTRL)  // endpoint 7 control
//#define  USBFS_UEP7_RX_CTRL   (USBFSD->UEP7_RX_CTRL)  // endpoint 7 control

#define     USBFS_UEP_AUTO_TOG     0x08      // enable automatic toggle after successful transfer completion on endpoint 1/2/3: 0=manual toggle, 1=automatic toggle
#define     USBFS_UEP_R_TOG        0x04      // expected data toggle flag of USB endpoint X receiving (OUT): 0=DATA0, 1=DATA1
#define     USBFS_UEP_T_TOG        0x04      // prepared data toggle flag of USB endpoint X transmittal (IN): 0=DATA0, 1=DATA1

#define     USBFS_UEP_R_RES1       0x02      // handshake response type high bit for USB endpoint X receiving (OUT)
#define     USBFS_UEP_R_RES0       0x01      // handshake response type low bit for USB endpoint X receiving (OUT)
#define     USBFS_UEP_R_RES_MASK   0x03      // bit mask of handshake response type for USB endpoint X receiving (OUT)
#define     USBFS_UEP_R_RES_ACK    0x00
#define     USBFS_UEP_R_RES_TOUT   0x01
#define     USBFS_UEP_R_RES_NAK    0x02
#define     USBFS_UEP_R_RES_STALL  0x03
// RB_UEP_R_RES1 & RB_UEP_R_RES0: handshake response type for USB endpoint X receiving (OUT)
//   00: ACK (ready)
//   01: no response, time out to host, for non-zero endpoint isochronous transactions
//   10: NAK (busy)
//   11: STALL (error)
#define     USBFS_UEP_T_RES1       0x02      // handshake response type high bit for USB endpoint X transmittal (IN)
#define     USBFS_UEP_T_RES0       0x01      // handshake response type low bit for USB endpoint X transmittal (IN)
#define     USBFS_UEP_T_RES_MASK   0x03      // bit mask of handshake response type for USB endpoint X transmittal (IN)
#define     USBFS_UEP_T_RES_ACK    0x00
#define     USBFS_UEP_T_RES_TOUT   0x01
#define     USBFS_UEP_T_RES_NAK    0x02
#define     USBFS_UEP_T_RES_STALL  0x03
// bUEP_T_RES1 & bUEP_T_RES0: handshake response type for USB endpoint X transmittal (IN)
//   00: DATA0 or DATA1 then expecting ACK (ready)
//   01: DATA0 or DATA1 then expecting no response, time out from host, for non-zero endpoint isochronous transactions
//   10: NAK (busy)
//   11: TALL (error)

#ifdef  USBFS_HOST
/* USBFSD HOST CONTROL&CFG */
/* HOST USB_CTRL */
#define  USBFS_UHOST_CTRL       (USBFSD->UDEV_CTRL) // USB host physical prot control
#define     USBFS_UH_PD_DIS        0x80      // disable USB UDP/UDM pulldown resistance: 0=enable pulldown, 1=disable
#define     USBFS_UH_DP_PIN        0x20      // ReadOnly: indicate current UDP pin level
#define     USBFS_UH_DM_PIN        0x10      // ReadOnly: indicate current UDM pin level
#define     USBFS_UH_LOW_SPEED     0x04      // enable USB port low speed: 0=full speed, 1=low speed
#define     USBFS_UH_BUS_RESET     0x02      // control USB bus reset: 0=normal, 1=force bus reset
#define     USBFS_UH_PORT_EN       0x01      // enable USB port: 0=disable, 1=enable port, automatic disabled if USB device detached
/* USB_INT_ST */
#define     USBFS_UIS_H_RES_MASK   0x0F      // RO, bit mask of current transfer handshake response for USB host mode: 0000=no response, time out from device, others=handshake response PID received
/* USB_BUF_MOD */
#define  USBFS_UH_EP_MOD        USBFS_UEP2_3_MOD               //host endpoint mode
#define    USBFS__UH_EP_TX_EN      0x40      // enable USB host OUT endpoint transmittal
#define    USBFS__UH_EP_TBUF_MOD   0x10      // buffer mode of USB host OUT endpoint
// UH_EP_TX_EN & UH_EP_TBUF_MOD: USB host OUT endpoint buffer mode, buffer start address is UH_TX_DMA
//   0 x:  disable endpoint and disable buffer
//   1 0:  64 bytes buffer for transmittal (OUT endpoint)
//   1 1:  dual 64 bytes buffer by toggle bit bUH_T_TOG selection for transmittal (OUT endpoint), total=128bytes
#define    USBFS_UH_EP_RX_EN      0x08      // enable USB host IN endpoint receiving
#define    USBFS_UH_EP_RBUF_MOD   0x01      // buffer mode of USB host IN endpoint
// UH_EP_RX_EN & UH_EP_RBUF_MOD: USB host IN endpoint buffer mode, buffer start address is UH_RX_DMA
//   0 x:  disable endpoint and disable buffer
//   1 0:  64 bytes buffer for receiving (IN endpoint)
//   1 1:  dual 64 bytes buffer by toggle bit bUH_R_TOG selection for receiving (IN endpoint), total=128bytes
/* USB_DMA */
#define  USBFS_UH_RX_DMA       USBFS_UEP2_DMA                // host rx endpoint buffer high address
#define  USBFS_UH_TX_DMA       USBFS_UEP3_DMA                // host tx endpoint buffer high address
/* USB_HOST_SETUP  */
#define  USBFS_UH_SETUP        (*((PUINT16V)(0x50000036))) // host aux setup
#define     USBFS_UH_PRE_PID_EN    0x0400      // USB host PRE PID enable for low speed device via hub
#define     USBFS_UH_SOF_EN        0x04        // USB host automatic SOF enable
#define  USBFS_UH_EP_PID        USBFS_UEP2_T_LEN               // host endpoint and PID
#define     USBFS_UH_TOKEN_MASK    0xF0        // bit mask of token PID for USB host transfer
#define     USBFS_UH_ENDP_MASK     0x0F        // bit mask of endpoint number for USB host transfer

#define  USBFS_UH_RX_CTRL       USBFS_UEP2_RX_CTRL             // host receiver endpoint control
#define     USBFS_UH_R_AUTO_TOG    0x08      // enable automatic toggle after successful transfer completion: 0=manual toggle, 1=automatic toggle
#define     USBFS_UH_R_TOG         0x04      // expected data toggle flag of host receiving (IN): 0=DATA0, 1=DATA1
#define     USBFS_UH_R_RES         0x01      // prepared handshake response type for host receiving (IN): 0=ACK (ready), 1=no response, time out to device, for isochronous transactions

#define  USBFS_UH_RX_CTRL       USBFS_UEP2_RX_CTRL             // host receiver endpoint control
#define     USBFS_UH_R_AUTO_TOG    0x08      // enable automatic toggle after successful transfer completion: 0=manual toggle, 1=automatic toggle
#define     USBFS_UH_R_TOG         0x04      // expected data toggle flag of host receiving (IN): 0=DATA0, 1=DATA1
#define     USBFS_UH_R_RES         0x01      // prepared handshake response type for host receiving (IN): 0=ACK (ready), 1=no response, time out to device, for isochronous transactions
#define  USBFS_UH_TX_LEN        USBFS_UEP3_T_LEN               // host transmittal endpoint transmittal length

#define  USBFS_UH_TX_CTRL       USBFS_UEP3_TX_CTRL             // host transmittal endpoint control
#define     USBFS_UH_T_AUTO_TOG    0x08      // enable automatic toggle after successful transfer completion: 0=manual toggle, 1=automatic toggle
#define     USBFS_UH_T_TOG         0x04      // prepared data toggle flag of host transmittal (SETUP/OUT): 0=DATA0, 1=DATA1
#define     USBFS_UH_T_RES         0x01      // expected handshake response type for host transmittal (SETUP/OUT): 0=ACK (ready), 1=no response, time out from device, for isochronous transactions
#endif
#ifdef USB_OTG
#define  USB_OTG_CR          (USBFSD->OTG_CR)  // usb otg control
#define     USB_OTG_CR_SESS           0x20
#define     USB_OTG_CR_VBUS           0x10
#define     USB_OTG_CR_OTG_EN         0x08
#define     USB_OTG_CR_IDPU           0x04
#define     USB_OTG_CR_CHARGEVBUS     0x02
#define     USB_OTG_CR_DISCHARGEVBUS  0x01

#define  USB_OTG_SR          (USBFSD->OTG_CR)
#define     USB_OTG_SR_VBUS_VLD       0x01
#define     USB_OTG_SR_SESS_VLD       0x02
#define     USB_OTG_SR_SESS_END       0x04
#define     USB_OTG_SR_ID_DIG         0x08
#endif


#ifndef  USBHS_EXIST
#define USB_48M_CLK_SRC_MASK   (1<<31)
#define USB_48M_CLK_SRC_SYS    (0<<31)
#define USB_48M_CLK_SRC_PHY    (1<<31)

#define USBHS_PLL_ALIVE        (1<<30)

#define USBHS_PLL_CKREF_MASK   (3<<28)
#define USBHS_PLL_CKREF_3M     (0<<28)
#define USBHS_PLL_CKREF_4M     (1<<28)
#define USBHS_PLL_CKREF_8M     (2<<28)
#define USBHS_PLL_CKREF_5M     (3<<28)

#define USBHS_PLL_SRC_MASK     (1<<27)
#define USBHS_PLL_SRC_HSE      (0<<27)
#define USBHS_PLL_SRC_HSI      (1<<27)

#define USBHS_PLL_SRC_PRE_MASK (7<<24)
#define USBHS_PLL_SRC_PRE_DIV1 (0<<24)
#define USBHS_PLL_SRC_PRE_DIV2 (1<<24)
#define USBHS_PLL_SRC_PRE_DIV3 (2<<24)
#define USBHS_PLL_SRC_PRE_DIV4 (3<<24)
#define USBHS_PLL_SRC_PRE_DIV5 (4<<24)
#define USBHS_PLL_SRC_PRE_DIV6 (5<<24)
#define USBHS_PLL_SRC_PRE_DIV7 (6<<24)


#define DEF_USB_FS_EP_SIZE      64
#endif


#define RCC_USBFS_CLK_DIV_1   (0<<22)
#define RCC_USBFS_CLK_DIV_2   (1<<22)
#define RCC_USBFS_CLK_DIV_3   (2<<22)
#define RCC_USBFS_CLK_SRC     (1<<31)


extern PUINT8  pEP0_RAM_Addr;                                                  //ep0(64)
extern PUINT8  pEP2_RAM_Addr;                                                  //ep2_out(64)+ep2_in(64)

extern volatile UINT8  USBFS_Endp1_Down_Flag;

#define pSetupReqPakHD      ((PUSB_SETUP_REQ)pEP0_RAM_Addr)
#define pEP0_DataBuf        (pEP0_RAM_Addr)
#define pEP2_OUT_DataBuf    (pEP2_RAM_Addr)
#define pEP2_IN_DataBuf     (pEP2_RAM_Addr+64)

#define EP2_GetINSta()      (R8_UEP2_CTRL&UEP_T_RES_NAK)


extern void DevEP2_OUT_Deal( UINT8 l );
extern void DevEP2_IN_Deal( UINT8 l );
extern void USBDeviceInit( void );
extern void USBFS_Init( void );


#endif
