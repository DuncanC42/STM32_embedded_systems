#include "sw.h"
#include "stm32f4xx_hal_gpio.h"

// SW_UP     --> PA4
// SW_DOWN   --> PB0
// SW_CENTER --> PB5
// SW_RIGHT  --> PC0
// SW_LEFT   --> PC1
//====================================================================
uint32_t sw_right_raw(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
}
//====================================================================
uint32_t sw_left_raw(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
}
//====================================================================
uint32_t sw_center_raw(void)
{
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
}
//====================================================================
uint32_t sw_up_raw(void)
{
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
}
//====================================================================
uint32_t sw_down_raw(void)
{
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
}
//====================================================================
//{CENTER, DOWN, UP, LEFT, RIGHT}
uint32_t sw_input_raw(void)
{
    uint32_t result = 0;

    // Bit 0 : RIGHT
    if (sw_right_raw()) {
        result |= (1 << 0);  // ou result |= 0x01;
    }

    // Bit 1 : LEFT
    if (sw_left_raw()) {
        result |= (1 << 1);  // ou result |= 0x02;
    }

    // Bit 2 : UP
    if (sw_up_raw()) {
        result |= (1 << 2);  // ou result |= 0x04;
    }

    // Bit 3 : DOWN
    if (sw_down_raw()) {
        result |= (1 << 3);  // ou result |= 0x08;
    }

    // Bit 4 : CENTER
    if (sw_center_raw()) {
        result |= (1 << 4);  // ou result |= 0x10;
    }

    return result;
}
//====================================================================
//====================================================================
uint32_t sw_right_debounce(void)
{
	// A COMPLETER
}
//====================================================================
uint32_t sw_left_debounce(void)
{
	// A COMPLETER
}
//====================================================================
uint32_t sw_up_debounce(void)
{
	// A COMPLETER
}
//====================================================================
uint32_t sw_down_debounce(void)
{
	// A COMPLETER
}
//====================================================================
uint32_t sw_center_debounce(void)
{
	// A COMPLETER
}
//====================================================================





