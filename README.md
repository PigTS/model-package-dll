# model-package-dll
将模型和代码整合打包成dll接口，并采用python进行调用测试，具体的打包过程详见博客：

目录介绍如下：

dll --- 编译好的dll接口，分为静态和动态两种

img --- 测试图片

ncnn --- 编译ncnn后的install目录，分为静态和动态两种，以及更新的CMakeLists.txt文件

python --- python调用dll示例，以及pytorch调用模型示例

src --- 打包的头文件(.h)/源文件(.cpp)/模板定义文件(.def)，其中模板定义文件用来输出dll接口

打包过程见博客即可，直接使用编译好的dll进行测试可以直接使用python目录下的测试代码体验。