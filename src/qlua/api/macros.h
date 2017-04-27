#pragma once

#define QLUACPP_DETAIL_API_FUNCTION2(RETURN_TYPE, NAME) \
  RETURN_TYPE NAME() const {                            \
    typedef RETURN_TYPE bare_return_type;               \
    typedef std::tuple<bare_return_type> return_type;   \
    return std::get<0>(l_.call<return_type>(#NAME));    \
  }                                                     \

#define QLUACPP_DETAIL_API_FUNCTION4(RETURN_TYPE, NAME,         \
                                     ARG1_TYPE, ARG1)           \
  RETURN_TYPE NAME(ARG1_TYPE ARG1) const {                      \
    typedef RETURN_TYPE bare_return_type;                       \
    typedef std::tuple<bare_return_type> return_type;           \
    return std::get<0>(l_.call<return_type>(#NAME, ARG1));      \
  }                                                             \

#define QLUACPP_DETAIL_API_FUNCTION6(RETURN_TYPE, NAME,         \
                                     ARG1_TYPE, ARG1,           \
                                     ARG2_TYPE, ARG2)           \
  RETURN_TYPE NAME(ARG1_TYPE ARG1, ARG2_TYPE ARG2) const {      \
    typedef std::tuple<RETURN_TYPE> return_type;                \
    return std::get<0>(l_.call<return_type>(#NAME, ARG1));      \
  }                                                             \

#define QLUACPP_DETAIL_API_FUNCTION14(RETURN_TYPE, NAME,        \
                                      ARG1_TYPE, ARG1,          \
                                      ARG2_TYPE, ARG2,          \
                                      ARG3_TYPE, ARG3,          \
                                      ARG4_TYPE, ARG4,          \
                                      ARG5_TYPE, ARG5,          \
                                      ARG6_TYPE, ARG6)          \
  RETURN_TYPE NAME(ARG1_TYPE ARG1,                              \
                   ARG2_TYPE ARG2,                              \
                   ARG3_TYPE ARG3,                              \
                   ARG4_TYPE ARG4,                              \
                   ARG5_TYPE ARG5,                              \
                   ARG6_TYPE ARG6) const {                      \
    typedef std::tuple<RETURN_TYPE> return_type;                \
    return std::get<0>(l_.call<return_type>(#NAME,              \
                                            ARG1,               \
                                            ARG2,               \
                                            ARG3,               \
                                            ARG4,               \
                                            ARG5,               \
                                            ARG6));             \
  }                                                             \

  

#define QLUACPP_DETAIL_API_FUNCTION_VOID3(NAME,                 \
                                          ARG1_TYPE, ARG1)      \
  void NAME(ARG1_TYPE ARG1) const {                             \
    l_.call<std::tuple<>>(#NAME, ARG1);                         \
  }                                                             \

