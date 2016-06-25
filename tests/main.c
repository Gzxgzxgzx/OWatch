#include <stdint.h>
#include <stdio.h>

int main(void)
{
  uint32_t moder = ((uint32_t)0x00000003);
  moder &= ~((3UL << 2*12));
  moder |=  ((1UL << 2*12));

  printf("%zu\n", moder);

  return 0;
}
