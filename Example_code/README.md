
# Code Example Directorys

Source: https://github.com/openwch/ch32v20x

## SRC

[SRC/Core/](SRC/Core/) - kernal system header file.

[SRC/Debug/](SRC/Debug/) - delay fuction, UART debugging source file and header file.

[SRC/Ld](SRC/Ld/) - ld file.

[SRC/Peripheral](SRC/Peripheral/) - basic peripheral driver source file and header file.

[SRC/Startup](SRC/Startup/) - startup file. For different devices selected by users, the following 3 startup files are provided, and the matched device definition is selected in the ch32v20x.h file.

- startup_ch32v20x_D6.S: applied to the CH32V203F6-CH32V203G6-CH32V203K8-CH32V203C6-CH32V203C8-CH32V203G8

- startup_ch32v20x_D8.S: applied to the CH32V203RB

- startup_ch32v20x_D8W.S: applied to the CH32V208

## ADC - Analog to Digital Converter

[ADC/ADC_DMA/](ADC/ADC_DMA/) - ADC DMA sampling routines

[ADC/AnalogWatchdog/](ADC/AnalogWatchdog/) - analog watchdog routine

[ADC/Auto_Injection/](ADC/Auto_Injection/) - automatic injection mode routine

[ADC/Discontinuous_mod/](ADC/Discontinuous_mode/) - discontinuous mode routine

[ADC/DualADC_AlternateTrigger/](ADC/DualADC_AlternateTrigger/) - dual ADC alternate trigger sampling routine, only applied to CH32V20x_D6

[ADC/DualADC_Combined_RegInjectionSimul/](ADC/DualADC_Combined_RegInjectionSimul/) - dual ADC combined regular + injection + simultaneous sampling routine, only applied to CH32V20x_D6

[ADC/DualADC_FastInterleaved/](ADC/DualADC_FastInterleaved/) - dual ADC fast interleaved sampling routine, only applied to CH32V20x_D6

[ADC/DualADC_InjectionSimul/](ADC/DualADC_InjectionSimul/) - dual ADC injection simultaneous sampling routine, only applied to CH32V20x_D6

[ADC/DualADC_RegSimul/](ADC/DualADC_RegSimul/) - dual ADC regular simultaneous sampling routine, only applied to CH32V20x_D6

[ADC/DualADC_SlowInterleaved/](ADC/DualADC_SlowInterleaved/) - dual ADC slow interleaved sampling routine, only applied to CH32V20x_D6

[ADC/ExtLines_Trigger/](ADC/ExtLines_Trigger/) - external lines trigger ADC conversion routine

[ADC/Internal_Temperature/](ADC/Internal_Temperature/) - internal temperature sensor routine

[ADC/TIM_Trigger/](ADC/TIM_Trigger/) - TIM trigger ADC conversion routine

[ADC/Temperature_External_channel/](ADC/Temperature_External_channel/) - Temperature External channel Injection alternating inversion routine

## APPLICATION

[APPLICATION/USBPD/](APPLICATION/USBPD/) - I2C_OP_CH223：I2C Operates CH223 routine, only applied to CH32V20x_D8

[APPLICATION/WS2812_LED/](APPLICATION/WS2812_LED/) - WS2812_LED：SPI\PWM Operates WS2812_LED routine

## BLE 

**Only for CH32V20x_D8W**

[BLE/BackupUpgrade_IAP/](BLE/BackupUpgrade_IAP/) - backup wireless upgrade IAP routine. Detect the current code flag, determine whether to move the code from the backup area to the user area, and run the code in the user area

BLE/BackupUpgrade_OTA/ - backup wireless upgrade user routine. Add OTA function to peripheral slave routines, save the upgrade firmware to the backup area and jump to the IAP program to upgrade

BLE/BLE_UART/ - BLE and UART transparent transmission routine, for detailed instructions, please refer to the <description.txt> document in the root directory

BLE/BLE_USB/ - BLE with USB routine, USB emulation 340 device forwards BLE data

BLE/Broadcaster/ - broadcaster routine, always broadcast when in broadcast status

BLE/CentPeri/ - central-peripheral routine, integrate the function of central routine and peripheral routine and run simultaneously

BLE/Central/ - central routine, actively scan surrounding devices, conect to the specified peripheral address, search custom service and characteristic, execute read/write commands, peripheral routine is needed, and modify the peripheral address to the routine target address, (84:C2:E4:03:02:02) by default

