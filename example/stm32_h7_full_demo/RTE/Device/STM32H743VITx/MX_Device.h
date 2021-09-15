/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 15/09/2021 20:02:37
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            32000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            64000000
#define MX_HSE_VALUE                            25000000
#define MX_EXTERNAL_CLOCK_VALUE                 12288000
#define MX_PLLDSIFreq_Value                     500000000
#define MX_SYSCLKFreq_VALUE                     480000000
#define MX_HCLKFreq_Value                       240000000
#define MX_CortexFreq_Value                     480000000
#define MX_APB1Freq_Value                       120000000
#define MX_APB2Freq_Value                       120000000
#define MX_CECFreq_Value                        32000
#define MX_RTCFreq_Value                        32000
#define MX_USBFreq_Value                        120000000
#define MX_WatchDogFreq_Value                   32000
#define MX_DSIFreq_Value                        96000000
#define MX_DSIPHYCLKFreq_Value                  96000000
#define MX_DSITXEscFreq_Value                   20000000
#define MX_SPDIFRXFreq_Value                    120000000
#define MX_MCO1PinFreq_Value                    64000000
#define MX_MCO2PinFreq_Value                    480000000

/*-------------------------------- CORTEX_M7  --------------------------------*/

#define MX_CORTEX_M7                            1

/* GPIO Configuration */

/*-------------------------------- DCMI       --------------------------------*/

#define MX_DCMI                                 1

/* GPIO Configuration */

/* Pin PA6 */
#define MX_DCMI_PIXCLK_GPIO_Speed               GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_PIXCLK_Pin                      PA6
#define MX_DCMI_PIXCLK_GPIOx                    GPIOA
#define MX_DCMI_PIXCLK_GPIO_PuPd                GPIO_NOPULL
#define MX_DCMI_PIXCLK_GPIO_Pin                 GPIO_PIN_6
#define MX_DCMI_PIXCLK_GPIO_AF                  GPIO_AF13_DCMI
#define MX_DCMI_PIXCLK_GPIO_Mode                GPIO_MODE_AF_PP

/* Pin PB7 */
#define MX_DCMI_VSYNC_GPIO_Speed                GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_VSYNC_Pin                       PB7
#define MX_DCMI_VSYNC_GPIOx                     GPIOB
#define MX_DCMI_VSYNC_GPIO_PuPd                 GPIO_NOPULL
#define MX_DCMI_VSYNC_GPIO_Pin                  GPIO_PIN_7
#define MX_DCMI_VSYNC_GPIO_AF                   GPIO_AF13_DCMI
#define MX_DCMI_VSYNC_GPIO_FM7                  __NULL
#define MX_DCMI_VSYNC_GPIO_Mode                 GPIO_MODE_AF_PP

/* Pin PE4 */
#define MX_DCMI_D4_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_D4_Pin                          PE4
#define MX_DCMI_D4_GPIOx                        GPIOE
#define MX_DCMI_D4_GPIO_PuPd                    GPIO_NOPULL
#define MX_DCMI_D4_GPIO_Pin                     GPIO_PIN_4
#define MX_DCMI_D4_GPIO_AF                      GPIO_AF13_DCMI
#define MX_DCMI_D4_GPIO_Mode                    GPIO_MODE_AF_PP

/* Pin PA4 */
#define MX_DCMI_HSYNC_GPIO_Speed                GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_HSYNC_Pin                       PA4
#define MX_DCMI_HSYNC_GPIOx                     GPIOA
#define MX_DCMI_HSYNC_GPIO_PuPd                 GPIO_NOPULL
#define MX_DCMI_HSYNC_GPIO_Pin                  GPIO_PIN_4
#define MX_DCMI_HSYNC_GPIO_AF                   GPIO_AF13_DCMI
#define MX_DCMI_HSYNC_GPIO_Mode                 GPIO_MODE_AF_PP

