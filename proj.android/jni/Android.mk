LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
../../Classes/AdmodAndroid.cpp \
../../Classes/AIRandomSuggest.cpp \
../../Classes/AlgorithmPikachu.cpp \
../../Classes/AlgorithmRandom.cpp \
../../Classes/AndroidScene.cpp \
../../Classes/BaseOject.cpp \
../../Classes/ButtonCustom.cpp \
../../Classes/DrawLinePikachu.cpp \
../../Classes/GameBoard.cpp \
../../Classes/GameCenterAndGoolePlay.cpp \
../../Classes/GameScene.cpp \
../../Classes/HomeScene.cpp \
../../Classes/MyLine.cpp \
../../Classes/PikachuObject.cpp \
../../Classes/PopupGame.cpp \
../../Classes/ProgressBarCustom.cpp \
../../Classes/SettingScene.cpp \
                   ../../Classes/Admob.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