BLE/CyclingSensor/ - cycling sensor routine, upload speed and cadence regularly after connected to the host

 BLE/DirectTest/ - direct test routine, test data packets sent by specified communication channel

BLE/HAL/ - Hardware-related files shared by routines

BLE/HeartRate/ - heart rate routine, upload heart rate regularly after connected to the central

BLE/HID_Consumer/ - BLE consumer routine, simulate user control device, upload volume key down key regularly after connected to the central

BLE/HID_Keyboard/ - BLE keyboard routine, simulate a keyboard device, upload key value regularly after connected to the central

BLE/HID_Mouse/ - BLE mouse routine, simulate a mouse device, upload key value regularly after connected to the central

BLE/HID_Touch/ - BLE touch routine, simulate a touch pencil device,  upload touch value regularly after connected to the central

BLE/LIB/ - BLE protocol stack library file and header file

BLE/LWNS/ - LWNS wireless networking routine,including broadcast/unicast/netflood/mesh.

BLE/MultiCentPeri/ - Multi-central and multi-peripheral routines, support connecting three masters and three slaves at the same time

BLE/MultiCentral/ - multicentral routine, actively scan surrounding devices, conect to the specified three peripheral addresses, search custom services and characteristics, execute read/write commands, peripheral routine is needed, and modify the peripheral address to this routine target address, the addresses of these peripherals are (84:C2:E4:03:02:02), (84:C2:E4:03:02:03) and (84:C2:E4:03:02:04) by default

BLE/Observer/ - observer routine, scan regularly, print the scanned broadcast address if the scanning result is not empty

BLE/OnlyUpdateApp_IAP/ - the only library wireless upgrade IAP routine, with OTA function, upgrade the user area code after receiving the upgraded firmware

BLE/OnlyUpdateApp_Peripheral/ - the only library wireless upgrade user routine, on the basis of peripheral routine, the jumping to IAP program is added for subsequent upgrades

BLE/PAwR_ADV/ - periodic advertising with responses routine in advertising

BLE/PAwR_RSP/ - periodic advertising with responses routine in responses

BLE/Peripheral/ -  peripheral role routine, custom including five services with different  attributes, including read attribute, write attribute, notify attribute, read/write attribute, and safe and readable attribute

BLE/peripheral_ancs_client/ - peripheral slave role routine, including Apple Notification Center service

BLE/peripheral_ETH/ - Bluetooth ETH routines

BLE/RF_PHY/ - non-standard wireless transceiver routines

BLE/RF_PHY_Auto/ - non-standard wireless auto transceiver routines

BLE/RF_PHY_Hop/ - non-standard wireless frequency hopping transceiver routine

BLE/RunningSensor/ - running sensor routine,upload rate regularly after connected to the central

BLE/SpeedTest_Central/ - Bluetooth speed test central routine

BLE/SpeedTest_Peripheral/ - Bluetooth speed test peripheral routine

BLE/SYNC_ADV/ - cycle synchronization advertising routine

BLE/SYNC_SCAN/ - cycle synchronization scanning routine

BLE/WCH/ - BLE Software Developers Guide.pdf

BLE/BLE/ -  Certification: Product: WCH CH32V208 QDID: 179771

BLE/MESH/adv_ali_light/ - Tmall Genie light routine, devices can be found and provisioned network via Tmall Genie, to control the switch state. By default, only switch attribute can be controlled. If other attributes (brightness, power, temperature, etc.) are needed, add the corresponding processing function and status report function according to the attribute description of the Alibaba Cloud product configuration.

BLE/MESH/adv_ali_light_add_lightness/ - MESH general attribute adding routine. On the basis of the Tmall Genie light routine, the brightness attribute is added, which is used to compare the original Tmall Genie light routine to quickly become familiar with the method of adding other MESH general attributes.

BLE/MESH/adv_ali_light_add_windspeed/ - Tmall definition attribute adding routine. On the basis of the Tmall Genie light routine, the wind speed attribute is added, which is used to compare the original Tmall Genie light routine to quickly become familiar with the method of adding other Tmall definition attributes.

BLE/MESH/adv_ali_light_multi_element/ - Multi-element fan lamp, which is used to compare the original Tmall Genie light routine to quickly become familiar with the method of adding multi-element Tmall definition attributes.

