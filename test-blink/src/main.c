#include "stm32f1xx.h"

void GPIO_Config(void);
void delay(uint32_t value);

int main()
{

  GPIO_Config();

  while(1)
  {
    GPIOC->ODR ^= GPIO_ODR_ODR13;
    delay(1000000);
  }// end enbedded loop

}

void GPIO_Config(void)
{
  // Pino C13
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;                     // Habilita o clock do portC
  GPIOC->CRH |= GPIO_CRH_MODE13_0 | GPIO_CRH_MODE13_1;    // Configura como Saida rapida
  GPIOC->CRH &= ~(GPIO_CRH_CNF13_0 | GPIO_CRH_CNF13_1);   // COnfigura modo Push-Pull
  GPIOC->ODR |= GPIO_ODR_ODR13;
}

void delay(uint32_t value)
{
  while(value--)
  {
    __NOP();
    __NOP();
    __NOP();
  }
}