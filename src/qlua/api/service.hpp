#pragma once

// This file should be included only from qlua.hpp
QLUACPP_DETAIL_API_FUNCTION2(unsigned int, isConnected)

QLUACPP_DETAIL_API_FUNCTION2(const char*, getScriptPath)
QLUACPP_DETAIL_API_FUNCTION4(const char*, getInfoParam,
                             const char*, param_name)
QLUACPP_DETAIL_API_FUNCTION6(unsigned int, message,
                             const char*, text,
                             const unsigned int, icon_type)
QLUACPP_DETAIL_API_FUNCTION4(unsigned int, message,
                             const char*, text)
QLUACPP_DETAIL_API_FUNCTION2(const char*, getWorkingFolder)
QLUACPP_DETAIL_API_FUNCTION_VOID3(PrintDbgStr,
                             const char*, s)