/* Pin PD3 */
#define MX_DCMI_D5_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_D5_Pin                          PD3
#define MX_DCMI_D5_GPIOx                        GPIOD
#define MX_DCMI_D5_GPIO_PuPd                    GPIO_NOPULL
#define MX_DCMI_D5_GPIO_Pin                     GPIO_PIN_3
#define MX_DCMI_D5_GPIO_AF                      GPIO_AF13_DCMI
#define MX_DCMI_D5_GPIO_Mode                    GPIO_MODE_AF_PP

/* Pin PE5 */
#define MX_DCMI_D6_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_D6_Pin                          PE5
#define MX_DCMI_D6_GPIOx                        GPIOE
#define MX_DCMI_D6_GPIO_PuPd                    GPIO_NOPULL
#define MX_DCMI_D6_GPIO_Pin                     GPIO_PIN_5
#define MX_DCMI_D6_GPIO_AF                      GPIO_AF13_DCMI
#define MX_DCMI_D6_GPIO_Mode                    GPIO_MODE_AF_PP

/* Pin PE6 */
#define MX_DCMI_D7_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_D7_Pin                          PE6
#define MX_DCMI_D7_GPIOx                        GPIOE
#define MX_DCMI_D7_GPIO_PuPd                    GPIO_NOPULL
#define MX_DCMI_D7_GPIO_Pin                     GPIO_PIN_6
#define MX_DCMI_D7_GPIO_AF                      GPIO_AF13_DCMI
#define MX_DCMI_D7_GPIO_Mode                    GPIO_MODE_AF_PP

/* Pin PC6 */
#define MX_DCMI_D0_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_D0_Pin                          PC6
#define MX_DCMI_D0_GPIOx                        GPIOC
#define MX_DCMI_D0_GPIO_PuPd                    GPIO_NOPULL
#define MX_DCMI_D0_GPIO_Pin                     GPIO_PIN_6
#define MX_DCMI_D0_GPIO_AF                      GPIO_AF13_DCMI
#define MX_DCMI_D0_GPIO_Mode                    GPIO_MODE_AF_PP

/* Pin PC7 */
#define MX_DCMI_D1_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_D1_Pin                          PC7
#define MX_DCMI_D1_GPIOx                        GPIOC
#define MX_DCMI_D1_GPIO_PuPd                    GPIO_NOPULL
#define MX_DCMI_D1_GPIO_Pin                     GPIO_PIN_7
#define MX_DCMI_D1_GPIO_AF                      GPIO_AF13_DCMI
#define MX_DCMI_D1_GPIO_Mode                    GPIO_MODE_AF_PP

/* Pin PE0 */
#define MX_DCMI_D2_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_D2_Pin                          PE0
#define MX_DCMI_D2_GPIOx                        GPIOE
#define MX_DCMI_D2_GPIO_PuPd                    GPIO_NOPULL
#define MX_DCMI_D2_GPIO_Pin                     GPIO_PIN_0
#define MX_DCMI_D2_GPIO_AF                      GPIO_AF13_DCMI
#define MX_DCMI_D2_GPIO_Mode                    GPIO_MODE_AF_PP

/* Pin PE1 */
#define MX_DCMI_D3_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_DCMI_D3_Pin                          PE1
#define MX_DCMI_D3_GPIOx                        GPIOE
#define MX_DCMI_D3_GPIO_PuPd                    GPIO_NOPULL
#define MX_DCMI_D3_GPIO_Pin                     GPIO_PIN_1
#define MX_DCMI_D3_GPIO_AF                      GPIO_AF13_DCMI
#define MX_DCMI_D3_GPIO_Mode                    GPIO_MODE_AF_PP

/* DMA Configuration */

