/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include "Pin_Connect.h"

/* ------------------------------------------------------------------------- */
/*                              VARIABLE BUTTON                              */
/* ------------------------------------------------------------------------- */

/**
 * Indicates the current state of the Button
 *
 * TRUE   : Button is pressing
 * FALSE  : Button is releasing (default)
 */
bool statusBtn = false;

/* Frequency of Checking Button */
unsigned long checkBtn;

/* ------------------------------------------------------------------------- */
/*                                  FUNCTION                                 */
/* ------------------------------------------------------------------------- */

/* Detect button, catch the "Edge-Up" */
byte detectButton(bool *ptrStatusBtn)
{
  int btn = analogRead(PIN_BTN);

  if (btn >= BTN_MIN && btn <= BTN_MAX)
  {
    /* Only need read ADC, when "statusBtn" is FALSE
    ** This means that the button is not currently pressed
    ** Skip if "statusBtn" still TRUE
    */
    if (!(*ptrStatusBtn))
    {
      delay(DEBOUNCE); // Skip Debounce (if have)
      btn = analogRead(PIN_BTN);

      if (btn >= BTN_1_MIN && btn <= BTN_1_MAX)
      {
        *ptrStatusBtn = true;
        return BTN_1;
      }
      else if (btn >= BTN_2_MIN && btn <= BTN_2_MAX)
      {
        *ptrStatusBtn = true;
        return BTN_2;
      }
      else if (btn >= BTN_3_MIN && btn <= BTN_3_MAX)
      {
        *ptrStatusBtn = true;
        return BTN_3;
      }
      else if (btn >= BTN_4_MIN && btn <= BTN_4_MAX)
      {
        *ptrStatusBtn = true;
        return BTN_4;
      }
      else if (btn >= BTN_12_MIN && btn <= BTN_12_MAX)
      {
        *ptrStatusBtn = true;
        return BTN_12;
      }
      else if (btn >= BTN_14_MIN && btn <= BTN_14_MAX)
      {
        *ptrStatusBtn = true;
        return BTN_14;
      }
      else if (btn >= BTN_32_MIN && btn <= BTN_32_MAX)
      {
        *ptrStatusBtn = true;
        return BTN_32;
      }
      else if (btn >= BTN_34_MIN && btn <= BTN_34_MAX)
      {
        *ptrStatusBtn = true;
        return BTN_34;
      }
      else
      {
        *ptrStatusBtn = false;
        return NONE_BTN; // Caused by Debounce
      }
    }
    else
    {
      return NONE_BTN; // Button being held (Hold Click)
    }
  }
  else
  {
    *ptrStatusBtn = false;
    return NONE_BTN; // Button is being released
  }
}

/* ------------------------------------------------------------------------- */
/*                                   CONFIG                                  */
/* ------------------------------------------------------------------------- */

void setup()
{
  /* To use the Debug feature */
  DEBUG_BEGIN(115200);
}

/* ------------------------------------------------------------------------- */
/*                                    MAIN                                   */
/* ------------------------------------------------------------------------- */

void loop()
{
  if (millis() - checkBtn >= TIME_CHECK_BTN)
  {
    switch (detectButton(&statusBtn))
    {
    case BTN_1:
    {
      DEBUG_PRINTLN("Btn 1");
      break;
    }
    case BTN_2:
    {
      DEBUG_PRINTLN("Btn 2");
      break;
    }
    case BTN_3:
    {
      DEBUG_PRINTLN("Btn 3");
      break;
    }
    case BTN_4:
    {
      DEBUG_PRINTLN("Btn 4");
      break;
    }
    case BTN_12:
    {
      DEBUG_PRINTLN("Btn 1 + 2");
      break;
    }
    case BTN_14:
    {
      DEBUG_PRINTLN("Btn 1 + 4");
      break;
    }
    case BTN_32:
    {
      DEBUG_PRINTLN("Btn 3 + 2");
      break;
    }
    case BTN_34:
    {
      DEBUG_PRINTLN("Btn 3 + 4");
      break;
    }
    case NONE_BTN:
    {
      break;
    }
    }

    /* --------------------------------------------------------------------- */

    checkBtn = millis();
  }
}