#!/bin/sh

#SVP Environment
#ln -s /dev/input/mouse0 /dev/mouse
export SVP_ROOT_PATH=/svp
export SVP_MEDIA_PATH=/media
export SVP_STORAGE_PATH=/storage

export SVP_ETC_PATH=${SVP_ROOT_PATH}/etc
#export SVP_RES_PATH=${SVP_ROOT_PATH}/share
export SVP_RES_PATH=${SVP_ROOT_PATH}/res
export SVP_FONT_PATH=${SVP_RES_PATH}/fonts
export SVP_THEME_PATH=${SVP_RES_PATH}/theme
export SVP_WALLPAPER_PATH=${SVP_RES_PATH}/wallpaper
export SVP_SOUND_PATH=${SVP_RES_PATH}/sound

export SVP_TMP_PATH=/tmp/run
export SVP_TMP_STORAGE_PATH=${SVP_TMP_PATH}/storage
export SVP_TMP_DATA_PATH=${SVP_TMP_STORAGE_PATH}/data

# Read Only Path: (Read + Write Under Update Mode)
export SVP_SYS_APP_INSTALL_PATH=${SVP_STORAGE_PATH}/app
export SVP_SYS_DATA_PATH=${SVP_STORAGE_PATH}

export SVP_UPDATE_PATH=${SVP_STORAGE_PATH}/update
export SVP_APP_PKG_PATH=${SVP_UPDATE_PATH}/app-pkg
export SVP_RMT_PKG_FILE=${SVP_UPDATE_PATH}/vic.bin

# Read + Write Path:
export SVP_DATA_PARTITION=/dev/mmcblk0p4
export SVP_USER_ROOT_PATH=${SVP_STORAGE_PATH}/data
export SVP_USER_APP_INSTALL_PATH=${SVP_USER_ROOT_PATH}/app
export SVP_USER_DATA_PATH=${SVP_USER_ROOT_PATH}/data
export SVP_USER_ETC_PATH=${SVP_USER_ROOT_PATH}/etc

#GStreamer Environment
#export GST_REGISTRY=/storage/data/.gstreamer-0.10/registry.arm.bin

#PATH Environment
export LD_LIBRARY_PATH=${SVP_ROOT_PATH}/lib:${LD_LIBRARY_PATH}
export PATH=${SVP_ROOT_PATH}/bin:${SVP_ROOT_PATH}/etc:${SVP_ROOT_PATH}:/svp:${PATH}
#export PATH=${PATH}:/svp/lib/DesayAB02HD/sample/bin:/svp/lib/DesayAB02HD/gstreamer/bin
#export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/svp/lib/DesayAB02HD/gstreamer/libs:/svp/lib/DesayAB02HD/sdk/libs
#export GST_PLUGIN_SYSTEM_PATH_1_0=/svp/lib/DesayAB02HD/gstreamer/libs/gstreamer-1.0
#export GST_PLUGIN_SCANNER=/svp/lib/DesayAB02HD/gstreamer/libs/gstreamer1.2/gstreamer-1.0/gst-plugin-scanner

export FRAMEBUFFER=/dev/fb3

#setup QT ENV
export QT_ROOT=/media/sdcard0/qt5
export QWS_MOUSE_PROTO=/dev/input/event0
export QT_QPA_PLATFORM_PLUGIN_PATH=$QT_ROOT/plugins
export QT_QPA_PLATFORM=linuxfb
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QT_ROOT/lib
export QML2_IMPORT_PATH=$QT_ROOT/qml
export QT_QPA_FONTDIR=/svp/share/fonts
export LD_PRELOAD=/svp/lib/preloadable_libiconv.so



#Debug Output: {"console" | "" | "none" | "null" | "kmsg" | "syslog" | "file"}
# Console: "console" | ""
# Disable: "none" | "null"
export APP_DEBUG_OUTPUT="none"
export SVP_DEBUG_OUTPUT="none"


#Debug Output: {"debug,info,warn,error"}
#you can combine any of them

export SVP_DEBUG_LEVEL="error|debug|info|warn"