BLE/MESH/adv_ali_light_with_peripheral/ - Based on the Tmall Genie light routine, add brightness and color temperature controls, it supports the connection control of BLE debugging tool on the mobile phone.

BLE/MESH/adv_proxy/ - proxy node routine, which can be used to provision network through the PV_GATT layer (BLE connection).

BLE/MESH/adv_vendor/ - vendor-defined model routine, used with provisioner_vendor, supports two communication attributes of response transmission and non-response transparent transmission, and develops the communication protocol by yourself.

BLE/MESH/adv_vendor_friend/ - based on vendor-defined model routine, support friend node function

BLE/MESH/adv_vendor_low_power/ - On the basis of the vendor custom model routine, support low-power node functions and should be used with friend nodes

BLE/MESH/adv_vendor_self_provision/ - On the basis of the vendor custom model routine, support local provision

BLE/MESH/adv_vendor_self_provision_IAP/ - MESH backup wireless upgrade IAP routine, detect the current code flag, judge whether to move the backup area code to the user area and run the user area code

BLE/MESH/adv_vendor_self_provision_with_peripheral/ - MESH backup wireless upgrade user routine, On the basis of the vendor custom model routine, supports the connection control of the mobile phone BLE debugging assistant, receives the distribution network information through BLE and distributes the network itself. It is suitable for terminal control networking applications. It can formulate the communication protocol by itself to realize the mobile phone control all devices in the mesh network.

BLE/MESH/provisioner_vendor/ - vendor-defined model self-provisioning network initiator routine, used with adv_vendor, automatically provision network to the surrounding devices without network, and add it to its own mesh network, support provision network to six devices by default . The default configuration device is bound with single APPKEY, which is used for response transmission and non-response transparent transmission, and the configuration device is bound with single subscription address, which is used for mass sending of unanswered messages

BLE/MESH/provisioner_vendor_with_peripheral/ - Based on the vendor-defined model self-provisioning network initiator routine, can be connected and controlled by BLE debugging tool on the mobile phone, transfer the communication between the mobile phone and the mesh network, and can draw up the communication protocol to implement that all devices in mesh network can be controlled the mobile phone.

BLE/MESH/MESH_LIB/ -  MESH protocol stack library file and header file
BLE/MESH/Qinheng MESH APP Management Distribution Network Application Manual.pdf
BLE/MESH/Qinheng Low Energy Bluetooth MESH Software Development Reference Manual.pdf

## BKP

BKP (Backup) refers to a set of registers or memory in microcontrollers that retain their contents during power loss, provided a backup power source is available. These registers are used to store critical data, such as RTC settings, system configuration, or fault recovery information. BKP registers are essential for ensuring system reliability and data integrity in embedded applications.

[BKP/BKP/](BKP/BKP/) - BKP routines

## CAN - Controller Area Network

*Only for CH32V20x_D6-CH32V20x_D8W*

It is a robust, widely used communication protocol designed for real-time applications, particularly in automotive and industrial systems. CAN allows microcontrollers and devices to communicate with each other without a host computer, making it ideal for distributed control systems.


[CAN/Networking/](CAN/Networking/) - CAN routine: normal mode, standard frame and expanded frame data transceiver

[CAN/TestMode/](CAN/TestMode/) - test mode, including silent mode, loopback mode and loopback silent mode

[CAN/Time-triggered/](CAN/Time-triggered/) - time triggered communication mode

## CRC - Cyclic Redundancy Check

It is a widely used error-detection technique in digital networks and storage devices to ensure the integrity of data during transmission or storage. CRC works by generating a short, fixed-length checksum (or hash) based on the data being transmitted. This checksum is appended to the data and verified by the receiver to detect any errors that may have occurred.


[CRC/CRC_Calculation/](CRC/CRC_Calculation/) CRC routines

## DMA - Direct Memory Access

It is a feature in computer systems and microcontrollers that allows certain hardware subsystems to access the main system memory independently of the central processing unit (CPU). This enables data to be transferred between peripherals (e.g., UART, SPI, ADC) and memory (RAM) without CPU intervention, significantly improving system performance and efficiency.

[DMA/DMA_MEM2MEM/](DMA/DMA_MEM2MEM/) - Memory to memory mode routine

[DMA/DMA_MEM2PERIP/](DMA/DMA_MEM2PERIP/) - Memory to peripheral mode, and peripheral to memory mode routine, see peripheral sub-routines

