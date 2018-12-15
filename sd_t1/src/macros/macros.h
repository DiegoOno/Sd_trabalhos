//Macros

//Change the state of the bit
#ifndef SWT_BIT
#define SWT_BIT(REG, POS) (REG ^= (1 << POS))
#endif

//Set 1 
#ifndef SET_BIT
#define SET_BIT(REG, POS) (REG |= (1 << POS))
#endif

//Set 0
#ifndef CLEAR_BIT
#define CLEAR_BIT(REG, POS) (REG &= ~(1 << POS))
#endif

//Compare if the bit is one
#ifndef TST_BIT
#define TST_BIT(REG, POS) (REG & (1 << POS))
#endif