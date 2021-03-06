#include "stk.h"

void enable_stk(uint32_t period_ms)
{
    // Disable timer
    STK->csr &= ~STK_CSR_ENABLE;

    // Set reload value
    STK->rvr &= ~STK_RVR_RELOAD;
    STK->rvr |= (period_ms * STK->calib) & 0xFFFFFF;

    // Reset current value 
    STK->cvr &= ~STK_CVR_CURRENT;

    // Enable interrupt and use processor as clock source
    STK->csr |= STK_CSR_TICKINT | STK_CSR_CLKSOURCE;

    // Enable timer
    STK->csr |= STK_CSR_ENABLE;
}