## ETH - Ethernet

**Only for CH32V20x_D8-CH32V20x_D8W**

[ETH/1_Tool_Doc/](ETH/1_Tool_Doc/) - routine-related documents and configuration software

[ETH/DHCP/](ETH/DHCP/) - DHCP demonstration routine to obtain IP automatically, and establish TCP connection for data return

[ETH/DNS/](ETH/DNS/) - DHCP demonstration routine to obtain IP automatically and then request domain name resolution

[ETH/ETH_CFG/](ETH/ETH_CFG/) - ETH_CFG routine. Create a UDP Server to communicate with upper computer, to configure WCHNET functions, including configuring various parameters and creating a new communication.

[ETH/ETH_IAP/](ETH/ETH_IAP/) - ETH IAP routine

[ETH/ETH_UART/](ETH/ETH_UART/) - ETH_UART routine, to demonstrate data transparent transfer between Ethernet and UART. By default, the 1000000 baud rate (can be modified in bsp_uart.h) is selected for serial port data transmission

[ETH/IPRaw_PING/](ETH/IPRaw_PING/) - PING function demonstration routine

[ETH/Mail/](ETH/Mail/) - to demonstrate reception and transmission of SMTP and POP3 mails

[ETH/MQTT/](ETH/MQTT/) - MQTT routine, to demonstrate MQTT protocol communication based on TCP/IP

[ETH/NetLib/](ETH/NetLib/) - Network protocol stack library file

[ETH/TcpClient/](ETH/TcpClient/) - demonstration routine that TCP client receives data after connected to the server and then returns data

[ETH/TcpServer/](ETH/TcpServer/) - demonstration routine that TCP server receives data after connected to the client and then returns data

[ETH/UdpClient/](ETH/UdpClient/) - demonstration routine that Udp Client receives data and returns data

[ETH/UdpServer/](ETH/UdpServer/) - demonstration routine that Udp Server receives data and returns data

[ETH/WebServer/](ETH/WebServer/) - Web Server routine, to demonstrate the configuration of WCHNET device functions through Web browser. As the WCHNET devices have built-in web server, the network parameter configuration and password management of WCHNET can be implemented on the web page.

## EXTI - External Interrupt

It is a feature in microcontrollers that allows external events (e.g., a button press, sensor trigger, or signal change) to interrupt the normal execution of the program and execute a specific interrupt service routine (ISR). EXTI is commonly used to handle real-time events efficiently without requiring constant polling of input pins.

[EXTI/EXTI0/](EXTI/EXTI0/) - External Interrupt Routine

## FLASH

 FLASH refers to a type of non-volatile memory used to store program code, configuration data, and other persistent information. Unlike RAM (Random Access Memory), which loses its contents when power is removed, FLASH memory retains its data even when the power is turned off. This makes it ideal for storing firmware, bootloaders, and other critical data in embedded systems.

[FLASH/FLASH_Program/](FLASH/FLASH_Program/) - FLASH erase/read/write, and fast programming

## FreeRTOS

[FreeRTOS/FreeRTOS_Core/](FreeRTOS/FreeRTOS_Core/) - FreeRTOS migration routines

## GPIO

[GPIO/GPIO_Toggle/](GPIO/GPIO_Toggle/) - GPIO routines

## HarmonyOS

[HarmonyOS/LiteOS_m/](HarmonyOS/LiteOS_m/) - HarmonyOS migration routine

## I2C

[I2C/I2C_7bit_Mode/](I2C/I2C_7bit_Mode/) - 7-bit addressing mode, master/slave mode, transceiver routine

[I2C/I2C_10bit_Mode/](I2C/I2C_10bit_Mode/) - 10-bit addressing mode, master/slave mode transceiver routine

[I2C/I2C_DMA/](I2C/I2C_DMA/) - I2C DMA, master/slave mode transceiver routine

[I2C/I2C_EEPROM/](I2C/I2C_EEPROM/) - I2C interface routine to operate EEPROM peripheral

[I2C/I2C_PEC/](I2C/I2C_PEC/) - PEC error check, master/slave mode transceiver routine

[I2C/I2C_7bit_Interrupt_Mode/](I2C/I2C_7bit_Interrupt_Mode/) - Use interrupt to receive and send routine

## INT

Vector Table Fetch Interrupt Request

[INT/Interrupt_VTF/](INT/Interrupt_VTF/) - VTF IRQ interrupt routine

