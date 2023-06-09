#pragma once

#include <AP_HAL/AP_HAL_Boards.h>

#ifndef HAL_EFI_ENABLED
#define HAL_EFI_ENABLED !HAL_MINIMIZE_FEATURES && BOARD_FLASH_SIZE > 1024
#endif

#ifndef AP_EFI_BACKEND_DEFAULT_ENABLED
#define AP_EFI_BACKEND_DEFAULT_ENABLED HAL_EFI_ENABLED
#endif

#ifndef HAL_EFI_DRONECAN_ENABLED
#define HAL_EFI_DRONECAN_ENABLED AP_EFI_BACKEND_DEFAULT_ENABLED && HAL_MAX_CAN_PROTOCOL_DRIVERS && BOARD_FLASH_SIZE > 1024 && HAL_CANMANAGER_ENABLED
#endif

#ifndef AP_EFI_SCRIPTING_ENABLED
#define AP_EFI_SCRIPTING_ENABLED (AP_EFI_BACKEND_DEFAULT_ENABLED && AP_SCRIPTING_ENABLED)
#endif
