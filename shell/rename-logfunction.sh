#!/bin/bash

# debug data
sed -i "s/MyLog::d(__FILE__, /SVP_DEBUG(/g" `grep "MyLog::d(__FILE__, "  -rl $1`
sed -i "s/MyLog::d(__FILE__,/SVP_DEBUG(/g" `grep "MyLog::d(__FILE__,"  -rl $1`

sed -i "s/MyLog::d(TAG, /SVP_DEBUG(/g" `grep "MyLog::d(TAG, "  -rl $1`
sed -i "s/MyLog::d(TAG,/SVP_DEBUG(/g" `grep "MyLog::d(TAG,"  -rl $1`

sed -i "s/MyLog::d(__FUNCTION__, /SVP_DEBUG(/g" `grep "MyLog::d(__FUNCTION__, "  -rl $1`
sed -i "s/MyLog::d(__FUNCTION__,/SVP_DEBUG(/g" `grep "MyLog::d(__FUNCTION__,"  -rl $1`

#  error data
sed -i "s/MyLog::e(__FILE__, /SVP_ERROR(/g" `grep "MyLog::e(__FILE__, "  -rl $1`
sed -i "s/MyLog::e(__FILE__,/SVP_ERROR(/g" `grep "MyLog::e(__FILE__,"  -rl $1`

sed -i "s/MyLog::e(TAG, /SVP_ERROR(/g" `grep "MyLog::e(TAG, "  -rl $1`
sed -i "s/MyLog::e(TAG,/SVP_ERROR(/g" `grep "MyLog::e(TAG,"  -rl $1`

sed -i "s/MyLog::e(__FUNCTION__, /SVP_ERROR(/g" `grep "MyLog::e(__FUNCTION__, "  -rl $1`
sed -i "s/MyLog::e(__FUNCTION__,/SVP_ERROR(/g" `grep "MyLog::e(__FUNCTION__,"  -rl $1`

#  info data
sed -i "s/MyLog::i(__FILE__, /SVP_INFO(/g" `grep "MyLog::i(__FILE__, "  -rl $1`
sed -i "s/MyLog::i(__FILE__,/SVP_INFO(/g" `grep "MyLog::i(__FILE__,"  -rl $1`

sed -i "s/MyLog::i(TAG, /SVP_INFO(/g" `grep "MyLog::i(TAG, "  -rl $1`
sed -i "s/MyLog::i(TAG,/SVP_INFO(/g" `grep "MyLog::i(TAG,"  -rl $1`

sed -i "s/MyLog::i(__FUNCTION__, /SVP_INFO(/g" `grep "MyLog::i(__FUNCTION__, "  -rl $1`
sed -i "s/MyLog::i(__FUNCTION__,/SVP_INFO(/g" `grep "MyLog::i(__FUNCTION__,"  -rl $1`


#  warn data
sed -i "s/MyLog::w(__FILE__, /SVP_WARN(/g" `grep "MyLog::w(__FILE__, "  -rl $1`
sed -i "s/MyLog::w(__FILE__,/SVP_WARN(/g" `grep "MyLog::w(__FILE__,"  -rl $1`

sed -i "s/MyLog::w(TAG, /SVP_WARN(/g" `grep "MyLog::w(TAG, "  -rl $1`
sed -i "s/MyLog::w(TAG,/SVP_WARN(/g" `grep "MyLog::w(TAG,"  -rl $1`

sed -i "s/MyLog::w(__FUNCTION__, /SVP_WARN(/g" `grep "MyLog::w(__FUNCTION__, "  -rl $1`
sed -i "s/MyLog::w(__FUNCTION__,/SVP_WARN(/g" `grep "MyLog::w(__FUNCTION__,"  -rl $1`


sed -i "s/printf/SVP_INFO/g" `grep "printf" -rl $1`
sed -i "s/g_print/SVP_INFO/g" `grep "g_print" -rl $1`
sed -i "s/g_message/SVP_INFO/g" `grep "g_message" -rl $1`
sed -i "s/g_error/SVP_ERROR/g" `grep "g_error" -rl $1`



## sed -i "s/SVP_ERROR/SVP_INFO/g" `ls`

#sed -i "s/www.admin99.net/admin99.net/g" `grep www.admin99.net -rl /home`
