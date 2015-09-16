# Introduction
Across the Great Wall we can reach every corner in the world.

# fanqiang
fanqiang is a shadowsocks-based command line tool, thanks for software school for providing accounts benevolently. 

## usage
1. Install pip if you don't already have:

    ```
    sudo apt-get install python-pip
    ```

2. Install python package: shadowsocks:

   ```
   sudo pip install shadowsocks
   ```

3. Run fanqiang and a proxy will start on localhost:1080:

   ```
   ./fanqiang
   ```
   
4. Install SwitchyOmega extension in your Chrome browser, resotre filter lists from ```backup/goagent/local/SwitchyOptions.bak```. Set agency protocol to SOCKS5, port to 1080, mode to auto switch in SwitchyOmega option page.

4. Restart your Chrome and now you should be able to explore everywhere in the world. You may want to view the log to check whether the sslocal are working correctly:

   ```
   tail -f /tmp/sslocal.log
   ```
   
# backup
Backup for goagent and shadowsocks are necessary due to well-known reason. All those backups are under ```backup/``` folder.