/* DMA DCMI */
#define MX_DCMI_DMA_MemBurst                    DMA_MBURST_SINGLE
#define MX_DCMI_DMA_Instance                    DMA2_Stream0
#define MX_DCMI_DMA_FIFOMode                    DMA_FIFOMODE_ENABLE
#define MX_DCMI_DMA_Priority                    DMA_PRIORITY_VERY_HIGH
#define MX_DCMI_DMA_MemDataAlignment            DMA_MDATAALIGN_WORD
#define MX_DCMI_DMA_Mode                        DMA_NORMAL
#define MX_DCMI_DMA_SyncRequestNumber           1
#define MX_DCMI_DMA_Request                     DMA_REQUEST_DCMI
#define MX_DCMI_DMA_SyncPolarity                HAL_DMAMUX_SYNC_NO_EVENT
#define MX_DCMI_DMA_Direction                   DMA_PERIPH_TO_MEMORY
#define MX_DCMI_DMA_PeriphBurst                 DMA_PBURST_SINGLE
#define MX_DCMI_DMA_SignalID                    NONE
#define MX_DCMI_DMA_MemInc                      DMA_MINC_ENABLE
#define MX_DCMI_DMA_IpInstance
#define MX_DCMI_DMA_RequestNumber               1
#define MX_DCMI_DMA_EventEnable                 DISABLE
#define MX_DCMI_DMA_SyncEnable                  DISABLE
#define MX_DCMI_DMA_DMA_Handle
#define MX_DCMI_DMA_PeriphDataAlignment         DMA_PDATAALIGN_WORD
#define MX_DCMI_DMA_Polarity                    HAL_DMAMUX_REQ_GEN_RISING
#define MX_DCMI_DMA_SyncSignalID                NONE
#define MX_DCMI_DMA_PeriphInc                   DMA_PINC_DISABLE
#define MX_DCMI_DMA_FIFOThreshold               DMA_FIFO_THRESHOLD_FULL

/* NVIC Configuration */

/* NVIC DCMI_IRQn */
#define MX_DCMI_IRQn_interruptPremptionPriority 6
#define MX_DCMI_IRQn_PriorityGroup              NVIC_PRIORITYGROUP_4
#define MX_DCMI_IRQn_Subriority                 0

/*-------------------------------- DMA        --------------------------------*/

#define MX_DMA                                  1

/* NVIC Configuration */

/* NVIC DMA1_Stream1_IRQn */
#define MX_DMA1_Stream1_IRQn_interruptPremptionPriority 9
#define MX_DMA1_Stream1_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA1_Stream1_IRQn_Subriority         0

/* NVIC DMA1_Stream2_IRQn */
#define MX_DMA1_Stream2_IRQn_interruptPremptionPriority 13
#define MX_DMA1_Stream2_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA1_Stream2_IRQn_Subriority         0

/* NVIC DMA2_Stream0_IRQn */
#define MX_DMA2_Stream0_IRQn_interruptPremptionPriority 7
#define MX_DMA2_Stream0_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA2_Stream0_IRQn_Subriority         0

/* NVIC DMA1_Stream0_IRQn */
#define MX_DMA1_Stream0_IRQn_interruptPremptionPriority 13
#define MX_DMA1_Stream0_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA1_Stream0_IRQn_Subriority         0

/*-------------------------------- I2C2       --------------------------------*/

#define MX_I2C2                                 1

/* GPIO Configuration */

/* Pin PB11 */
#define MX_I2C2_SDA_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_I2C2_SDA_Pin                         PB11
#define MX_I2C2_SDA_GPIOx                       GPIOB
#define MX_I2C2_SDA_GPIO_Pin                    GPIO_PIN_11
#define MX_I2C2_SDA_GPIO_AF                     GPIO_AF4_I2C2
#define MX_I2C2_SDA_GPIO_Pu                     GPIO_PULLUP
#define MX_I2C2_SDA_GPIO_Mode                   GPIO_MODE_AF_OD

/* Pin PB10 */
#define MX_I2C2_SCL_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_I2C2_SCL_Pin                         PB10
#define MX_I2C2_SCL_GPIOx                       GPIOB
#define MX_I2C2_SCL_GPIO_Pin                    GPIO_PIN_10
#define MX_I2C2_SCL_GPIO_AF                     GPIO_AF4_I2C2
#define MX_I2C2_SCL_GPIO_Pu                     GPIO_PULLUP
#define MX_I2C2_SCL_GPIO_Mode                   GPIO_MODE_AF_OD

/*-------------------------------- QUADSPI    --------------------------------*/

