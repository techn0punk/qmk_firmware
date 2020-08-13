# 'serial' Driver
This driver powers the [Split Keyboard](feature_split_keyboard.md) feature.

?> Serial in this context should be read as **sending information one bit at a time**, rather than implementing UART/USART/RS485/RS232 standards.

Drivers in this category have the following characteristics:
* bit bang and USART Half-duplex provide data and signaling over a single conductor
* USART Full-duplex provide data and signaling over two conductors
* They are all limited to single initiator and single target communication scheme

## Supported Driver Types

|                   | AVR                | ARM                |
|-------------------|--------------------|--------------------|
| bit bang          | :heavy_check_mark: | :heavy_check_mark: |
| USART Half-duplex |                    | :heavy_check_mark: |
| USART Full-duplex |                    | :heavy_check_mark: |

## Driver configuration

### Bitbang
Default driver, the absence of configuration assumes this driver. To configure it, add this to your rules.mk:

```make
SERIAL_DRIVER = bitbang
```

Configure the driver via your config.h:
```c
#define SERIAL_PIN_TX D0  // or D1, D2, D3, E6
#define SELECT_SERIAL_SPEED 1 // or 0, 2, 3, 4, 5
                                   //  0: about 189kbps (Experimental only)
                                   //  1: about 137kbps (default)
                                   //  2: about 75kbps
                                   //  3: about 39kbps
                                   //  4: about 26kbps
                                   //  5: about 20kbps
```

#### ARM

!> The bitbang driver causes connection issues with bitbang WS2812 driver

Along with the generic options above, you must also turn on the `PAL_USE_CALLBACKS` feature in your halconf.h.

### USART Half-duplex
Targeting STM32 boards where communication is offloaded to a USART hardware device. The advantage over bitbang is that this provides fast and accurate timings. `SERIAL_PIN_TX` for this driver is the configured USART TX pin. As this Pin is configured in open-drain mode an **external pull-up resistor is needed to keep the line high**. To configure it, add this to your rules.mk:

```make
SERIAL_DRIVER = usart
```

Configure the hardware via your config.h:
```c
#define SERIAL_PIN_TX B6  // USART TX pin
#define SELECT_SERIAL_SPEED 1 // or 0, 2, 3, 4, 5
                                   //  0: about 460800 baud
                                   //  1: about 230400 baud (default)
                                   //  2: about 115200 baud
                                   //  3: about 57600 baud
                                   //  4: about 38400 baud
                                   //  5: about 19200 baud
#define SERIAL_USART_DRIVER SD1 // USART driver of TX pin. default: SD1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
```

You must also enable the ChibiOS `SERIAL` feature:
* In your board's halconf.h: `#define HAL_USE_SERIAL TRUE`
* In your board's mcuconf.h: `#define STM32_SERIAL_USE_USARTn TRUE` (where 'n' matches the peripheral number of your selected USART on the MCU)

Do note that the configuration required is for the `SERIAL` peripheral, not the `UART` peripheral.

### USART Full-duplex
Targeting STM32 boards where communication is offloaded to a USART hardware device. The advantage over bitbang is that this provides fast and accurate timings. USART Full-Duplex requires two conductors instead of one conductor like the Half-duplex driver, but it is more efficent as it uses DMA transfers, which can result in even faster transmission speeds. To use this driver the usart peripherals `TX` and `RX` pins must be configured. `SERIAL_PIN_TX` is the USART `TX` pin, `SERIAL_PIN_RX` is the USART `RX` pin. No external pull-up resistors are needed as the `TX` pin operates in push-pull mode.

To use the driver, add this to your rules.mk:

```make
SERIAL_DRIVER = usart_duplex
```

Next configure the hardware via your config.h:

```c
#define SERIAL_PIN_TX B6  // USART TX pin
#define SERIAL_PIN_RX B7  // USART RX pin
#define SELECT_SERIAL_SPEED 1 // or 0, 2, 3, 4, 5
                                   //  0: about 460800 baud
                                   //  1: about 230400 baud (default)
                                   //  2: about 115200 baud
                                   //  3: about 57600 baud
                                   //  4: about 38400 baud
                                   //  5: about 19200 baud
#define SERIAL_USART_DRIVER UARTD1 // USART driver of TX and RX pin. default: UARTD1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
```

You must also enable the ChibiOS `UART` with blocking api feature:
* In your board's halconf.h: `#define HAL_USE_USAR TRUE` and `#define UART_USE_WAIT TRUE`
* In your board's mcuconf.h: `#define STM32_UART_USE_USARTn TRUE` (where 'n' matches the peripheral number of your selected USART on the MCU)

Do note that the configuration required is for the `UART` peripheral, not the `SERIAL` peripheral.
