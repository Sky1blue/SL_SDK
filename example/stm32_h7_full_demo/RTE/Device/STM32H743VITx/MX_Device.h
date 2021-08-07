/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 07/08/2021 15:17:14
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
#define MX_USBFreq_Value                        480000000
#define MX_WatchDogFreq_Value                   32000
#define MX_DSIFreq_Value                        96000000
#define MX_DSIPHYCLKFreq_Value                  96000000
#define MX_DSITXEscFreq_Value                   20000000
#define MX_SPDIFRXFreq_Value                    480000000
#define MX_MCO1PinFreq_Value                    64000000
#define MX_MCO2PinFreq_Value                    480000000

/*-------------------------------- CORTEX_M7  --------------------------------*/

#define MX_CORTEX_M7                            1

/* GPIO Configuration */

/*-------------------------------- DMA        --------------------------------*/

#define MX_DMA                                  1

/* NVIC Configuration */

/* NVIC DMA1_Stream0_IRQn */
#define MX_DMA1_Stream0_IRQn_interruptPremptionPriority 13
#define MX_DMA1_Stream0_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA1_Stream0_IRQn_Subriority         0

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

/* Pin PA1 */
#define MX_PA1_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PA1_Pin                              PA1
#define MX_PA1_GPIOx                            GPIOA
#define MX_PA1_PinState                         GPIO_PIN_RESET
#define MX_PA1_GPIO_PuPd                        GPIO_PULLUP
#define MX_LED_RUNNING                          PA1
#define MX_PA1_GPIO_Pin                         GPIO_PIN_1
#define MX_PA1_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

#endif  /* __MX_DEVICE_H */

