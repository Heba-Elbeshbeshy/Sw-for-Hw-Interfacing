
#include "INTERRUPT.h"
#include "GPIO.h"

int main(void)
{
    GPIO_EnableClock(0);  // Enable GPIOA
    SYSCFG_EnableClock(); // Enable SYSCFG

    // Button GPIOA pin0
    GPIO_Init(0, 0, INPUT, PULL_UP);

    // Led
    GPIO_Init(0, 1, OUTPUT, PUSH_PULL);

    // Configuration_EXTI
    Configuration_EXTI(0);

    while (1)
    {
    }
    return 0;
}

// ISR
void MY_EXTI0()
{
    // Toggle Led
    *GPIOA_ODR ^= 1 << 1;
    // Clear
    *EXTI_PR |= 1 << 0;
}
