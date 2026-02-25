#include "stm32f4xx_hal_msp.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_i2c.h"
#include "leds.h"
#include "sw.h"
#include "lm75.h"
#include "stm32f4xx_hal.h"

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim5;
UART_HandleTypeDef huart2;
I2C_HandleTypeDef hi2c1;

//===========================================================
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
	}
}
//============================================================
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == &huart2)
	{
	}
}
//============================================================
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

}
//============================================================
int main()
{
    HAL_Init();
    HAL_MspInit();
    red_led(0);
    blue_led(0);
    green_led(0);

    // Configuration TIM5 : période de 1 seconde (valeurs temporaires pour test)
    htim5.Instance = TIM5;
    htim5.Init.Prescaler = 8399;   // (PSC+1) = 8400 → Tick = 100µs
    htim5.Init.Period    = 9999;   // (ARR+1) = 10000 → T_CNT = 1s
    HAL_TIM_Base_Init(&htim5);
    HAL_TIM_Base_Start(&htim5);

    while (1)
    {
        // La LED bascule quand le compteur dépasse la moitié de sa période
        if (htim5.Instance->CNT < 5000)
            red_led(1);
        else
            red_led(0);
    }
    return 0;
}
//============================================================

