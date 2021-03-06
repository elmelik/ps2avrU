#include <stdio.h>
#include <stdbool.h>

#include "options.h"
#include "optionsled.h"
#include "esctilde.h"
#include "fncontrol.h"
#include "hardwareinfo.h"
#include "numlocklayer.h"
#include "keymatrix.h"

void setOptions(uint8_t *data)
{
    setLedOptions(data);

    if(*(data+1) == OPTION_INDEX_ESC_TO_TILDE)
    {
        setEscTilde(*(data+2));
    }
    else if(*(data+1) == OPTION_INDEX_NUMLOCK_LAYER)
    {
        setNumlockLayer(*(data+2));
    }
    else if(*(data+1) == OPTION_INDEX_DEBOUNCE_VALUE)
    {
        setDebounceValue(*(data+2));
    }
}

void getOptions(option_info_t *buffer)
{
    getLedOptions(buffer);

    buffer->esctotilde = isEscTilde();
//    buffer->fnled = getBeyondFnLed();

    // Ver 1.2
    buffer->version[0] = VERSION_MAJOR;
    buffer->version[1] = VERSION_MINOR;
    buffer->version[2] = VERSION_PATCH;
    buffer->firmware = FIRMWARE;
    buffer->numlocklayer = getNumlockLayer();

    // Ver 1.3
    buffer->debouncevalue = getDebounceValue();
    buffer->size = sizeof(option_info_t);
}