#define MX_QUADSPI                              1

/* GPIO Configuration */

/* Pin PB2 */
#define MX_QUADSPI_CLK_GPIO_Speed               GPIO_SPEED_FREQ_VERY_HIGH
#define MX_QUADSPI_CLK_Pin                      PB2
#define MX_QUADSPI_CLK_GPIOx                    GPIOB
#define MX_QUADSPI_CLK_GPIO_PuPd                GPIO_NOPULL
#define MX_QUADSPI_CLK_GPIO_Pin                 GPIO_PIN_2
#define MX_QUADSPI_CLK_GPIO_AF                  GPIO_AF9_QUADSPI
#define MX_QUADSPI_CLK_GPIO_Mode                GPIO_MODE_AF_PP

/* Pin PB6 */
#define MX_QUADSPI_BK1_NCS_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_QUADSPI_BK1_NCS_GPIO_FM6             __NULL
#define MX_QUADSPI_BK1_NCS_Pin                  PB6
#define MX_QUADSPI_BK1_NCS_GPIOx                GPIOB
#define MX_QUADSPI_BK1_NCS_GPIO_PuPd            GPIO_PULLUP
#define MX_QUADSPI_BK1_NCS_GPIO_Pin             GPIO_PIN_6
#define MX_QUADSPI_BK1_NCS_GPIO_AF              GPIO_AF10_QUADSPI
#define MX_QUADSPI_BK1_NCS_GPIO_Mode            GPIO_MODE_AF_PP

/* Pin PD13 */
#define MX_QUADSPI_BK1_IO3_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_QUADSPI_BK1_IO3_Pin                  PD13
#define MX_QUADSPI_BK1_IO3_GPIOx                GPIOD
#define MX_QUADSPI_BK1_IO3_GPIO_PuPd            GPIO_NOPULL
#define MX_QUADSPI_BK1_IO3_GPIO_Pin             GPIO_PIN_13
#define MX_QUADSPI_BK1_IO3_GPIO_AF              GPIO_AF9_QUADSPI
#define MX_QUADSPI_BK1_IO3_GPIO_Mode            GPIO_MODE_AF_PP

/* Pin PE2 */
#define MX_QUADSPI_BK1_IO2_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_QUADSPI_BK1_IO2_Pin                  PE2
#define MX_QUADSPI_BK1_IO2_GPIOx                GPIOE
#define MX_QUADSPI_BK1_IO2_GPIO_PuPd            GPIO_NOPULL
#define MX_QUADSPI_BK1_IO2_GPIO_Pin             GPIO_PIN_2
#define MX_QUADSPI_BK1_IO2_GPIO_AF              GPIO_AF9_QUADSPI
#define MX_QUADSPI_BK1_IO2_GPIO_Mode            GPIO_MODE_AF_PP

/* Pin PD12 */
#define MX_QUADSPI_BK1_IO1_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_QUADSPI_BK1_IO1_Pin                  PD12
#define MX_QUADSPI_BK1_IO1_GPIOx                GPIOD
#define MX_QUADSPI_BK1_IO1_GPIO_PuPd            GPIO_NOPULL
#define MX_QUADSPI_BK1_IO1_GPIO_Pin             GPIO_PIN_12
#define MX_QUADSPI_BK1_IO1_GPIO_AF              GPIO_AF9_QUADSPI
#define MX_QUADSPI_BK1_IO1_GPIO_Mode            GPIO_MODE_AF_PP

/* Pin PD11 */
#define MX_QUADSPI_BK1_IO0_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_QUADSPI_BK1_IO0_Pin                  PD11
#define MX_QUADSPI_BK1_IO0_GPIOx                GPIOD
#define MX_QUADSPI_BK1_IO0_GPIO_PuPd            GPIO_NOPULL
#define MX_QUADSPI_BK1_IO0_GPIO_Pin             GPIO_PIN_11
#define MX_QUADSPI_BK1_IO0_GPIO_AF              GPIO_AF9_QUADSPI
#define MX_QUADSPI_BK1_IO0_GPIO_Mode            GPIO_MODE_AF_PP

