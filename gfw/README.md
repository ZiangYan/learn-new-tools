# 简介
越过长城，走向世界！

# naive
`naive`是一个基于shadowsocks的*nix命令行工具，用于一键翻墙。`naive`是一个shadowsocks客户端，用shadowsocks账号和密码访问了运行shadowsocks的服务器。建立和shadowsocks服务器的连接后，在本地开启翻墙服务器，其他的应用（例如浏览器）便可以通过访问本地的翻墙服务器来和shadowsocks服务器通讯。需要注意的是，shadowsocks服务器通常是付费的，我们通过购买该服务器的账号和密码来访问该服务器。我通常到[枫叶主机](http://www.fyvps.com)购买账号密码，2016年5月时，其高级套餐可以给10人用，每季度60元。Bigeye内部人员可以找我免费共享～

## 用法
按如下步骤操作，即可使用`naive`翻墙：

1. 安装`pip`，已安装的可以跳过：

        sudo apt-get install python-pip

2. shadowsocks已经被打包成了一个python包，可以用`pip`安装：

        sudo pip install shadowsocks


3. 将有效的用户名，密码，以及shadowsocks服务器地址填入`naive`，运行`naive`，将会在本机开启翻墙服务器，默认端口为1080：

        ./naive

4. 安装SwitchyOmega这一Chrome插件，用于自动检测墙内墙外网站，并对墙内网站直接连接，墙外网站用shadowsocks代理。该插件需要到Chrome扩展程序市场下载，可暂时用google
   hosts等方式下载该插件。该插件的配置可从`./OmegaOptions.bak`导入，该配置自动设置好了Chrome和本地翻墙服务器的连接。如无法导入设置，请在SwitchyOmega配置页中新建情景模式，并设置代理协议为SOCKS5，代理服务器为127.0.0.1，代理端口为1080，最后将SwitchyOmega设置为自动切换模式


5. 重启Chrome，应该可以正常访问所有网站。


## 常见问题
* 如果墙外网站无法正常访问，可以尝试切换用户名/密码/服务器,然后重新启动`naive`。注意，重新启动前需要将旧的进程杀死：

        pkill sslocal
        ./naive


* 可以通过查看log文件来找bug：
   
        tail -f /tmp/sslocal.log
   

# 备份
我备份了goagent和shadowsocks，在`backup/`文件夹下
