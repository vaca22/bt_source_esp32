execute_process(COMMAND git describe --always --tags --dirty
                OUTPUT_VARIABLE ADF_VER
                OUTPUT_STRIP_TRAILING_WHITESPACE)

