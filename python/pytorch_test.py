# -*- coding: utf-8 -*-
"""
Created on Wed May 20 09:53:47 2020

@author: Hui Zhou
"""

import torch
import torchvision
import numpy as np
import cv2

#test image
img_path = "../img/test.jpg"
img = cv2.imread(img_path)
img = cv2.resize(img, (224, 224))
img = np.transpose(img, (2, 0, 1)).astype(np.float32)
img = torch.from_numpy(img)
img = img.unsqueeze(0)

#pytorch test
model = torchvision.models.mobilenet_v2(pretrained=True)
model.eval()
output = model.forward(img)
val, cls = torch.max(output.data, 1)
print("[pytorch]--->predicted class: %d, predicted value: %.6f" % (cls.item(), val.item()))