/* NVIC Configuration */

/* NVIC QUADSPI_IRQn */
#define MX_QUADSPI_IRQn_interruptPremptionPriority 4
#define MX_QUADSPI_IRQn_PriorityGroup           NVIC_PRIORITYGROUP_4
#define MX_QUADSPI_IRQn_Subriority              0

/*-------------------------------- SPI2       --------------------------------*/

#define MX_SPI2                                 1

/* GPIO Configuration */

/* Pin PB13 */
#define MX_SPI2_SCK_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_SCK_Pin                         PB13
#define MX_SPI2_SCK_GPIOx                       GPIOB
#define MX_SPI2_SCK_GPIO_PuPd                   GPIO_NOPULL
#define MX_SPI2_SCK_GPIO_Pin                    GPIO_PIN_13
#define MX_SPI2_SCK_GPIO_AF                     GPIO_AF5_SPI2
#define MX_SPI2_SCK_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PB14 */
#define MX_SPI2_MISO_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_MISO_Pin                        PB14
#define MX_SPI2_MISO_GPIOx                      GPIOB
#define MX_SPI2_MISO_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI2_MISO_GPIO_Pin                   GPIO_PIN_14
#define MX_SPI2_MISO_GPIO_AF                    GPIO_AF5_SPI2
#define MX_SPI2_MISO_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PB15 */
#define MX_SPI2_MOSI_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_MOSI_Pin                        PB15
#define MX_SPI2_MOSI_GPIOx                      GPIOB
#define MX_SPI2_MOSI_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI2_MOSI_GPIO_Pin                   GPIO_PIN_15
#define MX_SPI2_MOSI_GPIO_AF                    GPIO_AF5_SPI2
#define MX_SPI2_MOSI_GPIO_Mode                  GPIO_MODE_AF_PP

/* DMA Configuration */

/* DMA SPI2_TX */
#define MX_SPI2_TX_DMA_Instance                 DMA1_Stream1
#define MX_SPI2_TX_DMA_FIFOMode                 DMA_FIFOMODE_DISABLE
#define MX_SPI2_TX_DMA_Priority                 DMA_PRIORITY_MEDIUM
#define MX_SPI2_TX_DMA_MemDataAlignment         DMA_MDATAALIGN_BYTE
#define MX_SPI2_TX_DMA_Mode                     DMA_NORMAL
#define MX_SPI2_TX_DMA_SyncRequestNumber        1
#define MX_SPI2_TX_DMA_Request                  DMA_REQUEST_SPI2_TX
#define MX_SPI2_TX_DMA_SyncPolarity             HAL_DMAMUX_SYNC_NO_EVENT
#define MX_SPI2_TX_DMA_Direction                DMA_MEMORY_TO_PERIPH
#define MX_SPI2_TX_DMA_SignalID                 NONE
#define MX_SPI2_TX_DMA_MemInc                   DMA_MINC_ENABLE
#define MX_SPI2_TX_DMA_IpInstance
#define MX_SPI2_TX_DMA_RequestNumber            1
#define MX_SPI2_TX_DMA_EventEnable              DISABLE
#define MX_SPI2_TX_DMA_SyncEnable               DISABLE
#define MX_SPI2_TX_DMA_DMA_Handle
#define MX_SPI2_TX_DMA_PeriphDataAlignment      DMA_PDATAALIGN_BYTE
#define MX_SPI2_TX_DMA_Polarity                 HAL_DMAMUX_REQ_GEN_RISING
#define MX_SPI2_TX_DMA_SyncSignalID             NONE
#define MX_SPI2_TX_DMA_PeriphInc                DMA_PINC_DISABLE

/* NVIC Configuration */

/* NVIC SPI2_IRQn */
#define MX_SPI2_IRQn_interruptPremptionPriority 8
#define MX_SPI2_IRQn_PriorityGroup              NVIC_PRIORITYGROUP_4
#define MX_SPI2_IRQn_Subriority                 0

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/*-------------------------------- USART1     --------------------------------*/

