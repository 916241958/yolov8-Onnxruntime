### onnxruntime源码编译安装教程

#### 打开你的~/.bashrc <font color='Yellow'>这点很重要</font>

```bash
sudo gedit ~/.bashrc
```

```bash
export PATH=$PATH:/usr/local/cuda/bin  
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cuda/lib64  
export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/cuda/lib64
```

这里是你cuda的安装路径，后面编译onnxruntime的GPU版本的时候需要指定。

#### 拉取和安装编译源码

```bash
git clone --recursive https://github.com/Microsoft/onnxruntime
```

这里是从外网拉取，最好是用科学上网的方式（有很多子包需要递归拉取，拉取少了会很麻烦）

<font color='Yellow'>注意：</font> 拉取失败可以使用以下命令来进行递归更新子模块

```bash
cd onnxruntime
git submodule update --remote --recursive
```

完全拉取成功后执行以下命令选择特定版本onnxruntime

```bash
cd onnxruntime/
git checkout v1.11.1
```

onnnxruntime和cuda对应版本的图片

![](https://i-blog.csdnimg.cn/blog_migrate/9e4eaba0c1edd134c3ca8460e6c791d9.png)

![](https://i-blog.csdnimg.cn/blog_migrate/60d058212708b6a37bab01c7e43af2ec.png)

![](https://i-blog.csdnimg.cn/blog_migrate/83b107981374e3b648089f0fd250e8ff.png)

onnx和onnruntime和opset的对应关系

![](https://i-blog.csdnimg.cn/blog_migrate/c11a25aff7fbfc680c1c3dd15dcad6ce.png)

![](https://i-blog.csdnimg.cn/blog_migrate/96de933f03ec7b64fe4a40d02b352ee4.png)

使用命令进行编译安装，注意把cuda换成第一步cuda的位置，其中的`use_cuda`表示你要使用cuda的onnxruntime，`cuda_home`和`cudnn_home`均指向你的CUDA安装目录即可。

```bash
./build.sh --skip_tests --use_cuda --config Release --build_shared_lib --parallel --cuda_home /usr/local/cuda-11.3 --cudnn_home /usr/local/cuda-11.3
```

编译成功的提示

```bash
[100%] Linking CXX executable onnxruntime_test_all
[100%] Built target onnxruntime_test_all
[100%] Linking CUDA shared module libonnxruntime_providers_cuda.so
[100%] Built target onnxruntime_providers_cuda
2022-03-15 13:49:03,260 util.run [DEBUG] - Subprocess completed. Return code: 0
2022-03-15 13:49:03,260 build [INFO] - Build complete
```

#### 关于如何在项目中使用cmakelist导入

```cmake
SET (ONNXRUNTIME_DIR "/home/yjam/下载/gitClone/onnxruntime")
TARGET_INCLUDE_DIRECTORIES(YOLOv8 PRIVATE "${ONNXRUNTIME_DIR}/include")
if (WIN32)
    TARGET_LINK_LIBRARIES(YOLOv8 "${ONNXRUNTIME_DIR}/lib/onnxruntime.lib")
endif(WIN32)

if (UNIX)
    TARGET_LINK_LIBRARIES(YOLOv8 "${ONNXRUNTIME_DIR}/build/Linux/Release/libonnxruntime.so")
endif(UNIX)
```

