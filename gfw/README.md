# Introduction
Across the Great Wall we can reach every corner in the world.

# fanqiang
fanqiang is a shadowsocks-based command line tool, thanks for software school for providing accounts benevolently. 

## usage
1. Install pip if you don't already have:

        sudo apt-get install python-pip

2. Install python package: shadowsocks:

        sudo pip install shadowsocks


3. Run fanqiang and a proxy will start on localhost:1080:

        ./fanqiang

4. Install SwitchyOmega extension in your Chrome browser, resotre filter lists from ```./OmegaOptions.bak```. Set agency protocol to SOCKS5, port to 1080, mode to auto switch in SwitchyOmega option page.

4. Restart your Chrome and now you should be able to explore everywhere in the world. You may want to view the log to check whether the sslocal are working correctly:

   
        tail -f /tmp/sslocal.log
   

## note
Google Scholar may refuse your visit sometimes if you use accounts provided by software school. However, we can access Google Scholar directly inside campus. Just add rule in SwitchyOmega to exclude proxy when visiting scholar.google.com.


# backup
Backup for goagent and shadowsocks are necessary due to well-known reason. All those backups are under ```backup/``` folder.

# OmegaOptions.bak
Configuration backup file for SwitchyOmega extension in Chrome. This configuration will listen to 127.0.0.1:1080 for proxy, which is default port for sslocal. This configuration also automatically update gfw list.
