LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)

THIRDPARTY_PATH := thirdparty
THIRDPARTY_LOCAL_PATH := $(LOCAL_PATH)/thirdparty

LOCAL_MODULE := ffmpeg
LOCAL_SRC_FILES := $(THIRDPARTY_PATH)/libs/android/libffmpeg.so
include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)

LOCAL_CFLAGS := -D__STDC_CONSTANT_MACROS
FFMPEG_PATH := $(THIRDPARTY_LOCAL_PATH)/include/ffmpeg
STB_PATH := $(THIRDPARTY_LOCAL_PATH)/include/stb

MEDIA_PLAYER_LOCAL_PATH := $(LOCAL_PATH)/mediaplayer

LS_CPP=$(subst $(LOCAL_PATH)/,,$(wildcard $(1)/*.cpp))
LS_C=$(subst $(LOCAL_PATH)/,,$(wildcard $(1)/*.c))

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
    LOCAL_CFLAGS += -DHAVE_NEON=1
    LOCAL_ARM_NEON  := true 
    CFLAGS += -mfpu=neon 
endif

LOCAL_C_INCLUDES := $(FFMPEG_PATH) \
                    $(STB_PATH) \

LOCAL_MODULE        := cwqengine

LOCAL_SRC_FILES     := $(call LS_CPP, $(LOCAL_PATH)/base) \
                       $(call LS_CPP, $(LOCAL_PATH)/math) \
                       $(call LS_CPP, $(LOCAL_PATH)/engine) \
                       $(call LS_CPP, $(LOCAL_PATH)/renderer) \
                       $(call LS_CPP, $(LOCAL_PATH)/platform) \
                       $(call LS_CPP, $(LOCAL_PATH)/platform/android) \
                       $(call LS_CPP, $(MEDIA_PLAYER_LOCAL_PATH)/media) \
                       $(call LS_CPP, $(MEDIA_PLAYER_LOCAL_PATH)/audio) \
                       $(call LS_CPP, $(MEDIA_PLAYER_LOCAL_PATH)/audio/android) \
                       $(call LS_CPP, $(MEDIA_PLAYER_LOCAL_PATH)/video) \
                       $(call LS_CPP, $(MEDIA_PLAYER_LOCAL_PATH)/ijkutil) \
                       $(call LS_CPP, $(MEDIA_PLAYER_LOCAL_PATH)) \
                       $(call LS_CPP, $(LOCAL_PATH)/test) \


LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv2

LOCAL_SHARED_LIBRARIES := ffmpeg

include $(BUILD_SHARED_LIBRARY)
