# HXPod_Lib

[![CI Status](http://img.shields.io/travis/zengweizhen/HXPod_Lib.svg?style=flat)](https://travis-ci.org/zengweizhen/HXPod_Lib)
[![Version](https://img.shields.io/cocoapods/v/HXPod_Lib.svg?style=flat)](http://cocoapods.org/pods/HXPod_Lib)
[![License](https://img.shields.io/cocoapods/l/HXPod_Lib.svg?style=flat)](http://cocoapods.org/pods/HXPod_Lib)
[![Platform](https://img.shields.io/cocoapods/p/HXPod_Lib.svg?style=flat)](http://cocoapods.org/pods/HXPod_Lib)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

HXPod_Lib is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "HXPod_Lib"
```

## Author

zengweizhen, 18512166605@163.com

## License

HXPod_Lib is available under the MIT license. See the LICENSE file for more info.
1. 创建第一个用于存储 .podspec 后缀文件的 Git 仓库。(git的远端,在这里我们以文件夹的形式当做远端,命名HXPod),在服务器上面的地址

注意:但这里的仓库权限为公有的

2.创建第二个用于存储的共享代码的私有 Git 仓库(git的远端,在这里我们仍然以文件夹的形式当做远端,命名HXPod_Lib),在服务器上面的地址。用来存放源代码

注意:但这里的仓库权限为私有的(也可以为公有的)

3.本地创建后续要被共享的Lib工程

* 打开终端 cd 到你要创建的目录下 
* cd  /Users/jney/Documents/Pod_Public
* 然后输入 pod lib create HXPod_Lib 命令创建一个待上传的 Lib 模版
* 切换到HXPod_Lib目录下   cd  ~/HXPod_Lib
 重点:  HXPod_Lib必须和创建的第二个仓库名称一样


创建两个空文件模拟代码main.h   main.m


* 配置 .podspec 后缀文件
    Pod::Spec.new do|s|
    s.name : 项目名
    s.version :  是库源代码版本号，项目提交到github上时需要给项目加个标签，这个标签要和这个 version一致
    s.homepage : 项目主页（请注意，这里的地址跟git仓库地址有一定差别，请同学们看    清截图示例并区分）
    s.license : 开源协议（这里我们选择 MIT ）
    s.source : Git 仓库地址（第二步所复制的仓库地址）
    s.ios.deployment_target : 项目最低支持版本
    s.source_files : 具体去那个目录下下载特定共享代码（注意：这里的地址与 .podspec 文        件同级目录开始,，示例：PrivateLib/Classes/** /*表示如下目录下的所有文件
    s.frameworks : 项目所依赖的系统库(如果需要)

    s.dependency : 项目所依赖的第三方库(如果需要)

备注:
        配置完成后，我们需要验证下 .podspec 文件的格式正确性
        还是 .podspec 同级目录下，在终端输入pod lib lint

* 将本地 HXPod_Lib 工程与远程私有 Git 仓库关联(创建的第二个共享仓库)
       关联远程仓库
    git remote add origin 远程仓库地址(创建的第二个共享仓库)
       将本地仓库内容同步到远程仓库
    git push origin master

 //注意:如果你创建项目的时候生成了README或者license文件,那么这里你push的时候可能会push不了,这里的话可以用git push origin master -f 强制提交,会覆盖之前的文件


       然后进行本地和远程验证文件有效性。
    pod spec lint
备注:这里会报一个类似于clone地址找不到或者无法克隆的错误
解决方法:需要为远端的项目工程设置一个tag标签,这个tag标签必须和.podspec里面的s.version一致
git tag -a 0.1.0 -m "标签"
git push --tags

4. 上传.podspec到第一个远程私有仓库PrivatePodspec(用来放.podspec的仓库)
    还是在HXPod_Lib目录下面
* 创建一个私有仓库目录 文件创建在目录下面
    pod repo add HXPod (第一个创建的HXPod仓库地址)

* 然后向私有的 H 远程仓库HXPod中提交 .podspec
        pod repo push HXPod  HXPod_Lib.podspec







提交成功后，看看先前的 cocoapods 目录,确实生成了一个版本为0.1.0的文件,同时我们使用 search 命令，也是能搜索到的 
pod search HXPod_Lib
Creating search index for spec repo 'HXTest_PodSpec'.. Done!
Creating search index for spec repo 'master'.. Done!  

备注:
 
#下面两个source是必须写的,通过下面两个url,pod的时候才能找到对应的仓库地址
#官方仓库地址 
 source 'https://github.com/CocoaPods/Specs.git' 
#下面这个地址是管理spec文件的私有库地址,不是pod lib create那个项目的地址
 source 'https://github.com/zengweizhen/HXPod.git'


# Uncomment the next line to define a global platform for your project
# platform :ios, '9.0'

target 'Test' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  # use_frameworks!
  pod 'HXPod_Lib', '~> 0.1.0'
  # Pods for Test

  target 'TestTests' do
    inherit! :search_paths
    # Pods for testing
  end

  target 'TestUITests' do
    inherit! :search_paths
    # Pods for testing
  end

end



将自己私有的HXPod.podspec上传到CocoaPods后不需要早podfile里面设置两个source
想要发布自己的pods到CocoaPods，主要依靠pods trunk插件，使用trunk之前确认自己的cocoapods版本是不是在0.33及以上，打开终端，输入 pod --version 即可查看，如果版本过低，使用sudo gem update cocoapods 更新到最新版本。
* 注册Trunk
    pod trunk register 450083576@qq.com 'zengweizhen' --description='上传.podspec'
* pod trunk register orta@cocoapods.org 'Orta Therox' --description='macbook air’
          orta@cocoapods.org：一个真实存在的邮箱
          Orta Therox：用户名
          macbook ai：一个简单的描述
* 查看trunk
pod trunk me
可以查看已经注册的信息，其中包含你的name、email、since、Pods、sessions，其中Pods为你往CocoaPods提交的所有的Pod！
* 添加其他贡献者
pod trunk add-owner ARAnalytics kyle@cocoapods.org
ARAnalytics：其他贡献者的用户名
kyle@cocoapods.org：他的邮箱

* 使用trunk提交pods


* pod trunk push
          命令会首先验证podspec文件，然后把文件上传到trunk，最后会把podspec文件转化为需    要的json文件
* 测试pod
pod search PodName


 

