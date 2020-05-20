# model-package-dll
将模型和代码整合打包成dll接口，并采用python进行调用测试，具体的打包过程详见博客：https://blog.csdn.net/Enchanted_ZhouH/article/details/106231338

目录介绍如下：

dll --- 编译好的dll接口，分为静态和动态两种

img --- 测试图片

ncnn --- 编译ncnn后的install目录，分为静态和动态两种，以及更新的CMakeLists.txt文件

python --- python调用dll示例，以及pytorch调用模型示例

src --- 打包的头文件(.h)/源文件(.cpp)/模板定义文件(.def)，其中模板定义文件用来输出dll接口

src中的mobilenet_v2.id.h和mobilenet_v2.mem.h是mobilenet_v2模型读进内存后的头文件，由于大于50M，上传有些问题（提示错误，但上传成功了，文件却更大了？懵了），我将这两个文件放在了百度云上，链接：https://pan.baidu.com/s/1ry6-NhlUfQeCwSbLuMsEZw ，提取码：2zpp ，下载后替换掉src下的模型头文件即可，省心~

打包过程见博客即可，直接使用编译好的dll进行测试可以直接使用python目录下的测试代码体验。