## IAP: IAP upgrade routine, including the Hex to Bin tool and IAP upgrade tool

**IAP** stands for **In-Application Programming**. It refers to the ability of a microcontroller to reprogram its own flash memory or update its firmware while the application is running. This is a powerful feature that enables field updates, bug fixes, and feature enhancements without requiring physical access to the device or specialized programming hardware.

[IAP/USB_UART/](IAP/USB_UART/) - USB+UART IAP routine

## IWDG - Independent Watchdog Timer

It is a hardware timer that helps ensure the reliability and stability of embedded systems by detecting and recovering from software malfunctions. If the software fails to periodically "feed" (reset) the watchdog timer, the IWDG will trigger a system reset, allowing the system to recover from a fault.

[IWDG/IWDG/](IWDG/IWDG/) - Independent Watchdog routine

## OPA - Operational Amplifier

[OPA/OPA_Voltage_Follower/](OPA/OPA_Voltage_Follower/) - OPA4 as voltage follower output routine

## PWR - Power Management

[PWR/Sleep_Mode/](PWR/Sleep_Mode/) - low power, sleep mode routine

[PWR/Standby_Mode/](PWR/Standby_Mode/) - low power, standby mode routine

[PWR/Stop_Mode/](PWR/Stop_Mode/) - low power, stop mode routine

[PWR/Standby_RAM_LV_Mode/](PWR/Standby_RAM_LV_Mode/) - when LV is enabled in standby mode, RAM 2k and 30K low-power data holding routines

[PWR/Standby_RAM_Mode/](PWR/Standby_RAM_Mode/) - when LV is not enabled in standby mode, RAM 2k and 30K low-power data holding routines

[PWR/Standby_RAM_Application/](PWR/Standby_RAM_Application/) - When MCU in standby mode, RAM 2k and 30K low-power data holding application routine

[PWR/PVD_Wakeup/](PWR/PVD_Wakeup/) - STOP mode PVD wakeup MCU Routine

[PWR/PVD_VoltageJudger/](PWR/PVD_VoltageJudger/) - PVD voltage Judger Routine

PWR/Standby_RAM_Application/ - RAM data holding in standby mode Routine

## PMP - Physical Memory Protection

It is a hardware mechanism that enforces memory access permissions for different regions of physical memory.

[PMP/PMP/](PMP/PMP/) - Physical memory protection Routine

## RCC - Reset and Clock Control

It is a hardware peripheral in microcontrollers that manages the system's clock sources, clock distribution, and reset functionality. The RCC peripheral is critical for configuring the microcontroller's clock tree, enabling/disabling clock signals to peripherals, and controlling system resets.

[RCC/Get_CLK/](RCC/Get_CLK/) - Get system-HCLK-AHB1-AHB2 clock routine

[RCC/MCO/](RCC/MCO/) - MCO pin clock output routine

[RCC/HSI_PLL_Source/](RCC/HSI_PLL_Source/) - HSI or HSI/2 as PLL input clock routine

[RCC/HSI_Calibration/](RCC/HSI_Calibration/) - HSI calibrate routine

[RCC/HSE_CLK/](RCC/HSE_CLK/) - HSE frequency check routine

## RT-Thread - Real-Time Thread

[RT-Thread/RT_Thread_Core/](RT-Thread/RT_Thread_Core/) - RT-Thread migration routine

## RTC - Real-Time Clock

It is a hardware peripheral that keeps track of time (hours, minutes, seconds) and date (day, month, year) even when the main system power is turned off. The RTC is typically powered by a backup battery (e.g., a coin cell or supercapacitor), allowing it to maintain accurate timekeeping over long periods.

[RTC/RTC_Calendar/](RTC/RTC_Calendar/) - Calendar Routines

[RTC/RTC_Calibration/](RTC/RTC_Calibration/) - RTC calibrate Routines

## SPI - Serial Peripheral Interface

[SPI/1Lines_half-duplex/](SPI/1Lines_half-duplex/) - single wire half duplex mode, master/slave mode, data transceiver

[SPI/2Lines_FullDuplex/](SPI/2Lines_FullDuplex/) - two-wire full duplex mode, master/slave mode, data transceiver

[SPI/FullDuplex_HardNSS/](SPI/FullDuplex_HardNSS/) - Hardware NSS mode, master/slave mode, data transceiver

