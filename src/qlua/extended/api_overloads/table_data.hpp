#pragma once

unsigned int getNumberOf(const std::string& TableName) { return api::getNumberOf(TableName.c_str()); }
unsigned int getNumberOf(const char* TableName) { return api::getNumberOf(TableName); }

