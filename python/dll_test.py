# -*- coding: utf-8 -*-
"""
Created on Tue May 19 10:27:04 2020

@author: Hui Zhou
"""

import ctypes
import base64
import time

#test img
img_path = "../img/test.jpg"
with open(img_path, 'rb') as f:
    img_base64 = base64.b64encode(f.read())
#load dll
#IREngine = ctypes.CDLL("../dll/static/ImageRecognitionEngine.dll")
IREngine = ctypes.CDLL("../dll/dynamic/ImageRecognitionEngine.dll")
#config interface argtypes and restypes
IREngine.initModel.argtypes = []
IREngine.initModel.restype = ctypes.c_void_p
IREngine.identify.argtypes = [ctypes.c_char_p]
IREngine.identify.restype = ctypes.c_char_p
IREngine.freeModel.argtypes = []
IREngine.freeModel.restypes = ctypes.c_void_p
#init model
IREngine.initModel()
#indentify
count = 0
while count < 100:
    res = IREngine.identify(img_base64).decode()
    cls, value = res.split()
    print("[dll]--->predicted class: %s, predicted value: %s" % (cls, value))
    count += 1
    time.sleep(150/1000) #sleep 150ms
#free model
IREngine.freeModel()