[SPI/SPI_CRC/](SPI/SPI_CRC/) - CRC error check and master/slave mode transceiver routine

[SPI/SPI_DMA/](SPI/SPI_DMA/) - SPI DMA, master/slave mode transceiver routine

[SPI/SPI_FLASH/](SPI/SPI_FLASH/) - SPI interface operation flash peripheral routine

[SPI/SPI_LCD/](SPI/SPI_LCD/) - SPI interface operation FLASH  and LCD peripheral routines

## TencentOS

TencentOS is an operating system developed by Tencent. 

[TencentOS/TencentOS/](TencentOS/TencentOS/) - TencentOS migration routine

## SDI Printf

SDI Printf refers to a method of printing debug messages or log information using Serial Wire Debug (SWD) or Single Wire Output (SWO) interfaces. This technique is commonly used in ARM Cortex-M microcontrollers to output debug information without requiring a dedicated UART or additional hardware.

[SDI_Printf/SDI_Printf/](SDI_Printf/SDI_Printf/) - debug interface SDI, virtual serial port.

## SYSTICK - System Timer

[SYSTICK/SYSTICK_Interrupt/](SYSTICK/SYSTICK_Interrupt/) - Systick timer routine

## TIM - Timer

[TIM/Clock_Select/](TIM/Clock_Select/) - clock source selection routine

[TIM/ComplementaryOutput_DeadTime/](TIM/ComplementaryOutput_DeadTime/) - complementary output and deadband insertion mode routines

[TIM/ExtTrigger_Start_Two_Timer/](TIM/ExtTrigger_Start_Two_Timer/) - external trigger routines to start two timers synchronously

[TIM/Input_Capture/](TIM/Input_Capture/) - input capture routine

[TIM/One_Pulse/](TIM/One_Pulse/) - single pulse output routine

[TIM/Output_Compare_Mode/](TIM/Output_Compare_Mode/) - output comparison mode routine

[TIM/PWM_Output/](TIM/PWM_Output/) - PWM output routine

[TIM/Synchro_ExtTrigger/](TIM/Synchro_ExtTrigger/) - slave mode routine, including reset mode, gating mode and trigger mode

[TIM/Synchro_Timer/](TIM/Synchro_Timer/) - timer synchronization mode

[TIM/TIM_DMA/](TIM/TIM_DMA/) - timer DMA routines

[TIM/Encode/](TIM/Encode/) - Timer encoder mode routines

[TIM/TIM_INT/](TIM/TIM_INT/) - Timer interput mode routines

## TOUCHKEY

[TOUCHKEY/TKey/](TOUCHKEY/TKey/) - TouchKey Detection Routine

## USART - Universal Synchronous/Asynchronous Receiver/Transmitter

[USART/USART_DMA/](USART/USART_DMA/) - USART DMA, master/slave mode transceiver routine

[USART/USART_HalfDuplex/](USART/USART_HalfDuplex/) - single wire half duplex mode, master/slave mode transceiver routine

[USART/USART_HardwareFlowControl/](USART/USART_HardwareFlowControl/) - hardware flow control mode, master/slave mode, transceiver routine

[USART/USART_Interrupt/](USART/USART_Interrupt/) - USART interrupt routine, master/slave mode transceiver routine

[USART/USART_MultiProcessorCommunication/](USART/USART_MultiProcessorCommunication/) - multiprocessor communication mode routine

[USART/USART_Polling/](USART/USART_Polling/) - polling transceiver mode, master/slave transceiver routine

[USART/USART_Printf/](USART/USART_Printf/) - USART Print debugging routine

[USART/USART_SynchronousMode/](USART/USART_SynchronousMode/) - synchronous mode, master/slave mode, transceiver routine

[USART/USART_Printf/](USART/USART_Printf/) - Serial port printing debugging routines

[USART/USART_Idle_Recv/](USART/USART_Idle_Recv/) - USART use DMA receiving indeterminate length data routines

[USART/USART_SmartCard/](USART/USART_SmartCard/) - USART_SmartCard routines

## USB

* USB Device

* USB Full-Speed

[USB/USBD/CH372/](USB/USBD/CH372/) - Simulates a custom USB device (CH372 device) with endpoints 1, 3 down and 2, 4 up. Data down from endpoint 1 is uploaded from endpoint 3 and not reversed, and data down from endpoint 2 is uploaded from endpoint 4 and reversed.