#define MX_USART1                               1

#define MX_USART1_VM                            VM_ASYNC

/* GPIO Configuration */

/* Pin PA9 */
#define MX_USART1_TX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART1_TX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART1_TX_Pin                        PA9
#define MX_USART1_TX_GPIOx                      GPIOA
#define MX_USART1_TX_GPIO_PuPd                  GPIO_PULLUP
#define MX_USART1_TX_GPIO_Pin                   GPIO_PIN_9
#define MX_USART1_TX_GPIO_AF                    GPIO_AF7_USART1

/* Pin PA10 */
#define MX_USART1_RX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART1_RX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART1_RX_Pin                        PA10
#define MX_USART1_RX_GPIOx                      GPIOA
#define MX_USART1_RX_GPIO_PuPd                  GPIO_PULLUP
#define MX_USART1_RX_GPIO_Pin                   GPIO_PIN_10
#define MX_USART1_RX_GPIO_AF                    GPIO_AF7_USART1

/* DMA Configuration */

/* DMA USART1_TX */
#define MX_USART1_TX_DMA_Instance               DMA1_Stream2
#define MX_USART1_TX_DMA_FIFOMode               DMA_FIFOMODE_DISABLE
#define MX_USART1_TX_DMA_Priority               DMA_PRIORITY_LOW
#define MX_USART1_TX_DMA_MemDataAlignment       DMA_MDATAALIGN_BYTE
#define MX_USART1_TX_DMA_Mode                   DMA_NORMAL
#define MX_USART1_TX_DMA_SyncRequestNumber      1
#define MX_USART1_TX_DMA_Request                DMA_REQUEST_USART1_TX
#define MX_USART1_TX_DMA_SyncPolarity           HAL_DMAMUX_SYNC_NO_EVENT
#define MX_USART1_TX_DMA_Direction              DMA_MEMORY_TO_PERIPH
#define MX_USART1_TX_DMA_SignalID               NONE
#define MX_USART1_TX_DMA_MemInc                 DMA_MINC_ENABLE
#define MX_USART1_TX_DMA_IpInstance
#define MX_USART1_TX_DMA_RequestNumber          1
#define MX_USART1_TX_DMA_EventEnable            DISABLE
#define MX_USART1_TX_DMA_SyncEnable             DISABLE
#define MX_USART1_TX_DMA_DMA_Handle
#define MX_USART1_TX_DMA_PeriphDataAlignment    DMA_PDATAALIGN_BYTE
#define MX_USART1_TX_DMA_Polarity               HAL_DMAMUX_REQ_GEN_RISING
#define MX_USART1_TX_DMA_SyncSignalID           NONE
#define MX_USART1_TX_DMA_PeriphInc              DMA_PINC_DISABLE

/* DMA USART1_RX */
#define MX_USART1_RX_DMA_Instance               DMA1_Stream0
#define MX_USART1_RX_DMA_FIFOMode               DMA_FIFOMODE_DISABLE
#define MX_USART1_RX_DMA_Priority               DMA_PRIORITY_LOW
#define MX_USART1_RX_DMA_MemDataAlignment       DMA_MDATAALIGN_BYTE
#define MX_USART1_RX_DMA_Mode                   DMA_NORMAL
#define MX_USART1_RX_DMA_SyncRequestNumber      1
#define MX_USART1_RX_DMA_Request                DMA_REQUEST_USART1_RX
#define MX_USART1_RX_DMA_SyncPolarity           HAL_DMAMUX_SYNC_NO_EVENT
#define MX_USART1_RX_DMA_Direction              DMA_PERIPH_TO_MEMORY
#define MX_USART1_RX_DMA_SignalID               NONE
#define MX_USART1_RX_DMA_MemInc                 DMA_MINC_ENABLE
#define MX_USART1_RX_DMA_IpInstance
#define MX_USART1_RX_DMA_RequestNumber          1
#define MX_USART1_RX_DMA_EventEnable            DISABLE
#define MX_USART1_RX_DMA_SyncEnable             DISABLE
#define MX_USART1_RX_DMA_DMA_Handle
#define MX_USART1_RX_DMA_PeriphDataAlignment    DMA_PDATAALIGN_BYTE
#define MX_USART1_RX_DMA_Polarity               HAL_DMAMUX_REQ_GEN_RISING
#define MX_USART1_RX_DMA_SyncSignalID           NONE
#define MX_USART1_RX_DMA_PeriphInc              DMA_PINC_DISABLE