[USB/USBD/Compatibility_HID/](USB/USBD/Compatibility_HID/) - Simulates HID devices, with data transmitted up and down through the serial port.

[USB/USBD/CompositeKM/](USB/USBD/CompositeKM/) - Simulate keyboard and mouse, use IO to simulate keystrokes, while simulated data can be uploaded through serial port 2.

[USB/USBD/MSC_U-Disk/](USB/USBD/MSC_U-Disk/) - Smulates a simple USB flash drive, optionally using on-chip Flash or external SPI-Flash

[USB/USBD/MSC_CD-ROM/](USB/USBD/MSC_CD-ROM/) - Simulate CDROM, need external SPI-Flash

[USB/USBD/SimulateCDC/](USB/USBD/SimulateCDC/) - Simulate a CDC serial port and use serial port 2 to send and receive.

[USB/USBD/SimulateCDC-HID/](USB/USBD/SimulateCDC-HID/) - Simulate a CDC serial port, use serial port 2 to send and receive, HID interrupt endpoints to send and receive data to reverse and upload.

[USB/USBFS/DEVICE/CH372/](USB/USBFS/DEVICE/CH372/) - Simulates a custom USB device (CH372 device) with endpoints 1, 3 down and 2, 4 up. Data down from endpoint 1 is uploaded from endpoint 3 and not reversed, and data down from endpoint 2 is uploaded from endpoint 4 and reversed.

[USB/USBFS/DEVICE/Compatibility_HID/](USB/USBFS/DEVICE/Compatibility_HID/) - Simulates HID devices, with data transmitted up and down through the serial port.

[USB/USBFS/DEVICE/CompositeKM/](USB/USBFS/DEVICE/CompositeKM/) - Simulate keyboard and mouse, use IO to simulate keystrokes, while simulated data can be uploaded through serial port 2.

[USB/USBFS/DEVICE/MSC_U-Disk/](USB/USBFS/DEVICE/MSC_U-Disk/) - Smulates a simple USB flash drive, optionally using on-chip Flash or external SPI-Flash

[USB/USBFS/DEVICE/MSC_CD-ROM/](USB/USBFS/DEVICE/MSC_CD-ROM/) - Simulate CDROM, need external SPI-Flash

[USB/USBFS/DEVICE/SimulateCDC/](USB/USBFS/DEVICE/SimulateCDC/) -Simulate a CDC serial port and use serial port 2 to send and receive.

[USB/USBFS/DEVICE/SimulateCDC-HID/](USB/USBFS/DEVICE/SimulateCDC-HID/) - Simulate a CDC serial port, use serial port 2 to send and receive, HID interrupt endpoints to send and receive data to reverse and upload.


[USB/USBFS/HOST_IAP/APP/](USB/USBFS/HOST_IAP/APP/) - APP used with HOST_IAP, the project has modified the starting location of the program, after compilation, you need to convert the file into a bin file and rename it to APP.bin

[USB/USBFS/HOST_IAP/HOST_IAP/](USB/USBFS/HOST_IAP/HOST_IAP/) - The host U disk IAP routine based on the U disk read file routine finishing, read the file with the name bit APP.bin from the U disk, write it to the internal flash, check it and jump automatically.

[USB/USBFS/HOST_KM/](USB/USBFS/HOST_KM/) - The host operates the keypad, gets the data of the endpoints uploaded by the keypad and prints it, supports U-port under level 1 hub

[USB/USBFS/HOST_MTP_FileSystem/](USB/USBFS/HOST_MTP_FileSystem/) - Enumeration process of a USB host to a device that supports MTP and PTP protocols, supports MTP and PTP protocols, and reads its files

[USB/USBFS/Host_Udisk/](USB/USBFS/Host_Udisk/) - USB host operation USB disk routine

[USB/USBFS/Udisk_Lib/](USB/USBFS/Udisk_Lib/) - U disk file system library file.

## WWDG - Window Watchdog Timer

It is a type of watchdog timer used in microcontrollers to detect and recover from software malfunctions. Unlike a standard watchdog timer, which only checks if the system is reset within a maximum time period, a window watchdog timer adds an additional layer of safety by requiring the system to reset within a specific time window.

[WWDG/WWDG/](WWDG/WWDG/) - Window Watchdog Routine.

_______________
Tauno Erik ♥ Väimela ♥ 2025