/* NVIC Configuration */

/* NVIC USART1_IRQn */
#define MX_USART1_IRQn_interruptPremptionPriority 12
#define MX_USART1_IRQn_PriorityGroup            NVIC_PRIORITYGROUP_4
#define MX_USART1_IRQn_Subriority               0

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

/* Pin PC4 */
#define MX_PC4_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PC4_Pin                              PC4
#define MX_PC4_GPIOx                            GPIOC
#define MX_PC4_PinState                         GPIO_PIN_SET
#define MX_PC4_GPIO_PuPd                        GPIO_PULLUP
#define MX_CAM_RESET                            PC4
#define MX_PC4_GPIO_Pin                         GPIO_PIN_4
#define MX_PC4_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PA1 */
#define MX_PA1_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PA1_Pin                              PA1
#define MX_PA1_GPIOx                            GPIOA
#define MX_PA1_PinState                         GPIO_PIN_SET
#define MX_PA1_GPIO_PuPd                        GPIO_PULLUP
#define MX_LED_RUNNING                          PA1
#define MX_PA1_GPIO_Pin                         GPIO_PIN_1
#define MX_PA1_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PA5 */
#define MX_PA5_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PA5_Pin                              PA5
#define MX_PA5_GPIOx                            GPIOA
#define MX_PA5_PinState                         GPIO_PIN_RESET
#define MX_PA5_GPIO_PuPd                        GPIO_PULLDOWN
#define MX_CAM_LIGHT                            PA5
#define MX_PA5_GPIO_Pin                         GPIO_PIN_5
#define MX_PA5_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PB12 */
#define MX_PB12_GPIO_Speed                      GPIO_SPEED_FREQ_VERY_HIGH
#define MX_PB12_Pin                             PB12
#define MX_PB12_GPIOx                           GPIOB
#define MX_PB12_PinState                        GPIO_PIN_SET
#define MX_PB12_GPIO_PuPd                       GPIO_PULLUP
#define MX_LCD_SPI_CS                           PB12
#define MX_PB12_GPIO_Pin                        GPIO_PIN_12
#define MX_PB12_GPIO_ModeDefaultOutputPP        GPIO_MODE_OUTPUT_PP

/* Pin PA7 */
#define MX_PA7_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PA7_Pin                              PA7
#define MX_PA7_GPIOx                            GPIOA
#define MX_PA7_PinState                         GPIO_PIN_SET
#define MX_PA7_GPIO_PuPd                        GPIO_PULLUP
#define MX_CAM_POWER                            PA7
#define MX_PA7_GPIO_Pin                         GPIO_PIN_7
#define MX_PA7_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PB1 */
#define MX_PB1_GPIO_Speed                       GPIO_SPEED_FREQ_VERY_HIGH
#define MX_PB1_Pin                              PB1
#define MX_PB1_GPIOx                            GPIOB
#define MX_PB1_PinState                         GPIO_PIN_SET
#define MX_PB1_GPIO_PuPd                        GPIO_PULLUP
#define MX_LCD_SPI_DC                           PB1
#define MX_PB1_GPIO_Pin                         GPIO_PIN_1
#define MX_PB1_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PB0 */
#define MX_PB0_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PB0_Pin                              PB0
#define MX_PB0_GPIOx                            GPIOB
#define MX_PB0_PinState                         GPIO_PIN_SET
#define MX_PB0_GPIO_PuPd                        GPIO_PULLUP
#define MX_LCD_BLK                              PB0
#define MX_PB0_GPIO_Pin                         GPIO_PIN_0
#define MX_PB0_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

#endif  /* __MX_DEVICE_H */

